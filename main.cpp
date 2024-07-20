#include <iostream>

#include "ecs/entity.hpp"

#include "component/transform.hpp"

int main() {
    auto& entity0 = Entity::Create();
    auto& transform = entity0.addComponent<Transform>();

    std::cout << transform.id << std::endl;

    transform.id = 10;
    
    std::cout << transform.id << std::endl;

    if (entity0.hasComponent<Transform>()) {
        std::cout << "Component exists" << std::endl;

        auto& t = entity0.getComponent<Transform>();

        t.id = 20;
        std::cout << t.id << std::endl;
    } else {
        std::cout << "Component do not exists" << std::endl;
    }
    std::cout << transform.id << std::endl;

    return 0;
}


