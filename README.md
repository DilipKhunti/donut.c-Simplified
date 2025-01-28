# Donut.c - Simplified Version

This repository contains a C implementation of a 3D spinning donut animation, along with a Python version and an optimized version of the same. The animation is rendered in the terminal using ASCII characters, creating a visually appealing spinning donut effect. The C program has been simplified to its core components to make it easier to understand and learn from.

![](output.gif)

## Table of Contents
1. [Overview](#overview)
2. [How It Works](#how-it-works)
3. [Simplified Explanation](#simplified-explanation)
4. [Repository Structure](#repository-structure)
5. [Getting Started](#getting-started)
6. [Usage](#usage)
7. [Contributing](#contributing)
8. [Credits](#credits)
9. [Additional Information](#additional-information)

---

## Overview

The spinning donut animation is a classic example of rendering a 3D object in a 2D space using ASCII characters. The C program calculates the 3D coordinates of a torus (donut shape), applies rotations, and projects the 3D points onto a 2D plane. The brightness of each point is determined by the surface normal, and the result is displayed in the terminal.

This implementation is intentionally kept simple to focus on the core concepts, making it ideal for learning and experimentation.

---

## How It Works

### Step-by-Step Explanation

1. **Initialization**:
   - The program defines constants for the screen width (`WIDTH`), height (`HEIGHT`), and the spacing between angles (`THETA_SPACING`, `PHI_SPACING`).
   - The radii of the torus (`R1`, `R2`) and the perspective projection constants (`K1`, `K2`) are also defined.

2. **Frame Rendering**:
   - The `render_frame` function is responsible for rendering each frame of the animation.
   - A frame buffer (`frame`) and a z-buffer (`z_buffer`) are initialized to store the ASCII characters and depth information, respectively.

3. **3D Coordinates Calculation**:
   - The program loops through angles `theta` and `phi` to calculate the 3D coordinates of the torus.
   - The coordinates are rotated around the x and y axes using the rotation angles `A` and `B`.

4. **Perspective Projection**:
   - The 3D coordinates are projected onto a 2D plane using perspective projection.
   - The projected coordinates are clamped to the screen bounds.

5. **Brightness Calculation**:
   - The brightness of each point is calculated based on the surface normal and the light source.
   - The brightness index is used to select an appropriate ASCII character from the `LIGHT` gradient.

6. **Frame Display**:
   - The frame buffer is printed to the terminal, creating the spinning donut animation.

7. **Animation Loop**:
   - The `main` function continuously updates the rotation angles `A` and `B` and renders new frames, creating the animation effect.

---

## Simplified Explanation

This program has been simplified to its most basic form to make it easier to understand. Here's how it achieves simplicity while maintaining functionality:

1. **Minimal Code**:
   - The program avoids unnecessary complexity and focuses on the core logic of rendering the donut.
   - Only essential variables and calculations are included.

2. **Straightforward Math**:
   - The 3D transformations and projections are implemented using basic trigonometry and linear algebra.
   - The math is kept as simple as possible, with clear variable names and comments.

3. **No External Dependencies**:
   - The program uses only standard C libraries (`stdio.h`, `stdlib.h`, `math.h`, `string.h`), making it easy to compile and run on any system.

4. **Readable Structure**:
   - The code is organized into logical sections, with comments explaining each step.
   - The `render_frame` function encapsulates the rendering logic, making it easy to follow.

5. **Focus on Learning**:
   - The program is designed to be a learning tool, with simplicity and clarity prioritized over performance or advanced features.

---

## Repository Structure

- `donut.c`: The simplified C implementation of the spinning donut animation.
- `donut.py`: A Python version of the spinning donut animation.
- `optimized_donut.c`: An optimized version of the C implementation.
- `original_donut.c`: An original legacy code of the notorious donut.c.
- `README.md`: This file, containing detailed information about the project.


---

## Getting Started

### Prerequisites

- **C Compiler**: To compile and run the C version, you need a C compiler like `gcc`.
- **Python Interpreter**: To run the Python version, you need Python 3 installed.

### Cloning the Repository

To clone the repository, run the following command:

```bash
git clone https://github.com/DilipKhunti/donut.c-Simplified.git
cd donut.c-Simplified
```

### Compiling and Running the C Version

To compile and run the C version, use the following commands:

```bash
gcc donut.c -o donut -lm
./donut
```

### Running the Python Version

To run the Python version, use the following command:

```bash
python donut.py
```

---

## Usage

- **C Version**: The C version is optimized for simplicity and is ideal for learning and experimentation.
- **Python Version**: The Python version is easier to modify and experiment with, making it ideal for educational purposes.
- **Optimized C Version**: The optimized C version includes improvements for better performance and readability.

---

## Contributing

Contributions are welcome! If you have any improvements, optimizations, or additional features, feel free to open an issue or submit a pull request.

1. Fork the repository.
2. Create a new branch (`git checkout -b feature/YourFeatureName`).
3. Commit your changes (`git commit -m 'Add some feature'`).
4. Push to the branch (`git push origin feature/YourFeatureName`).
5. Open a pull request.

Please ensure that your code is well-documented and follows the existing style.

---

## Credits

This project is inspired by the original article by Andy Sloane, which can be found [here](https://www.a1k0n.net/2011/07/20/donut-math.html).

---

## Additional Information

- **Performance Considerations**: The C version is simplified for clarity, but further optimizations can be made depending on the target platform.
- **Educational Value**: This project is an excellent example of how to render 3D graphics in a 2D space using basic mathematical concepts. It can be used as a learning tool for understanding 3D transformations, perspective projection, and ASCII art rendering.

Feel free to explore the code, experiment with different parameters, and contribute to the project!

---

Enjoy the spinning donut! 🍩