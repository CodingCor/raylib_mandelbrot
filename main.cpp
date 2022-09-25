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
const double SIZEINCREASE = 0.1;

static double s_currentSize = STARTSIZE;
static double xOff = 0.0;
static double yOff = 0.0;

void UpdateDrawFrame(void);     // Update and Draw one frame
void updateLogic();

int main() {
    InitWindow(screenWidth, screenHeight, "Mandelbrot-Set");

    SetTargetFPS(15);   // Set our game to run at 60 frames-per-second

    while (!WindowShouldClose()){
        updateLogic();
        UpdateDrawFrame();
    }

    CloseWindow();        // Close window and OpenGL context

    return 0;
}

void updateLogic(){
    if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        s_currentSize += SIZEINCREASE;
        std::cout << "LEFT" << std::endl;

        //int xPosition = GetMouseX();
        //int yPosition = GetMouseY();
        //xOff = (double)(xPosition) / (double)(screenWidth) * STARTSIZE - STARTSIZE/2.0; 
        //yOff = (double)(yPosition) / (double)(screenHeight) * STARTSIZE - STARTSIZE/2.0;

    }else if(IsMouseButtonDown(MOUSE_BUTTON_RIGHT)){
        s_currentSize -= SIZEINCREASE;
        std::cout << "RIGHT" << std::endl;
        //int xPosition = GetMouseX();
        //int yPosition = GetMouseY();
        //xOff = (double)(xPosition) / (double)(screenWidth) * STARTSIZE - STARTSIZE/2.0; 
        //yOff = (double)(yPosition) / (double)(screenHeight) * STARTSIZE - STARTSIZE/2.0;
    }
}

void UpdateDrawFrame(void) {
    BeginDrawing();

        ClearBackground(WHITE);

        for(int x = 0; x < screenWidth; x++){
            for(int y = 0; y < screenHeight; y++){
                double a = (double)(x) / (double)(screenWidth) * s_currentSize - s_currentSize/2.0;
                int yPosition = screenHeight - y;
                double b = (double)(yPosition) / (double)(screenHeight) * s_currentSize - s_currentSize/2.0;

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
