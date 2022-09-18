#include "raylib.h"
#include <iostream>
#include <cmath>

/// 
/// Globals
///
int screenWidth = 800;
int screenHeight = 800;
const double STARTSIZE = 4.0;
const int MAXITERATIONS = 100;

void UpdateDrawFrame(void);     // Update and Draw one frame

int main() {
    InitWindow(screenWidth, screenHeight, "Mandelbrot-Set");

    SetTargetFPS(15);   // Set our game to run at 60 frames-per-second

    while (!WindowShouldClose()){
        UpdateDrawFrame();
    }

    CloseWindow();        // Close window and OpenGL context

    return 0;
}

void UpdateDrawFrame(void) {
    BeginDrawing();

        ClearBackground(WHITE);

        for(int x = 0; x < screenWidth; x++){
            for(int y = 0; y < screenHeight; y++){
                double a = (double)(x) / (double)(screenWidth) * STARTSIZE - STARTSIZE/2.0;
                double b = (double)(y) / (double)(screenHeight) * STARTSIZE - STARTSIZE/2.0;

                const double ca = a;
                const double cb = b;

                 //std:: cout << "a: " << a << " b: " << b << std::endl;

                int i = 0;
                while(i < MAXITERATIONS){

                    double aa = (a * a) - (b * b);
                    double bb = 2.0 * a * b;

                    a = aa + ca;
                    b = bb + cb;

                    if(a * a + b * b > 4.0) {
                        break;
                    }
                    i++;
                }
                //colorization
                double bright = (double)(i) / (double)(MAXITERATIONS);
                unsigned char brightColorValue = std::sqrt(bright) * 255.0; 
                DrawPixel(x, y, {brightColorValue, brightColorValue, brightColorValue, 255});
                if(i == MAXITERATIONS){
                    brightColorValue = 0;
                }
                DrawPixel(x, y, {brightColorValue, brightColorValue, brightColorValue, 255});
            }
        }


    EndDrawing();
}
