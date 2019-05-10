#include "AddMeasurementCommand.h"
#include "Lab3Model.h"
#include "QDebug"

AddMeasurementCommand::AddMeasurementCommand(Lab3Model& model)
    : QUndoCommand("Add measurement")
    , model(model)
    , measurement(model.nextMeasurement())
{}

void AddMeasurementCommand::undo() {
    model.removeLastMeasurement();
}

void AddMeasurementCommand::redo() {
    model.addNextMeasurement(measurement);
}
