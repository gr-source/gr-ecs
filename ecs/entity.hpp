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
    template <typename T>
    static ComponentID GenerateIDByType() noexcept {
        static ComponentID id = GenerateID();
        return id;
    }

private:
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

    Component *addComponent(const std::string &name);

    Component *getComponent(const std::string &name);

private:
    std::unordered_map<std::string, std::unique_ptr<Component>> components;

    std::bitset<MAX_COMPONENT> sequence;

    static std::vector<std::unique_ptr<Entity>> s_entities;
};

#include <iostream>

template <typename T, typename... Args>
inline T &Entity::addComponent(Args &&...args) {
    // auto id = ComponentIDGenerator::GenerateIDByType<T>();
    auto name = typeid(T).name();

    components.emplace(name, std::make_unique<T>(std::forward<Args>(args)...));
    // sequence.set(name, true);

    auto& component = components[name];
    component->entity = this;
    component->Init();

    return *dynamic_cast<T*>(component.get());
}

template <typename T>
inline T &Entity::getComponent() {
    return *dynamic_cast<T*>(components[typeid(T).name()].get());
}

template <typename T>
inline const bool Entity::hasComponent() {
    auto it = components.find(typeid(T).name());
    if (it != components.end()) {
        return true;
    }
    return false;
}
