#include <GL/glut.h>
#include <cmath>
#include <vector>

#define PI 3.14159265358979323846
using namespace std;

// Variables for rotation
float centerAngle = 0.0f;  // Rotation angle of the center line
float outerAngle = 0.0f;   // Rotation angle of the outer line

// Vector to store the traced points of the circle
vector<pair<float, float>> tracedPoints;

// Function to draw the traced circle
void drawTracedCircle() {
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f);  // White color for the traced path
    for (const auto& point : tracedPoints) {
        glVertex2f(point.first, point.second);
    }
    glEnd();
}

// Display callback function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Draw the traced circle
    drawTracedCircle();

    // Draw the center line
    float centerX = 0.0f, centerY = 0.0f;  // Starting point of the center line
    float endX = cos(centerAngle) * 0.5f;  // Rotating endpoint (scaled for smaller circle)
    float endY = sin(centerAngle) * 0.5f;
    glColor3f(1.0f, 0.0f, 0.0f);  // Red color for center line
    glBegin(GL_LINES);
    glVertex2f(centerX, centerY);
    glVertex2f(endX, endY);
    glEnd();

    // Calculate the outer line's endpoint
    float outerEndX = endX + cos(outerAngle) * 0.25f;  // Shorter outer line
    float outerEndY = endY + sin(outerAngle) * 0.25f;

    // Add the outer line's endpoint to the traced path
    tracedPoints.emplace_back(outerEndX, outerEndY);

    // Draw the outer line
    glColor3f(0.0f, 0.0f, 1.0f);  // Blue color for outer line
    glBegin(GL_LINES);
    glVertex2f(endX, endY);
    glVertex2f(outerEndX, outerEndY);
    glEnd();

    glutSwapBuffers();
}

// Timer function to update angles
void timer(int value) {
    const int steps = 10;  // Number of intermediate steps per frame
    const float angleIncrement = 0.05f / steps;  // Smaller increments for smoother path

    for (int i = 0; i < steps; ++i) {
        // Increment the center and outer angles in smaller steps
        centerAngle += angleIncrement;
        if (centerAngle >= 2 * PI) centerAngle -= 2 * PI;

        outerAngle += angleIncrement * PI;  // Outer line rotates π times faster
        if (outerAngle >= 2 * PI) outerAngle -= 2 * PI;

        // Calculate the outer line's endpoint
        float endX = cos(centerAngle) * 0.5f;
        float endY = sin(centerAngle) * 0.5f;
        float outerEndX = endX + cos(outerAngle) * 0.25f;
        float outerEndY = endY + sin(outerAngle) * 0.25f;

        // Add the endpoint to the traced path
        tracedPoints.emplace_back(outerEndX, outerEndY);
    }

    glutPostRedisplay();  // Redraw the scene
    glutTimerFunc(16, timer, 0);  // Call timer again after 16 ms
}

// Initialization function
void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // Black background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.5, 1.5, -1.5, 1.5);  // Set coordinate system
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000, 1000);
    glutCreateWindow("Visualizing Pi by Drawing a Circle");

    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}
