#include "raylib.h"

/// 
/// Globals
///
int screenWidth = 800;
int screenHeight = 450;

void UpdateDrawFrame(void);     // Update and Draw one frame

int main() {
    InitWindow(screenWidth, screenHeight, "Mandelbrot-Set");

    SetTargetFPS(60);   // Set our game to run at 60 frames-per-second

    while (!WindowShouldClose()){
        UpdateDrawFrame();
    }

    CloseWindow();        // Close window and OpenGL context

    return 0;
}

void UpdateDrawFrame(void) {
    BeginDrawing();

        ClearBackground(GRAY);

        DrawText("Mandelbrot-Set", 190, 200, 20, LIGHTGRAY);

    EndDrawing();
}
