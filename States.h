#ifndef STATES_H
#define STATES_H

#include "TaskState.h"
#include <iostream>

/**
 * Not Started State: Initial state, task is created but not started
 */
class NotStartedState : public TaskState
{
public:
    TaskState *clone() const override { return new NotStartedState(*this); }
    void start() override;
    void pause() override;
    void complete() override;
    void cancel() override;
    void block() override;
    void unblock() override;
    std::string getStateName() const override { return "Not Started"; }
    bool canStart() const override { return true; }
    bool canCancel() const override { return true; }
    bool canBlock() const override { return true; }
};

/**
 * InProgress State: Task is actively being worked on
 */
class InProgressState : public TaskState
{
public:
    TaskState *clone() const override { return new InProgressState(*this); }
    void start() override;
    void pause() override;
    void complete() override;
    void cancel() override;
    void block() override;
    void unblock() override;
    std::string getStateName() const override { return "In Progress"; }
    bool canPause() const override { return true; }
    bool canComplete() const override { return true; }
    bool canCancel() const override { return true; }
    bool canBlock() const override { return true; }
};

/**
 * Paused State: Task is temporarily halted
 */
class PausedState : public TaskState
{
public:
    TaskState *clone() const override { return new PausedState(*this); }
    void start() override;
    void pause() override;
    void complete() override;
    void cancel() override;
    void block() override;
    void unblock() override;
    std::string getStateName() const override { return "Paused"; }
    bool canStart() const override { return true; }
    bool canCancel() const override { return true; }
};

/**
 * Blocked State: Task is blocked waiting for something
 */
class BlockedState : public TaskState
{
public:
    TaskState *clone() const override { return new BlockedState(*this); }
    void start() override;
    void pause() override;
    void complete() override;
    void cancel() override;
    void block() override;
    void unblock() override;
    std::string getStateName() const override { return "Blocked"; }
    bool canUnblock() const override { return true; }
    bool canCancel() const override { return true; }
};

/**
 * Completed State: Task is finished
 */
class CompletedState : public TaskState
{
public:
    TaskState *clone() const override { return new CompletedState(*this); }
    void start() override;
    void pause() override;
    void complete() override;
    void cancel() override;
    void block() override;
    void unblock() override;
    std::string getStateName() const override { return "Completed"; }
};

/**
 * Cancelled State: Task was cancelled
 */
class CancelledState : public TaskState
{
public:
    TaskState *clone() const override { return new CancelledState(*this); }
    void start() override;
    void pause() override;
    void complete() override;
    void cancel() override;
    void block() override;
    void unblock() override;
    std::string getStateName() const override { return "Cancelled"; }
};

#endif