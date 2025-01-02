# Sierpinski Triangle Fractal Pattern

This project demonstrates the drawing of a **Sierpinski Triangle** using recursion and the ability to zoom into the fractal pattern on the screen. The program uses **OpenGL** and **GLUT** for graphical rendering and event handling.

## Overview

The **Sierpinski Triangle** is a fractal that is formed by recursively subdividing an equilateral triangle into smaller triangles. It is a well-known example of a self-replicating geometric structure, and its recursive nature allows for the generation of intricate and detailed patterns at various levels of depth.

In this implementation:
- The triangle is drawn recursively, with each level dividing the previous triangles into three smaller ones.
- The user can zoom into the fractal pattern by double-clicking on the screen. This zoom effect is achieved by adjusting the view boundaries.

## Features
- **Sierpinski Triangle** is drawn using recursion.
- **Double-Click Zoom-In**: The user can zoom into the fractal by double-clicking on the screen.
- **Interactive Rendering**: The program continuously re-renders the fractal at different zoom levels based on user input.
- **OpenGL and GLUT**: The program utilizes OpenGL for rendering and GLUT for managing the graphical window and handling user input.

## How It Works

### Sierpinski Triangle Algorithm

The Sierpinski Triangle is created through recursion, where an equilateral triangle is repeatedly divided into three smaller triangles. The algorithm works as follows:

1. The base case of the recursion draws a triangle.
2. For higher levels of recursion:
   - Find the midpoints of the sides of the current triangle.
   - Subdivide the current triangle into three smaller triangles by connecting these midpoints.
   - Recursively apply the same process to the smaller triangles.

In the code, the `sierpinski()` function is responsible for recursively drawing the triangle at various depths. The `drawTriangle()` function is used to draw a simple triangle using OpenGL's `GL_TRIANGLES` primitive.

### Double-Click Zoom-In

To zoom in on the fractal:
1. The program detects a **double-click** using the mouse callback function (`mouse()`).
2. If a double-click is detected (based on a time threshold), the program calculates the new boundaries for the view to zoom in. The `SCALE_FACTOR` is used to determine how much to zoom in.
3. The view boundaries are adjusted (`leftco`, `rightco`, `top`, `bottom`), and the screen is re-rendered at the new zoomed-in level.

The zoom effect is achieved by shrinking the current view boundaries, which makes the fractal appear larger in the window.

### Code Walkthrough

1. **Global Variables**:
   - `SCALE_FACTOR`: The factor by which the view zooms in during each double-click.
   - `leftco`, `rightco`, `top`, `bottom`: Define the boundaries of the visible region for rendering the triangle.
   - `LAST_CLICK_TIME`: Tracks the time of the last mouse click to detect double-clicks.
   - `DOUBLE_CLICK_THRESHOLD`: The time threshold in milliseconds for detecting a double-click.

2. **`drawTriangle()`**:
   - This function draws a simple triangle using OpenGL's `glBegin(GL_TRIANGLES)` and `glVertex2f()`.

3. **`sierpinski()`**:
   - This function is the heart of the recursion. It draws the Sierpinski Triangle by recursively subdividing each triangle into smaller ones. The depth of recursion determines how many levels of detail the fractal will have.

4. **`mouse()`**:
   - Handles mouse clicks to detect double-clicks. When a double-click is detected, the view is zoomed in by adjusting the boundaries (`leftco`, `rightco`, `top`, `bottom`), and the screen is re-rendered.

5. **`display()`**:
   - Clears the screen and renders the Sierpinski Triangle with the current view boundaries. It calls the `sierpinski()` function with the updated boundaries to draw the fractal at the current zoom level.

6. **`main()`**:
   - Initializes GLUT and OpenGL settings, including window size, display mode, and projection matrix. It then enters the GLUT main loop, where rendering and user input are continuously processed.
   
## Media

Here are some images showcasing the Sierpinski Triangle fractal pattern:

### Sierpinski Triangle Set Example 1:
![Sierpinski Triangle Example 1](https://github.com/Kangaeruhito14/Some-Special-Code/blob/main/Sierpinski%20Triangle/Media/Sierpinski%20Triangle.png)

### Sierpinski Triangle Set Animation (GIF):
![Sierpinski Triangle Set Animation](https://github.com/Kangaeruhito14/Some-Special-Code/blob/main/Sierpinski%20Triangle/Media/Sierpinski%20Triangle%20Works.gif)

## Requirements

To run this project, you need the following:

- **GLUT Library** (for OpenGL functionality)
- **C++ Compiler** (with support for C++11 or later)
- **Threading Support** (for multi-threading)

## How to Run

1. **Clone the Repository:**
   Clone this repository using the following command:
   ```bash
   git clone https://github.com/Kangaeruhito14/Some-Special-Code.git

2. **Compile the Code:**
   If you have the required libraries installed, compile the code using a C++ compiler. You may need to link the GLUT library during the compilation. For Windows, install MinGW or Visual Studio. For Mac, ensure you have Xcode and its command-line tools installed.

   Example compilation command (on Linux):
   ```bash
   g++ -o sierpinski sierpinski.cpp -lGL -lGLU -lglut -lpthread
   ```

   Example compilation command (on Windows):
   ```bash
   g++ -o sierpinski sierpinski.cpp -lfreeglut -lopengl32 -lglu32 -lpthread
   ```
   
   Example compilation command (on Mac):
   ```bash
   g++ -o sierpinski sierpinski.cpp -framework OpenGL -framework GLUT -lpthread
   ```
3. **After Compilation:**
   If you successfully compile and run the code, then "Double-Click" on your compiler to zoom in.
