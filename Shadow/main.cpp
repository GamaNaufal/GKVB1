#include <math.h>
#include <stdio.h>
#include <GL/glut.h>

double rx = 0.0;
double ry = 0.0;
double rz = 25.0; // Rotasi awal untuk memiringkan donat lebih jelas

float l[] = { 50.0, 100.0, 50.0 }; // Posisi sumber cahaya
float n[] = { 0.0, -40.0, 0.0 };
float e[] = { 0.0, -60.0, 0.0 };

void help();

// Obyek donat
void draw()
{
    // Material properties untuk donat coklat muda
    GLfloat brown_diffuse[] = {0.7f, 0.5f, 0.3f, 1.0f};
    GLfloat brown_specular[] = {0.3f, 0.2f, 0.1f, 1.0f};
    GLfloat brown_shininess = 32.0f;
    
    glMaterialfv(GL_FRONT, GL_DIFFUSE, brown_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, brown_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, brown_shininess);
    
    glutSolidTorus(15, 30, 32, 32); // Donat lebih halus
}

void glShadowProjection(float * l, float * e, float * n)
{
    float d, c;
    float mat[16];

    d = n[0]*l[0] + n[1]*l[1] + n[2]*l[2];
    c = e[0]*n[0] + e[1]*n[1] + e[2]*n[2] - d;

    mat[0] = l[0]*n[0]+c;
    mat[4] = n[1]*l[0];
    mat[8] = n[2]*l[0];
    mat[12] = -l[0]*c-l[0]*d;

    mat[1] = n[0]*l[1];
    mat[5] = l[1]*n[1]+c;
    mat[9] = n[2]*l[1];
    mat[13] = -l[1]*c-l[1]*d;

    mat[2] = n[0]*l[2];
    mat[6] = n[1]*l[2];
    mat[10] = l[2]*n[2]+c;
    mat[14] = -l[2]*c-l[2]*d;

    mat[3] = n[0];
    mat[7] = n[1];
    mat[11] = n[2];
    mat[15] = -d;

    glMultMatrixf(mat);
}

void render()
{
    glClearColor(0.9f, 0.9f, 1.0f, 1.0f); // Background biru muda
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLightfv(GL_LIGHT0, GL_POSITION, l);
    glDisable(GL_CULL_FACE);
    glDisable(GL_LIGHTING);
    glColor3f(1.0, 1.0, 0.0);

    // Gambar sumber cahaya sebagai titik kuning
    glPointSize(8.0);
    glBegin(GL_POINTS);
    glVertex3f(l[0], l[1], l[2]);
    glEnd();
    glPointSize(1.0);

    // Gambar lantai warna krem
    glColor3f(0.96f, 0.87f, 0.7f);
    glBegin(GL_QUADS);
    glNormal3f(0.0, 1.0, 0.0);
    glVertex3f(-300.0, e[1]-0.1, 300.0);
    glVertex3f( 300.0, e[1]-0.1, 300.0);
    glVertex3f( 300.0, e[1]-0.1, -300.0);
    glVertex3f(-300.0, e[1]-0.1, -300.0);
    glEnd();

    // Gambar donat utama
    glPushMatrix();
    glRotatef(ry, 0, 1, 0);  // Rotasi Y (horizontal)
    glRotatef(rx, 1, 0, 0);  // Rotasi X (vertikal)
    glRotatef(rz, 0, 0, 1);   // Rotasi Z (miringkan donat)
    glEnable(GL_LIGHTING);
    draw();
    glPopMatrix();

    // Gambar bayangan
    glPushMatrix();
    glShadowProjection(l, e, n);
    glRotatef(ry, 0, 1, 0);
    glRotatef(rx, 1, 0, 0);
    glRotatef(rz, 0, 0, 1);   // Miringkan bayangan sama seperti donat
    glDisable(GL_LIGHTING);
    glColor3f(0.25f, 0.25f, 0.25f); // Bayangan lebih gelap
    draw();
    glPopMatrix();
    
    glutSwapBuffers();
}

void keypress(unsigned char c, int a, int b)
{
    if (c == 27) exit(0); // ESC untuk keluar
    else if (c == 's') l[1] -= 5.0; // Cahaya turun
    else if (c == 'w') l[1] += 5.0; // Cahaya naik
    else if (c == 'a') l[0] -= 5.0; // Cahaya kiri
    else if (c == 'd') l[0] += 5.0; // Cahaya kanan
    else if (c == 'q') l[2] -= 5.0; // Cahaya mundur
    else if (c == 'e') l[2] += 5.0; // Cahaya maju
    else if (c == 'h') help();      // Tampilkan help
    else if (c == '1') rx += 5.0;  // Rotasi X
    else if (c == '2') ry += 5.0;  // Rotasi Y
    else if (c == '3') rz += 5.0;  // Rotasi Z (miringkan)
    else if (c == 'r') { rx = 0; ry = 0; rz = 25; } // Reset rotasi
    
    render();
}

void help()
{
    printf("\n=== KONTROL DONAT COKLAT ===\n");
    printf("w/s   : Naik/turunkan cahaya\n");
    printf("a/d   : Geser cahaya kiri/kanan\n");
    printf("q/e   : Geser cahaya depan/belakang\n");
    printf("1/2/3 : Rotasi donat (sumbu X/Y/Z)\n");
    printf("r     : Reset rotasi ke posisi awal\n");
    printf("h     : Tampilkan bantuan ini\n");
    printf("ESC   : Keluar dari program\n\n");
}

void idle()
{
    // Kosongkan - tidak ada rotasi otomatis
    render();
}

void resize(int w, int h)
{
    glViewport(0, 0, w, h);
}

int main(int argc, char * argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(300, 30);
    glutCreateWindow("Donat Coklat Pak Budi");
    glutReshapeFunc(resize);
    glutReshapeWindow(800, 600);
    glutKeyboardFunc(keypress);
    glutDisplayFunc(render);
    glutIdleFunc(idle);

    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    
    // Setup pencahayaan
    GLfloat lightAmbient[] = {0.3f, 0.3f, 0.3f, 1.0f};
    GLfloat lightDiffuse[] = {0.9f, 0.9f, 0.9f, 1.0f};
    GLfloat lightSpecular[] = {1.0f, 1.0f, 1.0f, 1.0f};
    
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, 800.0/600.0, 1.0, 500.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 50, 200, 0, 0, 0, 0, 1, 0);

    help(); // Tampilkan petunjuk
    
    glutMainLoop();
    return 0;
}
