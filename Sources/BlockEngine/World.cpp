#include "World.h"

#include <iostream>

#include "Chunk.h"

World::World(int width, int depth) {
    for (int i = 0; i < width;i++) {
        for (int j = 0; j < depth;j++) {
            int coordX = i * 16;
            int coordZ = j * 16;
            Chunk* chunk = new Chunk(coordX,coordZ,BlockState::None,*this);
            chunk->generateBlocks();
            chunkToRender.push_back(chunk);
            chunkMap.insert({{coordX,coordZ},chunk});
        }
    }
}

void World::printChunksData() {
    for (int i = 0; i < chunkToRender.size(); i ++) {
        std::cout << "chunk memory address: " << &chunkToRender[i] << std::endl;
    }
}

void World::constructAll() {
    for (int i = 0 ; i < chunkToRender.size(); i++) {
        chunkToRender[i]->unloadMesh();
        chunkToRender[i]->constructMesh();
        chunkToRender[i]->uploadMesh();
    }
}

void World::render(Material mat) {
    for (int i = 0; i < chunkToRender.size();i++) {
        chunkToRender[i]->render(mat);
    }
}

// fix the negative coordinate
Vector3 World::getChunkCoord(int x, int z) {
    int cx = (int)(std::floor(x / 16.0f) * 16);
    int cz = (int)(std::floor(z / 16.0f) * 16);
    return Vector3(cx, 0, cz);
}

Chunk *World::getChunk(int x, int z) {
    Vector3 chunkCoord = getChunkCoord(x,z);
    int cx = (int)chunkCoord.x;
    int cz = (int)chunkCoord.z;
    if (chunkMap.contains({cx,cz})) {
        Chunk* chunk = chunkMap[{cx,cz}];
        return chunk;
    }
    return nullptr;
}

BlockState World::getBlock(int x, int y, int z) {
    Chunk* chunk = getChunk(x,z);
    if (chunk != nullptr) {
        int lx = x - chunk->getX();
        int lz = z - chunk->getZ();
        return chunk->getBLock(lx,y,lz);
    }
    return BlockState::None;
}

void World::setBlock(int x, int y, int z, BlockState block_state) {
    Chunk* chunk = getChunk(x,z);
    if (chunk != nullptr) {
        int lx = x - chunk->getX();
        int lz = z - chunk->getZ();
        chunk->setBlock(lx,y,lz, block_state);
    }
}

void World::loadChunks(int originX, int originZ, int renderDist) {
    int currentChunk_x = (int)getChunkCoord(originX,originZ).x;
    int currentChunk_z = (int)getChunkCoord(originX,originZ).z;
    for (int x = -renderDist; x <= renderDist; ++x) {
        for (int z = -renderDist; z <= renderDist; ++z) {
            int chunkCoordX = x * 16 + currentChunk_x;
            int chunkCoordZ = z * 16 + currentChunk_z;
            if (!chunkMap.contains({chunkCoordX,chunkCoordZ})) {
                Chunk* chunk = new Chunk(chunkCoordX,chunkCoordZ,BlockState::Solid,*this);
                newLoadedChunks.push_back(chunk);
                chunkToRender.push_back(chunk);
                chunkMap.insert({{chunkCoordX,chunkCoordZ},chunk});
            }
        }
    }
}

void World::loadedChunksConstruct() {
    for (int i = 0; i < newLoadedChunks.size(); ++i) {
        newLoadedChunks[i]->constructMesh();
    }
}

void World::unloadChunks(int cx, int cz) {
    for (int i = 0; i < chunkToRender.size(); ++i) {
        Chunk* chunk = chunkToRender[i];
        int pos_x = chunk->getX();
        int pos_z = chunk->getZ();

    }
}

bool World::chunkIsInBound(int cx, int cz) {
    int min_x = -8 * 16 + cx;
    int max_x = 8 * 16 + cx;

    int min_z = -8 * 16 + cz;
    int max_z = 8 * 16 + cz;

    return cx >= min_x && cx < max_x && cz >= min_z && cz < max_z;

}
