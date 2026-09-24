#pragma once
#include <vector>

#include "BlockState.h"
#include "raylib.h"

class World;

class Chunk {
    int width = 16, height = 128, depth = 16;
    BlockState blockList[16 * 128 * 16];
    int posX,posY,posZ;
    Mesh mesh = {0};
    World &world;

    Vector3 directions[6] {
        Vector3(0,1,0), // up
        Vector3(0,-1,0), // down
        Vector3(0,0,1), // front
        Vector3(0,0,-1), // back
        Vector3(-1,0,0), // right
        Vector3(1,0,0), // left
    };

public:
    std::string name;
    Chunk(int px, int pz, BlockState initialBlock, World& world);
    BlockState getBLock(int x, int y, int z);
    void setBlock(int x, int y, int z,BlockState block);
    void constructMesh();
    void render(Material mat);
    bool coordInChunk(int x, int y ,int z);
    int getX();
    int getZ();
    void generateBlocks();
};
