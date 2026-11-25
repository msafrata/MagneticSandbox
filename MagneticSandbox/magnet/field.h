#pragma once

#include <memory>
#include <vector>
#include "raylib.h"
#include "magnet.h"

// PHYSICS ONLY - nothing is drawn here.
// Field of a magnet modelled as a dipole, in the desk plane (2D slice through the magnet centers).
// All positions in m, result in T.

// B from one magnet at a point on the desk
Vector2 magneticInductionInPoint(const magnet& mg, Vector2 point);

// B from all magnets in the scene (vector sum)
Vector2 totalMagneticInduction(const std::vector<std::unique_ptr<baseObject>>& objects, Vector2 point);
