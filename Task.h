#ifndef TASK_H
#define TASK_H

#include "WorkItem.h"
#include "TaskState.h"
#include <iostream>

/**
 * Leaf: Individual task that cannot have children
 * Uses State pattern for lifecycle management
 */
class Task : public WorkItem {
private:
    double progress;          
    double estimatedHours;
    double actualHours;
    TaskState* state;

public:
    Task(const std::string& name, 
         const std::string& desc = "", 
         double cost = 0.0,
         double estimatedHours = 0.0);
    ~Task() override;

    // Core operations
    double getProgress() const override;
    double getCost() const override;
    void display(int depth = 0) const override;
    bool isComposite() const override { return false; }

    // Task-specific methods
    double getEstimatedHours() const;
    double getActualHours() const;
    void setActualHours(double hours);
    void setProgress(double progress);

    // State pattern operations
    void startTask() override;
    void pauseTask() override;
    void completeTask() override;
    void blockTask() override;
    void unblockTask() override;
    void cancelTask() override;
    std::string getStateName() const override;
    void setState(TaskState* newState) override;
    bool isCompleted() const override { 
        return state ? state->getStateName() == "Completed" : false; 
}
    // Getter for state
    TaskState* getState() const { return state; }
};

#endif