#pragma once

namespace draw
{
    // constants
    const int DRAW_LINES = 1;
    const int DRAW_POINTS = 2;
    const int DRAW_TRIANGLES = 3;

    // core functions
    void drawEnd();
    void drawMode(int mode);
    void drawBegin();
    void drawClear(int mode);
    void drawColour(float r, float g, float b);
    void drawColour(float r, float g, float b, float a);
    void drawVertex(float x, float y);
    void drawVertex(float x, float y, float z);
    void drawVertex(float x, float y, float z, float w);
    void drawViewport(int x, int y, int w, int h);
}