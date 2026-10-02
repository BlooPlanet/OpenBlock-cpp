#pragma once
#include "raylib.h"
#include "raymath.h"
#include "../BlockState.h"


class Chunk {
    BlockState blocks[16 * 64 * 16];
    Mesh mesh = {0};
    Vector3 directions[6] {
        Vector3(0,1,0),
        Vector3(0,-1,0),
        Vector3(0,0,1),
        Vector3(0,0,-1),
        Vector3(-1,0,0),
        Vector3(1,0,0),
    };
    int posX = 0, posZ = 0;
    Material mat = LoadMaterialDefault();
    Matrix matrix = MatrixIdentity();
public:
    Chunk(int posX, int posZ);
    void constructMesh();
    BlockState getBlock(Vector3 coordinate);
    void setBlock(int x, int y , int z, BlockState block);
    void render();
};
