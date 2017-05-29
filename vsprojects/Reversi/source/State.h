#pragma once
//-- Declarations ----------------------------------------------------------------------------------

    enum States
    {
        // states
        PvEState,
        PvPState,
        EvEState,
        MenuState,
        PauseState,
        // default
        EmptyState,
    };

    class State
    {
    public:
        State() {};
        virtual ~State() {};
        virtual void OnEnd() {};
        virtual void OnBegin() {};
        virtual void OnPaint() {};
        virtual void OnKeyState(int key, bool pressed) {};
        virtual void OnMouseMove(int mouseX, int mouseY) {};
        virtual void OnMouseState(int key, bool pressed) {};
    };

//--------------------------------------------------------------------------------------------------