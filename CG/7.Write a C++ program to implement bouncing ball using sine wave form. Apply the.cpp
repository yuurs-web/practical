/*
Name : Prem Gopal Chuniyan
Roll No : 75
Class : SE - A     Seat No :     
Title of Practical : Write a C++ program to implement bouncing ball using sine wave form. Apply the
concept of polymorphism.   
*/




#include <iostream>
#include <graphics.h>
#include <math.h>
#include <conio.h>

class BouncingBall {
public:
    virtual void ball() {
        // Base class method
    }
};

class BouncingBallSine : public BouncingBall {
public:
    void ball() override {
        int gd = DETECT, gm;
        initgraph(&gd, &gm, NULL);
        float x = 1, y, j = 0.5, count = 0.1, i;
        int k;

        for (k = 0; k < 7; k++) {
            for (i = 0; i < 180; i += 10) {
                y = sin(i * 3.14 / 180) / j;
                if (y > 0) y = -y;
                x += 5;
                setcolor(WHITE);
                setfillstyle(SOLID_FILL, WHITE);
                circle(x, y * 100 + 200, 15);
                floodfill(x, y * 100 + 200, WHITE);
                line(0, 215, 800, 215);
                delay(50);
                cleardevice();
            }
            j += count;
            count += 0.1;
        }
        getch();
        closegraph();
    }
};

int main() {
    BouncingBall* ballPtr;
    BouncingBallSine sineBall;
    ballPtr = &sineBall;
    ballPtr->ball();
    return 0;
}
