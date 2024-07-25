#include "entity.hpp"

#include <iostream>

std::vector<std::unique_ptr<Entity>> Entity::s_entities;

Entity &Entity::Create() {
    return *s_entities.emplace_back(std::make_unique<Entity>());
}

Component *Entity::addComponent(const std::string &name) {
    auto it = s_registersComponenet.find(name);
    if (it != s_registersComponenet.end()) {
    }
    return nullptr;
}

Component *Entity::getComponent(const std::string &name) {
    return nullptr;
}
