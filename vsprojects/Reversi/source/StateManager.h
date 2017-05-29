#pragma once
//-- Declarations ----------------------------------------------------------------------------------

    class StateManager
    {
    public:
        StateManager();
        ~StateManager();
        void OnPaint();
        void SetState(States state);
        void OnKeyState(int key, bool pressed);
        void OnMouseMove(int mouseX, int mouseY);
        void OnMouseState(int key, bool pressed);
    private:
        State * currentState;
    };

//--------------------------------------------------------------------------------------------------