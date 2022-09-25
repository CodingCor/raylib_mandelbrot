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
const int SIZECHANGEPERCENT = 10;

static double s_currentSize = STARTSIZE;

void UpdateDrawFrame(void);     // Update and Draw one frame
void updateLogic();

double getRelativePositionX(const int screenPositionX);
double getRelativePositionY(const int screenPositionY);


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

double getRelativePositionX(const int screenPositionX){
    double relativeX = (double)(screenPositionX) / (double)(screenWidth) * s_currentSize;
    relativeX -= s_currentSize / 2.0;
    return relativeX;
}

double getRelativePositionY(const int screenPositionY){
    int yPosition = screenHeight - screenPositionY;
    double relativeY =(double)(yPosition) / (double)(screenHeight) * s_currentSize;
    relativeY -= s_currentSize / 2.0;
    return relativeY;
}

void updateLogic(){
    if(IsMouseButtonDown(MOUSE_BUTTON_MIDDLE)){
    }
    if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        s_currentSize += s_currentSize / 100.0 * (double)(SIZECHANGEPERCENT);
        //s_currentSize += SIZEINCREASE;
        //reCenterScreen();

    }else if(IsMouseButtonDown(MOUSE_BUTTON_RIGHT)){
        s_currentSize -= s_currentSize / 100.0 * (double)(SIZECHANGEPERCENT);
        //s_currentSize -= SIZEINCREASE;
        //reCenterScreen();
    }
}

void UpdateDrawFrame(void) {
    BeginDrawing();

        ClearBackground(WHITE);

        for(int x = 0; x < screenWidth; x++){
            for(int y = 0; y < screenHeight; y++){

                double a = getRelativePositionX(x);
                double b = getRelativePositionY(y);

                const double ca = a;
                const double cb = b;


                //mandelbrot calculation
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

                if(i == MAXITERATIONS){
                    brightColorValue = 0;
                }

                DrawPixel(x, y, {brightColorValue, brightColorValue, brightColorValue, 255});
            }
        }


    EndDrawing();
}
