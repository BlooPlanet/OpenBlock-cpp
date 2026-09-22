#include "Chunk.h"

#include <vector>

#include "QuadRendererData.h"
#include "raymath.h"

Chunk::Chunk(int px, int pz, BlockState initialBLock) {
    posX = px;
    posY = 0;
    posZ = pz;
    for (auto & i : blockList) {
        i = initialBLock;
    }
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

    for (int x = 0 ; x < width; x++) {
        for (int z = 0;z <depth;z++) {
            for (int y = 0; y < height;y++) {
                Vector3 blockPos(x,y,z);
                BlockState block = getBLock(x,y,z);

                if (block == BlockState::Solid) {
                    BlockState up_block = getBLock(x,y + 1,z);
                    BlockState down_block = getBLock(x,y - 1,z);
                    BlockState left_block = getBLock(x + 1,y,z);
                    BlockState right_block = getBLock(x - 1,y,z);
                    BlockState front_block = getBLock(x,y,z + 1);
                    BlockState back_block = getBLock(x,y,z - 1);

                    if (up_block == BlockState::None) {
                        QuadRendererData::addTopVertices(vertices,blockPos);
                        QuadRendererData::addTris(triangles,vertex_count);
                        QuadRendererData::addBrightness(colors,1);
                        vertex_count += 4;
                        triangle_count += 2;
                    }

                    if (down_block == BlockState::None) {
                        QuadRendererData::addDownVertices(vertices,blockPos);
                        QuadRendererData::addTris(triangles,vertex_count);
                        QuadRendererData::addBrightness(colors,0.5f);
                        vertex_count += 4;
                        triangle_count += 2;
                    }

                    if (right_block == BlockState::None) {
                        QuadRendererData::addRightVertices(vertices,blockPos);
                        QuadRendererData::addTris(triangles,vertex_count);
                        QuadRendererData::addBrightness(colors,0.9f);
                        vertex_count += 4;
                        triangle_count += 2;
                    }

                    if (left_block == BlockState::None) {
                        QuadRendererData::addLeftVertices(vertices,blockPos);
                        QuadRendererData::addTris(triangles,vertex_count);
                        QuadRendererData::addBrightness(colors,0.9f);
                        vertex_count += 4;
                        triangle_count += 2;
                    }

                    if (front_block == BlockState::None) {
                        QuadRendererData::addFrontVertices(vertices,blockPos);
                        QuadRendererData::addTris(triangles,vertex_count);
                        QuadRendererData::addBrightness(colors,0.8f);
                        vertex_count += 4;
                        triangle_count += 2;
                    }

                    if (back_block == BlockState::None) {
                        QuadRendererData::addBackVertices(vertices,blockPos);
                        QuadRendererData::addTris(triangles,vertex_count);
                        QuadRendererData::addBrightness(colors,0.8f);
                        vertex_count += 4;
                        triangle_count += 2;
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

    UploadMesh(&mesh,false);
}

void Chunk::render(Material mat) {
    Matrix transform = MatrixTranslate(posX,posY,posZ);
    DrawMesh(mesh,mat,transform);
}

bool Chunk::coordInChunk(int x, int y, int z) {
    return x >= 0 && x < width && y >= 0 && y < height && z >= 0 && z < depth;
}
