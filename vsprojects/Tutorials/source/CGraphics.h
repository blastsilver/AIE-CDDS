#pragma once

// *************************************************************************************************
// ** Struct Declarations **************************************************************************

    struct CGraphics
    {
        static const int LINES         = 2;
        static const int POINTS        = 1;
        static const int TRIANGLES     = 3;
        static const int DEPTH_BUFFER  = 2;
        static const int COLOUR_BUFFER = 1;

        ~CGraphics();
        CGraphics(int w, int h);
        static void draw();                                     // draw buffers
        static void mode(int mode);                             // set draw mode
        static void clear(int mode);                            // clear buffers
        static void vertex(float x, float y);                   // set vertex 2f
        static void vertex(float x, float y, float z);          // set vertex 3f
        static void colour(float r, float g, float b);          // set RGB colour
        static void vertex(float x, float y, float z, float w); // set vertex 4f
        static void colour(float r, float g, float b, float a); // set RGBA colour
        static void viewport(int x, int y, int w, int h);       // set screen viewport
    };

// *************************************************************************************************