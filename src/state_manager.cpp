#include "state_manager.hpp"
#include <memory>
#include <utility>

StateManager &StateManager::getInstance() {
  static StateManager instance;
  return instance;
}

void StateManager::addScene(const std::string &name,
                            std::unique_ptr<Scene> scene) {
  scenes[name] = std::move(scene);
}

void StateManager::switchToScene(const std::string &name) {
  auto it = scenes.find(name);
  if (it != scenes.end())
    currentScene = it->second.get();
}

void StateManager::updateCurrScene() {
  if (currentScene)
    currentScene->update();
}

void StateManager::drawCurrScene() {
  if (currentScene)
    currentScene->draw();
}
