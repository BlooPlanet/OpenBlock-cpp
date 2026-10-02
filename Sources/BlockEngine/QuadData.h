#pragma once
#include <vector>

#include "raylib.h"


class QuadData {
public:
    static void addUpVertices(std::vector<float>& vertices,Vector3 blockPos);
    static void addDownVertices(std::vector<float>& vertices,Vector3 blockPos);
    static void addRightVertices(std::vector<float>& vertices,Vector3 blockPos);
    static void addLeftVertices(std::vector<float>& vertices,Vector3 blockPos);
    static void addFrontVertices(std::vector<float>& vertices,Vector3 blockPos);
    static void addBackVertices(std::vector<float>& vertices,Vector3 blockPos);

    static void addIndices(std::vector<unsigned short>& indices, int vertexCount);
    static void addBrightness(std::vector<unsigned char>& colors, float intensity);
    static void addDefaultUV(std::vector<float>& uvs);
    static void addUV(int x, int y,std::vector<float>& uvs);
    static void addVertices(std::vector<float>& vertices, int faceId, Vector3 blockPos);
};
