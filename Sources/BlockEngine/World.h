#pragma once
#include <iostream>
#include <map>

#include "Chunk.h"


class World {


public:
    std::vector<Chunk*> chunkToRender;
    std::map<std::pair<int,int>,Chunk*> chunkMap;
    World(int width, int depth);
    void constructAll();
    void render(Material mat);
    void printChunksData();

    Vector3 getChunkCoord(int x,int z);
    Chunk* getChunk(int x, int z);
    BlockState getBlock(int x, int y , int z);
    void setBlock(int x, int y, int z, BlockState block_state);
    void loadChunks(int originX, int originZ, int renderDist);
};
