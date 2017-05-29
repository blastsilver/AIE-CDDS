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
        if (this->currentState != nullptr)
        {
            this->currentState->OnEnd();
            delete this->currentState;
            this->currentState = nullptr;
        }

        switch (state)
        {
            case States::Menu:
                this->currentState = new MenuState();
                break;
            case States::Finish:
                this->currentState = new MenuState();
                break;
            case States::Player1:
                this->currentState = new MenuState();
                break;
            case States::Player2:
                this->currentState = new MenuState();
                break;
        }

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