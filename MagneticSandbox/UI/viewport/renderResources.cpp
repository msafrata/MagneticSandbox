#include "renderResources.h"

// Paints centered text onto a transparent square and uploads it to the GPU.
static Texture2D makeLabelTexture(const char* text) {
    const int size = 128;
    const int fontSize = 100;

    Image img = GenImageColor(size, size, BLANK);
    int textWidth = MeasureText(text, fontSize);
    ImageDrawText(&img, text, (size - textWidth) / 2, (size - fontSize) / 2,
        fontSize, WHITE);

    Texture2D tex = LoadTextureFromImage(img);
    UnloadImage(img);
    SetTextureFilter(tex, TEXTURE_FILTER_BILINEAR);
    return tex;
}

void RenderResources::load() {
    // Magnet
    box = LoadModelFromMesh(GenMeshCube(1.0f, 1.0f, 1.0f));
    labelN = LoadModelFromMesh(GenMeshPlane(1.0f, 1.0f, 1, 1));
    labelS = LoadModelFromMesh(GenMeshPlane(1.0f, 1.0f, 1, 1));

    labelN.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = makeLabelTexture("N");
    labelS.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = makeLabelTexture("S");
}

void RenderResources::unload() {
    // Textures assigned by hand are not freed by UnloadModel
    UnloadTexture(labelN.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture);
    UnloadTexture(labelS.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture);

    UnloadModel(box);
    UnloadModel(labelN);
    UnloadModel(labelS);
}