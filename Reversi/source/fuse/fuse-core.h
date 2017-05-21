#pragma once

#include "fuse.h"

// Fuse :: debugging tools
#if !defined(_DEBUG)
 #define FUSE_ASSERT(test, msg)
#else
 #define FUSE_ASSERT(test, msg) { if (!test) throw msg; }
#endif