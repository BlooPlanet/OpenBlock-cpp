#include "Chunk.h"


#include <iostream>
#include <vector>

#include "QuadRendererData.h"
#include "raymath.h"
#include "World.h"

Chunk::Chunk(int px, int pz, BlockState initialBLock ,World& world) : world(world) {
    posX = px;
    posY = 0;
    posZ = pz;
    for (auto &i: blockList) {
        i = initialBLock;
    }
    name = "chunk (" + std::to_string(px) + "," + std::to_string(pz) + ")";
}

BlockState Chunk::getBLock(int x, int y, int z) {
    if (coordInChunk(x,y,z)) {
        int index = x + y * width + z * width * height;
        BlockState block = blockList[index];
        return block;
    }
    return BlockState::None;
}

void Chunk::setBlock(int x, int y, int z, BlockState block) {
    int index = x + y * width + z * width * height;
    blockList[index] = block;
}

void Chunk::constructMesh() {
    UnloadMesh(mesh);
    mesh = {0};

    int vertex_count = 0;
    int triangle_count = 0;

    std::vector<float> vertices;
    std::vector<unsigned short> triangles;
    std::vector<unsigned char> colors;
    std::vector<float> uvs;

    for (int x = 0 ; x < width; x++) {
        for (int z = 0;z <depth;z++) {
            for (int y = 0; y < height;y++) {
                Vector3 blockPos(x,y,z);
                BlockState block = getBLock(x,y,z);

                if (block == BlockState::Solid) {
                    for (int i = 0; i < sizeof(directions) / sizeof(Vector3);i++) {
                        Vector3 direction = directions[i];
                        Vector3 block_dir = blockPos + direction;
                        if (coordInChunk(block_dir.x, block_dir.y, block_dir.z)) {
                            if (getBLock(block_dir.x,block_dir.y,block_dir.z) == BlockState::None) {
                                QuadRendererData::addVertices(vertices,i,blockPos);
                                QuadRendererData::addTris(triangles,vertex_count);
                                QuadRendererData::addFaceBrightness(colors,i);
                                QuadRendererData::addDefaultTexCoord(uvs);
                                vertex_count += 4;
                                triangle_count += 2;
                            }
                        }else {
                            int cx = getX();
                            int cz = getZ();
                            Vector3 chunkCoord(cx,0,cz);
                            Vector3 world_blockCoord = Vector3Add(chunkCoord, block_dir);
                            if (world.getBlock(world_blockCoord.x,world_blockCoord.y,world_blockCoord.z) == BlockState::None) {
                                QuadRendererData::addVertices(vertices,i,blockPos);
                                QuadRendererData::addTris(triangles,vertex_count);
                                QuadRendererData::addFaceBrightness(colors,i);
                                QuadRendererData::addDefaultTexCoord(uvs);
                                vertex_count += 4;
                                triangle_count += 2;
                            }
                        }

                    }
                }
            }
        }
    }

    mesh.vertexCount = vertex_count;
    mesh.triangleCount = triangle_count;

    mesh.vertices = (float*)malloc(vertices.size() * sizeof(float));
    memcpy(mesh.vertices,vertices.data(),vertices.size() * sizeof(float));
    mesh.indices = (unsigned short*)malloc(triangles.size() * sizeof(unsigned short));
    memcpy(mesh.indices,triangles.data(),triangles.size() * sizeof(unsigned short));
    mesh.colors = (unsigned char*)malloc(colors.size() * sizeof(unsigned char));
    memcpy(mesh.colors,colors.data(), colors.size() * sizeof(unsigned char));
    mesh.texcoords = (float*)malloc(uvs.size() * sizeof(float));
    memcpy(mesh.texcoords,uvs.data(),uvs.size() * sizeof(float));

    UploadMesh(&mesh,false);
    std::cout << name << " " << "is loaded" << std::endl;
}

void Chunk::render(Material mat) {
    Matrix transform = MatrixTranslate(posX,posY,posZ);
    DrawMesh(mesh,mat,transform);
}

bool Chunk::coordInChunk(int x, int y, int z) {
    return x >= 0 && x < width && y >= 0 && y < height && z >= 0 && z < depth;
}

int Chunk::getX() {
    return posX;
}

int Chunk::getZ() {
    return posZ;
}

void Chunk::generateBlocks() {
    for (int x = 0; x < width ; x ++) {
        for (int z = 0; z < depth; ++z) {
            for (int y = 0; y < height; ++y) {
                setBlock(x,y,z,BlockState::Solid);
            }
        }
    }
}
