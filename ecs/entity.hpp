#pragma once

#include <unordered_map>
#include <bitset>
#include <cstdio>
#include <vector>
#include <memory>

#include "component.hpp"

#define MAX_COMPONENT 16

using ComponentID = std::size_t;

class ComponentIDGenerator {
public:
    // Função template para gerar ID único por tipo de componente
    template <typename T>
    static ComponentID GenerateIDByType() noexcept {
        static ComponentID id = GenerateID();
        return id;
    }

private:
    // Função estática para gerar ID único globalmente
    static ComponentID GenerateID() noexcept {
        static ComponentID id = 0;
        return id++;
    }
};

class Entity {
public:
    static Entity& Create();

    template <typename T, typename... Args>
    T& addComponent(Args&&... args);

    template <typename T>
    T& getComponent();
    
    template <typename T>
    const bool hasComponent();

private:
    static std::vector<std::unique_ptr<Entity>> s_entities;

    std::unordered_map<ComponentID, std::unique_ptr<Component>> components;
    std::bitset<MAX_COMPONENT> sequence;
};

template <typename T, typename... Args>
inline T &Entity::addComponent(Args &&...args) {
    auto id = ComponentIDGenerator::GenerateIDByType<T>();

    components.emplace(id, std::make_unique<T>(std::forward<Args>(args)...));
    sequence.set(id, true);

    auto& component = components[id];
    component->entity = this;
    component->Init();

    return *dynamic_cast<T*>(component.get());
}

template <typename T>
inline T &Entity::getComponent() {
    return *dynamic_cast<T*>(components[ComponentIDGenerator::GenerateIDByType<T>()].get());
}

template <typename T>
inline const bool Entity::hasComponent() {
    return sequence.test(ComponentIDGenerator::GenerateIDByType<T>());
}
