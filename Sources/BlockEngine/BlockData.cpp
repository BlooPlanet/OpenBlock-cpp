#include "BlockData.h"

void BlockData::addTopVertices(std::vector<float>& vertices, Vector3 blockPos) {
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

void BlockData::addDownVertices(std::vector<float> &vertices, Vector3 blockPos) {
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

void BlockData::addBackVertices(std::vector<float> &vertices, Vector3 blockPos) {
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

void BlockData::addFrontVertices(std::vector<float> &vertices, Vector3 blockPos) {
    vertices.push_back(1 + blockPos.x);
    vertices.push_back(1 + blockPos.y);
    vertices.push_back(1 + blockPos.z);

    vertices.push_back(0 + blockPos.x);
    vertices.push_back(1 + blockPos.y);
    vertices.push_back(1 + blockPos.z);

    vertices.push_back(1 + blockPos.x);
    vertices.push_back(0 + blockPos.y);
    vertices.push_back(1 + blockPos.z);

    vertices.push_back(0 + blockPos.x);
    vertices.push_back(0 + blockPos.y);
    vertices.push_back(1 + blockPos.z);


}

void BlockData::addRightVertices(std::vector<float> &vertices, Vector3 blockPos) {
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

void BlockData::addLeftVertices(std::vector<float> &vertices, Vector3 blockPos) {
    vertices.push_back(1 + blockPos.x);
    vertices.push_back(1 + blockPos.y);
    vertices.push_back(0 + blockPos.z);

    vertices.push_back(1 + blockPos.x);
    vertices.push_back(1 + blockPos.y);
    vertices.push_back(1 + blockPos.z);

    vertices.push_back(1 + blockPos.x);
    vertices.push_back(0 + blockPos.y);
    vertices.push_back(0 + blockPos.z);

    vertices.push_back(1 + blockPos.x);
    vertices.push_back(0 + blockPos.y);
    vertices.push_back(1 + blockPos.z);
}

void BlockData::addTris(std::vector<unsigned short>& triangles, int vertexCount) {
    triangles.push_back(0 + vertexCount);
    triangles.push_back(1 + vertexCount);
    triangles.push_back(2 + vertexCount);

    triangles.push_back(3 + vertexCount);
    triangles.push_back(2 + vertexCount);
    triangles.push_back(1 + vertexCount);
}

void BlockData::addBrightness(std::vector<unsigned char> &colors, float intensity) {
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
