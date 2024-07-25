#pragma once

#include <unordered_map>
#include <memory>
#include <string>

class Entity;

class Component {
public:
    virtual void Init() {}

    virtual void Start() {}

    virtual void Update() {}
    
    virtual ~Component() {}
    
    Entity* entity;
};

inline std::unordered_map<std::string, std::shared_ptr<Component>> s_registersComponenet;

#define REGISTER_COMPONENT(cls) \
    namespace { \
        struct Register_##cls { \
            Register_##cls() { \
                s_registersComponenet.emplace(typeid(cls).name(), std::make_shared<cls>()); \
            } \
        } register_##cls; \
    } // namespace 
    