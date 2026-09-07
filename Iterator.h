#ifndef ITERATOR_H
#define ITERATOR_H

#include <vector>
#include <queue>
#include "WorkItem.h"

class Iterator {
    public:
        virtual ~Iterator() = default;
        virtual void first() = 0;
        virtual void next() = 0;
        virtual WorkItem* current() = 0;
        virtual bool isDone() const = 0;
        virtual std::vector<WorkItem*> all() const = 0;
        virtual std::vector<WorkItem*> getLevel(int level) = 0;
        int getLevelCount();
};

class LevelIterator : public Iterator {
    private:
        WorkItem* root;
        std::vector<WorkItem*> currentLevel;
        std::vector<WorkItem*> nextLevel;
        size_t currentIndex;
        bool done;
        void buildNextLevel();

    public:
        LevelIterator(WorkItem* rootItem);
        void first() override;
        void next() override;
        WorkItem* current() override;
        bool isDone() const override;
        std::vector<WorkItem*> all() const override;
        std::vector<WorkItem*> getLevel(int level) override;
        int getLevelCount();
};      

#endif//ITERATOR_H