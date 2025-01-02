# Mandelbrot Fractal Viewer

This project is an interactive Mandelbrot set viewer that allows you to explore the beauty of fractals. It uses OpenGL for rendering the fractal on the screen, with multi-threading to optimize performance and a zoom-in feature for a more detailed exploration of the Mandelbrot set. By clicking on the screen, users can zoom into a particular area of the Mandelbrot set, making it easy to explore infinite patterns and structures.

## Overview

The **Mandelbrot Effect** refers to the stunning, intricate patterns that emerge from the **Mandelbrot set**, a famous fractal in mathematics. The Mandelbrot set is a set of complex numbers that generates self-similar, infinitely repeating structures as you zoom in. The set showcases how simple mathematical iterations can lead to complex, infinite structures.

In this project, the **Mandelbrot Effect** is visualized through OpenGL, allowing for real-time exploration of the fractal. The program supports interactive zooming and multi-threading to enhance performance while rendering the fractal.

## Features

- **Interactive Zooming:** Zoom into any part of the Mandelbrot set by clicking on the screen.
- **Smooth Coloring:** A smooth coloring technique is used to enhance the aesthetic quality of the fractal visualization.
- **Multi-threading:** The program uses multi-threading to compute the fractal in parallel, speeding up the rendering process.
- **Real-time Rendering:** The fractal is drawn in real time, allowing you to explore the set as you zoom in.

## How It Works

1. **Initialization and Setup:**
   - The program defines the size of the window and sets up the pixel matrix that stores the color values of the Mandelbrot set.
   - The region of the complex plane to visualize is specified by the variables `left`, `right`, `top`, and `bottom`.

2. **Mandelbrot Set Computation:**
   - For each pixel on the screen, the program maps it to a corresponding point on the complex plane and iterates through the Mandelbrot function.
   - Based on the number of iterations it takes for a point to escape to infinity, the program assigns a color to each pixel, resulting in a colorful, fractal pattern.

3. **Multi-threading for Optimization:**
   - To speed up the rendering process, the program uses multi-threading to divide the task of computing the Mandelbrot set into smaller chunks. This allows multiple sections of the image to be processed simultaneously.

4. **Zoom Functionality:**
   - The user can click on the screen to zoom into a specific area of the Mandelbrot set. The program adjusts the boundaries of the fractal and recomputes the set, providing a deeper view of the fractal structure.
   - The zoom-in factor is controlled by the `SCALE_FACTOR` variable, which determines how much the image zooms in.

## Media

Here are some images showcasing the Mandelbrot fractal effect:

### Mandelbrot Set Example 1:
![Mandelbrot Example 1](https://github.com/Kangaeruhito14/Some-Special-Code/blob/main/Mandelbrot%20Effect/Media/Mandelbrot%20Effect%20-%2001.png)

### Mandelbrot Set Example 2:
![Mandelbrot Example 2](https://github.com/Kangaeruhito14/Some-Special-Code/blob/main/Mandelbrot%20Effect/Media/Mandelbrot%20Effect%20-%2002.png)

### Mandelbrot Set Example 3:
![Mandelbrot Example 3](https://github.com/Kangaeruhito14/Some-Special-Code/blob/main/Mandelbrot%20Effect/Media/Mandelbrot%20Effect%20-%2003.png)

### Mandelbrot Set Animation (GIF):
![Mandelbrot Set Animation](https://github.com/Kangaeruhito14/Some-Special-Code/blob/main/Mandelbrot%20Effect/Media/Mandelbrot%20Effect.gif)

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
   g++ -o mandelbrot mandelbrot.cpp -lGL -lGLU -lglut -lpthread
   ```

   Example compilation command (on Windows):
   ```bash
   g++ -o mandelbrot mandelbrot.cpp -lfreeglut -lopengl32 -lglu32 -lpthread
   ```
   
   Example compilation command (on Mac):
   ```bash
   g++ -o mandelbrot mandelbrot.cpp -framework OpenGL -framework GLUT -lpthread
   ```
3. **After Compilation:**
   If you successfully compile and run the code, then "Double-Click" on your compiler where you want to zoom in.
