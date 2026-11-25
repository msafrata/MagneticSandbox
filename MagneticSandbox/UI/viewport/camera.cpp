#include "../viewport/camera.h"
#include "raymath.h"
#include <cmath>

ViewportCamera::ViewportCamera() {
    camera.up = { 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    updatePosition();
}

void ViewportCamera::update() {
    Vector2 d = GetMouseDelta();

    // Orbit: hold the mouse wheel
    if (IsMouseButtonDown(MOUSE_BUTTON_MIDDLE)) {
        yaw -= d.x * 0.005f;
        pitch += d.y * 0.005f;
        pitch = Clamp(pitch, -1.5f, 1.5f);
    }

    // Zoom: scroll the wheel
    float wheel = GetMouseWheelMove();
    if (wheel != 0.0f) {
        distance *= (wheel > 0.0f) ? 0.9f : 1.1f;
        distance = Clamp(distance, 0.5f, 100.0f);
    }

    // Pan: right mouse button
    if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
        Vector3 forward = Vector3Normalize(Vector3Subtract(camera.target, camera.position));
        Vector3 right = Vector3Normalize(Vector3CrossProduct(forward, camera.up));
        Vector3 up = Vector3CrossProduct(right, forward);

        float speed = distance * 0.0015f;
        target = Vector3Add(target, Vector3Scale(right, -d.x * speed));
        target = Vector3Add(target, Vector3Scale(up, d.y * speed));
    }

    updatePosition();
}

void ViewportCamera::updatePosition() {
    camera.target = target;
    camera.position = {
        target.x + distance * cosf(pitch) * sinf(yaw),
        target.y + distance * sinf(pitch),
        target.z + distance * cosf(pitch) * cosf(yaw)
    };
}