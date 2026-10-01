#include <iostream>
#include "raylib.h"
#include "raymath.h"
#include "BlockEngine/QuadData.h"

Camera3D camera;
Mesh mesh = {0};

void testMesh();

int main() {
    InitWindow(1300,800,"Infiniminer clone c++");
    SetTargetFPS(120);
    DisableCursor();

    camera = {0,1,-1};
    camera.target = {0,0,0};
    camera.fovy = 67;
    camera.up = {0,1,0};
    camera.projection = CAMERA_PERSPECTIVE;

    testMesh();

    Texture2D terrain = LoadTexture("Resources/terrain.png");
    Matrix matrix = MatrixIdentity();
    Material mat = LoadMaterialDefault();
    mat.maps[MATERIAL_MAP_DIFFUSE].texture = terrain;

    while (!WindowShouldClose()) {
        UpdateCamera(&camera,CAMERA_FREE);

        BeginDrawing();
        ClearBackground(BLANK);
        BeginMode3D(camera);
        DrawGrid(2,16);
        DrawMesh(mesh,mat,matrix);
        EndMode3D();
        EndDrawing();
    }
    return 0;
}

void testMesh() {
    std::vector<float> vertices;
    std::vector<unsigned short> indices;
    std::vector<unsigned char> colors;
    std::vector<float> uvs;

    int vertexCount = 0;
    int triangleCount = 0;

    Vector3 blockPos = {0,0,0};

    QuadData::addUpVertices(vertices,blockPos);
    QuadData::addIndices(indices,vertexCount);
    QuadData::addBrightness(colors,1);
    //QuadData::addDefaultUV(uvs);
    QuadData::addUV(7,0,uvs);
    vertexCount += 4;
    triangleCount += 2;

    QuadData::addDownVertices(vertices,blockPos);
    QuadData::addIndices(indices,vertexCount);
    QuadData::addBrightness(colors,0.4);
    //QuadData::addDefaultUV(uvs);
    QuadData::addUV(7,0,uvs);
    vertexCount += 4;
    triangleCount += 2;

    QuadData::addFrontVertices(vertices,blockPos);
    QuadData::addIndices(indices,vertexCount);
    QuadData::addBrightness(colors,0.6f);
    //QuadData::addDefaultUV(uvs);
    QuadData::addUV(7,0,uvs);
    vertexCount += 4;
    triangleCount += 2;

    QuadData::addBackVertices(vertices,blockPos);
    QuadData::addIndices(indices,vertexCount);
    QuadData::addBrightness(colors,0.6);
    //QuadData::addDefaultUV(uvs);
    QuadData::addUV(7,0,uvs);
    vertexCount += 4;
    triangleCount += 2;

    QuadData::addRightVertices(vertices,blockPos);
    QuadData::addIndices(indices,vertexCount);
    QuadData::addBrightness(colors,0.85);
    //QuadData::addDefaultUV(uvs);
    QuadData::addUV(7,0,uvs);
    vertexCount += 4;
    triangleCount += 2;

    QuadData::addLeftVertices(vertices,blockPos);
    QuadData::addIndices(indices,vertexCount);
    QuadData::addBrightness(colors,0.85);
    //QuadData::addDefaultUV(uvs);
    QuadData::addUV(7,0,uvs);
    vertexCount += 4;
    triangleCount += 2;

    mesh.vertexCount = vertexCount;
    mesh.triangleCount = triangleCount;

    mesh.vertices = vertices.data();
    mesh.indices = indices.data();
    mesh.colors = colors.data();
    mesh.texcoords = uvs.data();

    UploadMesh(&mesh,false);
}