#include "BlockData.h"

void BlockData::setBackVertices(float array[], Vector3 blockPos) {
    array[0] = 0 + blockPos.x;
    array[1] = 0 + blockPos.y;
    array[2] = 0 + blockPos.z;

    array[3] = 1 + blockPos.x;
    array[4] = 0 + blockPos.y;
    array[5] = 0 + blockPos.z;

    array[6] = 0 + blockPos.x;
    array[7] = 1 + blockPos.y;
    array[8] = 0 + blockPos.z;

    array[9] = 1 + blockPos.x;
    array[10] = 1 + blockPos.y;
    array[11] = 0 + blockPos.z;
}

void BlockData::setFrontVertices(float array[], Vector3 blockPos) {
    array[0] = 0 + blockPos.x;
    array[1] = 1 + blockPos.y;
    array[2] = 1 + blockPos.z;

    array[3] = 1 + blockPos.x;
    array[4] = 1 + blockPos.y;
    array[5] = 1 + blockPos.z;

    array[6] = 0 + blockPos.x;
    array[7] = 0 + blockPos.y;
    array[8] = 1 + blockPos.z;

    array[9] = 1 + blockPos.x;
    array[10] = 0 + blockPos.y;
    array[11] = 1 + blockPos.z;

}

void BlockData::setLeftVertices(float array[], Vector3 blockPos) {
    array[0] = 1 + blockPos.x;
    array[1] = 0 + blockPos.y;
    array[2] = 0 + blockPos.z;

    array[3] = 1 + blockPos.x;
    array[4] = 0 + blockPos.y;
    array[5] = 1 + blockPos.z;

    array[6] = 1 + blockPos.x;
    array[7] = 1 + blockPos.y;
    array[8] = 0 + blockPos.z;

    array[9] = 1 + blockPos.x;
    array[10] = 1 + blockPos.y;
    array[11] = 1 + blockPos.z;
}

void BlockData::setRightVertices(float array[], Vector3 blockPos) {
    array[0] = 0 + blockPos.x;
    array[1] = 1 + blockPos.y;
    array[2] = 0 + blockPos.z;

    array[3] = 0 + blockPos.x;
    array[4] = 1 + blockPos.y;
    array[5] = 1 + blockPos.z;

    array[6] = 0 + blockPos.x;
    array[7] = 0 + blockPos.y;
    array[8] = 0 + blockPos.z;

    array[9] = 0 + blockPos.x;
    array[10] = 0 + blockPos.y;
    array[11] = 1 + blockPos.z;


}


void BlockData::setTopVertices(float array[], Vector3 blockPos) {
    array[0] = 0 + blockPos.x;
    array[1] = 1 + blockPos.y;
    array[2] = 0 + blockPos.z;

    array[3] = 1 + blockPos.x;
    array[4] = 1 + blockPos.y;
    array[5] = 0 + blockPos.z;

    array[6] = 0 + blockPos.x;
    array[7] = 1 + blockPos.y;
    array[8] = 1 + blockPos.z;

    array[9] = 1 + blockPos.x;
    array[10] = 1 + blockPos.y;
    array[11] = 1 + blockPos.z;
}

void BlockData::setDownVertices(float array[], Vector3 blockPos) {
    array[0] = 0 + blockPos.x;
    array[1] = 0 + blockPos.y;
    array[2] = 1 + blockPos.z;

    array[3] = 1 + blockPos.x;
    array[4] = 0 + blockPos.y;
    array[5] = 1 + blockPos.z;

    array[6] = 0 + blockPos.x;
    array[7] = 0 + blockPos.y;
    array[8] = 0 + blockPos.z;

    array[9] = 1 + blockPos.x;
    array[10] = 0 + blockPos.y;
    array[11] = 0 + blockPos.z;
}

void BlockData::addTriangles(std::vector<unsigned short>& tris, int vertex_size) {
    tris.push_back(2 + vertex_size);
    tris.push_back(1 + vertex_size);
    tris.push_back(0 + vertex_size);

    tris.push_back(1 + vertex_size);
    tris.push_back(2 + vertex_size);
    tris.push_back(3 + vertex_size);
}

void BlockData::addBrightness(std::vector<unsigned char> &cols, float l) {
    cols.push_back((unsigned char)(l * 255));
    cols.push_back((unsigned char)(l * 255));
    cols.push_back((unsigned char)(l * 255));
    cols.push_back((unsigned char)(255));

    cols.push_back((unsigned char)(l * 255));
    cols.push_back((unsigned char)(l * 255));
    cols.push_back((unsigned char)(l * 255));
    cols.push_back((unsigned char)(255));

    cols.push_back((unsigned char)(l * 255));
    cols.push_back((unsigned char)(l * 255));
    cols.push_back((unsigned char)(l * 255));
    cols.push_back((unsigned char)(255));

    cols.push_back((unsigned char)(l * 255));
    cols.push_back((unsigned char)(l * 255));
    cols.push_back((unsigned char)(l * 255));
    cols.push_back((unsigned char)(255));
}
