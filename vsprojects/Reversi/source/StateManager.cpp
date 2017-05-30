//-- Dependencies ----------------------------------------------------------------------------------

    #include "Reversi.h"

//-- Definitions -----------------------------------------------------------------------------------

    StateManager::StateManager()
    {
        this->currentState = nullptr;
    }
    StateManager::~StateManager()
    {
        if (this->currentState != nullptr)
        {
            delete this->currentState;
        }
    }
    void StateManager::OnPaint()
    {
        this->currentState->OnPaint();
    }
    void StateManager::SetState(States state)
    {
        throw "ERROR";

        if (this->currentState != nullptr)
        {
            this->currentState->OnEnd();
            delete this->currentState;
            this->currentState = nullptr;
        }

        //switch (state)
        //{
        //    
        //}

        this->currentState->OnBegin();
    }
    void StateManager::OnKeyState(int key, bool pressed)
    {
        this->currentState->OnKeyState(key, pressed);
    }
    void StateManager::OnMouseMove(int mouseX, int mouseY)
    {
        this->currentState->OnMouseMove(mouseX, mouseY);
    }
    void StateManager::OnMouseState(int key, bool pressed)
    {
        this->currentState->OnMouseState(key, pressed);
    }

//--------------------------------------------------------------------------------------------------