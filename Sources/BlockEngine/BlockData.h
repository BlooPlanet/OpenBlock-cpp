#pragma once
#include <vector>

#include "raylib.h"


class BlockData {
public:
    static void setBackVertices(float array[],Vector3 blockPos);
    static void setFrontVertices(float array[],Vector3 blockPos);

    static void setRightVertices(float array[],Vector3 blockPos);
    static void setLeftVertices(float array[],Vector3 blockPos);

    static void setTopVertices(float array[],Vector3 blockPos);
    static void setDownVertices(float array[],Vector3 blockPos);

    static void addTriangles(std::vector<unsigned short>& tris, int vertex_size);
    static void addBrightness(std::vector<unsigned char>& cols, float l);
};
