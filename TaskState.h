#ifndef TASKSTATE_H
#define TASKSTATE_H

#include <string>

// Forward declaration
class WorkItem;

/**
 * State: Abstract base class for all task states
 * Defines the interface for state-dependent behavior
 */
class TaskState {
protected:
    WorkItem* context;  // The task that owns this state (should be WorkItem*, not TaskState*)

public:
    virtual ~TaskState() = default;
    
    void setContext(WorkItem* task) { context = task; }
    
    // State transition methods
    virtual void start() = 0;
    virtual void pause() = 0;
    virtual void complete() = 0;
    virtual void cancel() = 0;
    virtual void block() = 0;
    virtual void unblock() = 0;
    virtual std::string getStateName() const = 0;
    
    // Validation methods
    virtual bool canBlock() const { return false; }
    virtual bool canUnblock() const { return false; }
    virtual bool canStart() const { return false; }
    virtual bool canPause() const { return false; }
    virtual bool canComplete() const { return false; }
    virtual bool canCancel() const { return false; }
};

#endif