#include "gameNode.h"

bool gameNode::init(void)
{
    if (!Layer::init()) return false;
    
    return true;
}

void gameNode::onEnter(void)
{
    Layer::onEnter();
}

void gameNode::onExit(void)
{
    Layer::onExit();
}