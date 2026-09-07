#include "Task.h"
#include "States.h"
#include <iostream>

Task::Task(const std::string& name, const std::string& desc, double cost, double estimatedHours)
    : WorkItem(name, desc, cost), 
      progress(0.0),
      estimatedHours(estimatedHours),
      actualHours(0.0),
      state(new NotStartedState()) {  
    state->setContext(this);
}

Task::~Task() {
    delete state;
}

double Task::getProgress() const {
    return progress; 
}

double Task::getCost() const { 
    return cost; 
}

void Task::display(int depth) const {
    std::string indent(depth * 2, ' ');
    std::cout << indent << " Task: " << name << " Progress: " << progress << "%"<< "Cost: R" << cost<< "State: " << getStateName()
              << "Estimation: " << estimatedHours << "hours"
              << "Actual: " << actualHours << "hours"<< std::endl;
}

double Task::getEstimatedHours() const { 
    return estimatedHours; 
}
double Task::getActualHours() const { 
    return actualHours; 
}
void Task::setActualHours(double hours) { 
    actualHours = hours; 
}


void Task::setProgress(double p) { 
    if (p < 0) {
        progress = 0;
    } else if (p > 100) {
        progress = 100;
    } else {
        progress = p;
    }
}

void Task::startTask() { 
    if (state) {
        state->start();
    } 
}

void Task::pauseTask() { 
    if (state) {
        state->pause();
    } 
}

void Task::completeTask() { 
    if (state) {
        state->complete();
    } 
}

void Task::blockTask() {
    if (state) {
        state->block();
    } 
}

void Task::unblockTask() {
    if (state) {
        state->unblock();
    } 
}

void Task::cancelTask() { 
    if (state) {
        state->cancel();
    } 
}

std::string Task::getStateName() const {
    return state ? state->getStateName() : "Unknown";
}

void Task::setState(TaskState* newState) {
    delete state;
    state = newState;
    if (state) {
        state->setContext(this);
    }
}
