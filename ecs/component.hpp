#pragma once

class Entity;

class Component {
public:
    virtual void Init() {}

    virtual void Start() {}

    virtual void Update() {}
    
    virtual ~Component() {}
    
    Entity* entity;
};

