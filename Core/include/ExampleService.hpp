// ExampleService.hpp
#pragma once

class ExampleService {
public:
    void DoSomething();
    int  GetStatus() const { return m_status; }

private:
    int m_status = 0;
};
