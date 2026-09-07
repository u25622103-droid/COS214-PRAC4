#ifndef WORKITEMDECORATOR_H
#define WORKITEMDECORATOR_H

#include "WorkItem.h"
#include <string>

class WorkItemDecorator : public WorkItem {
protected:
    WorkItem* wrappedItem;

public:
    WorkItemDecorator(WorkItem* item) : WorkItem(
        item->getName(),
        item->getDescription(),
        item->getCost()
    ), wrappedItem(item) {}

    ~WorkItemDecorator() override {
    }

    std::string getName() const override { return wrappedItem->getName(); }
    std::string getDescription() const override { return wrappedItem->getDescription(); }
    double getCost() const override { return wrappedItem->getCost(); }
    void setName(const std::string& n) override { wrappedItem->setName(n); }
    void setDescription(const std::string& d) override { wrappedItem->setDescription(d); }

    double getProgress() const override { return wrappedItem->getProgress(); }
    void display(int depth = 0) const override { wrappedItem->display(depth); }
    bool isComposite() const override { return wrappedItem->isComposite(); }

    void startTask() override { wrappedItem->startTask(); }
    void pauseTask() override { wrappedItem->pauseTask(); }
    void completeTask() override { wrappedItem->completeTask(); }
    void blockTask() override { wrappedItem->blockTask(); }
    void unblockTask() override { wrappedItem->unblockTask(); }
    void cancelTask() override { wrappedItem->cancelTask(); }
    std::string getStateName() const override { return wrappedItem->getStateName(); }
    void setState(TaskState* newState) override { wrappedItem->setState(newState); }

    WorkItem* getWrapped() const { return wrappedItem; }
};

class PriorityDecorator : public WorkItemDecorator {
    private:
        int priority;

    public:
        PriorityDecorator(WorkItem* item, int prio);
        int getPriority() const;
        void setPriority(int p);
        void display(int depth = 0) const override;
};

class DeadlineDecorator : public WorkItemDecorator {
    private:
        std::string deadline; 

    public:
        DeadlineDecorator(WorkItem* item, const std::string& deadline);
        std::string getDeadline() const;
        void display(int depth = 0) const override;

};

class TagDecorator : public WorkItemDecorator {
    private:
        std::vector<std::string> tags;

    public:
        TagDecorator(WorkItem* item);
        void addTag(const std::string& tag);
        std::vector<std::string> getTags();
        void display(int depth = 0) const override;

};


#endif//WORKITEMDECORATOR_H