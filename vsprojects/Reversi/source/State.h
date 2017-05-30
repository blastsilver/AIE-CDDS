#pragma once
//-- Declarations ----------------------------------------------------------------------------------

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

    enum class States
    {
        NONE, PVP, MENU, P1WON, P2WON, PAUSE,
    };

//--------------------------------------------------------------------------------------------------