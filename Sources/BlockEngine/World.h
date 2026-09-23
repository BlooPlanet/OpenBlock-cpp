#pragma once
#include <iostream>
#include <map>

#include "Chunk.h"


class World {
    std::map<std::pair<int,int>,Chunk> chunkMap;

public:
    std::vector<Chunk*> chunkToRender;
    World(int width, int depth);
    void constructAll();
    void render(Material mat);
    Chunk getChunkFromIndex(int i) {
        return *chunkToRender[i];
    }

    void printChunksData() ;
};
