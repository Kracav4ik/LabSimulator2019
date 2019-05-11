#include "LabRootWidget.h"

#include "LabModel.h"

#include <QFileDialog>
#include <QTableWidget>
#include <QTextStream>
#include <QClipboard>
#include <QApplication>

LabRootWidget::LabRootWidget(std::vector<TableColumns> tableColumns)
    : _tableColumns(std::move(tableColumns))
{
}

QUndoStack* LabRootWidget::undoStack() {
    return &_undoStack;
}

void LabRootWidget::setTableWidget(QTableWidget* table) {
    tableWidget = table;

    int columnsCount = _tableColumns.size();
    tableWidget->setColumnCount(columnsCount);
    for (int i = 0; i < columnsCount; ++i) {
        const auto& column = _tableColumns[i];
        tableWidget->setHorizontalHeaderItem(i, new QTableWidgetItem(column.text));
        tableWidget->setColumnWidth(i, column.width);
    }
}

void LabRootWidget::undo() {
    _undoStack.undo();
}

void LabRootWidget::redo() {
    _undoStack.redo();
}

void LabRootWidget::reset() {
    _undoStack.clear();
    model().clear();
}

void LabRootWidget::copyTable() {
    QClipboard* clipboard = QApplication::clipboard();
    clipboard->setText(tableToString("\t"));
}

void LabRootWidget::saveToCSV() {
    QString fileName = QFileDialog::getSaveFileName(this, u8"Сохранить в CSV", "", "*.csv");
    if (fileName.isEmpty()) {
        return;
    }

    if (!fileName.toLower().endsWith(".csv")) {
        fileName += ".csv";
    }

    QFile csvFile(fileName);
    if(csvFile.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        QTextStream out(&csvFile);
        out << tableToString(",");
        csvFile.close();
    }
}

QString LabRootWidget::tableToString(const QString& sep) const {
    QString textData;
    int rows = tableWidget->rowCount();
    int columns = tableWidget->columnCount();
    textData += tableWidget->horizontalHeaderItem(0)->text();
    for (int k = 1; k < columns; ++k) {
        textData += sep + tableWidget->horizontalHeaderItem(k)->text();
    }
    textData += "\n";

    for (int i = 0; i < rows; i++) {
        textData += tableWidget->item(i, 0)->text();
        for (int j = 1; j < columns; j++) {
            textData += sep + tableWidget->item(i, j)->text();
        }
        textData += "\n";
    }
    return textData;
}
