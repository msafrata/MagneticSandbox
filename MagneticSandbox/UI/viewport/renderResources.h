#pragma once
#include "raylib.h"

// Shared graphics resources for all scene objects.
// Load once after InitWindow, unload before CloseWindow.
struct RenderResources {
    // Magnet
    Model box{};        // 1 x 1 x 1 box, scaled when drawing
    Model labelN{};     // flat square with "N"
    Model labelS{};     // flat square with "S"

    // Later: coil, compass, light gate...

    void load();
    void unload();
};