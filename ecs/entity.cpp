#include "entity.hpp"

#include <iostream>

std::vector<std::unique_ptr<Entity>> Entity::s_entities;

Entity &Entity::Create() {
    return *s_entities.emplace_back(std::make_unique<Entity>());
}

Component *Entity::addComponent(const std::string &name) {
    auto it = s_registersComponenet.find(name);
    if (it == s_registersComponenet.end()) {
        return nullptr;
    }
    components.emplace(name, (*it).second);

    auto& component = components[name];
    component->entity = this;
    component->Init();

    return dynamic_cast<Component*>(component.get());
}

Component *Entity::getComponent(const std::string &name) {
    return components[name].get();
}

const bool Entity::hasComponent(const std::string &name) {
    auto it = components.find(name);
    return it != components.end();
}
