#include <GL/glut.h>
#include <math.h>

#define PI 3.1415926535898

void drawCircle(float x, float y, float radius, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * PI * i / 100;
        glVertex2f(x + cos(angle) * radius, y + sin(angle) * radius);
    }
    glEnd();
}

void drawCar() {
    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_QUADS);
    glVertex2f(-0.55f, -0.35f);
    glVertex2f(-0.35f, -0.35f);
    glVertex2f(-0.35f, -0.3f);
    glVertex2f(-0.55f, -0.3f);
    glEnd();

    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_QUADS);
    glVertex2f(-0.45f, -0.35f);
    glVertex2f(-0.43f, -0.35f);
    glVertex2f(-0.43f, -0.45f);
    glVertex2f(-0.45f, -0.45f);
    glEnd();

    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.4f, -0.6f);
    glVertex2f(0.4f, -0.6f);
    glVertex2f(0.4f, -0.4f);
    glVertex2f(-0.4f, -0.4f);
    glEnd();

    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.4f, -0.6f);
    glVertex2f(0.6f, -0.6f);
    glVertex2f(0.6f, -0.5f);
    glVertex2f(0.4f, -0.5f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(0.4f, -0.5f);
    glVertex2f(0.6f, -0.5f);
    glVertex2f(0.4f, -0.4f);
    glEnd();

    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.4f, -0.6f);
    glVertex2f(-0.6f, -0.6f);
    glVertex2f(-0.6f, -0.5f);
    glVertex2f(-0.4f, -0.5f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(-0.4f, -0.5f);
    glVertex2f(-0.6f, -0.5f);
    glVertex2f(-0.4f, -0.4f);
    glEnd();

    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.35f, -0.4f);
    glVertex2f(0.35f, -0.4f);
    glVertex2f(0.25f, -0.25f);
    glVertex2f(-0.25f, -0.25f);
    glEnd();

    glColor3f(0.8f, 0.8f, 0.8f);
    glBegin(GL_QUADS);
    glVertex2f(-0.33f, -0.4f);
    glVertex2f(0.33f, -0.4f);
    glVertex2f(0.23f, -0.27f);
    glVertex2f(-0.23f, -0.27f);
    glEnd();

    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.55f, -0.55f);
    glVertex2f(0.6f, -0.55f);
    glVertex2f(0.6f, -0.5f);
    glVertex2f(0.55f, -0.5f);
    glEnd();

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.6f, -0.55f);
    glVertex2f(-0.55f, -0.55f);
    glVertex2f(-0.55f, -0.5f);
    glVertex2f(-0.6f, -0.5f);
    glEnd();

    glColor4f(0.0f, 0.0f, 0.5f, 0.3f);
    glBegin(GL_QUADS);
    glVertex2f(-0.6f, -0.7f);
    glVertex2f(0.6f, -0.7f);
    glVertex2f(0.6f, -0.6f);
    glVertex2f(-0.6f, -0.6f);
    glEnd();

    glPushMatrix();
    glTranslatef(0.45f, -0.65f, 0.0f);
    drawCircle(0.0f, 0.0f, 0.1f, 0.0f, 0.0f, 0.0f);
    drawCircle(0.0f, 0.0f, 0.06f, 1.0f, 1.0f, 1.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.45f, -0.65f, 0.0f);
    drawCircle(0.0f, 0.0f, 0.1f, 0.0f, 0.0f, 0.0f);
    drawCircle(0.0f, 0.0f, 0.06f, 1.0f, 1.0f, 1.0f);
    glPopMatrix();
}

void drawMountain() {
    glColor3f(0.0f, 0.5f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-1.0f, -0.7f);
    glVertex2f(0.0f, 0.5f);
    glVertex2f(1.0f, -0.7f);
    glEnd();
}

void drawRoad() {
    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -0.7f);
    glVertex2f(1.0f, -0.7f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    for (float i = -0.9f; i <= 0.9f; i += 0.2f) {
        glVertex2f(i, -0.85f);
        glVertex2f(i + 0.1f, -0.85f);
    }
    glEnd();
}

void drawTree(float x, float y) {
    glColor3f(0.55f, 0.27f, 0.07f);
    glBegin(GL_QUADS);
    glVertex2f(x - 0.03f, y - 0.2f);
    glVertex2f(x + 0.03f, y - 0.2f);
    glVertex2f(x + 0.03f, y);
    glVertex2f(x - 0.03f, y);
    glEnd();

    glColor3f(0.0f, 0.4f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(x - 0.2f, y);
    glVertex2f(x + 0.2f, y);
    glVertex2f(x, y + 0.3f);
    glVertex2f(x - 0.15f, y + 0.2f);
    glVertex2f(x + 0.15f, y + 0.2f);
    glVertex2f(x, y + 0.5f);
    glVertex2f(x - 0.1f, y + 0.4f);
    glVertex2f(x + 0.1f, y + 0.4f);
    glVertex2f(x, y + 0.7f);
    glEnd();
}

void drawSun() {
    drawCircle(0.8f, 0.8f, 0.1f, 1.0f, 1.0f, 0.0f);
}

void drawCloud(float x, float y) {
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(x, y, 0.1f, 1.0f, 1.0f, 1.0f);
    drawCircle(x + 0.1f, y, 0.1f, 1.0f, 1.0f, 1.0f);
    drawCircle(x + 0.05f, y + 0.05f, 0.1f, 1.0f, 1.0f, 1.0f);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.53f, 0.81f, 0.98f);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();

    drawSun();

    drawCloud(-0.5f, 0.7f);
    drawCloud(0.2f, 0.6f);

    drawMountain();

    drawRoad();

    drawTree(-0.8f, -0.5f);
    drawTree(0.8f, -0.5f);

    drawCar();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Mobil Balap Dari Rembang");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
