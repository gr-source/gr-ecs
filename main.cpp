#include <iostream>

#include "ecs/entity.hpp"

#include "component/transform.hpp"

class Render : public Component {
};

class Math : public Component {
};

REGISTER_COMPONENT(Math)

int main() {
    std::cout << "Entity: 0" << std::endl;
    auto& entity0 = Entity::Create();

    entity0.addComponent("4Math");

    if (entity0.hasComponent("4Math")) {
        std::cout << "Has component." << std::endl;
    } else {
        std::cout << "do not has component." << std::endl;
    }
    return 0;
}


