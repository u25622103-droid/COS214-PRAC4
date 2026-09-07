// TaskGroup.h
#ifndef TASKGROUP_H
#define TASKGROUP_H

#include "WorkItem.h"
#include <vector>
#include <string>
#include <iostream>

/**
 * Composite: A group of tasks that can contain other groups or individual tasks
 */
class TaskGroup : public WorkItem
{
private:
    std::vector<WorkItem *> children;
    TaskState *state; // Group also has a state

public:
    TaskGroup(const std::string &name, const std::string &desc = "", double cost = 0.0);
    ~TaskGroup() override;

    // Composite operations
    void addItem(WorkItem *item) override;
    void removeItem(const std::string &name) override;
    WorkItem *getItem(const std::string &name) override;
    std::vector<WorkItem *> getChildren() const override;
    size_t getChildCount() const override;
    WorkItem *getChild(size_t index) const override;
    bool isComposite() const override { return true; }

    // Override core operations
    double getProgress() const override;
    double getCost() const override;
    void display(int depth = 0) const override;

    // State pattern operations for group
    void startTask() override;
    void pauseTask() override;
    void completeTask() override;
    void blockTask() override;
    void unblockTask() override;
    void cancelTask() override;
    bool isCompleted() const override
    {
        return allChildrenCompleted();
    }
    std::string getStateName() const override;
    void setState(TaskState *newState) override;

    // Helper methods
    WorkItem *findItem(const std::string &name) const;
    size_t getTotalTaskCount() const;

private:
    void propagateState();
    bool allChildrenCompleted() const;
    bool anyChildrenInProgress() const;
};

#endif