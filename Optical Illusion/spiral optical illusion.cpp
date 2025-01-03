#include <GL/glut.h>
#include <cmath>

float angle = 0.0;
float radiusIncrement = 0.5;
int width = 800, height = 600; // Default window size

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Move to the center of the screen
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, 0.0f);

    glLineWidth(2);

    glBegin(GL_LINE_STRIP);

    float radius = 0.0;
    for (int i = 0; i < 1000; ++i) {
        float x = radius * cos(angle);
        float y = radius * sin(angle);

        // Set color based on angle (for the color cycling effect)
        glColor3f(0.5 + 0.5 * sin(angle), 0.5 + 0.5 * cos(angle), 1.0);

        glVertex2f(x, y);

        radius += radiusIncrement;
        angle += M_PI / 180.0f * 5.0f; // Adjust angle increment for spiral density
    }

    glEnd();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    width = w;
    height = h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Set the correct aspect ratio and view size for the window
    glOrtho(-w / 2.0, w / 2.0, -h / 2.0, h / 2.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

void idle() {
    angle += 0.05f; // Adjust speed of spiral movement
    glutPostRedisplay(); // Redraw the scene
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutCreateWindow("Infinite Spiral Optical Illusion");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);

    glutMainLoop();

    return 0;
}
