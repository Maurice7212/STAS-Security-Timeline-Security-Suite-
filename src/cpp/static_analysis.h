#ifndef STATIC_ANALYSIS_H
#define STATIC_ANALYSIS_H

#include <string>

class StaticAnalysis {
private:
    std::string filepath;
public:
    StaticAnalysis(const std::string& file);
    void performAnalysis();
    void computeHashes();
    void calculateEntropy();
    void detectPackers();
};

#endif