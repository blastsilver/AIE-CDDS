#include "main.h"

void main()
{
    // create state manager
    StateManager manager;
    // set current state to menu
    manager.SetState(States::MenuState);
    
    while (true)
    {
        // update current state
        manager.OnUpdate();
    }
}