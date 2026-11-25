#include "viewport.h"

ViewportCamera camera;
RenderResources res;
std::vector<std::unique_ptr<baseObject>> sceneObjects;

bool initViewport() {
	InitWindow(1280, 720, "Magnetic Sandbox Simulator");
	SetTargetFPS(60);
	res.load();
	return true;
}

void drawFrame() {
	BeginDrawing();
	ClearBackground(RAYWHITE);
	BeginMode3D(camera.get());
	camera.update();
	for (const auto& obj : sceneObjects) {
		obj->draw(res);
	}
	DrawGrid(10, 1.0f);
	EndMode3D();
	DrawText("Magnetic Sandbox", 10, 10, 20, DARKGRAY);
	EndDrawing();
}

