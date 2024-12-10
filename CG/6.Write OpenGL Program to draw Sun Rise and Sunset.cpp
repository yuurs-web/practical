/*
Name : Prem Gopal Chuniyan
Roll No : 75
Class : SE - A     Seat No :     
Title of Practical : Write OpenGL Program to draw Sun Rise and Sunset.  
*/




#include <GL/glut.h>
#include <cmath>

GLfloat sunX = 0.0f;
GLfloat sunY = -0.8f;
GLfloat sunSpeed = 0.001f;
bool isSunset = false;

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

void drawSun() {
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float theta = i * 3.142 / 180;
        glVertex2f(0.1 * cos(theta) + sunX, 0.1 * sin(theta) + sunY);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawSun();
    glutSwapBuffers();
}

void timer(int) {
    if (isSunset) {
        sunY -= sunSpeed;
        if (sunY <= -0.8f) {
            isSunset = false;
        }
    } else {
        sunY += sunSpeed;
        if (sunY >= 0.8f) {
            isSunset = true;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Sunrise and Sunset");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}

