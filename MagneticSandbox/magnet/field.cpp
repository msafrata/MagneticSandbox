#include "field.h"
#include <cmath>
#include "raymath.h"

static const float MU0 = 4.0f * PI * 1e-7f;   // permeability of vacuum

//  B = mu0 * M * V / (4*pi*r^3) * (3*cos(theta)*rDir - mDir)
Vector2 magneticInductionInPoint(const magnet& mg, Vector2 point) {

	Vector2 r = Vector2Subtract(point, mg.position);
	float distance = Vector2Length(r);

	if (distance < 1e-4f) {
		return { 0.0f, 0.0f };
	}

	Vector2 rDir = Vector2Scale(r, 1.0f / distance);
	Vector2 mDir = { cosf(mg.rotation), sinf(mg.rotation) };

	Vector3 size = mg.getSize();
	float volume = size.x * size.y * size.z;
	float strength = MU0 * mg.getMagnetisation() * volume / (4.0f * PI);

	float cosTheta = Vector2DotProduct(mDir, rDir);

	Vector2 dir = Vector2Subtract(Vector2Scale(rDir, 3.0f * cosTheta), mDir);

	float r3 = distance * distance * distance;
	return Vector2Scale(dir, strength / r3);
}

Vector2 totalMagneticInduction(const std::vector<std::unique_ptr<baseObject>>& objects, Vector2 point) {
	Vector2 B = { 0.0f, 0.0f };
	for (const auto& obj : objects) {
		if (const magnet* mg = dynamic_cast<const magnet*>(obj.get())) {
			B = Vector2Add(B, magneticInductionInPoint(*mg, point));
		}
	}
	return B;
}
