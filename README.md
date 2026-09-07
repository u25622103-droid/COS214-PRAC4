# COS214-PRAC4

# TaskForge

A software project management system demonstrating the Composite, State, Iterator, and Decorator design patterns.

## Features

- **Composite Pattern**: Hierarchical project structure with TaskGroups and Tasks
- **State Pattern**: Task lifecycle management (Not Started, In Progress, Paused, Blocked, Completed, Cancelled)
- **Iterator Pattern**: Level-by-level traversal of the project hierarchy
- **Decorator Pattern**: Enhance tasks with priority, deadlines, and tags

# Project Structure
├── main.cpp              # Demo application

├── WorkItem.h/.cpp       # Abstract component

├── Task.h/.cpp           # Leaf component

├── TaskGroup.h/.cpp      # Composite component

├── TaskState.h           # State interface

├── States.h/.cpp         # Concrete states

├── Iterator.h/.cpp       # Level-order iterator

├── WorkItemDecorator.h/.cpp  # Decorator pattern

├── Dockerfile            # Docker configuration

└── Makefile              # Build configuration

## Building
make

## Running
./taskforge

## Memory Checking
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./taskforge

## Docker
bash

# Build the Docker image
docker build -t taskforge .

# Run the application
docker run --rm taskforge

# Run with valgrind
docker run --rm taskforge valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./taskforge

# Clean
make clean
