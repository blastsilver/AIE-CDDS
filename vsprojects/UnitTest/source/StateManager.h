#pragma once

namespace util
{
    class StateManager
    {
        // variables
        State * m_currentState;
    public:
        // public defaults
        inline StateManager() { m_currentState = nullptr; };
        inline ~StateManager() {};
        // public functions
        inline void set(States state)
        {
            if (m_currentState != nullptr)
            {
                if (m_currentState->type() == state) return;
                m_currentState->OnEnd();
                delete this->m_currentState;
            }
            switch (state)
            {
                case States::State1:
                {
                    m_currentState = new State1();
                    break;
                }
                case States::State2:
                {
                    m_currentState = new State2();
                    break;
                }
                case States::State3:
                {
                    m_currentState = new State3();
                    break;
                }
                default:
                    throw "You done gooffed!";
            }
            m_currentState->OnBegin();
        }
        inline void update()
        {
            if (m_currentState != nullptr)
            {
                m_currentState->OnUpdate();
            }
        }
    };
}