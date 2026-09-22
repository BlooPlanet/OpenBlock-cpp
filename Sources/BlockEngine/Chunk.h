#pragma once
#include <vector>

#include "BlockState.h"
#include "raylib.h"


class Chunk {
    int width = 16, height = 64, depth = 16;
    BlockState blockList[16 * 64 * 16];
    int posX,posY,posZ;
    Mesh mesh = {0};
public:
    Chunk(int px,int pz, BlockState initialBLock);
    BlockState getBLock(int x, int y, int z);
    void setBlock(int x, int y, int z,BlockState block);
    void constructMesh();
    void render(Material mat);
    bool coordInChunk(int x, int y ,int z);
};
