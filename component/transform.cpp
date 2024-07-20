#include "transform.hpp"

#include <iostream>

Transform::Transform() : id(0) {}

void Transform::Init() {
    std::cout << "Initialize Object" << std::endl;
}

void Transform::Start() {
    std::cout << "Started Object" << std::endl;
}

void Transform::Update() {
    std::cout << "Update Object" << std::endl;
}

Transform::~Transform() {
    std::cout << "destroyed Object" << std::endl;
}


