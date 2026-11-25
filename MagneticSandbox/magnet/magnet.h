#pragma once

#include <memory>
#include <cmath>
#include "raylib.h"
#include "raymath.h"
#include "../UI/viewport/renderResources.h"
#include "../UI/viewport/viewport.h"

// Permanent magnet (block): only its data and how it is drawn.
// The magnetic field is computed in field.h. field.h knows magnet, magnet does not know field.
// Units: position in m (from baseObject), sizes are set in mm and stored in m.

class magnet : public baseObject{
     public:
          void setWidth(float w); //Sets width in mm
          void setHeight(float h); //Sets height in mm
          void setLength(float l); //Sets length in mm (along the S->N axis)
          void setSize(float w, float h, float l); //Sets size in mm
          void setMagnetisation(float m); //Sets magnetisation in A/m
          void setRemanence(float Br); //Sets magnetisation from remanence Br in T (N42 ~ 1.3 T)

          float getMagnetisation() const;
          Vector3 getSize() const; // { width, height, length } in m

          void draw(const RenderResources& res) const override;
          const char* typeName() const override { return "Magnet"; }
     private: 

          float width = 0.01f;//Width in m
          float height = 0.01f;//Height in m
          float length = 0.01f;//Length in m

          float magnetisation = 1.3f / (4.0f * PI * 1e-7f);//Magnetisation in A/m (default: N42, Br = 1.3 T)
};
