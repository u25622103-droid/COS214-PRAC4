#ifndef WORKITEM_H
#define WORKITEM_H

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>

// Helper function for formatting doubles
inline std::string formatDouble(double value) {
    std::stringstream ss;
    ss.precision(1);
    ss << std::fixed << value;
    return ss.str();
}

// Forward declaration for State
class TaskState;

/**
 * Component: Abstract base for all work items
 * This is the root of the Composite pattern
 */
class WorkItem {
protected:
    std::string name;
    std::string description;
    double cost;

public:
    WorkItem(const std::string& name, const std::string& desc = "", double cost = 0.0);
    virtual ~WorkItem() = default;

    // Core operations
    virtual std::string getName() const;
    virtual std::string getDescription() const;
    virtual double getCost() const;
    virtual void setName(const std::string& newName);
    virtual void setDescription(const std::string& newDesc);
    
    // Composite operations - default implementations throw for leaves
    virtual void addItem(WorkItem* item);
    virtual void removeItem(const std::string& name);
    virtual WorkItem* getItem(const std::string& name);
    virtual std::vector<WorkItem*> getChildren() const;
    virtual size_t getChildCount() const;
    virtual bool isComposite() const;
    
    // Virtual operations for derived classes
    virtual double getProgress() const = 0;
    virtual void display(int depth = 0) const = 0;
    
    // State pattern operations
    virtual void startTask() = 0;
    virtual void blockTask() = 0;
    virtual void unblockTask() = 0;
    virtual void pauseTask() = 0;
    virtual void completeTask() = 0;
    virtual void cancelTask() = 0;
    virtual std::string getStateName() const = 0;
    virtual void setState(TaskState* newState) = 0;
};

#endif