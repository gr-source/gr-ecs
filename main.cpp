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

    auto& transform = *static_cast<Transform*>(entity0.addComponent("9Transform"));
    std::cout << "Original: " << transform.id << std::endl;
    transform.id = 10;
    std::cout << "Modify: " << transform.id << std::endl;

    if (entity0.hasComponent<Transform>()) {
        std::cout << "Has transform componenet, using template." << std::endl;

        auto& tt = entity0.getComponent<Transform>();

        std::cout << "Last: " << tt.id << std::endl;
        tt.id = 800;
        std::cout << "Befor: " << tt.id << std::endl;
    } else {
        std::cout << "Component transform do not exists, using template." << std::endl;
    }

    if (entity0.hasComponent("9Transform")) {
        std::cout << "Has transform componenet, using string." << std::endl;

        auto& ts = *static_cast<Transform*>(entity0.getComponent("9Transform"));

        std::cout << "Last: " << ts.id << std::endl;
        ts.id = 40;
        std::cout << "Befor: " << ts.id << std::endl;
    } else {
        std::cout << "Component transform do not exists, using string." << std::endl;
    }

    std::cout << "Finished: " << transform.id << std::endl;

    return 0;
}


