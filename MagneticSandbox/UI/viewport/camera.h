#pragma once
#include "raylib.h"

class ViewportCamera {
public:
    ViewportCamera();

    void update();                              // call once per frame, before drawing
    const Camera3D& get() const { return camera; }

private:
    Camera3D camera{};

    Vector3 target{ 0.0f, 0.0f, 0.0f };         // point the camera orbits around
    float yaw = 0.8f;                           // angle around the vertical axis [rad]
    float pitch = 0.5f;                         // angle above the desk [rad]
    float distance = 10.0f;                     // distance from target

    void updatePosition();
};