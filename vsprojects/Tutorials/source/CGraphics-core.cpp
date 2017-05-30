// ** Dependencies *********************************************************************************
    
    #include "CGraphics-core.h"

    namespace CAPI
    {
        int countVertex;
        int countColour;
        CRenderInfo rInfo;
        CWindowInfo wInfo;
    }

// *************************************************************************************************
// ** Definitions **********************************************************************************

    CGraphics::~CGraphics()
    {
        // ccon :: Terminate
        ccon::cconTerminate();
    }
    CGraphics::CGraphics(int w, int h)
    {
        // CAPI :: Check if running
        if (!CAPI::wInfo.running)
        {
            // ccon :: Initiate
            ccon::cconInit();
            ccon::cconSize(w, h);
            ccon::cconViewport(0, 0, w, h);
            // CAPI :: Initiate
            CAPI::rInfo.mode = CGraphics::LINES;
            CAPI::rInfo.depth.resize(w * h);
            CAPI::rInfo.method = &CAPI::AlgorithmLine;
            CAPI::rInfo.vertex.resize(3);
            CAPI::rInfo.colour.resize(3);
            CAPI::wInfo.viewsize = { w, h };
            CAPI::wInfo.viewport = { 0.0f, 0.0f, float(w - 1), float(h - 1) };
        }
        // CAPI :: Set as running
        CAPI::wInfo.running = true;
    }
    void CGraphics::draw()
    {
        // ccon :: Draw buffers
        ccon::cconDrawBuffer();
    }
    void CGraphics::mode(int mode)
    {
        // CAPI :: Set mode
        CAPI::rInfo.mode = mode;
        // Check rendering mode
        switch (mode)
        {
            case CGraphics::LINES:
            {
                CAPI::rInfo.method = &CAPI::AlgorithmLine;
                break;
            }
            case CGraphics::POINTS:
            {
                CAPI::rInfo.method = &CAPI::AlgorithmDot;
                break;
            }
            case CGraphics::TRIANGLES:
            {
                CAPI::rInfo.method = &CAPI::AlgorithmTriangle;
                break;
            }
            default:
            {
                throw "CGraphics :: wrong mode type!";
            }
        }
        // CAPI :: Reset counters
        CAPI::countColour = 0;
        CAPI::countVertex = 0;
    }
    void CGraphics::clear(int mode)
    {
        // Check if colour buffer
        if ((mode | CGraphics::COLOUR_BUFFER) == mode)
        {
            // ccon :: Clear colour buffer
            ccon::cconClear(0, 0);
        }
        // Check if depth buffer
        if ((mode | CGraphics::DEPTH_BUFFER) == mode)
        {
            // CAPI :: clear depth buffer
            CAPI::rInfo.depth.clear();
        }
    }
    void CGraphics::vertex(float x, float y)
    {
        // set vertex 4f
        CGraphics::vertex(x, y, 0, 1);
    }
    void CGraphics::vertex(float x, float y, float z)
    {
        // set vertex 4f
        CGraphics::vertex(x, y, z, 1);
    }
    void CGraphics::colour(float r, float g, float b)
    {
        // set RGBA colour
        CGraphics::colour(r, g, b, 1);
    }
    void CGraphics::vertex(float x, float y, float z, float w)
    {
        // CAPI :: Calculate index
        int index = CAPI::countVertex++;
        // CAPI :: Set 4 float vertex
        CAPI::rInfo.vertex[index].x = x;
        CAPI::rInfo.vertex[index].y = y;
        CAPI::rInfo.vertex[index].z = z;
        CAPI::rInfo.vertex[index].w = w;
        // CAPI :: Check colour
        if (CAPI::countVertex > CAPI::countColour)
        {
            // CAPI :: Set RGBA colour
            CAPI::countColour++;
            CAPI::rInfo.colour[index].x = 1;
            CAPI::rInfo.colour[index].y = 1;
            CAPI::rInfo.colour[index].z = 1;
            CAPI::rInfo.colour[index].w = 1;
        }
        // CAPI :: Check mode
        if (CAPI::countVertex == CAPI::rInfo.mode)
        {
            // CAPI :: Reset counters
            CAPI::rInfo.callMethod();
            CAPI::countVertex = 0;
            CAPI::countColour = 0;
        }
    }
    void CGraphics::colour(float r, float g, float b, float a)
    {
        // CAPI :: Set RGBA colour
        int index = CAPI::countVertex;
        CAPI::countColour = index + 1;
        CAPI::rInfo.colour[index].x = r;
        CAPI::rInfo.colour[index].y = g;
        CAPI::rInfo.colour[index].z = b;
        CAPI::rInfo.colour[index].w = a;
    }
    void CGraphics::viewport(int x, int y, int w, int h)
    {
        // CAPI :: Set viewport
        CAPI::wInfo.viewport.x = float(x);
        CAPI::wInfo.viewport.y = float(y);
        CAPI::wInfo.viewport.z = float(w - 1);
        CAPI::wInfo.viewport.w = float(h - 1);
    }

// *************************************************************************************************