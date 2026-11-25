#pragma once

#include "raylib.h"

#include "../viewport/camera.h"
#include <memory>
#include <vector>
#include "renderResources.h"

extern ViewportCamera camera;	

bool initViewport();

void drawFrame();

// Desk coordinates (x, y) -> 3D world (x, 0, -y).
// The minus keeps the desk right-handed: rotation phi on the desk matches
// the rotation raylib applies around the up axis.
inline Vector3 deskToWorld(Vector2 p) { return { p.x, 0.0f, -p.y }; }

class baseObject {
public:
	virtual ~baseObject() = default;

	virtual void draw(const RenderResources& res) const = 0;;          // each type draws itself
	virtual const char* typeName() const = 0;

	Vector2 position{ 0.0f, 0.0f };         // x, y on the desk
	float rotation = 0.0f;                     // rotation φ
	bool grounded = true;
};


extern std::vector<std::unique_ptr<baseObject>> sceneObjects;
extern RenderResources res;