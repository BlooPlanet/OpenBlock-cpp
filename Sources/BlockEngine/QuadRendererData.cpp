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
