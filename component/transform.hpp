#pragma once

#include "../ecs/component.hpp"

class Transform : public Component {
private:
    void Init() override;

    void Start() override;
    
    void Update() override;
public:
    Transform();
    ~Transform() override;

    int id;
};

REGISTER_COMPONENT(Transform)


