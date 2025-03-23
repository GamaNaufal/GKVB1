#include <GL/glut.h>
#include <math.h>

#define PI 3.1415926535898

// Sudut rotasi global
float rotX = 0.0f;
float rotY = 0.0f;
float rotZ = 0.0f;
float cameraDistance = 2.0f;

// Fungsi untuk menggambar silinder 3D
void drawCylinder(float radius, float height, int slices) {
    float angle, x, y;
    float angleIncrement = 2.0f * PI / slices;
    
    // Bagian atas silinder
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.0f, height/2, 0.0f);
    for (int i = 0; i <= slices; i++) {
        angle = i * angleIncrement;
        x = radius * cos(angle);
        y = radius * sin(angle);
        glVertex3f(x, height/2, y);
    }
    glEnd();
    
    // Bagian bawah silinder
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.0f, -height/2, 0.0f);
    for (int i = slices; i >= 0; i--) {
        angle = i * angleIncrement;
        x = radius * cos(angle);
        y = radius * sin(angle);
        glVertex3f(x, -height/2, y);
    }
    glEnd();
    
    // Sisi silinder
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= slices; i++) {
        angle = i * angleIncrement;
        x = radius * cos(angle);
        y = radius * sin(angle);
        glVertex3f(x, height/2, y);
        glVertex3f(x, -height/2, y);
    }
    glEnd();
}

// Fungsi untuk menggambar roda dengan pelek
void drawWheel(float radius, float width) {
    // Ban (hitam)
    glPushMatrix();
    glColor3f(0.1f, 0.1f, 0.1f);
    drawCylinder(radius, width, 20);
    glPopMatrix();
    
    // Pelek (putih)
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCylinder(radius * 0.6f, width * 1.1f, 20);
    glPopMatrix();
}

// Fungsi untuk menggambar mobil 3D
void drawCar() {
    // Badan utama mobil (biru)
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 1.0f);
    glScalef(0.8f, 0.2f, 0.4f);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // Bagian depan mobil
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 1.0f);
    glTranslatef(0.5f, 0.0f, 0.0f);
    glScalef(0.2f, 0.1f, 0.4f);
    glutSolidCube(1.0);
    
    // Segitiga miring depan (sisi kanan)
    glPushMatrix();
    glTranslatef(0.0f, 0.5f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex3f(-1.0f, 0.0f, 0.5f);
    glVertex3f(0.5f, 0.0f, 0.5f);
    glVertex3f(-1.0f, 1.0f, 0.5f);
    glEnd();
    glPopMatrix();
    
    // Segitiga miring depan (sisi kiri)
    glPushMatrix();
    glTranslatef(0.0f, 0.5f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex3f(-1.0f, 0.0f, -0.5f);
    glVertex3f(0.5f, 0.0f, -0.5f);
    glVertex3f(-1.0f, 1.0f, -0.5f);
    glEnd();
    glPopMatrix();
    
    // Atap miring depan
    glPushMatrix();
    glTranslatef(0.0f, 0.5f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(-1.0f, 1.0f, 0.5f);
    glVertex3f(-1.0f, 1.0f, -0.5f);
    glVertex3f(0.5f, 0.0f, -0.5f);
    glVertex3f(0.5f, 0.0f, 0.5f);
    glEnd();
    glPopMatrix();
    glPopMatrix();
    
    // Bagian belakang mobil
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 1.0f);
    glTranslatef(-0.5f, 0.0f, 0.0f);
    glScalef(0.2f, 0.1f, 0.4f);
    glutSolidCube(1.0);
    
    // Segitiga miring belakang (sisi kanan)
    glPushMatrix();
    glTranslatef(0.0f, 0.5f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex3f(-0.5f, 0.0f, 0.5f);
    glVertex3f(1.0f, 0.0f, 0.5f);
    glVertex3f(1.0f, 1.0f, 0.5f);
    glEnd();
    glPopMatrix();
    
    // Segitiga miring belakang (sisi kiri)
    glPushMatrix();
    glTranslatef(0.0f, 0.5f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex3f(-0.5f, 0.0f, -0.5f);
    glVertex3f(1.0f, 0.0f, -0.5f);
    glVertex3f(1.0f, 1.0f, -0.5f);
    glEnd();
    glPopMatrix();
    
    // Atap miring belakang
    glPushMatrix();
    glTranslatef(0.0f, 0.5f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(-0.5f, 0.0f, 0.5f);
    glVertex3f(-0.5f, 0.0f, -0.5f);
    glVertex3f(1.0f, 1.0f, -0.5f);
    glVertex3f(1.0f, 1.0f, 0.5f);
    glEnd();
    glPopMatrix();
    glPopMatrix();
    
    // Kabin mobil
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 1.0f);
    glTranslatef(0.0f, 0.15f, 0.0f);
    glScalef(0.6f, 0.15f, 0.3f);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // Kaca atas (transparan)
    glPushMatrix();
    glColor4f(0.7f, 0.9f, 1.0f, 0.7f);
    glTranslatef(0.0f, 0.3f, 0.0f);
    glScalef(0.5f, 0.15f, 0.25f);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // Kap mesin
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.8f);
    glTranslatef(0.0f, 0.375f, 0.0f);
    glScalef(0.55f, 0.08f, 0.3f);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // Kaca depan (transparan)
    glPushMatrix();
    glColor4f(0.7f, 0.9f, 1.0f, 0.7f);
    glTranslatef(0.0f, 0.15f, 0.0f);
    glScalef(0.56f, 0.13f, 0.26f);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // Knalpot
    glPushMatrix();
    glColor3f(0.2f, 0.2f, 0.2f);
    glTranslatef(-0.45f, -0.03f, -0.15f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    drawCylinder(0.02f, 0.1f, 8);
    glPopMatrix();
    
    // Lampu depan (kanan)
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 0.0f);
    glTranslatef(0.58f, 0.0f, 0.15f);
    glutSolidCube(0.05f);
    glPopMatrix();
    
    // Lampu depan (kiri)
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 0.0f);
    glTranslatef(0.58f, 0.0f, -0.15f);
    glutSolidCube(0.05f);
    glPopMatrix();
    
    // Lampu belakang (kanan)
    glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(-0.58f, 0.0f, 0.15f);
    glutSolidCube(0.05f);
    glPopMatrix();
    
    // Lampu belakang (kiri)
    glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(-0.58f, 0.0f, -0.15f);
    glutSolidCube(0.05f);
    glPopMatrix();
    
    // Bumper depan
    glPushMatrix();
    glColor3f(0.5f, 0.5f, 0.5f);
    glTranslatef(0.49f, -0.085f, 0.0f);
    glScalef(0.25f, 0.07f, 0.45f);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // Bumper belakang
    glPushMatrix();
    glColor3f(0.5f, 0.5f, 0.5f);
    glTranslatef(-0.49f, -0.085f, 0.0f);
    glScalef(0.25f, 0.07f, 0.45f);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // Pilar mobil
    float pillarWidth = 0.045f;
    
    // Pilar depan kanan
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 1.0f);
    glTranslatef(0.225f, 0.2f, 0.115f);
    glScalef(pillarWidth, 0.35f, pillarWidth);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // Pilar depan kiri
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 1.0f);
    glTranslatef(0.225f, 0.2f, -0.115f);
    glScalef(pillarWidth, 0.35f, pillarWidth);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // Pilar belakang kanan
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 1.0f);
    glTranslatef(-0.225f, 0.2f, 0.115f);
    glScalef(pillarWidth, 0.35f, pillarWidth);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // Pilar belakang kiri
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 1.0f);
    glTranslatef(-0.225f, 0.2f, -0.115f);
    glScalef(pillarWidth, 0.35f, pillarWidth);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // Penghubung tengah depan
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 1.0f);
    glTranslatef(0.35f, 0.05f, 0.0f);
    glScalef(0.3f, 0.1f, 0.4f);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // Penghubung tengah belakang
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 1.0f);
    glTranslatef(-0.35f, 0.05f, 0.0f);
    glScalef(0.3f, 0.1f, 0.4f);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // Roda depan kanan
    glPushMatrix();
    glTranslatef(0.3f, -0.1f, 0.2f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    drawWheel(0.1f, 0.05f);
    glPopMatrix();
    
    // Roda depan kiri
    glPushMatrix();
    glTranslatef(0.3f, -0.1f, -0.2f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    drawWheel(0.1f, 0.05f);
    glPopMatrix();
    
    // Roda belakang kanan
    glPushMatrix();
    glTranslatef(-0.3f, -0.1f, 0.2f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    drawWheel(0.1f, 0.05f);
    glPopMatrix();
    
    // Roda belakang kiri
    glPushMatrix();
    glTranslatef(-0.3f, -0.1f, -0.2f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    drawWheel(0.1f, 0.05f);
    glPopMatrix();
}

// Fungsi display dengan kontrol zoom
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    // Posisikan kamera dengan kontrol zoom
    gluLookAt(0.0f, 0.5f, cameraDistance, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    
    // Terapkan rotasi
    glRotatef(rotX, 1.0f, 0.0f, 0.0f);
    glRotatef(rotY, 0.0f, 1.0f, 0.0f);
    glRotatef(rotZ, 0.0f, 0.0f, 1.0f);
    
    drawCar();
    
    glutSwapBuffers();
}

// Fungsi reshape
void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float aspect = (float)width / (float)height;
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

// Fungsi keyboard dengan kontrol zoom
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'w': rotX += 5.0f; break;
        case 's': rotX -= 5.0f; break;
        case 'a': rotY += 5.0f; break;
        case 'd': rotY -= 5.0f; break;
        case 'q': rotZ += 5.0f; break;
        case 'e': rotZ -= 5.0f; break;
        case '+': 
        case '=': 
            cameraDistance -= 0.1f;
            if (cameraDistance < 0.5f) cameraDistance = 0.5f;
            break;
        case '-': 
            cameraDistance += 0.1f;
            if (cameraDistance > 5.0f) cameraDistance = 5.0f;
            break;
        case 27:  exit(0); break;
    }
    glutPostRedisplay();
}

// Inisialisasi OpenGL
void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Mobil Mobil apa yang bikin seneng?");
    
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    
    glutMainLoop();
    return 0;
}
