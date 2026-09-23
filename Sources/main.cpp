#include <iostream>

#include "raylib.h"
#include "raymath.h"
#include "BlockEngine/Chunk.h"
#include "BlockEngine/QuadRendererData.h"
#include <cmath>

#include "BlockEngine/World.h"

void printVertices(std::vector<float> vertices);
void printTriangles(std::vector<unsigned short> triangles);
void breakBlock(float step,int dist);
Camera3D camera = {0,1,-2};

int main() {
    std::cout << "hello world!" << std::endl;
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

    // printVertices(vertices);
    // for (int t : triangles) {
    //     std::cout << t << std::endl;
    // }
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
    SetTargetFPS(60);

    DisableCursor();

    // chunk = {0,0,BlockState::Solid};
    // chunk.constructMesh();



    UploadMesh(&mesh, false);
    Texture2D texture = LoadTexture("terrain.png");
    Material mat = LoadMaterialDefault();
   // mat.maps[MATERIAL_MAP_DIFFUSE].texture = texture;
    Matrix trans = MatrixTranslate(-1,0,-1);


    // World world = {2,2};
    // Chunk chunk = world.getChunkFromIndex(2);
    // std::cout << &chunk << std::endl;
    // std::cout << "testing " << std::endl;
    // world.printChunksData();

    // for (int i = 0; i < world.chunkToRender.size(); i++) {
    //     world.chunkToRender[i].constructMesh();
    //     std::cout << &world.chunkToRender[i] << std::endl;
    // }
    //

    // Chunk* chunk_ptr = new Chunk(0,0,BlockState::Solid);
    // chunk_ptr->constructMesh();

    World world = {2,2};
    world.constructAll();

    while (!WindowShouldClose()) {
        UpdateCamera(&camera, CAMERA_FREE);

        // if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        //     breakBlock(0.05f,10);
        //     chunk.constructMesh();
        //     std::cout << "chunk created" << std::endl;
        // }

        ClearBackground(BLANK);
        BeginDrawing();
        BeginMode3D(camera);
        DrawGrid(32,1);
        DrawLine3D(Vector3(0,0,0) , Vector3(0,1,0),GREEN);
        DrawLine3D(Vector3(0,0,0) , Vector3(0,0,1),BLUE);
        DrawLine3D(Vector3(0,0,0) , Vector3(1,0,0),RED);
        //DrawMesh(mesh,mat,trans);
        // chunk_ptr->render(mat);
        world.render(mat);
        EndMode3D();
        EndDrawing();
    }
    // delete chunk_ptr;
    CloseWindow();
    for (Chunk* c : world.chunkToRender) {
        delete c;
    }
    world.chunkToRender.clear();
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

// void breakBlock(float step,int dist) {
//     Vector3 sub = Vector3Subtract(camera.target, camera.position);
//     Vector3 forward = Vector3Normalize(sub);
//     for (float i = 0; i < (float)dist; i += step) {
//         Vector3 worldCoord = camera.position + forward * i;
//         int x = (int)worldCoord.x;
//         int y = (int)worldCoord.y;
//         int z = (int)worldCoord.z;
//
//         if (chunk.getBLock(x,y,z) == BlockState::Solid) {
//             chunk.setBlock(x,y,z,BlockState::None);
//             break;
//         }
//     }
// }