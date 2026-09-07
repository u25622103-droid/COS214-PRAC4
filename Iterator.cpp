#include "Iterator.h"
#include "WorkItem.h"

LevelIterator::LevelIterator(WorkItem *rootItem)
    : root(rootItem), currentIndex(0), done(false)
{
    first();
}

void LevelIterator::buildNextLevel()
{
    nextLevel.clear();

    for (WorkItem *item : currentLevel)
    {
        if (item->isComposite())
        {
            for (size_t i = 0; i < item->getChildCount(); i++)
            {
                WorkItem *child = item->getChild(i);

                if (child)
                {
                    nextLevel.push_back(child);
                }
            }
        }
    }
}

void LevelIterator::first()
{
    currentLevel.clear();
    nextLevel.clear();
    currentIndex = 0;
    done = false;

    if (root)
    {
        currentLevel.push_back(root);
    }
    else
    {
        done = true;
    }
}

void LevelIterator::next()
{
    if (done)
    {
        return;
    }

    // Move to the next LEVEL
    buildNextLevel();

    currentLevel = nextLevel;
    nextLevel.clear();

    currentIndex = 0;

    // If there are no more items, traversal is finished
    if (currentLevel.empty())
    {
        done = true;
    }
}

WorkItem *LevelIterator::current()
{
    if (done || currentLevel.empty())
    {
        return nullptr;
    }

    return currentLevel[currentIndex];
}

bool LevelIterator::isDone() const
{
    return done;
}

std::vector<WorkItem *> LevelIterator::all() const
{
    return currentLevel;
}

std::vector<WorkItem *> LevelIterator::getLevel(int level)
{
    if (level < 0)
    {
        return std::vector<WorkItem *>();
    }

    LevelIterator temp(root);

    for (int i = 0; i < level; i++)
    {
        if (temp.isDone())
        {
            return std::vector<WorkItem *>();
        }

        temp.next();
    }

    return temp.all();
}

int LevelIterator::getLevelCount()
{
    LevelIterator temp(root);
    int count = 0;

    while (!temp.isDone())
    {
        count++;
        temp.next();
    }

    return count;
}