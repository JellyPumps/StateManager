#pragma once

#include <memory>
#include <string>
#include <unordered_map>

#include "scene.hpp"

class StateManager {
public:
  static StateManager &getInstance();

  void addScene(const std::string &name, std::unique_ptr<Scene> scene);
  void switchToScene(const std::string &name);
  void updateCurrScene();
  void drawCurrScene();

private:
  StateManager() = default;

  std::unordered_map<std::string, std::unique_ptr<Scene>> scenes;
  Scene *currentScene = nullptr;
};
