#pragma once

#include <QUndoCommand>
#include <QPoint>

class Lab3Model;

class AddMeasurementCommand : public QUndoCommand {
private:
    Lab3Model& model;
    QPoint measurement;

public:
    explicit AddMeasurementCommand(Lab3Model& model);

    void undo() override;
    void redo() override;
};


