#include <GL/glut.h>

// Variabel untuk menyimpan sudut rotasi
static int shoulder = 0, elbow = 0, wrist = 0;
static int fingers[5] = {0, 0, 0, 0, 0};  // Rotasi jari-jari
static int knuckles[5] = {0, 0, 0, 0, 0}; // Rotasi buku-buku jari

// Konstanta untuk ukuran dan posisi
const float FINGER_LENGTH = 0.4;
const float KNUCKLE_LENGTH = 0.3;
const float FINGER_OFFSET = 0.2;

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0); // Set background color to black
    glShadeModel(GL_FLAT);            // Set shading model to flat
}

// Fungsi untuk menggambar satu jari
void drawFinger(float xOffset, int fingerIndex) {
    glPushMatrix();
    glTranslatef(xOffset, 0.1, 0.3); // Posisi jari relatif terhadap telapak tangan

    // Rotasi dan translasi untuk jari
    glRotatef((GLfloat) fingers[fingerIndex], 0.0, 0.0, 1.0);
    glTranslatef(FINGER_OFFSET, 0.0, 0.0);
    glPushMatrix();
    glScalef(FINGER_LENGTH, 0.1, 0.1); // Skala untuk jari
    glutWireCube(1.0);                 // Gambar jari
    glPopMatrix();

    // Rotasi dan translasi untuk buku jari
    glTranslatef(FINGER_LENGTH / 2, 0.0, 0.0);
    glRotatef((GLfloat) knuckles[fingerIndex], 0.0, 0.0, 1.0);
    glTranslatef(FINGER_OFFSET, 0.0, 0.0);
    glPushMatrix();
    glScalef(KNUCKLE_LENGTH, 0.1, 0.1); // Skala untuk buku jari
    glutWireCube(1.0);                  // Gambar buku jari
    glPopMatrix();

    glPopMatrix();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer
    glPushMatrix();

    // Shoulder (Bahu)
    glTranslatef(-1.0, 0.0, 0.0); // Posisi bahu
    glRotatef((GLfloat) shoulder, 0.0, 0.0, 1.0); // Rotasi bahu
    glTranslatef(1.0, 0.0, 0.0);

    glPushMatrix();
    glScalef(2.0, 0.4, 1.0); // Skala untuk bahu
    glutWireCube(1.0);       // Gambar bahu
    glPopMatrix();

    // Elbow (Siku)
    glTranslatef(1.0, 0.0, 0.0); // Posisi siku
    glRotatef((GLfloat) elbow, 0.0, 0.0, 1.0); // Rotasi siku
    glTranslatef(1.0, 0.0, 0.0);

    glPushMatrix();
    glScalef(2.0, 0.4, 1.0); // Skala untuk siku
    glutWireCube(1.0);       // Gambar siku
    glPopMatrix();

    // Wrist (Pergelangan Tangan)
    glTranslatef(1.0, 0.0, 0.0); // Posisi pergelangan tangan
    glRotatef((GLfloat) wrist, 0.0, 0.0, 1.0); // Rotasi pergelangan tangan
    glTranslatef(0.5, 0.0, 0.0);

    glPushMatrix();
    glScalef(1.0, 0.3, 0.8); // Skala untuk pergelangan tangan
    glutWireCube(1.0);       // Gambar pergelangan tangan
    glPopMatrix();

    // Fingers (Jari-jari)
    drawFinger(0.4, 0); // Jari 1
    drawFinger(0.2, 1); // Jari 2
    drawFinger(0.0, 2); // Jari 3
    drawFinger(-0.2, 3); // Jari 4
    drawFinger(-0.4, 4); // Jari 5

    glPopMatrix();
    glutSwapBuffers(); // Swap buffers for smooth animation
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h); // Set viewport
    glMatrixMode(GL_PROJECTION);                // Set projection matrix
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat) w / (GLfloat) h, 1.0, 20.0); // Set perspective
    glMatrixMode(GL_MODELVIEW);                 // Set modelview matrix
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0); // Posisi kamera
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        // Rotasi bahu
        case 'a': shoulder = (shoulder + 5) % 360; break;
        case 'A': shoulder = (shoulder - 5) % 360; break;

        // Rotasi siku
        case 's': elbow = (elbow + 5) % 360; break;
        case 'S': elbow = (elbow - 5) % 360; break;

        // Rotasi pergelangan tangan
        case 'd': wrist = (wrist + 5) % 360; break;
        case 'D': wrist = (wrist - 5) % 360; break;

        // Rotasi jari-jari
        case '1': fingers[0] = (fingers[0] + 5) % 360; break;
        case '!': fingers[0] = (fingers[0] - 5) % 360; break;
        case '2': fingers[1] = (fingers[1] + 5) % 360; break;
        case '@': fingers[1] = (fingers[1] - 5) % 360; break;
        case '3': fingers[2] = (fingers[2] + 5) % 360; break;
        case '#': fingers[2] = (fingers[2] - 5) % 360; break;
        case '4': fingers[3] = (fingers[3] + 5) % 360; break;
        case '$': fingers[3] = (fingers[3] - 5) % 360; break;
        case '5': fingers[4] = (fingers[4] + 5) % 360; break;
        case '%': fingers[4] = (fingers[4] - 5) % 360; break;

        // Rotasi buku-buku jari
        case 'q': knuckles[0] = (knuckles[0] + 5) % 360; break;
        case 'Q': knuckles[0] = (knuckles[0] - 5) % 360; break;
        case 'w': knuckles[1] = (knuckles[1] + 5) % 360; break;
        case 'W': knuckles[1] = (knuckles[1] - 5) % 360; break;
        case 'e': knuckles[2] = (knuckles[2] + 5) % 360; break;
        case 'E': knuckles[2] = (knuckles[2] - 5) % 360; break;
        case 'r': knuckles[3] = (knuckles[3] + 5) % 360; break;
        case 'R': knuckles[3] = (knuckles[3] - 5) % 360; break;
        case 't': knuckles[4] = (knuckles[4] + 5) % 360; break;
        case 'T': knuckles[4] = (knuckles[4] - 5) % 360; break;

        // Keluar dari program
        case 27: exit(0); break;
        default: break;
    }
    glutPostRedisplay(); // Memanggil ulang tampilan setelah perubahan
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); // Inisialisasi GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // Set display mode
    glutInitWindowSize(700, 600); // Set ukuran window
    glutInitWindowPosition(100, 100); // Set posisi window
    glutCreateWindow(argv[0]); // Buat window dengan nama program
    init(); // Panggil fungsi inisialisasi
    glutDisplayFunc(display); // Set fungsi display
    glutReshapeFunc(reshape); // Set fungsi reshape
    glutKeyboardFunc(keyboard); // Set fungsi keyboard
    glutMainLoop(); // Masuk ke loop utama GLUT
    return 0;
}
