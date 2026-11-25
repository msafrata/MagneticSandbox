#include "magnet.h"


void magnet::setWidth(float w){
     this->width = w/1000;
}

void magnet::setHeight(float h){
     this->height = h/1000;
}

void magnet::setLength(float l){
    this->length = l/1000;
}

void magnet::setSize(float w, float h, float l) {
     this->width = w/1000;
     this->height = h/1000;
     this->length = l/1000;
}

void magnet::setMagnetisation(float m) {
	this->magnetisation = m;
}

void magnet::draw(const RenderResources& res) const {
    // desk (x, y) -> 3D (x, 0, z); the magnet's center lies in the desk plane
    Vector3 center = { position.x, 0.0f, position.y };
    float deg = rotation * RAD2DEG;                       // raylib wants degrees

    // direction of the magnet's axis (from S to N) in 3D
    Vector3 axis = { cosf(rotation), 0.0f, -sinf(rotation) };
    Vector3 offset = Vector3Scale(axis, length / 4.0f);

    Vector3 northPos = Vector3Add(center, offset);
    Vector3 southPos = Vector3Subtract(center, offset);
    Vector3 halfSize = { length / 2.0f, height, width };
    Vector3 up = { 0.0f, 1.0f, 0.0f };

    // pole halves
    DrawModelEx(res.box, northPos, up, deg, halfSize, RED);
    DrawModelEx(res.box, southPos, up, deg, halfSize, BLUE);

    // labels: just above the top face, so they don't flicker into the box
    float labelSize = fminf(length / 2.0f, width) * 0.8f;
    Vector3 lift = { 0.0f, height / 2.0f + 0.001f, 0.0f };
    Vector3 labelScale = { labelSize, 1.0f, labelSize };

    DrawModelEx(res.labelN, Vector3Add(northPos, lift), up, deg, labelScale, WHITE);
    DrawModelEx(res.labelS, Vector3Add(southPos, lift), up, deg, labelScale, WHITE);
}

