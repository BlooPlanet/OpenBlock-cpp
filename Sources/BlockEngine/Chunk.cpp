#include "Chunk.h"

#include <vector>

#include "QuadData.h"
#include "raylib.h"
#include "raymath.h"

Chunk::Chunk(int posX, int posZ) {
    this->posX = posX;
    this->posZ = posZ;

    for (int i = 0; i < 16*64*16; ++i) {
        blocks[i] = BlockState::Air;
    }

    matrix = MatrixTranslate(this->posX,0,this->posZ);
    mat = LoadMaterialDefault();
}

void Chunk::constructMesh() {
    UnloadMesh(mesh);

    int vertexCount = 0;
    int triangleCount = 0;

    std::vector<float> vertices;
    std::vector<unsigned short> indices;
    std::vector<unsigned char> colors;

    for (int x = 0; x < 16; ++x) {
        for (int z = 0; z < 16; ++z) {
            for (int y = 0; y < 64; ++y) {
                Vector3 blockPos(x,y,z);
                if (getBlock(blockPos) == BlockState::Stone) {
                    for (int i = 0 ; i < 6; i++) {
                        Vector3 direction = directions[i];
                        Vector3 blockDir = Vector3Add(blockPos,direction);
                        if (getBlock(blockDir) == BlockState::Air) {
                            QuadData::addVertices(vertices,i,blockPos);
                            QuadData::addIndices(indices,vertexCount);
                            vertexCount += 4;
                            triangleCount += 2;
                        }
                    }
                }
            }
        }
    }

    mesh = {0};
    mesh.vertexCount = vertexCount;
    mesh.triangleCount = triangleCount;

    mesh.vertices = vertices.data();
    mesh.indices = indices.data();
    UploadMesh(&mesh,false);
}

BlockState Chunk::getBlock(Vector3 coordinate) {
    int x = (int)coordinate.x;
    int y = (int)coordinate.y;
    int z = (int)coordinate.z;
    int index = x + y * 16 + z * 16 * 64;
    return blocks[index];
}

void Chunk::render() {
    DrawMesh(mesh,mat,matrix);
}

void Chunk::setBlock(int x, int y, int z,BlockState block) {
    int index = x + y * 16 + z * 16 * 64;
    blocks[index] = block;
}
