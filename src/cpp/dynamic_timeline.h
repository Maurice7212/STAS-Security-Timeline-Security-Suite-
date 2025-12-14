#ifndef DYNAMIC_TIMELINE_H
#define DYNAMIC_TIMELINE_H

#include <vector>
#include <string>
#include <windows.h>  // For GetTickCount64()

struct Event {
    std::string type;
    unsigned long timestamp;
    // Add more fields later if needed (pid, details, etc.)
};

class DynamicTimeline {
private:
    std::vector<Event> events;

public:
    DynamicTimeline();
    void trackEvents();  // Simulated events for now
    std::vector<Event> getEvents() const;
};

#endif