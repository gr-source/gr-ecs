#include "entity.hpp"

std::vector<std::unique_ptr<Entity>> Entity::s_entities;

Entity &Entity::Create() {
    return *s_entities.emplace_back(std::make_unique<Entity>());
}


