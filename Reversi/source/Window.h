#pragma once

class Window
{
public:
private:
};

class WindowClass
{
public:
private:
};

class WindowEvents
{
public:
    friend class Window;
    // Callbacks :: called on paint
    virtual void OnPaint(Window * window);
    // Callbacks :: called on create
    virtual void OnCreate(Window * window);
    // Callbacks :: called on destroy
    virtual void OnDestroy(Window * window);
    // Callbacks :: called on key change
    virtual void OnKeyState(Window * window, int key, int state);
    // Callbacks :: called on mouse move
    virtual void OnMouseMove(Window * window, int posX, int posY);
    // Callbacks :: called on mouse change
    virtual void OnMouseState(Window * window, int key, int state);
private:
    // variables
    Window * window;
    // constructor
    WindowEvents(Window * window);
};
