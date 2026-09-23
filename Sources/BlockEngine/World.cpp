#include "World.h"

#include <iostream>

#include "Chunk.h"

World::World(int width, int depth) {
    for (int i = 0 ; i < width;i++) {
        for (int j = 0 ; j < depth;j++) {
            int coordX = i * 16;
            int coordZ = j * 16;
            Chunk* chunk = new Chunk(coordX,coordZ,BlockState::Solid);
            chunkToRender.push_back(chunk);
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
        chunkToRender[i]->constructMesh();
    }
}

void World::render(Material mat) {
    for (int i = 0; i < chunkToRender.size();i++) {
        chunkToRender[i]->render(mat);
    }
}
