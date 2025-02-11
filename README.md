# FDF

🔍 Turning text files into terrains—because why not? ⛰️📜

---

## Table of Contents

1. [Introduction](#introduction)
2. [Features](#features)
3. [Dependencies](#dependencies)
4. [Installation](#installation)
5. [Usage](#usage)
6. [Contributing](#contributing)
7. [License](#license)
8. [Acknowledgments](#acknowledgments)

---

## Introduction

Ever felt like drawing in MS Paint was too boring? Ever felt like making PowerPoint presentations is too mainstream? Ever felt like ASCII art isn't chaotic enough? Try wireframes then! Build your own Minecraft terrains with this project!
**FDF** is a graphical program that takes a file describing a 3D terrain and represents it in a 2D isometric projection. This project is part of the 42 School curriculum and aims to deepen your understanding of computer graphics, file parsing, and the mathematics behind 3D projections.

---

## Features

✅ **3D to 2D Projection** – Converts 3D wireframe models into 2D isometric views.  

✅ **Interactive Controls** – Rotate, zoom, and adjust the view dynamically.  

✅ **Customizable Colors** – Apply different color schemes to enhance visualization.  

✅ **Lightweight and Efficient** – Optimized for performance with a minimal footprint.


---

## Dependencies

Before installing and running FDF, ensure that you have the necessary dependencies for generating the image window. The required dependencies vary depending on your operating system.

**macOS:**

- **Homebrew:** If you don't have Homebrew installed, you can install it by running:
  ```bash
  /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
  ```
- **GLFW:** Install GLFW using Homebrew:
  ```bash
  brew install glfw
  ```

**Linux:**

- **GLFW:** Install GLFW using your package manager. For example, on Debian-based systems:
  ```bash
  sudo apt-get update
  sudo apt-get install libglfw3-dev
  ```
- **CMake:** Ensure CMake is installed:
  ```bash
  sudo apt-get install cmake
  ```

**Windows (WSL2):**

- **WSL2:** Ensure you have Windows Subsystem for Linux 2 installed.
- **X Server:** Install an X Server like [VcXsrv](https://sourceforge.net/projects/vcxsrv/) to handle graphical display.
- **GLFW and CMake:** Follow the Linux instructions above within your WSL2 environment.

For detailed installation instructions about the dependencies, I highly recommend you to refer to the [MLX42 Installation Guide](https://github.com/codam-coding-college/MLX42#installation-).

---

## Installation

Once the dependencies are installed, follow these steps to set up FDF:

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/MKNSTEJA/FDF.git
   cd FDF
   ```

2. **Build the Project:**
   ```bash
   make
   ```

---

## Usage

After building the project, you can run the program by providing a map file as an argument:

```bash
./fdf [path_to_map_file]
```

Example:

```bash
./fdf maps/42.fdf
```

**Controls:**

- **Rotate:** Use the arrow keys to rotate the model.
- **Zoom:** Use the `+` and `-` keys to zoom in and out.
- **Height Adjustment:** Use the `Page Up` and `Page Down` keys to adjust the height scale.
- **Exit:** Press the `ESC` key to exit the program.

---

## Contributing

Contributions are welcome! If you'd like to contribute to FDF, please follow these steps:

1. **Fork the Repository.**
2. **Create a New Branch:**
   ```bash
   git checkout -b feature/your-feature-name
   ```
3. **Commit Your Changes:**
   ```bash
   git commit -m "Add your feature description"
   ```
4. **Push to Your Branch:**
   ```bash
   git push origin feature/your-feature-name
   ```
5. **Open a Pull Request** on GitHub.

---

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

## Acknowledgments

- **42 School:** For providing the opportunity to work on this project.
- **MiniLibX:** For the lightweight graphics library that made this project possible.
- **Open-Source Community:** For the tools and libraries that support this project.

---

## Author

**MKNSTEJA**

- GitHub: [MKNSTEJA](https://github.com/MKNSTEJA)

---

*Happy mapping!* 🗺️🚀

