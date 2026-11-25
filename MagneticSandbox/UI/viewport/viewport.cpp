#include "viewport.h"
#include "fieldView.h"

ViewportCamera camera;
RenderResources res;
std::vector<std::unique_ptr<baseObject>> sceneObjects;
FieldView fieldView;

bool initViewport() {
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(1280, 720, "Magnetic Sandbox Simulator");
	SetTargetFPS(60);
	res.load();
	fieldView.load();
	return true;
}

void drawFrame() {
	fieldView.update();      // field may change when magnets move

	BeginDrawing();
	ClearBackground(RAYWHITE);
	BeginMode3D(camera.get());
	camera.update();
	fieldView.draw();
	for (const auto& obj : sceneObjects) {
		obj->draw(res);
	}
	DrawGrid(100, 0.1f);
	EndMode3D();
	DrawText("Magnetic Sandbox", 10, 10, 20, DARKGRAY);
	EndDrawing();
}
