#pragma once

#include <Windows.h>

namespace graphics
{
    struct Buffer { HDC hdc; HBITMAP hbmp; };

    void createBuffer(Buffer * buffer);
    void deleteBuffer(Buffer * buffer);
}