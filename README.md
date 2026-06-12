# 2D Graphics Editor (ASCII Graphics in C)

A simple command-line 2D Graphics Editor written in C that allows users to draw and manipulate basic geometric shapes on a text-based canvas using ASCII characters.

## Features

* Draw Lines
* Draw Rectangles
* Draw Triangles
* Draw Circles
* Delete Areas from the Canvas
* Modify Existing Rectangles
* Display the Current Drawing
* Clear the Canvas
* Interactive Menu-Driven Interface

## Canvas Representation

The editor uses a 2D character array as its drawing canvas.

```c
char canvas[ROWS][COLS];
```

* `*` represents drawn pixels.
* `_` represents empty space.
* Canvas Size: **30 Rows × 60 Columns**

### Coordinate System

* `x` → Row Index (0 to 29)
* `y` → Column Index (0 to 59)

## Technologies Used

* C Programming Language
* Standard Libraries:

  * stdio.h
  * stdlib.h
  * math.h

## Project Structure

```text
2d-graphics-editor/
├── R25EJ040.c      # Main source code
├── README.md       # Project documentation
└── LICENSE         # License file (optional)
```

## How to Compile and Run

### Compile

```bash
gcc R25EJ040.c -o graphics_editor -lm
```

### Run

Linux/macOS:

```bash
./graphics_editor
```

Windows:

```bash
graphics_editor.exe
```

## Menu Options

```text
===== 2D GRAPHICS EDITOR =====

1. Draw Line
2. Draw Rectangle
3. Draw Triangle
4. Draw Circle
5. Delete Area
6. Modify Rectangle
7. Display Picture
8. Clear Canvas
0. Exit
```

## Usage Examples

### Draw a Line

Input:

```text
1
x1 y1 x2 y2
5 5 5 30
```

### Draw a Rectangle

Input:

```text
2
x y height width
3 10 8 15
```

### Draw a Triangle

Input:

```text
3
x1 y1 x2 y2 x3 y3
5 5 15 25 20 10
```

### Draw a Circle

Input:

```text
4
centerX centerY radius
15 30 8
```

## Sample Workflow

1. Start the application.
2. Draw a rectangle.
3. Add a circle inside it.
4. Display the canvas.
5. Modify the rectangle dimensions.
6. Erase a selected area.
7. Display the updated drawing.
8. Exit the program.

## Implementation Details

### Line Drawing

Uses **Bresenham's Line Drawing Algorithm** for efficient rendering of straight lines.

### Circle Drawing

Uses the **Midpoint Circle Algorithm** to generate circular shapes using symmetry.

### Rectangle Drawing

Constructed using four connected boundaries.

### Triangle Drawing

Created by connecting three vertices using line-drawing operations.

### Canvas Management

* Shapes are rendered directly onto the canvas.
* Drawing occurs by modifying specific positions in the 2D character array.
* Canvas can be cleared and redrawn at any time.

## Learning Outcomes

This project demonstrates:

* Computer Graphics Fundamentals
* ASCII-Based Rendering
* Geometric Shape Construction
* Coordinate Systems
* Array Manipulation in C
* Graphics Algorithms
* Menu-Driven Program Design

## Limitations

* Console-based graphics only
* Fixed canvas size
* No color support
* No object persistence
* No save/load functionality
* Rectangle modification requires manual re-entry of coordinates

## Future Enhancements

* Shape Filling (Solid Shapes)
* Undo/Redo Operations
* Save and Load Drawings
* Dynamic Canvas Resizing
* Color Support
* Shape Selection Using IDs
* Mouse-Based GUI Version
* Export Drawing to Text File

## Author

**Harshil Nair**

B.Tech Computer Science & Information Technology
REVA University, Bengaluru

## License

This project is intended for educational and academic purposes.
