#pragma once

#include <memory>
#include <cmath>
#include "../UI/viewport/renderResources.h"
#include "raylib.h"
#include "raymath.h"
#include "../UI/viewport/viewport.h"


class magnet : public baseObject{
     public:
          void setWidth(float w); //Sets width in mm
          void setHeight(float h); //Sets height in mm
          void setLength(float l); //Sets length in mm
          void setSize(float w, float h, float l); //Sets size in mm
		  void setMagnetisation(float m); //Sets magnetisation in A/m

          void draw(const RenderResources& res) const override;
          const char* typeName() const override { return "Magnet"; }
     private: 

          float width;//Width in m
          float height;//Height in m
          float length;//Length in m

		  float magnetisation;//Magnetisation in A/m
};

