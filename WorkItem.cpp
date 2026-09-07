#include "WorkItem.h"


WorkItem::WorkItem(const std::string& name, const std::string& desc, double cost)
    : name(name), description(desc), cost(cost) {}

double WorkItem::getCost() const { 
    return cost; 
}
std::string WorkItem::getName() const { 
    return name; 
}
std::string WorkItem::getDescription() const { 
    return description;
}
void WorkItem::setName(const std::string& newName) { 
    name = newName; 
}
void WorkItem::setDescription(const std::string& newDesc) { 
    description = newDesc; 
}

void WorkItem::addItem(WorkItem*) {
    std::cout << "Cannot add items to a leaf work item\n";
}

void WorkItem::removeItem(const std::string&) {
    std::cout<< "Cannot remove items from a leaf work item\n";
}

WorkItem* WorkItem::getItem(const std::string&) {
    std::cout << "Leaf work item has no children\n";
    return nullptr;
}

std::vector<WorkItem*> WorkItem::getChildren() const {
    return std::vector<WorkItem*>();
}

size_t WorkItem::getChildCount() const { 
    return 0; 
}

bool WorkItem::isComposite() const { 
    return false; 
}
