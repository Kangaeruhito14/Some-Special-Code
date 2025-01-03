# Spiral Optical Illusion

## Overview
The **Spiral Optical Illusion** is a dynamic graphical effect that simulates the movement of an infinite spiral. The spiral appears to be continuously expanding and rotating in such a way that it creates a visual illusion of motion. This illusion is created by rendering a series of increasingly larger points (lines) in a spiral pattern, with colors cycling along the path, giving the viewer the impression of an animated and endless motion.

This project is built using **OpenGL** and **GLUT** to create the spiral effect, and it involves manipulating geometric properties such as angles, radii, and colors to generate the illusion.

## Features
- **Spiral Path**: A dynamic spiral that continually grows outward.
- **Color Cycling**: The color of the spiral changes as the angle increases, creating a visually appealing and smooth transition.
- **Smooth Animation**: Continuous motion is created by adjusting the angle and radius incrementally, making the spiral appear to move infinitely.
- **Adjustable Parameters**: The density and speed of the spiral can be modified by changing the parameters in the code.

## How it Works
This optical illusion effect is based on drawing a series of connected points that form a spiral. The process includes the following key steps:

1. **Initialization**:
    - The OpenGL window is initialized with a default size and color setup.
    - The `glOrtho` projection is used to ensure proper scaling and aspect ratio for the window.
  
2. **Spiral Drawing**:
    - The spiral is created by incrementally increasing the radius (`radiusIncrement`) and angle (`angle`) while calculating the (x, y) coordinates for each point along the spiral.
    - The `cos(angle)` and `sin(angle)` functions are used to convert the angle into Cartesian coordinates, which are then scaled by the radius.
  
3. **Color Cycling**:
    - The color of the points along the spiral changes based on the current angle. This is achieved by using the `sin` and `cos` functions to cycle through different color values.
  
4. **Animation**:
    - The `idle` function continuously increments the `angle`, causing the spiral to animate and rotate over time.
    - The window is constantly updated using `glutPostRedisplay()` to create the appearance of a dynamic, rotating spiral.

5. **User Interaction**:
    - The window can be resized, and the projection matrix is adjusted accordingly to maintain the correct aspect ratio.
    
## Media

Here is a gif file showcasing the Spiral Optical Illusion pattern:

### Optical Illusion Set Animation (GIF):
![Optical Illusion Set Animation](https://github.com/Kangaeruhito14/Some-Special-Code/blob/main/Optical%20Illusion/Media/Optical%20Illusion%20Pattern.gif)


### Key Functions:
- **display()**: Draws the spiral path by calculating (x, y) positions based on the radius and angle, then cycles through colors.
- **reshape()**: Adjusts the view based on window resizing to maintain the correct aspect ratio.
- **idle()**: Continuously updates the angle to animate the spiral.
  
### How to Run:
1. **Clone the Repository:**
   Clone this repository using the following command:
   ```bash
   git clone https://github.com/Kangaeruhito14/Some-Special-Code.git

2. **Compile the Code:**
   If you have the required libraries installed, compile the code using a C++ compiler. You may need to link the GLUT library during the compilation. For Windows, install MinGW or Visual Studio. For Mac, ensure you have Xcode and its command-line tools installed.

   Example compilation command (on Linux):
   ```bash
   g++ -o illusion illusion.cpp -lGL -lGLU -lglut -lpthread
   ```

   Example compilation command (on Windows):
   ```bash
   g++ -o illusion illusion.cpp -lfreeglut -lopengl32 -lglu32 -lpthread
   ```
   
   Example compilation command (on Mac):
   ```bash
   g++ -o illusion illusion.cpp -framework OpenGL -framework GLUT -lpthread
   ```
3. The program will open a window showing the animated spiral optical illusion.
