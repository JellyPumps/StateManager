#pragma once

#include <string>

class Scene {
public:
  Scene(const std::string &name) : name(name) {}
  virtual ~Scene() {}

  virtual void update() = 0;
  virtual void draw() = 0;

  std::string getName() const { return name; }

private:
  std::string name;
};
