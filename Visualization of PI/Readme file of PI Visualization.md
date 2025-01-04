# Visualization of Pi by Drawing a Circle

## **Overview**

This project visualizes the mathematical constant **π (pi)** by drawing a circle using OpenGL. The visualization demonstrates how π relates to rotations by simulating the rotation of two lines around a center point. As the outer line rotates **π times** around the center, it traces the circular path, illustrating the geometric interpretation of π.

## **Features**

- **Geometric Visualization of Pi:** Illustrates the concept of π through rotational motion of lines.
- **Smooth Animation:** Real-time drawing of the traced circle as the outer line rotates, showing the progression.
- **Adjustable Speed:** The animation can be sped up or slowed down to suit the user’s needs.
- **Educational Tool:** Helps in understanding the abstract concept of π by visualizing its connection to circular motion.

## **How It Works**

1. **Center and Outer Rotation:** The center line rotates around a fixed point, while a second outer line rotates **π times** faster, tracing the circular path.
2. **Point Plotting:** Each point traced by the outer line is recorded and drawn on the canvas, forming the circle over time.
3. **Real-Time Update:** Using OpenGL’s timer and display functions, the circle is drawn in real-time with high density for a smooth visual.

## **Functionalities**

- **Dynamic Circle Drawing:** The outer line progressively traces the circle while rotating around the center.
- **Smooth Path Tracing:** High-density points are used to ensure the path remains smooth, even at higher drawing speeds.
- **Real-Time Updates:** The animation continues to update, allowing for continuous drawing of the circle.
- **Color-Coded Lines:** The center line is red, and the outer tracing line is blue, making it easy to differentiate between the two.

## **Key Variables**

- **centerAngle and outerAngle:** Angles used to calculate the positions of the center and outer lines.
- **tracedPoints:** Stores the coordinates of the traced circle path, which is then drawn on the screen.

## Media

Here are some images showcasing the visualization of PI:

### PI Visualization Set Example 1:
![PI Visualization Example 1](https://github.com/Kangaeruhito14/Some-Special-Code/blob/main/Visualization%20of%20PI/Media/Visualization%20of%20PI.png)

### PI Visualization Set Animation (GIF):
![PI Visualization Set Animation](https://github.com/Kangaeruhito14/Some-Special-Code/blob/main/Visualization%20of%20PI/Media/Visualization%20of%20PI.gif)

## **Installation**
- OpenGL libraries and GLUT (GL Utility Toolkit) for rendering and window management.
- A C++ compiler (e.g., g++) for compiling the code.

## How to Run

1. **Clone the Repository:**
   Clone this repository using the following command:
   ```bash
   git clone https://github.com/Kangaeruhito14/Some-Special-Code.git

2. **Compile the Code:**
   If you have the required libraries installed, compile the code using a C++ compiler. You may need to link the GLUT library during the compilation. For Windows, install MinGW or Visual Studio. For Mac, ensure you have Xcode and its command-line tools installed.

   Example compilation command (on Linux):
   ```bash
   g++ -o PI_visualization PI_visualization.cpp -lGL -lGLU -lglut -lpthread
   ```

   Example compilation command (on Windows):
   ```bash
   g++ -o PI_visualization PI_visualization.cpp -lfreeglut -lopengl32 -lglu32 -lpthread
   ```
   
   Example compilation command (on Mac):
   ```bash
   g++ -o PI_visualization PI_visualization.cpp -framework OpenGL -framework GLUT -lpthread
   ```
