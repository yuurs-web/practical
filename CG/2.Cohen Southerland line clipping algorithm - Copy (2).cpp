#include<iostream>
#include<graphics.h>
#include<cmath>
#include<string>  // For std::string
#include<dos.h>  // For delay, might not work with modern compilers.

using namespace std;

typedef struct coordinate {
    int x, y;
    string code;  // Use string instead of const char*
    coordinate() : x(0), y(0), code("0000") {}  // Initialize 'code' with a default value
} PT;

void drawwindow();
void drawline(PT p1, PT p2);
PT setcode(PT p);
int visibility(PT p1, PT p2);
PT resetendpt(PT p1, PT p2);

int main() {
    int gd = DETECT, gm;
    PT p1, p2, p3, p4, ptemp;
    int v;
    
    cout << "\nEnter x1 and y1\n";
    cin >> p1.x >> p1.y;
    cout << "\nEnter x2 and y2\n";
    cin >> p2.x >> p2.y;

    initgraph(&gd, &gm, "C:\\Program Files (x86)\\Dev-Cpp\\MinGW64\\include");
    // Modify this if using a modern compiler
    drawwindow();
    delay(500);

    drawline(p1, p2);
    delay(500);
    cleardevice();
    
    delay(500);
    p1 = setcode(p1);
    p2 = setcode(p2);
    v = visibility(p1, p2);
    delay(500);

    switch(v) {
        case 0:
            drawwindow();
            delay(500);
            drawline(p1, p2);
            break;
        case 1:
            drawwindow();
            delay(500);
            break;
        case 2:
            p3 = resetendpt(p1, p2);
            p4 = resetendpt(p2, p1);
            drawwindow();
            delay(500);
            drawline(p3, p4);
            break;
    }

    delay(5000);  // Replace with another delay function if needed
    closegraph();
    return 0;
}

void drawwindow() {
    // Drawing the window (rectangular clipping area)
    line(150, 100, 450, 100);
    line(450, 100, 450, 350);
    line(450, 350, 150, 350);
    line(150, 350, 150, 100);
}

void drawline(PT p1, PT p2) {
    // Drawing a line from point p1 to p2
    line(p1.x, p1.y, p2.x, p2.y);
}

PT setcode(PT p) {  // Setting the 4-bit code for point p
    PT ptemp;
    
    ptemp.code = "0000";  // Initialize 'code' with a string

    ptemp.code[0] = (p.y < 100) ? '1' : '0';  // Top
    ptemp.code[1] = (p.y > 350) ? '1' : '0';  // Bottom
    ptemp.code[2] = (p.x > 450) ? '1' : '0';  // Right
    ptemp.code[3] = (p.x < 150) ? '1' : '0';  // Left

    ptemp.x = p.x;
    ptemp.y = p.y;
    
    return ptemp;
}

int visibility(PT p1, PT p2) {
    int i, flag = 0;
    
    for(i = 0; i < 4; i++) {
        if((p1.code[i] != '0') || (p2.code[i] != '0'))
            flag = 1;
    }
    
    if(flag == 0)
        return 0;
    
    for(i = 0; i < 4; i++) {
        if((p1.code[i] == p2.code[i]) && (p1.code[i] == '1'))
            flag = 0;
    }
    
    if(flag == 0)
        return 1;
    
    return 2;
}

PT resetendpt(PT p1, PT p2) {
    PT temp;
    int x, y, i;
    float m, k;
    
    if(p1.code[3] == '1')
        x = 150;
    
    if(p1.code[2] == '1')
        x = 450;
    
    if((p1.code[3] == '1') || (p1.code[2] == '1')) {
        m = (float)(p2.y - p1.y) / (p2.x - p1.x);
        k = (p1.y + (m * (x - p1.x)));
        temp.y = k;
        temp.x = x;
        
        for(i = 0; i < 4; i++)
            temp.code[i] = p1.code[i];  // Here, code is now modifiable
        
        if(temp.y <= 350 && temp.y >= 100)
            return temp;
    }
    
    if(p1.code[0] == '1')
        y = 100;
    
    if(p1.code[1] == '1')
        y = 350;
        
    if((p1.code[0] == '1') || (p1.code[1] == '1')) {
        m = (float)(p2.y - p1.y) / (p2.x - p1.x);
        k = (float)p1.x + (float)(y - p1.y) / m;
        temp.x = k;
        temp.y = y;
        
        for(i = 0; i < 4; i++)
            temp.code[i] = p1.code[i];
        
        return temp;
    }
    else
        return p1;
}

