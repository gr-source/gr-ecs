#include <iostream>

#include "ecs/entity.hpp"

#include "component/transform.hpp"

class Render : public Component {
};

class Math : public Component {
};

int main() {
    std::cout << "Entity: 0" << std::endl;
    auto& entity0 = Entity::Create();

    auto& t = entity0.addComponent<Transform>();

    t.id = 90;
    entity0.addComponent<Render>();
    entity0.addComponent<Math>();
    auto& transform = *static_cast<Transform*>(entity0.addComponent("Transform"));

    if (entity0.hasComponent<Transform>()) {
        auto& tg = entity0.getComponent<Transform>();
        std::cout << "Component exists: " << tg.id << std::endl;

        tg.id = 70;
    } else {
        std::cout << "Component do not exists." << std::endl;
    }

    std::cout << "V: " << t.id << std::endl;
    // std::cout << "Entity: 1" << std::endl;
    // auto& entity1 = Entity::Create();
    // entity1.addComponent<Transform>();
    // entity1.addComponent<Render>();
    // entity1.addComponent<Math>();

    std::cout << "Finish." << std::endl;

    return 0;
}


