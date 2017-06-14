#include "main.h"

StateManager::StateManager()
{
    // initialize variables
    this->m_currentState = nullptr;
};
StateManager::~StateManager()
{
    // delete state if exists
    if (this->m_currentState != nullptr)
    {
        // delete state
        delete this->m_currentState;
        this->m_currentState = nullptr;
    }
};
void StateManager::set(States state)
{
    // delete state if exists
    if (this->m_currentState != nullptr)
    {
        // check if same state
        if (m_currentState->type() == state) return;
        // end state
        m_currentState->OnEnd();
        // delete state
        delete this->m_currentState;
    }
    // check current state
    switch (state)
    {
        case States::MenuState:
        {
            m_currentState = new MenuState(this);
            break;
        }
        case States::TreeState:
        {
            m_currentState = new TreeState(this);
            break;
        }
        case States::HashState:
        {
            m_currentState = new HashState(this);
            break;
        }
        case States::ListState:
        {
            m_currentState = new ListState(this);
            break;
        }
        default:
            throw "ERROR :: State not found!";
    }
    // begin state
    m_currentState->OnBegin();
}
void StateManager::update()
{
    // check if state exists
    if (m_currentState != nullptr)
    {
        // update state
        m_currentState->OnUpdate();
    }
}