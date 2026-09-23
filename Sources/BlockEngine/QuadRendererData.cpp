#include "QuadRendererData.h"

void QuadRendererData::addTopVertices(std::vector<float>& vertices, Vector3 blockPos) {
    vertices.push_back(1 + blockPos.x);
    vertices.push_back(1 + blockPos.y);
    vertices.push_back(0 + blockPos.z);

    vertices.push_back(0 + blockPos.x);
    vertices.push_back(1 + blockPos.y);
    vertices.push_back(0 + blockPos.z);

    vertices.push_back(1 + blockPos.x);
    vertices.push_back(1 + blockPos.y);
    vertices.push_back(1 + blockPos.z);

    vertices.push_back(0 + blockPos.x);
    vertices.push_back(1 + blockPos.y);
    vertices.push_back(1 + blockPos.z);
}

void QuadRendererData::addDownVertices(std::vector<float> &vertices, Vector3 blockPos) {
    vertices.push_back(1 + blockPos.x);
    vertices.push_back(0 + blockPos.y);
    vertices.push_back(1 + blockPos.z);

    vertices.push_back(0 + blockPos.x);
    vertices.push_back(0 + blockPos.y);
    vertices.push_back(1 + blockPos.z);

    vertices.push_back(1 + blockPos.x);
    vertices.push_back(0 + blockPos.y);
    vertices.push_back(0 + blockPos.z);

    vertices.push_back(0 + blockPos.x);
    vertices.push_back(0 + blockPos.y);
    vertices.push_back(0 + blockPos.z);

}

void QuadRendererData::addBackVertices(std::vector<float> &vertices, Vector3 blockPos) {
    vertices.push_back(1 + blockPos.x);
    vertices.push_back(0 + blockPos.y);
    vertices.push_back(0 + blockPos.z);

    vertices.push_back(0 + blockPos.x);
    vertices.push_back(0 + blockPos.y);
    vertices.push_back(0 + blockPos.z);

    vertices.push_back(1 + blockPos.x);
    vertices.push_back(1 + blockPos.y);
    vertices.push_back(0 + blockPos.z);

    vertices.push_back(0 + blockPos.x);
    vertices.push_back(1 + blockPos.y);
    vertices.push_back(0 + blockPos.z);
}

void QuadRendererData::addFrontVertices(std::vector<float> &vertices, Vector3 blockPos) {
    vertices.push_back(0 + blockPos.x);
    vertices.push_back(0 + blockPos.y);
    vertices.push_back(1 + blockPos.z);

    vertices.push_back(1 + blockPos.x);
    vertices.push_back(0 + blockPos.y);
    vertices.push_back(1 + blockPos.z);

    vertices.push_back(0 + blockPos.x);
    vertices.push_back(1 + blockPos.y);
    vertices.push_back(1 + blockPos.z);

    vertices.push_back(1 + blockPos.x);
    vertices.push_back(1 + blockPos.y);
    vertices.push_back(1 + blockPos.z);
}

void QuadRendererData::addRightVertices(std::vector<float> &vertices, Vector3 blockPos) {
    vertices.push_back(0 + blockPos.x);
    vertices.push_back(0 + blockPos.y);
    vertices.push_back(0 + blockPos.z);

    vertices.push_back(0 + blockPos.x);
    vertices.push_back(0 + blockPos.y);
    vertices.push_back(1 + blockPos.z);

    vertices.push_back(0 + blockPos.x);
    vertices.push_back(1 + blockPos.y);
    vertices.push_back(0 + blockPos.z);

    vertices.push_back(0 + blockPos.x);
    vertices.push_back(1 + blockPos.y);
    vertices.push_back(1 + blockPos.z);
}

void QuadRendererData::addLeftVertices(std::vector<float> &vertices, Vector3 blockPos) {
    vertices.push_back(1 + blockPos.x);
    vertices.push_back(0 + blockPos.y);
    vertices.push_back(1 + blockPos.z);

    vertices.push_back(1 + blockPos.x);
    vertices.push_back(0 + blockPos.y);
    vertices.push_back(0 + blockPos.z);

    vertices.push_back(1 + blockPos.x);
    vertices.push_back(1 + blockPos.y);
    vertices.push_back(1 + blockPos.z);

    vertices.push_back(1 + blockPos.x);
    vertices.push_back(1 + blockPos.y);
    vertices.push_back(0 + blockPos.z);
}

void QuadRendererData::addTris(std::vector<unsigned short>& triangles, int vertexCount) {
    triangles.push_back(0 + vertexCount);
    triangles.push_back(1 + vertexCount);
    triangles.push_back(2 + vertexCount);

    triangles.push_back(3 + vertexCount);
    triangles.push_back(2 + vertexCount);
    triangles.push_back(1 + vertexCount);
}

void QuadRendererData::addBrightness(std::vector<unsigned char> &colors, float intensity) {
    colors.push_back((unsigned char)(intensity * 255));
    colors.push_back((unsigned char)(intensity * 255));
    colors.push_back((unsigned char)(intensity * 255));
    colors.push_back((unsigned char)(1 * 255));

    colors.push_back((unsigned char)(intensity * 255));
    colors.push_back((unsigned char)(intensity * 255));
    colors.push_back((unsigned char)(intensity * 255));
    colors.push_back((unsigned char)(1 * 255));

    colors.push_back((unsigned char)(intensity * 255));
    colors.push_back((unsigned char)(intensity * 255));
    colors.push_back((unsigned char)(intensity * 255));
    colors.push_back((unsigned char)(1 * 255));

    colors.push_back((unsigned char)(intensity * 255));
    colors.push_back((unsigned char)(intensity * 255));
    colors.push_back((unsigned char)(intensity * 255));
    colors.push_back((unsigned char)(1 * 255));
}

void QuadRendererData::addDefaultTexCoord(std::vector<float>& textureCoord) {
    textureCoord.push_back(1);
    textureCoord.push_back(1);

    textureCoord.push_back(0);
    textureCoord.push_back(1);

    textureCoord.push_back(1);
    textureCoord.push_back(0);

    textureCoord.push_back(0);
    textureCoord.push_back(0);
}

void QuadRendererData::addVertices(std::vector<float> &vertices, int faceId, Vector3 blockPos) {
    switch (faceId) {
        case 0:
            addTopVertices(vertices,blockPos);
            break;
        case 1:
            addDownVertices(vertices,blockPos);
            break;
        case 2:
            addFrontVertices(vertices,blockPos);
            break;
        case 3:
            addBackVertices(vertices, blockPos);
            break;
        case 4:
            addRightVertices(vertices,blockPos);
            break;
        case 5:
            addLeftVertices(vertices,blockPos);
            break;
    }
}


void QuadRendererData::addFaceBrightness(std::vector<unsigned char> &colors, int faceId) {
    switch (faceId) {
        case 0:
            addBrightness(colors,1);
            break;
        case 1:
            addBrightness(colors,0.5f);
            break;
        case 2:
            addBrightness(colors,0.9);
            break;
        case 3:
            addBrightness(colors,0.9);
            break;
        case 4:
            addBrightness(colors,0.8);
            break;
        case 5:
            addBrightness(colors,0.8);
            break;
    }
}
