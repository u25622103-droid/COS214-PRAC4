#include <vector>
#include <queue>
#include "WorkItem.h"
#include "Iterator.h"

LevelIterator::LevelIterator(WorkItem* rootItem) : root(rootItem), currentIndex(0), done(false) {
        first();
}

void LevelIterator::buildNextLevel() {
    nextLevel.clear();
    for (WorkItem* item : currentLevel) {
        if (item->isComposite()) {
            std::vector<WorkItem*> children = item->getChildren();
            nextLevel.insert(nextLevel.end(), children.begin(), children.end());
        }
    }
}
    

void LevelIterator::first() {
    currentLevel.clear();
    nextLevel.clear();
    currentIndex = 0;
    
    if (root) {
        currentLevel.push_back(root);
    } else {
        done = true;
    }
}

void LevelIterator::next() {
    if (done) return;
    
    currentIndex++;
    if (currentIndex >= currentLevel.size()) {
        // Move to next level
        buildNextLevel();
        currentLevel = nextLevel;
        currentIndex = 0;
        
        if (currentLevel.empty()) {
            done = true;
        }
    }
}

WorkItem* LevelIterator::current() {
    if (done || currentIndex >= currentLevel.size()) {
        return nullptr;
    }
    return currentLevel[currentIndex];
}

bool LevelIterator::isDone() const {
    return done;
}

std::vector<WorkItem*> LevelIterator::all() const {
    return currentLevel;
}

std::vector<WorkItem*> LevelIterator::getLevel(int level) {
    LevelIterator temp(root);
    int currentLevelNum = 0;
    
    while (currentLevelNum < level && !temp.isDone()) {
        temp.next();
        currentLevelNum++;
    }
    
    if (currentLevelNum == level) {
        return temp.all();
    }
    return {};
}

int LevelIterator::getLevelCount() {
    LevelIterator temp(root);
    int count = 1;
    
    while (!temp.isDone()) {
        temp.next();
        if (!temp.isDone()) count++;
    }
    return count;
}