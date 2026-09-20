#include <iostream>

#include "raylib.h"
#include "raymath.h"
#include "Sources/BlockEngine/BlockData.h"

int main() {
    std::cout << "hello world!" << std::endl;

    Camera3D camera = {-1,-2,-2};
    camera.target = {0,0,0};
    camera.fovy = 67;
    camera.up = {0,1,0};
    camera.projection = CAMERA_PERSPECTIVE;



    float vertData[4 * 3];
    std::vector<float> vertices;
    std::vector<unsigned short> indices;
    std::vector<unsigned char> colors;
    int vertexCount = 0;
    int triangleCount = 0;

    // top face
    BlockData::setTopVertices(vertData,Vector3(0,0,0));
    for (float verts : vertData) {
        vertices.push_back(verts);
    }
    BlockData::addTriangles(indices,vertexCount);
    BlockData::addBrightness(colors,1);
    vertexCount += 4;
    triangleCount += 2;

    // down face
    BlockData::setDownVertices(vertData,Vector3(0,0,0));
    for (float verts : vertData) {
        vertices.push_back(verts);
    }
    BlockData::addTriangles(indices,vertexCount);
    BlockData::addBrightness(colors,0.5);
    vertexCount += 4;
    triangleCount += 2;

    // back face
    BlockData::setBackVertices(vertData,Vector3(0,0,0));
    for (float verts : vertData) {
        vertices.push_back(verts);
    }
    BlockData::addTriangles(indices,vertexCount);
    BlockData::addBrightness(colors,0.8);
    vertexCount += 4;
    triangleCount += 2;

    // front face
    BlockData::setFrontVertices(vertData,Vector3(0,0,0));
    for (float verts : vertData) {
        vertices.push_back(verts);
    }
    BlockData::addTriangles(indices,vertexCount);
    BlockData::addBrightness(colors,0.8);
    vertexCount += 4;
    triangleCount += 2;

    // left face
    BlockData::setLeftVertices(vertData,Vector3(0,0,0));
    for (float verts : vertData) {
        vertices.push_back(verts);
    }
    BlockData::addTriangles(indices,vertexCount);
    BlockData::addBrightness(colors,0.9);
    vertexCount += 4;
    triangleCount += 2;

    // right face
    BlockData::setRightVertices(vertData,Vector3(0,0,0));
    for (float verts : vertData) {
        vertices.push_back(verts);
    }
    BlockData::addTriangles(indices,vertexCount);
    BlockData::addBrightness(colors,0.9);
    vertexCount += 4;
    triangleCount += 2;

    // float vertices_array[vertices.size()];
    // for (int i = 0 ; i < 12;i++) {
    //     vertices_array[i] = vertices[i];
    //     std::cout << vertices[i] << std::endl;
    // }

    InitWindow(1000,600, "MeshTest") ;
    SetTargetFPS(60);

    Mesh mesh = {0};
    mesh.vertexCount = vertexCount;
    mesh.triangleCount = triangleCount;
    mesh.vertices = vertices.data();
    mesh.indices = indices.data();
    mesh.colors = colors.data();
    UploadMesh(&mesh, false);

    Material mat = LoadMaterialDefault();

    Matrix trans = MatrixIdentity();

    while (WindowShouldClose() == false) {
        UpdateCamera(&camera,CAMERA_FREE);
        BeginDrawing();
        ClearBackground(BLANK);
        BeginMode3D(camera);
        DrawGrid(2,1);
        DrawLine3D(Vector3(0,0,0),Vector3(0,1,0),GREEN);
        DrawLine3D(Vector3(0,0,0),Vector3(1,0,0),RED);
        DrawLine3D(Vector3(0,0,0),Vector3(0,0,1),BLUE);
        DrawMesh(mesh,mat,trans);
        EndMode3D();
        EndDrawing();
    }
    CloseWindow();
    UnloadMaterial(mat);
    std::cout << "Window is closed" << std::endl;
    return 0;
}
