#ifndef SANDBOX_H
#define SANDBOX_H

#include <string>

class Sandbox {
private:
    std::string samplePath;
public:
    Sandbox(const std::string& sample);
    void executeInSandbox();
};

#endif