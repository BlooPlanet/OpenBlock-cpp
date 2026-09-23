#pragma once
#include <vector>

#include "raylib.h"


class QuadRendererData {
public:
    static void addTopVertices(std::vector<float>& vertices, Vector3 blockPos);
    static void addDownVertices(std::vector<float>& vertices, Vector3 blockPos);
    static void addFrontVertices(std::vector<float>& vertices, Vector3 blockPos);
    static void addBackVertices(std::vector<float>& vertices, Vector3 blockPos);
    static void addRightVertices(std::vector<float>& vertices, Vector3 blockPos);
    static void addLeftVertices(std::vector<float>& vertices, Vector3 blockPos);
    static void addVertices(std::vector<float>& vertices, int faceId, Vector3 blockPos);

    static void addTris(std::vector<unsigned short>& triangles , int vertexCount);
    static void addBrightness(std::vector<unsigned char>& colors, float intensity);
    static void addFaceBrightness(std::vector<unsigned char>& colors, int faceId);
    static void addDefaultTexCoord(std::vector<float>& textureCoord);
};
