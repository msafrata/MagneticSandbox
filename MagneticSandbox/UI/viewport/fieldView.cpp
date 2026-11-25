#include "fieldView.h"
#include <cmath>
#include "raymath.h"
#include "viewport.h"
#include "../../magnet/field.h"

void FieldView::load(int res) {
    resolution = res;
    image = GenImageColor(resolution, resolution, BLANK);
    texture = LoadTextureFromImage(image);
    SetTextureFilter(texture, TEXTURE_FILTER_BILINEAR);

    plane = LoadModelFromMesh(GenMeshPlane(1.0f, 1.0f, 1, 1));
    plane.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
}

void FieldView::unload() {
    UnloadTexture(texture);
    UnloadImage(image);
    UnloadModel(plane);
}

void FieldView::update() {
    Color* pixels = (Color*)image.data;
    float logMin = log10f(Bmin);
    float logMax = log10f(Bmax);

    for (int row = 0; row < resolution; row++) {
        for (int col = 0; col < resolution; col++) {

            Vector2 p = {
                center.x - areaSize / 2.0f + (col + 0.5f) / resolution * areaSize,
                center.y + areaSize / 2.0f - (row + 0.5f) / resolution * areaSize
            };

            
            Vector2 B = totalMagneticInduction(sceneObjects, p);
            float Bmag = Vector2Length(B);
            if (Bmag < 1e-12f) Bmag = 1e-12f;

           
            float t = (log10f(Bmag) - logMin) / (logMax - logMin);
            t = Clamp(t, 0.0f, 1.0f);

            pixels[row * resolution + col] = ColorLerp(GREEN, RED, t);
        }
    }
    UpdateTexture(texture, image.data);
}

void FieldView::draw() const {
    Vector3 pos = deskToWorld(center);
    pos.y = -0.0002f;
    DrawModelEx(plane, pos, { 0.0f, 1.0f, 0.0f }, 0.0f, { areaSize, 1.0f, areaSize }, WHITE);
}
