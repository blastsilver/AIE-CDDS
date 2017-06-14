#pragma once

class StateManager
{
    // variables
    State * m_currentState;
public:
    // public defaults
    StateManager();
    ~StateManager();
    // public functions
    void set(States state);
    void update();
};