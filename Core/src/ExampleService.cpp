// ExampleService.cpp
#include "ExampleService.hpp"
#include <iostream>

void ExampleService::DoSomething() {
    m_status++;
    std::cout << "ExampleService doing something. Status: " << m_status << std::endl;
}
