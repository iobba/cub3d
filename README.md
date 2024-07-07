# CUB3D

![cub3D Demo](https://github.com/iobba/cub3d/blob/master/VID-20230416-WA0001-ezgif.com-video-to-gif-converter.gif)

## About cub3D

cub3D aims to create an immersive maze exploration experience using the miniLibX library for graphical output. It includes features such as textured walls, floor and ceiling colors, player movement controls, and scene parsing from a configuration file (.cub).

## Key Features

- **Ray-Casting**: Implements Ray-Casting to render 3D visuals from a 2D map.
- **Textures**: Displays different wall textures based on the orientation (North, South, East, West).
- **Smooth Window Management**: Ensures seamless window interactions like switching and minimizing.
- **Controls**:
  - Arrow keys: Look left and right.
  - W, A, S, D keys: Move forward, backward, strafe left, and strafe right.
  - ESC key or window close button: Exit the program cleanly.
- **Scene Configuration**: Reads scene details from a .cub file, including textures paths, floor and ceiling colors, and map layout.
- **Error Handling**: Detects and gracefully handles misconfigurations in the .cub file, exiting with specific error messages.

## Bonus Features

- **Wall Collisions**: Implements collision detection with walls.
- **Minimap System**: Displays a minimap for navigation.
- **Interactive Elements**: Includes doors that can open and close.
- **Animated Sprites**: Adds animated sprites for enhanced visuals.
- **Mouse Control**: Allows rotating the viewpoint using the mouse.

## Installation and Usage

To compile and run cub3D, follow these steps:

1. **Clone the Repository**:
    ```sh
    git clone git@github.com:iobba/cub3d.git
    cd cub3D
    ```

2. **Compile the Program**:
    ```sh
    make
    ```

3. **Run cub3D**:
    ```sh
    ./cub3D path_to_map.cub
    ```
