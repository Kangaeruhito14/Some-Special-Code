#include <GL/glut.h>
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

const int width = 1200;
const int height = 900;

// Scale and translation factors
float SCALE_FACTOR = 1.03;  // Initial zoom-in factor (values greater than 1 zoom in)
float leftco = -1.0, rightco = 1.0, top = 1.0, bottom = -1.0;  // View boundaries

// Mouse double-click detection variables
auto LAST_CLICK_TIME = steady_clock::now();
const int DOUBLE_CLICK_THRESHOLD = 3000; // Time threshold for double-click detection (in milliseconds)

void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3) {
    glBegin(GL_TRIANGLES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}

void sierpinski(float x1, float y1, float x2, float y2, float x3, float y3, double depth) {
    if (depth == 0) {
        drawTriangle(x1, y1, x2, y2, x3, y3);
    } else {
        float mid1_x = (x1 + x2) / 2;
        float mid1_y = (y1 + y2) / 2;

        float mid2_x = (x2 + x3) / 2;
        float mid2_y = (y2 + y3) / 2;

        float mid3_x = (x1 + x3) / 2;
        float mid3_y = (y1 + y3) / 2;

        sierpinski(x1, y1, mid1_x, mid1_y, mid3_x, mid3_y, depth - 1);
        sierpinski(mid1_x, mid1_y, x2, y2, mid2_x, mid2_y, depth - 1);
        sierpinski(mid3_x, mid3_y, mid2_x, mid2_y, x3, y3, depth - 1);
    }
}

// Handle mouse clicks for manual zooming (double-click zoom)
void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        auto currentTime = steady_clock::now();
        int elapsedTime = duration_cast<milliseconds>(currentTime - LAST_CLICK_TIME).count();

        // If the time between two clicks is less than the threshold, it's a double-click
        if (elapsedTime <= DOUBLE_CLICK_THRESHOLD) {
            // Perform zoom-in on double-click
            float dx = rightco - leftco;
            float dy = top - bottom;

            float new_center_x = (leftco + rightco) / 2;
            float new_center_y = (bottom + top) / 2;

            // Adjusting delta_x and delta_y for zooming (shrink boundaries)
            float new_delta_x = dx * SCALE_FACTOR;
            float new_delta_y = dy * SCALE_FACTOR;

            // Update view boundaries based on zooming in (making the view smaller)
            leftco = new_center_x - (new_delta_x / 2.0);
            rightco = new_center_x + (new_delta_x / 2.0);
            bottom = new_center_y - (new_delta_y / 2.0);
            top = new_center_y + (new_delta_y / 2.0);

            glutPostRedisplay();
        }

        // Update the last click time
        LAST_CLICK_TIME = currentTime;
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Draw the Sierpinski triangle
    sierpinski(leftco, bottom, rightco, bottom, 0.0f, top, 11.00);  // Depth of recursion is 11
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(width, height);
    glutCreateWindow("Double Click Zoom In Sierpinski Triangle");

    glClearColor(0.1f, 0.15f, 0.35f, 0.4f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, 0.0, height, -1.0, 1.0);  // Setting up orthogonal view

    // Register display handler
    glutDisplayFunc(display);

    // Register mouse callback function
    glutMouseFunc(mouse);

    // Enter GLUT main loop
    glutMainLoop();
    return 0;
}
