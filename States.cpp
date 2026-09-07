#include "States.h"
#include "WorkItem.h"
#include <iostream>

// NotStartedState
void NotStartedState::start()
{
    std::cout << "Let's start the task:)\n";
    context->setState(new InProgressState());
}

void NotStartedState::pause()
{
    std::cout << "Cannot pause as the task hasn't been started.\n";
}

void NotStartedState::complete()
{
    std::cout << "Cannot complete a task that hasn't started.\n";
}

void NotStartedState::cancel()
{
    std::cout << "Cancelling task...:(\n";
    context->setState(new CancelledState());
}

void NotStartedState::block()
{
    std::cout << "Cannot block a task that hasn't started.\n";
}

void NotStartedState::unblock()
{
    std::cout << "Cannot unblock a task that hasn't started.\n";
}

// InProgressState 
void InProgressState::start()
{
    std::cout << "Task already in progress.\n";
}

void InProgressState::pause()
{
    std::cout << "Pausing task...\n";
    context->setState(new PausedState());
}

void InProgressState::complete()
{
    std::cout << "Completing task...\n";
    context->setState(new CompletedState());
}

void InProgressState::cancel()
{
    std::cout << "Cancelling in-progress task...\n";
    context->setState(new CancelledState());
}

void InProgressState::block()
{
    std::cout << "Blocking task...\n";
    context->setState(new BlockedState());
}

void InProgressState::unblock()
{
    std::cout << "Cannot unblock a task that isn't blocked.\n";
}

// PausedState
void PausedState::start()
{
    std::cout << "Resuming task...\n";
    context->setState(new InProgressState());
}

void PausedState::pause()
{
    std::cout << "Task already paused.\n";
}

void PausedState::complete()
{
    std::cout << "Cannot complete a paused task. Resume first.\n";
}

void PausedState::cancel()
{
    std::cout << "Cancelling paused task...\n";
    context->setState(new CancelledState());
}

void PausedState::block()
{
    std::cout << "Cannot block a paused task.\n";
}

void PausedState::unblock()
{
    std::cout << "Cannot unblock a task that isn't blocked.\n";
}

//BlockedState 
void BlockedState::start()
{
    std::cout << "Cannot start a blocked task. Unblock first.\n";
}

void BlockedState::pause()
{
    std::cout << "Cannot pause a blocked task.\n";
}

void BlockedState::complete()
{
    std::cout << "Cannot complete a blocked task. Unblock first.\n";
}

void BlockedState::cancel()
{
    std::cout << "Cancelling blocked task...\n";
    context->setState(new CancelledState());
}

void BlockedState::block()
{
    std::cout << "Task already blocked.\n";
}

void BlockedState::unblock()
{
    std::cout << "Unblocking task...\n";
    context->setState(new InProgressState());
}

// CompletedState 
void CompletedState::start()
{
    std::cout << "Cannot start a completed task.\n";
}

void CompletedState::pause()
{
    std::cout << "Cannot pause a completed task.\n";
}

void CompletedState::complete()
{
    std::cout << "Task already completed.\n";
}

void CompletedState::cancel()
{
    std::cout << "Cannot cancel a completed task.\n";
}

void CompletedState::block()
{
    std::cout << "Cannot block a completed task.\n";
}

void CompletedState::unblock()
{
    std::cout << "Cannot unblock a completed task.\n";
}

//  CancelledState
void CancelledState::start()
{
    std::cout << "Cannot start a cancelled task.\n";
}

void CancelledState::pause()
{
    std::cout << "Cannot pause a cancelled task.\n";
}

void CancelledState::complete()
{
    std::cout << "Cannot complete a cancelled task.\n";
}

void CancelledState::cancel()
{
    std::cout << "Task already cancelled.\n";
}

void CancelledState::block()
{
    std::cout << "Cannot block a cancelled task.\n";
}

void CancelledState::unblock()
{
    std::cout << "Cannot unblock a cancelled task.\n";
}
