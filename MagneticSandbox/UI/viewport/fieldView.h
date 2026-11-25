#pragma once

#include "raylib.h"

// DRAWING of the field: heatmap of |B| lying in the desk plane.
// Knows the physics (field.h), the physics does not know about this.
class FieldView {
public:
    void load(int resolution = 200);   // call after InitWindow
    void unload();
    void update();                     // recompute the heatmap from sceneObjects
    void draw() const;                 // call inside BeginMode3D

    Vector2 center{ 0.0f, 0.0f };      // center of the shown area on the desk [m]
    float areaSize = 10.0f;             // side of the shown square [m]
    float Bmin = 1e-4f;                // 0.1 mT and less -> blue
    float Bmax = 1.0f;                 // 1 T and more    -> red

private:
    int resolution = 0;                
    Image image{};
    Texture2D texture{};
    Model plane{};
};
