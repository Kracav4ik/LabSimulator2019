#pragma once

#include "symbols_export.h"

#include <QWidget>
#include <QUndoStack>

class LabModel;
class QTableWidget;

class SYMBOLS_EXPORT LabRootWidget : public QWidget {
Q_OBJECT
private:
    QString tableToString(const QString& sep) const;

protected:
    virtual LabModel& model() = 0;

    struct TableColumns {
        int width;
        QString text;
    };
    std::vector<TableColumns> _tableColumns;

    QUndoStack _undoStack;
    QTableWidget* tableWidget = nullptr;

public:
    LabRootWidget(std::vector<TableColumns> tableColumns);

    QUndoStack* undoStack();
    void setTableWidget(QTableWidget* table);

public slots:
    void undo();
    void redo();
    void reset();
    void copyTable();
    void saveToCSV();

};


