#include <windows.h>
#include <iostream>

using namespace std;

HWND hwnd = GetConsoleWindow();
HDC hdc = GetDC(hwnd);

void figure(float x1, float y1, float x2, float y2) {

    float d, dx, dy;
    dx = abs(x1 - x2);
    dy = abs(y1 - y2);

    if (dx == 0) {
        d = 0;
        while (y1 < y2) {
            y1 += 1;
            for (float i = x1; i < x1 + 20; i++) {
                for (float j = y1; j < y1 + 20; j++) {
                    SetPixel(hdc, i, j, RGB(255, 0, 0));
                }
            }
        }
    }

    if (dy == 0) {
        d = 0;
        while (x1 < x2) {
            x1 += 1;
            for (float i = x1; i < x1 + 20; i++) {
                for (float j = y1; j < y1 + 20; j++) {
                    SetPixel(hdc, i, j, RGB(255, 0, 0));
                }
            }
        }
    }

    /*
    if (dx >= dy) {
        dx = x1 - x2;
        dy = y1 - y2;
        d = dy / dx;
        while (x1 < x2) {
            x1 += 1;
            y1 += d ;
            for (float i = x1; i < x1 + 20; i++) {
                for (float j = y1; j < y1 + 20; j++) {
                    SetPixel(hdc, i, j, RGB(255, 0, 0));
                }
            }
        }
    }

    if (dx < dy) {
        dx = x1 - x2;
        dy = y1 - y2;
        d = dx / dy;
        while (y1 < y2) {
            y1 += 1;
            x1 += d ;
            for (float i = x1; i < x1 + 20; i++) {
                for (float j = y1; j < y1 + 20; j++) {
                    SetPixel(hdc, i, j, RGB(255, 0, 0));
                }
            }
        }
    }
    */

}

void figure2(float x1, float y1, float x2, float y2) {

    float d, dx, dy, t;

    dx = x1 - x2;
    dy = y1 - y2;
    d = 0;
    t = dx / dy;

    
    while(x1<x2){
        for (int i = x1; i < x1+10; i++) {
            for (int j = y1; j < y1+10; j++) {
                SetPixel(hdc, i, j, RGB(0, 255, 0));
            }
        }
        d += t;
        y1 += 1;
        if (d > 0.5) {
            x1 += 1;
            d -= 1;
        }
    }

}

void figure3(float x1, float y1, float x2, float y2) {

    float d, dx, dy, t;

    dx = x1 - x2;
    dy = y1 - y2;
    d = 0;
    t = dx / dy;

    while (x1 < x2) {
        for (int i = x1; i < x1 + 10; i++) {
            for (int j = y1; j < y1 + 10; j++) {
                SetPixel(hdc, i, j, RGB(0, 0, 255));
            }
        }

        d -= t;
        y1 -= 1;
        if (d > 0.5) {
            x1 += 1;
            d -= 1;
        }
    }

}



int main() {        

    // верхня сторона
    figure(15, 15, 215, 15); 
    // нижня сторона
    figure(15, 315, 215, 315);
    // ліва сторона
    figure(15, 15, 15, 315);
    // права сторона
    figure(215, 15, 215, 315);

    // діагональ \ 
    figure2(15, 15, 226, 326);
    // діагональ /
    figure3(15, 325, 226, 14);

    ReleaseDC(hwnd, hdc);
    cin.ignore();
    return 0;

}