#include <iostream>
#include <string>
#include <vector>

#include "WorkItem.h"
#include "Task.h"
#include "TaskGroup.h"
#include "States.h"
#include "Iterator.h"
#include "WorkItemDecorator.h"

void printSeparator()
{
    std::string separator;

    for (int i = 0; i < 80; i++)
    {
        separator += "~";
    }

    std::cout << separator << std::endl;
}

void printHeader(const std::string &title)
{
    std::cout << "\n";
    printSeparator();
    std::cout << "  " << title << std::endl;
    printSeparator();
}

/*
 * Creates a complete Website Redesign project.
 *
 * Hierarchy:
 *
 * Website Redesign
 * |
 * +-- Frontend Development
 * |   |
 * |   +-- UI Design
 * |   |   +-- Wireframes
 * |   |   +-- Mockups
 * |   |
 * |   +-- Responsive Layout
 * |   +-- Animations
 * |
 * +-- Backend Development
 * |   |
 * |   +-- API Development
 * |   |   +-- User API
 * |   |   +-- Product API
 * |   |
 * |   +-- Authentication
 * |   +-- Email Service
 * |
 * +-- Database
 *     |
 *     +-- Schema Design
 *     |   +-- Users Table
 *     |   +-- Products Table
 *     |
 *     +-- Migrations
 *     +-- Seed Data
 *
 *
 */
TaskGroup *createProject()
{
    TaskGroup *project =
        new TaskGroup("Website Redesign",
                      "Complete website overhaul",
                      25000.0);

    // ---------------------------------------------------------
    // FRONTEND
    // ---------------------------------------------------------

    TaskGroup *frontend =
        new TaskGroup("Frontend Development",
                      "Client-side development",
                      10000.0);

    TaskGroup *uiDesign =
        new TaskGroup("UI Design",
                      "Design the new user interface",
                      3500.0);

    Task *wireframes =
        new Task("Wireframes",
                 "Create website wireframes",
                 1500.0,
                 12.0);

    Task *mockups =
        new Task("Mockups",
                 "Create high-fidelity UI mockups",
                 2000.0,
                 18.0);

    uiDesign->addItem(wireframes);
    uiDesign->addItem(mockups);

    Task *responsiveLayout =
        new Task("Responsive Layout",
                 "Make the website mobile-friendly",
                 3000.0,
                 25.0);

    Task *animations =
        new Task("Animations",
                 "Add CSS and JavaScript animations",
                 3000.0,
                 20.0);

    frontend->addItem(uiDesign);
    frontend->addItem(responsiveLayout);
    frontend->addItem(animations);

    // ---------------------------------------------------------
    // BACKEND
    // ---------------------------------------------------------

    TaskGroup *backend =
        new TaskGroup("Backend Development",
                      "Server-side development",
                      10000.0);

    TaskGroup *apiDevelopment =
        new TaskGroup("API Development",
                      "Develop the REST API",
                      5000.0);

    Task *userApi =
        new Task("User API",
                 "Implement user endpoints",
                 2500.0,
                 20.0);

    Task *productApi =
        new Task("Product API",
                 "Implement product endpoints",
                 2500.0,
                 20.0);

    apiDevelopment->addItem(userApi);
    apiDevelopment->addItem(productApi);

    Task *authentication =
        new Task("Authentication",
                 "Implement login and authentication",
                 3000.0,
                 25.0);

    Task *emailService =
        new Task("Email Service",
                 "Implement email notifications",
                 2000.0,
                 15.0);

    backend->addItem(apiDevelopment);
    backend->addItem(authentication);
    backend->addItem(emailService);

    // ---------------------------------------------------------
    // DATABASE
    // ---------------------------------------------------------

    TaskGroup *database =
        new TaskGroup("Database",
                      "Data layer development",
                      5000.0);

    TaskGroup *schemaDesign =
        new TaskGroup("Schema Design",
                      "Design the database schema",
                      2000.0);

    Task *usersTable =
        new Task("Users Table",
                 "Create the users table",
                 1000.0,
                 8.0);

    Task *productsTable =
        new Task("Products Table",
                 "Create the products table",
                 1000.0,
                 8.0);

    schemaDesign->addItem(usersTable);
    schemaDesign->addItem(productsTable);

    Task *migrations =
        new Task("Migrations",
                 "Create database migrations",
                 1500.0,
                 10.0);

    Task *seedData =
        new Task("Seed Data",
                 "Populate initial database data",
                 1500.0,
                 8.0);

    database->addItem(schemaDesign);
    database->addItem(migrations);
    database->addItem(seedData);

    // ---------------------------------------------------------
    // BUILD COMPLETE PROJECT TREE
    // ---------------------------------------------------------

    project->addItem(frontend);
    project->addItem(backend);
    project->addItem(database);

    return project;
}

/*
 * Demonstrates the State pattern.
 */
void demonstrateTaskLifecycle()
{
    printHeader("TASKFORGE WORKFLOW: TASK LIFECYCLE");

    Task *task =
        new Task("Implement Login",
                 "Implement secure user authentication",
                 3000.0,
                 25.0);

    std::cout << "\nInitial state: "
              << task->getStateName()
              << std::endl;

    std::cout << "\nAttempting to complete before starting:"
              << std::endl;

    task->completeTask();

    std::cout << "\nStarting task:"
              << std::endl;

    task->startTask();

    task->setProgress(25.0);
    task->setActualHours(6.0);

    std::cout << "Current state: "
              << task->getStateName()
              << std::endl;

    std::cout << "\nPausing task:"
              << std::endl;

    task->pauseTask();

    std::cout << "Current state: "
              << task->getStateName()
              << std::endl;

    std::cout << "\nAttempting invalid completion while paused:"
              << std::endl;

    task->completeTask();

    std::cout << "\nResuming task:"
              << std::endl;

    task->startTask();

    task->setProgress(100.0);
    task->setActualHours(24.0);

    std::cout << "\nCompleting task:"
              << std::endl;

    task->completeTask();

    std::cout << "Final state: "
              << task->getStateName()
              << std::endl;

    delete task;
}

/*
 * Demonstrates Composite behaviour using the complete project tree.
 */
void demonstrateProjectStructure(TaskGroup *project)
{
    printHeader("TASKFORGE WORKFLOW: PROJECT STRUCTURE");

    std::cout << "\nComplete project hierarchy:\n\n";

    project->display();

    std::cout << "\nProject summary:"
              << std::endl;

    std::cout << "Total cost: R"
              << project->getCost()
              << std::endl;

    std::cout << "Overall progress: "
              << project->getProgress()
              << "%"
              << std::endl;

    std::cout << "Total leaf tasks: "
              << project->getTotalTaskCount()
              << std::endl;
}

/*
 * Demonstrates recursive searching through the Composite.
 */
void demonstrateFindingTasks(TaskGroup *project)
{
    printHeader("TASKFORGE WORKFLOW: FIND PROJECT ITEMS");

    std::cout << "\nSearching for 'Mockups'..."
              << std::endl;

    WorkItem *found =
        project->findItem("Mockups");

    if (found)
    {
        std::cout << "Found: "
                  << found->getName()
                  << std::endl;

        std::cout << "Description: "
                  << found->getDescription()
                  << std::endl;
    }
    else
    {
        std::cout << "Item not found."
                  << std::endl;
    }

    std::cout << "\nSearching for 'User API'..."
              << std::endl;

    found = project->findItem("User API");

    if (found)
    {
        std::cout << "Found: "
                  << found->getName()
                  << std::endl;
    }
    else
    {
        std::cout << "Item not found."
                  << std::endl;
    }
}

/*
 * Demonstrates state propagation through nested TaskGroups.
 */
void demonstrateProjectWork(TaskGroup *project)
{
    printHeader("TASKFORGE WORKFLOW: START PROJECT WORK");

    TaskGroup *frontend =
        dynamic_cast<TaskGroup *>(
            project->getItem("Frontend Development"));

    TaskGroup *uiDesign =
        dynamic_cast<TaskGroup *>(
            project->findItem("UI Design"));

    TaskGroup *backend =
        dynamic_cast<TaskGroup *>(
            project->getItem("Backend Development"));

    TaskGroup *apiDevelopment =
        dynamic_cast<TaskGroup *>(
            project->findItem("API Development"));

    TaskGroup *database =
        dynamic_cast<TaskGroup *>(
            project->getItem("Database"));

    TaskGroup *schemaDesign =
        dynamic_cast<TaskGroup *>(
            project->findItem("Schema Design"));

    // ---------------------------------------------------------
    // FRONTEND
    // ---------------------------------------------------------

    std::cout << "\nStarting Frontend Development..."
              << std::endl;

    frontend->startTask();

    Task *wireframes =
        dynamic_cast<Task *>(
            project->findItem("Wireframes"));

    Task *mockups =
        dynamic_cast<Task *>(
            project->findItem("Mockups"));

    wireframes->setProgress(100.0);
    wireframes->setActualHours(12.0);
    wireframes->completeTask();

    mockups->setProgress(100.0);
    mockups->setActualHours(18.0);
    mockups->completeTask();

    std::cout << "\nUI Design children completed."
              << std::endl;

    uiDesign->completeTask();

    Task *responsiveLayout =
        dynamic_cast<Task *>(
            project->findItem("Responsive Layout"));

    Task *animations =
        dynamic_cast<Task *>(
            project->findItem("Animations"));

    responsiveLayout->setProgress(70.0);
    responsiveLayout->setActualHours(18.0);

    animations->setProgress(40.0);
    animations->setActualHours(8.0);

    // ---------------------------------------------------------
    // BACKEND
    // ---------------------------------------------------------

    std::cout << "\nStarting Backend Development..."
              << std::endl;

    backend->startTask();

    Task *userApi =
        dynamic_cast<Task *>(
            project->findItem("User API"));

    Task *productApi =
        dynamic_cast<Task *>(
            project->findItem("Product API"));

    userApi->setProgress(100.0);
    userApi->completeTask();

    productApi->setProgress(100.0);
    productApi->completeTask();

    apiDevelopment->completeTask();

    Task *authentication =
        dynamic_cast<Task *>(
            project->findItem("Authentication"));

    Task *emailService =
        dynamic_cast<Task *>(
            project->findItem("Email Service"));

    authentication->setProgress(50.0);
    emailService->setProgress(30.0);

    // ---------------------------------------------------------
    // DATABASE
    // ---------------------------------------------------------

    std::cout << "\nStarting Database Development..."
              << std::endl;

    database->startTask();

    Task *usersTable =
        dynamic_cast<Task *>(
            project->findItem("Users Table"));

    Task *productsTable =
        dynamic_cast<Task *>(
            project->findItem("Products Table"));

    usersTable->setProgress(100.0);
    usersTable->completeTask();

    productsTable->setProgress(100.0);
    productsTable->completeTask();

    schemaDesign->completeTask();

    Task *migrations =
        dynamic_cast<Task *>(
            project->findItem("Migrations"));

    Task *seedData =
        dynamic_cast<Task *>(
            project->findItem("Seed Data"));

    migrations->setProgress(60.0);
    seedData->setProgress(30.0);

    // ---------------------------------------------------------
    // DISPLAY UPDATED PROJECT
    // ---------------------------------------------------------

    std::cout << "\nUpdated project status:"
              << std::endl;

    project->display();
}

/*
 * Demonstrates Iterator independently from direct hierarchy traversal.
 *
 * The client does not obtain the TaskGroup's complete children vector.
 * It only asks the Iterator for the current level.
 */
void demonstrateTraversal(TaskGroup *project)
{
    printHeader("TASKFORGE WORKFLOW: PROJECT TRAVERSAL");

    LevelIterator iterator(project);

    int level = 0;

    while (!iterator.isDone())
    {
        std::cout << "\nLevel "
                  << level
                  << ":"
                  << std::endl;

        std::vector<WorkItem *> items =
            iterator.all();

        for (WorkItem *item : items)
        {
            std::cout << "  - "
                      << item->getName()
                      << " ["
                      << item->getStateName()
                      << "]"
                      << std::endl;
        }

        iterator.next();
        level++;
    }

    std::cout << "\nTotal levels in hierarchy: "
              << level
              << std::endl;
}

/*
 * Demonstrates a second meaningful traversal of the same hierarchy.
 *
 * This traversal uses the Iterator's direct level-access operation
 * rather than the sequential traversal above.
 */
void demonstrateSecondTraversal(TaskGroup *project)
{
    printHeader("TASKFORGE WORKFLOW: ACCESS SPECIFIC PROJECT LEVEL");

    LevelIterator iterator(project);

    std::cout << "\nLevel 0:"
              << std::endl;

    std::vector<WorkItem *> level0 =
        iterator.getLevel(0);

    for (WorkItem *item : level0)
    {
        std::cout << "  - "
                  << item->getName()
                  << std::endl;
    }

    std::cout << "\nLevel 2:"
              << std::endl;

    std::vector<WorkItem *> level2 =
        iterator.getLevel(2);

    for (WorkItem *item : level2)
    {
        std::cout << "  - "
                  << item->getName()
                  << " ["
                  << item->getStateName()
                  << "]"
                  << std::endl;
    }

    std::cout << "\nLevel 3:"
              << std::endl;

    std::vector<WorkItem *> level3 =
        iterator.getLevel(3);

    for (WorkItem *item : level3)
    {
        std::cout << "  - "
                  << item->getName()
                  << " ["
                  << item->getStateName()
                  << "]"
                  << std::endl;
    }
}

/*
 * Demonstrates runtime structural modification.
 *
 * A new task is added to the project after the original hierarchy
 * has already been created.
 */
void demonstrateRuntimeChange(TaskGroup *project)
{
    printHeader("TASKFORGE WORKFLOW: RUNTIME PROJECT CHANGE");

    TaskGroup *frontend =
        dynamic_cast<TaskGroup *>(
            project->getItem("Frontend Development"));

    if (!frontend)
    {
        std::cout << "Frontend group not found."
                  << std::endl;

        return;
    }

    std::cout << "\nAdding a new task at runtime..."
              << std::endl;

    Task *accessibility =
        new Task("Accessibility Review",
                 "Check the website for accessibility issues",
                 1200.0,
                 10.0);

    frontend->addItem(accessibility);

    std::cout << "New task added: "
              << accessibility->getName()
              << std::endl;

    std::cout << "\nUpdated frontend structure:"
              << std::endl;

    frontend->display();

    std::cout << "\nUpdated total task count: "
              << project->getTotalTaskCount()
              << std::endl;
}

/*
 * Demonstrates multiple decorators stacked at runtime.
 */
void demonstrateDecorators()
{
    printHeader("TASKFORGE WORKFLOW: ENHANCE A TASK");

    Task *baseTask =
        new Task("Security Audit",
                 "Perform security checks on the website",
                 4000.0,
                 30.0);

    std::cout << "\nOriginal task:"
              << std::endl;

    baseTask->display();

    // First decorator
    PriorityDecorator *priorityTask =
        new PriorityDecorator(baseTask, 5);

    // Second decorator
    DeadlineDecorator *deadlineTask =
        new DeadlineDecorator(priorityTask,
                              "2026-09-15");

    // Third decorator
    TagDecorator *taggedTask =
        new TagDecorator(deadlineTask);

    taggedTask->addTag("security");
    taggedTask->addTag("urgent");
    taggedTask->addTag("release");

    std::cout << "\nAfter applying decorators:"
              << std::endl;

    taggedTask->display();

    std::cout << "\nDecorator properties:"
              << std::endl;

    std::cout << "Priority: "
              << priorityTask->getPriority()
              << std::endl;

    std::cout << "Deadline: "
              << deadlineTask->getDeadline()
              << std::endl;

    std::cout << "Tags: ";

    std::vector<std::string> tags =
        taggedTask->getTags();

    for (const std::string &tag : tags)
    {
        std::cout << tag << " ";
    }

    std::cout << std::endl;

    std::cout << "\nStarting decorated task:"
              << std::endl;

    taggedTask->startTask();

    baseTask->setProgress(50.0);

    std::cout << "State through decorator: "
              << taggedTask->getStateName()
              << std::endl;

    std::cout << "Progress through decorator: "
              << taggedTask->getProgress()
              << "%"
              << std::endl;

    /*
     * The outer decorator owns the wrapped decorator,
     * which owns the next decorator, which owns baseTask.
     */
    delete taggedTask;
}

/*
 * Main coherent TaskForge demonstration.
 */
void runTaskForgeDemo()
{
    printHeader("TASKFORGE PROJECT MANAGEMENT SYSTEM");

    std::cout << "\nCreating Website Redesign project..."
              << std::endl;

    TaskGroup *project = createProject();

    std::cout << "Project created successfully."
              << std::endl;

    // 1. Composite
    demonstrateProjectStructure(project);

    // 2. Recursive Composite search
    demonstrateFindingTasks(project);

    // 3. State + Composite
    demonstrateProjectWork(project);

    // 4. Iterator traversal
    demonstrateTraversal(project);

    // 5. Second independent traversal
    demonstrateSecondTraversal(project);

    // 6. Runtime structural modification
    demonstrateRuntimeChange(project);

    // 7. Decorator
    demonstrateDecorators();

    // 8. Final summary
    printHeader("TASKFORGE FINAL PROJECT SUMMARY");

    std::cout << "\nProject: "
              << project->getName()
              << std::endl;

    std::cout << "Total cost: R"
              << project->getCost()
              << std::endl;

    std::cout << "Overall progress: "
              << project->getProgress()
              << "%"
              << std::endl;

    std::cout << "Total tasks: "
              << project->getTotalTaskCount()
              << std::endl;

    std::cout << "\nFinal project structure:"
              << std::endl;

    project->display();

    delete project;

    std::cout << "\nProject memory released successfully."
              << std::endl;
}

int main()
{

    runTaskForgeDemo();

    printSeparator();
    std::cout << "  TaskForge terminated successfully." << std::endl;
    printSeparator();

    return 0;
}