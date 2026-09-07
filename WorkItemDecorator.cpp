#include "WorkItem.h"
#include "WorkItemDecorator.h"

PriorityDecorator::PriorityDecorator(WorkItem* item, int prio) : WorkItemDecorator(item), priority(prio) {}

int PriorityDecorator::getPriority() const { 
    return priority; 
}

void PriorityDecorator::setPriority(int p) { 
    priority = p; 
}

void PriorityDecorator::display(int depth = 0) const {
    std::string indent(depth * 2, ' ');
    std::cout << indent << "[Priority: " << priority << "] ";
    wrappedItem->display(depth);
}

DeadlineDecorator::DeadlineDecorator(WorkItem* item, const std::string& deadline): WorkItemDecorator(item), deadline(deadline) {}

std::string DeadlineDecorator::getDeadline() const { 
    return deadline; 
}

void DeadlineDecorator::setDeadline(const std::string& d) { 
    deadline = d; 
}

void DeadlineDecorator::display(int depth = 0) const {
    std::string indent(depth * 2, ' ');
    std::cout << indent << "[Deadline: " << deadline << "] ";
    wrappedItem->display(depth);
}

TagDecorator::TagDecorator(WorkItem* item) : WorkItemDecorator(item) {}

void TagDecorator::addTag(const std::string& tag) { 
    tags.push_back(tag); 
}

std::vector<std::string> TagDecorator::getTags() const { 
    return tags; 
}

void TagDecorator::display(int depth = 0) const {
    std::string indent(depth * 2, ' ');
    std::cout << indent << "[Tags: ";
    for (size_t i = 0; i < tags.size(); ++i) {
        if (i > 0) std::cout << ", ";
        std::cout << tags[i];
    }
    std::cout << "] ";
    wrappedItem->display(depth);
}