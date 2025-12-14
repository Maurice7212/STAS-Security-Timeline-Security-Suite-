#include "dynamic_timeline.h"

DynamicTimeline::DynamicTimeline() {
    // Constructor - empty for now
}

void DynamicTimeline::trackEvents() {
    // Simulated malware events (replace with real hooking later)
    events.push_back({"ProcessCreate", GetTickCount()});
    events.push_back({"FileCreate", GetTickCount() + 100});
    events.push_back({"RegistryModify", GetTickCount() + 200});
    events.push_back({"NetworkConnect", GetTickCount() + 300});
}

std::vector<Event> DynamicTimeline::getEvents() const {
    return events;
}