# Fract'ol

A fractal visualization program developed as part of 42 School projects. Renders Mandelbrot and Julia sets in real-time using the MiniLibX graphics library.

## 📋 Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Controls](#controls)
- [Fractal Types](#fractal-types)
- [Technical Details](#technical-details)

## 🌟 Overview

Fract'ol is an interactive visualization tool that allows you to explore the beauty of mathematical fractals. The program generates the famous Mandelbrot and Julia sets through iterative calculations in the complex number plane.

## ✨ Features

- **Mandelbrot Set**: Visualize the classic Mandelbrot fractal
- **Julia Set**: Julia fractals with customizable parameters
- **Interactive Zoom**: Infinite zoom capability with mouse wheel
- **Dynamic Iteration**: Automatic detail adjustment based on zoom level
- **Colorful Rendering**: Aesthetic appearance with gradient color scheme
- **Real-time**: Instant rendering and smooth navigation

## 🔧 Requirements

- **Operating System**: Linux
- **Compiler**: GCC or Clang
- **Libraries**:
  - X11 development libraries
  - XExt development libraries
  - Math library (libm)

### Installing Required Packages (Ubuntu/Debian):

```bash
sudo apt-get update
sudo apt-get install gcc make xorg libxext-dev libbsd-dev
```

## 🚀 Installation

1. Clone the repository:

```bash
git clone https://github.com/ccakirr/fractol.git
cd fractol
```

2. Compile the project:

```bash
make
```

This command automatically performs the following operations:

- Compiles the LibFT library
- Compiles the ft_printf library
- Compiles the MiniLibX library
- Compiles all source files and creates the `fractol` executable

## 💻 Usage

### Mandelbrot Set

```bash
./fractol mandelbrot
```

### Julia Set

The Julia set requires two complex number parameters:

```bash
./fractol julia <real_part> <imaginary_part>
```

**Example Julia Parameters:**

```bash
# Classic Julia set
./fractol julia -0.7 0.27015

# Spiral appearance
./fractol julia -0.8 0.156

# Electric appearance
./fractol julia 0.285 0.01

# Dragon fractal
./fractol julia -0.4 0.6
```

## 🎮 Controls

| Control               | Function     |
| --------------------- | ------------ |
| **Mouse Scroll Up**   | Zoom in      |
| **Mouse Scroll Down** | Zoom out     |
| **ESC**               | Exit program |

### Zoom Features

- Each zoom operation zooms in/out towards the mouse pointer position
- Iteration count automatically increases as zoom level increases (maximum 200)
- More iterations = more detailed fractal image

## 🎨 Fractal Types

### Mandelbrot Set

The Mandelbrot set tests whether the iteration remains bounded for each complex number `c` with initial value `z₀ = 0`:

```
zₙ₊₁ = zₙ² + c
```

**Visual Characteristics:**

- Main body: Cardioid shape
- Main bulb: Circular structure
- Infinite detail: New structures at every zoom level

### Julia Set

The Julia set uses the iteration with a fixed complex number `c` and `z₀ = pixel_coordinate`:

```
zₙ₊₁ = zₙ² + c
```

**Visual Characteristics:**

- Completely different shapes based on parameter changes
- Connected or disconnected sets
- Symmetric and organic structures

## 🛠️ Technical Details

### Project Structure

```
fractol/
├── srcs/
│   ├── main.c              # Program entry point
│   ├── parser.c            # Argument parsing
│   ├── render.c            # Fractal calculation and rendering
│   ├── handlers.c          # Event handlers
│   ├── event_listeners.c   # MLX event processing
│   ├── utils.c             # Helper functions
│   └── fractol.h           # Header file
├── libs/
│   ├── libft/              # Basic C functions library
│   ├── ft_printf/          # Printf implementation
│   └── minilibx-linux/     # MLX graphics library
└── Makefile
```

### Rendering Algorithm

1. **Pixel Mapping**: Each screen pixel is mapped to the complex plane
2. **Iteration**: Escape time algorithm is executed for each point
3. **Coloring**: RGB value is calculated based on iteration count
4. **Display**: Image buffer is transferred to screen via MLX

### Color Scheme

The program uses a gradient color palette based on iteration count:

```c
color_value = (iteration * 255) / max_iteration
color = (R << 16) | (G << 8) | B
```

### Optimizations

- **Escape Condition**: Early exit with `|z|² > 4` check
- **Adaptive Iteration**: Dynamic maximum iteration based on zoom level
- **Efficient Coordinate Transformation**: Pixel-to-complex plane mapping

## 📚 Makefile Commands

```bash
make        # Compile the project
make clean  # Remove object files
make fclean # Remove all compilation outputs
make re     # Clean and recompile
```

## 🐛 Troubleshooting

### Common Issues

**Problem**: Program doesn't run, MLX error occurs

```bash
# Solution: Install X11 libraries
sudo apt-get install xorg libxext-dev libbsd-dev
```

**Problem**: "Invalid args" error

```bash
# Solution: Use correct parameters
./fractol mandelbrot
# or
./fractol julia -0.7 0.27015
```

**Problem**: Image renders too slowly

```bash
# Reason: Maximum iteration count might be too high
# Solution: Zoom out or restart the program
```

## 📖 Mathematical Background

### Complex Numbers

Complex number: `c = a + bi`

- `a`: Real part
- `b`: Imaginary part
- `i`: √(-1)

### Fractal Theory

Fractals are mathematical sets that exhibit similar characteristics at any scale. The Mandelbrot and Julia sets are the most famous examples of complex dynamical systems.

## 🎓 Learning Resources

- [Mandelbrot Set - Wikipedia](https://en.wikipedia.org/wiki/Mandelbrot_set)
- [Julia Set - Wikipedia](https://en.wikipedia.org/wiki/Julia_set)
- [Complex Numbers](https://en.wikipedia.org/wiki/Complex_number)
- [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx)

## 👨‍💻 Developer

**Caner Çakır** - [ccakirr](https://github.com/ccakirr)

## 📝 License

This project is part of the 42 School curriculum.

## 🙏 Acknowledgments

- 42 School community
- MiniLibX developers
- Fractal mathematicians

---

⭐ If you liked this project, don't forget to give it a star!
