#pragma once
//-- Definitions -----------------------------------------------------------------------------------

    class WindowClass
    {
    public:
        // :: constructor
        WindowClass(char * name, WindowEvents * events);
        // Run the class
        void execute();
        // Add a new window
        void addWindow(int width, int height, char * name);
    private:
        // :: variables
        char * name;
        WindowEvents * events;
        std::vector<Window> windows;
    };

//--------------------------------------------------------------------------------------------------