# State Manager Library

C++ library for managing scenes in applications.

## Features

- Management of multiple scenes (Adding & Switching)
- Functions to "update" and "draw" the scenes

## Installation

- Copy `libstate_manager.a`, `state_manager.hpp` and `scene.hpp` into your project directory

- Link `libstate_manager.a` to your project. For CMake add the following:

   ```cmake 
   add_library(state_manager STATIC IMPORTED)
   set_target_properties(state_manager PROPERTIES IMPORTED_LOCATION /path/to/libstate_manager.a)
   ```

   Replace `path/to/libstate_manager.a` with the actual path to the file.

## Usage

- Include `state_manager.hpp` wherever you wish to use it.

- Create new scenes by subclassing the `Scene` class.

- Add your scenes to the `StateManager` class using `addScene()`.

- Switch to scenes using `switchToScene()`.

- Use `update()` ONLY for logic. Use `draw()` for display.

- Call `update()` & `draw` using `updateCurrScene()` and `drawCurrScene()` respectively.

## Examples

```cpp
#include "state_manager.hpp"

int main() {
    // Create instances of your scenes
    std::unique_ptr<Scene> scene1 = std::make_unique<MyScene1>();
    std::unique_ptr<Scene> scene2 = std::make_unique<MyScene2>();

    // Add scenes to the StateManager
    StateManager::getInstance().addScene("Scene1", std::move(scene1));
    StateManager::getInstance().addScene("Scene2", std::move(scene2));

    // Switch to Scene1
    StateManager::getInstance().switchToScene("Scene1");

    // Main loop
    while (true) {
        // Update and draw the current scene
        StateManager::getInstance().updateCurrentScene();
        StateManager::getInstance().drawCurrentScene();
    }

    return 0;
}
```


## Contributing

If you'd like to contribute to StateManager, feel free to submit an issue to make sure I, or anyone else who has decided to contribute isn't working on that feature/fix/etc. Make sure to follow the existing code style.

## License

[GPL v3.0](https://choosealicense.com/licenses/gpl-3.0/)
