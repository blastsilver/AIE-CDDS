#pragma once
//-- Definitions -----------------------------------------------------------------------------------

    class WindowEvents
    {
    public:
        // Called on paint message
        virtual void OnPaint(Window * window);
        // Called on update message
        virtual void OnUpdate();
        // Called on create message
        virtual void OnCreate(Window * window);
        // Called on destroy message
        virtual void OnDestroy(Window * window);
        // Called on key change message
        virtual void OnKeyState(Window * window, int key, int state);
        // Called on mouse move message
        virtual void OnMouseMove(Window * window, int posX, int posY);
        // Called on mouse change message
        virtual void OnMouseState(Window * window, int key, int state);
    };

//--------------------------------------------------------------------------------------------------