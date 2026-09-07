#include "TaskGroup.h"
#include "States.h"
#include <iostream>

TaskGroup::TaskGroup(const std::string& name, const std::string& desc, double cost)
    : WorkItem(name, desc, cost), state(new NotStartedState()) {
}

TaskGroup::~TaskGroup() {
    delete state;
    for (WorkItem* child : children) {
        delete child;
    }
}

void TaskGroup::addItem(WorkItem* item) {
    if (item) {
        children.push_back(item);
    }
    
}

void TaskGroup::removeItem(const std::string& name) {
    for (auto find = children.begin(); find != children.end(); ++find) {
        if ((*find)->getName() == name) {
            delete *find;
            children.erase(find);
            return;
        }
    }
}

WorkItem* TaskGroup::getItem(const std::string& name) {
    for (WorkItem* child : children) {
        if (child->getName() == name) {
            return child;
        }
        if (child->isComposite()) {
            TaskGroup* group = dynamic_cast<TaskGroup*>(child);
            if (group) {
                WorkItem* found = group->getItem(name);
                if (found) {
                    return found;
                }
            }
        }
    }
    return nullptr;
}

std::vector<WorkItem*> TaskGroup::getChildren() const {
    return children;
}

size_t TaskGroup::getChildCount() const {
    return children.size();
}

double TaskGroup::getProgress() const {
    if (children.empty()) return 0.0;
    
    double total = 0.0;
    for (WorkItem* child : children) {
        total += child->getProgress();
    }
    return total / children.size();
}

double TaskGroup::getCost() const {
    double total = WorkItem::getCost();  // Base cost
    for (WorkItem* child : children) {
        total += child->getCost();
    }
    return total;
}

void TaskGroup::display(int depth) const {
    std::string indent(depth * 2, ' ');
    std::cout << indent << "Group: " << name 
              << " Progress: " << getProgress() << "%"
              << " Cost: R" << getCost()
              << " State: " << getStateName()
              << " Children: " << children.size()
              << std::endl;
    
    for (WorkItem* child : children) {
        child->display(depth + 1);
    }
}

void TaskGroup::startTask() {
    if (state) {
        state->start();
        propagateState();
    }
}

void TaskGroup::pauseTask() {
    if (state) {
        state->pause();
        propagateState();
    }
}

void TaskGroup::completeTask() {
    if (allChildrenCompleted()) {
        if (state) {
            state->complete();
        }
    } else {
        std::cout << "Cannot complete group - not all children are completed\n";
    }
}

void TaskGroup::cancelTask() {
    if (state) {
        state->cancel();
        propagateState();
    }
}

std::string TaskGroup::getStateName() const {
    return state ? state->getStateName() : "Unknown";
}

void TaskGroup::setState(TaskState* newState) {
    delete state;
    state = newState;
    if (state) {
        state->setContext(this);
    }
}

void TaskGroup::propagateState() {
    for (WorkItem* child : children) {
        child->setState(state);
    }
}



bool TaskGroup::allChildrenCompleted() const {
    for (WorkItem* child : children) {
        if (child->getStateName() != "Completed") {
            return false;
        }
    }
    return true;
}

bool TaskGroup::anyChildrenInProgress() const {
    for (WorkItem* child : children) {
        if (child->getStateName() == "In Progress") {
            return true;
        }
        if (child->isComposite()) {
            TaskGroup* group = dynamic_cast<TaskGroup*>(child);
            if (group && group->anyChildrenInProgress()) {
                return true;
            }
        }
    }
    return false;
}

WorkItem* TaskGroup::findItem(const std::string& name) const {
    for (WorkItem* child : children) {
        if (child->getName() == name) {
            return child;
        }
        if (child->isComposite()) {
            TaskGroup* group = dynamic_cast<TaskGroup*>(child);
            if (group) {
                WorkItem* found = group->findItem(name);
                if (found) {
                    return found;
                }
            }
        }
    }
    return nullptr;
}

size_t TaskGroup::getTotalTaskCount() const {
    size_t count = 0;
    for (WorkItem* child : children) {
        if (child->isComposite()) {
            TaskGroup* group = dynamic_cast<TaskGroup*>(child);
            if (group) {
                count += group->getTotalTaskCount();
            }
        } else {
            count++;
        }
    }
    return count;
}

void TaskGroup::blockTask(){
    if (state) {
        state->block();
        propagateState();
    }
}

void TaskGroup::unblockTask() {
    if (state) {
        state->unblock();
        propagateState();
    }
}
