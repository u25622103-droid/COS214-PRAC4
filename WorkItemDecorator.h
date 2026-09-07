#ifndef WORKITEMDECORATOR_H
#define WORKITEMDECORATOR_H

#include "WorkItem.h"
#include <string>

class WorkItemDecorator : public WorkItem {
protected:
    WorkItem* wrapped;

public:
    WorkItemDecorator(WorkItem* item) : WorkItem(
        item->getName(),
        item->getDescription(),
        item->getCost()
    ), wrapped(item) {}

    ~WorkItemDecorator() override {
    }

    std::string getName() const override { return wrapped->getName(); }
    std::string getDescription() const override { return wrapped->getDescription(); }
    double getCost() const override { return wrapped->getCost(); }
    void setName(const std::string& n) override { wrapped->setName(n); }
    void setDescription(const std::string& d) override { wrapped->setDescription(d); }

    double getProgress() const override { return wrapped->getProgress(); }
    void display(int depth = 0) const override { wrapped->display(depth); }
    bool isComposite() const override { return wrapped->isComposite(); }

    void startTask() override { wrapped->startTask(); }
    void pauseTask() override { wrapped->pauseTask(); }
    void completeTask() override { wrapped->completeTask(); }
    void blockTask() override { wrapped->blockTask(); }
    void unblockTask() override { wrapped->unblockTask(); }
    void cancelTask() override { wrapped->cancelTask(); }
    std::string getStateName() const override { return wrapped->getStateName(); }
    void setState(TaskState* newState) override { wrapped->setState(newState); }

    WorkItem* getWrapped() const { return wrapped; }
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