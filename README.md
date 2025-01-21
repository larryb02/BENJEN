# BENJEN
2D Engine Rewrite
- Making code cleaner and easier to build on top of
    - Planning for a potential GUI
- Creating a proper Entity-Component System
- Re-evaluating the render pipeline
- Adding logging
# Build Instructions
- Currently works/tested for macos only
- Run cmake commands:
```
    cmake -S <root_dir> -B <build_dir>
    cmake --build <build_dir>
```
# Dependencies
- Currently this project uses SDL, glm, stb_image, and opengl. Excluding SDL, all of the necessary files are in the core/include directory. Here are links to the other dependencies if you run into any issues compiling the code:
- Glad (OpenGL): TODO
- glm: TODO
- stb_image: TODO
- SDL: TODO


