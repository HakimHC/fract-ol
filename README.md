# Fract'ol Project

## Project Description

Fract'ol is a project aimed at exploring fractal mathematics by creating a small fractal exploration program. The main focus of this project is to render the Julia and Mandelbrot fractal sets, allowing the user to zoom in and out to observe the self-similarity inherent in fractals.

## Features

1. **Fractal Sets**: The program provides the Julia set and the Mandelbrot set. The user can switch between the sets through the command line.
2. **Zoom**: The mouse wheel allows the user to zoom in and out of the fractal, exploring its infinite intricacy (limited by the computational capabilities of the machine).
3. **Coloring**: The program uses color to represent the depth of each fractal, with the potential for additional effects for a more psychedelic experience.
4. **Parameters**: A parameter passed on the command line defines the type of fractal to be viewed. If no parameter is provided, or if it's invalid, the program will display a list of available parameters and exit.
5. **Julia Set Variations**: The program can generate variations of the Julia set based on the parameters passed to it.

## Usage

The program can be run by passing a parameter defining the type of fractal to view:

```bash
./fractol <fractal_type>
```

## Controls

* ESC: Exit the program.
* Mouse wheel: Zoom in and out.
* Arrow keys: Move the fractal view (Bonus feature).

## Graphics

The MinilibX library is used to create the graphical interface of the program. This library allows the manipulation of windows and images for a custom graphical interface.

## Bonuses

Here are some ideas for potential bonus features:

1. Implement an additional fractal set. There are hundreds of different types of fractals that could be implemented for extra credit.
2. Make the zoom follow the actual mouse position, allowing for more precise exploration of the fractals.
3. Allow for moving the view with the arrow keys, providing another way to explore the fractals.
4. Implement a shifting color range, providing an even more psychedelic experience.
