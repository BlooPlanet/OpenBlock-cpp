#include <iostream>

#include "raylib.h"
#include "raymath.h"
#include "BlockEngine/BlockData.h"

void printVertices(std::vector<float> vertices);
void printTriangles(std::vector<unsigned short> triangles);



int main() {
    std::cout << "hello world!" << std::endl;
    std::vector<float> vertices;
    std::vector<unsigned short> triangles;
    std::vector<unsigned char> colors;

    int vertexCount = 0;
    int trianglesCount = 0;
    // top face
    BlockData::addTopVertices(vertices, Vector3(0,0,0));
    BlockData::addTris(triangles,vertexCount);
    BlockData::addBrightness(colors,1);
    vertexCount += 4;
    trianglesCount += 2;

    // down face
    BlockData::addDownVertices(vertices, Vector3(0,0,0));
    BlockData::addTris(triangles,vertexCount);
    BlockData::addBrightness(colors,0.5f);
    vertexCount += 4;
    trianglesCount += 2;

    // back face
    BlockData::addBackVertices(vertices, Vector3(0,0,0));
    BlockData::addTris(triangles,vertexCount);
    BlockData::addBrightness(colors,0.8);
    vertexCount += 4;
    trianglesCount += 2;

    // front face
    BlockData::addFrontVertices(vertices, Vector3(0,0,0));
    BlockData::addTris(triangles,vertexCount);
    BlockData::addBrightness(colors,0.8);
    vertexCount += 4;
    trianglesCount += 2;

    // right face
    BlockData::addRightVertices(vertices, Vector3(0,0,0));
    BlockData::addTris(triangles,vertexCount);
    BlockData::addBrightness(colors,0.9);
    vertexCount += 4;
    trianglesCount += 2;

    // left face
    BlockData::addLeftVertices(vertices, Vector3(0,0,0));
    BlockData::addTris(triangles,vertexCount);
    BlockData::addBrightness(colors,0.9);
    vertexCount += 4;
    trianglesCount += 2;

    // printVertices(vertices);
    // for (int t : triangles) {
    //     std::cout << t << std::endl;
    // }

    Camera3D camera = {0,1,-2};
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

    InitWindow(1200,800, "cube");
    SetTargetFPS(60);

    DisableCursor();

    UploadMesh(&mesh, false);
    Material mat = LoadMaterialDefault();
    Matrix trans = MatrixIdentity();

    while (!WindowShouldClose()) {
        UpdateCamera(&camera, CAMERA_FREE);

        ClearBackground(BLACK);
        BeginDrawing();
        BeginMode3D(camera);
        // DrawGrid(2,1);
        // DrawLine3D(Vector3(0,0,0) , Vector3(0,1,0),GREEN);
        // DrawLine3D(Vector3(0,0,0) , Vector3(0,0,1),BLUE);
        // DrawLine3D(Vector3(0,0,0) , Vector3(1,0,0),RED);
        DrawMesh(mesh,mat,trans);
        EndMode3D();
        EndDrawing();
    }

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
