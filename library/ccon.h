#pragma once
// *************************************************************************************************
// ** @name: CCON
// ** @date: 14 February 2017
// ** @author: Francisco Romano
// ** @version: 4.2.0
// *************************************************************************************************
// ** Type Definitions *****************************************************************************

    namespace ccon
    {
        typedef void(*callback) (int, int); // callback definition
    }

// *************************************************************************************************
// ** Method Declarations **************************************************************************
    
    namespace ccon
    {
        // core
        void cconInit();                                           // core :: initiate library
        void cconClose();                                          // core :: close console
        bool cconRunning();                                        // core :: check if running
        void cconTerminate();                                      // core :: terminate library
        // graphics
        void cconSize(int width, int height);                      // graphics :: set window size
        void cconClear();                                          // graphics :: clear buffer
        void cconClear(unsigned char n);                           // graphics :: clear buffer
        void cconClear(unsigned char ascii, unsigned char attrib); // graphics :: clear buffer
        void cconAscii(unsigned char n, int index);                // graphics :: set ascii
        void cconAttrib(unsigned char n, int index);               // graphics :: set attribute
        void cconViewport(int x, int y, int width, int height);    // graphics :: set window viewport
        void cconDrawBuffer();                                     // graphics :: draw buffer
    }

// *************************************************************************************************