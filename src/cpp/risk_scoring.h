#ifndef RISK_SCORING_H
#define RISK_SCORING_H

#include "dynamic_timeline.h"  // This now brings in struct Event
#include <vector>

class RiskScoring {
private:
    std::vector<Event> events;

public:
    RiskScoring(const std::vector<Event>& evs);
    int calculateScore();
};

#endif