#include "QuadData.h"

void QuadData::addUpVertices(std::vector<float> &vertices, Vector3 blockPos) {
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

void QuadData::addDownVertices(std::vector<float> &vertices, Vector3 blockPos) {
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

void QuadData::addFrontVertices(std::vector<float> &vertices, Vector3 blockPos) {
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

void QuadData::addBackVertices(std::vector<float> &vertices, Vector3 blockPos) {
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

void QuadData::addRightVertices(std::vector<float> &vertices, Vector3 blockPos) {
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

void QuadData::addLeftVertices(std::vector<float> &vertices, Vector3 blockPos) {
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

void QuadData::addIndices(std::vector<unsigned short> &indices, int vertexCount) {
    indices.push_back(0 + vertexCount);
    indices.push_back(1 + vertexCount);
    indices.push_back(2 + vertexCount);

    indices.push_back(3 + vertexCount);
    indices.push_back(2 + vertexCount);
    indices.push_back(1 + vertexCount);
}

void QuadData::addBrightness(std::vector<unsigned char> &colors, float intensity) {
    colors.push_back(255 * intensity);
    colors.push_back(255 * intensity);
    colors.push_back(255 * intensity);
    colors.push_back(255);

    colors.push_back(255 * intensity);
    colors.push_back(255 * intensity);
    colors.push_back(255 * intensity);
    colors.push_back(255);

    colors.push_back(255 * intensity);
    colors.push_back(255 * intensity);
    colors.push_back(255 * intensity);
    colors.push_back(255);

    colors.push_back(255 * intensity);
    colors.push_back(255 * intensity);
    colors.push_back(255 * intensity);
    colors.push_back(255);
}

void QuadData::addDefaultUV(std::vector<float> &uvs) {
    uvs.push_back(1);
    uvs.push_back(1);

    uvs.push_back(0);
    uvs.push_back(1);

    uvs.push_back(1);
    uvs.push_back(0);

    uvs.push_back(0);
    uvs.push_back(0);
}

void QuadData::addUV(int x, int y,std::vector<float>& uvs) {
    int pixelCoordMinX = x * 16;
    int pixelCoordMaxX = (x + 1) * 16;
    int pixelCoordMinY = y * 16;
    int pixelCoordMaxY = (y + 1) * 16;

    float uvMinX = pixelCoordMinX / 256.0f;
    float uvMaxX = pixelCoordMaxX / 256.0f;
    float uvMinY = pixelCoordMinY / 256.0f;
    float uvMaxY = pixelCoordMaxY / 256.0f;

    uvs.push_back(uvMaxX);
    uvs.push_back(uvMaxY);

    uvs.push_back(uvMinX);
    uvs.push_back(uvMaxY);

    uvs.push_back(uvMaxX);
    uvs.push_back(uvMinY);

    uvs.push_back(uvMinX);
    uvs.push_back(uvMinY);
}

void QuadData::addVertices(std::vector<float> &vertices, int faceId, Vector3 blockPos) {
    switch (faceId) {
        case 0:
            addUpVertices(vertices,blockPos);
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
