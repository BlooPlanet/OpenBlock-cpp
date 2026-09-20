#include "raylib.h"
#include "raymath.h"

void update();
void render();

int main() {
    Camera3D camera = {0,0.5f,-1};
    camera.fovy = 67;
    camera.target = {0,0.5f,0};
    camera.up = {0,1,0};
    camera.projection = CAMERA_PERSPECTIVE;

    InitWindow(1000,700,"Triangle");
    SetTargetFPS(60);

    Mesh mesh = {0};
    mesh.vertexCount = 3;
    mesh.triangleCount = 1;

    float vertices[3 * 3];
    vertices[0] = 0.5f;
    vertices[1] = 0;
    vertices[2] = 0;

    vertices[3] = -0.5f;
    vertices[4] = 0;
    vertices[5] = 0;

    vertices[6] = 0;
    vertices[7] = 1;
    vertices[8] = 0;

    unsigned char colors[] {
        255,0,0,255,
        0,255,0,255,
        0,0,255,255
    };

    mesh.vertices = vertices;
    mesh.colors = colors;
    UploadMesh(&mesh,false);

    Material mat = LoadMaterialDefault();
    Matrix matrix = MatrixIdentity();

    while (!WindowShouldClose()) {
        update();

        BeginDrawing();
        BeginMode3D(camera);
        render();
        DrawMesh(mesh,mat, matrix);
        EndMode3D();
        EndDrawing();
    }
    return 0;
}

void update() {
    ClearBackground(BLANK);
}

void render() {
    //DrawGrid(2,1);
}
