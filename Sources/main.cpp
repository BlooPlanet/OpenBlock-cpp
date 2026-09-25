#include <iostream>

#include "raylib.h"
#include "raymath.h"
#include "BlockEngine/Chunk.h"
#include "BlockEngine/QuadRendererData.h"
#include <cmath>
#include <future>

#include "BlockEngine/World.h"

void printVertices(std::vector<float> vertices);
void printTriangles(std::vector<unsigned short> triangles);
void breakBlock(float step,int dist);
World world = {0,0};
Camera3D camera = {1,130,1};

float timer = 0;
int cx = 0;
int cz = 0;

int main() {
    std::vector<float> vertices;
    std::vector<unsigned short> triangles;
    std::vector<unsigned char> colors;
    std::vector<float> textureCoord;

    int vertexCount = 0;
    int trianglesCount = 0;

    // top face
    QuadRendererData::addTopVertices(vertices, Vector3(0,0,0));
    QuadRendererData::addTris(triangles,vertexCount);
    QuadRendererData::addBrightness(colors,1);
    QuadRendererData::addDefaultTexCoord(textureCoord);
    vertexCount += 4;
    trianglesCount += 2;

    // down face
    QuadRendererData::addDownVertices(vertices, Vector3(0,0,0));
    QuadRendererData::addTris(triangles,vertexCount);
    QuadRendererData::addBrightness(colors,0.5f);
    QuadRendererData::addDefaultTexCoord(textureCoord);
    vertexCount += 4;
    trianglesCount += 2;

    // back face
    QuadRendererData::addBackVertices(vertices, Vector3(0,0,0));
    QuadRendererData::addTris(triangles,vertexCount);
    QuadRendererData::addBrightness(colors,0.8);
    QuadRendererData::addDefaultTexCoord(textureCoord);
    vertexCount += 4;
    trianglesCount += 2;

    // front face
    QuadRendererData::addFrontVertices(vertices, Vector3(0,0,0));
    QuadRendererData::addTris(triangles,vertexCount);
    QuadRendererData::addBrightness(colors,0.8);
    QuadRendererData::addDefaultTexCoord(textureCoord);
    vertexCount += 4;
    trianglesCount += 2;

    // right face
    QuadRendererData::addRightVertices(vertices, Vector3(0,0,0));
    QuadRendererData::addTris(triangles,vertexCount);
    QuadRendererData::addBrightness(colors,0.9);
    QuadRendererData::addDefaultTexCoord(textureCoord);
    vertexCount += 4;
    trianglesCount += 2;

    // left face
    QuadRendererData::addLeftVertices(vertices, Vector3(0,0,0));
    QuadRendererData::addTris(triangles,vertexCount);
    QuadRendererData::addBrightness(colors,0.9);
    QuadRendererData::addDefaultTexCoord(textureCoord);
    vertexCount += 4;
    trianglesCount += 2;

    camera.fovy = 67;
    camera.target = {0,0,0};
    camera.up = {0,1,0};
    camera.projection = CAMERA_PERSPECTIVE;

    Mesh mesh = {0};
    mesh.vertexCount = vertexCount;
    mesh.triangleCount = trianglesCount;
    mesh.vertices = vertices.data();
    mesh.indices = triangles.data();
    mesh.colors = colors.data();
    mesh.texcoords = textureCoord.data();

    InitWindow(1200,800, "cube");
    SetTargetFPS(30);

    DisableCursor();

    UploadMesh(&mesh, false);
    Texture2D texture = LoadTexture("xDirt.png");
    GenTextureMipmaps(&texture);
    SetTextureFilter(texture,TEXTURE_FILTER_TRILINEAR);
    Material mat = LoadMaterialDefault();
    mat.maps[MATERIAL_MAP_DIFFUSE].texture = texture;
    Matrix trans = MatrixTranslate(-1,0,-1);


    auto loadFuture = std::async(std::launch::async, [&]() {
        world.loadChunks((int)camera.position.x,(int)camera.position.z,4);
        world.loadedChunksConstruct();
    });
    // //std::future<void> worker = std::async(std::launch::async,world.loadChunks,(int)camera.position.x,(int)camera.position.z,1);
    // world.loadChunks((int)camera.position.x,(int)camera.position.z,1);
    // world.loadedChunksConstruct();
    // world.newLoadedChunks.clear();

    while (!WindowShouldClose()) {
        std::cout <<"fps : " <<  1 / GetFrameTime() << std::endl;
        using namespace std::chrono_literals;


        UpdateCamera(&camera, CAMERA_FREE);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            breakBlock(0.05f,20);
        }

        if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
            EnableCursor();
        }

        timer += GetFrameTime();
        if (timer >= 0.5f) {
            Vector3 currentChunk = world.getChunkCoord(camera.position.x,camera.position.z);
            if (cx != (int)currentChunk.x || cz != (int)currentChunk.z) {


                loadFuture = std::async(std::launch::async, [&]() {
                    world.loadChunks((int)camera.position.x,(int)camera.position.z,4);
                    world.loadedChunksConstruct();
                });

                // world.loadChunks((int)camera.position.x,(int)camera.position.z,1);
                // world.loadedChunksConstruct();
                // world.newLoadedChunks.clear();

                cx = (int)currentChunk.x;
                cz = (int)currentChunk.z;
            }
            timer -= 0.5f;
        }

        if (loadFuture.valid() && loadFuture.wait_for(0ms) == std::future_status::ready) {
            loadFuture.get(); // Async task is completely finished
            for (int i = 0; i < world.newLoadedChunks.size(); ++i) {
                world.newLoadedChunks[i]->uploadMesh();
            }
            world.newLoadedChunks.clear();
        }

        ClearBackground(BLANK);
        BeginDrawing();
        BeginMode3D(camera);
        DrawGrid(2,16);
        world.render(mat);
        EndMode3D();
        EndDrawing();
    }

    for (int i = 0 ; i < world.chunkToRender.size(); i ++) {
        delete world.chunkToRender[i];
    }
    world.chunkToRender.clear();
    CloseWindow();
    return 0;
}

void printVertices(std::vector<float> vertices ) {
    for (int i = 0 ; i < vertices.size(); i += 3) {
        std::string x = std::to_string(vertices[i]);
        std::string y = std::to_string(vertices[i + 1]);
        std::string z = std::to_string(vertices[i + 2]);
        std::string coord = "(" + x + "," + y + "," + z + ")";
        std::cout << coord << std::endl;
    }
}

void breakBlock(float step, int dist) {
    Vector3 forward = Vector3Normalize(Vector3Subtract(camera.target, camera.position));
    for (float i = 0; i < dist; i += step) {
        Vector3 floating_blockPos = forward * i + camera.position;
        int bx = (int)std::floor(floating_blockPos.x);
        int by = (int)std::floor(floating_blockPos.y);
        int bz = (int)std::floor(floating_blockPos.z);
        if (world.getBlock(bx,by,bz) == BlockState::Solid) {
            Chunk* chunk = world.getChunk(bx,bz);
            world.setBlock(bx,by,bz,BlockState::None);
            if (chunk != nullptr) {
                if (chunk->mesh.vaoId != 0) {
                    chunk->unloadMesh();
                }
                chunk->constructMesh();
                chunk->uploadMesh();
            }
            break;
        }


    }
}
