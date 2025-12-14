#include <iostream>
#include "static_analysis.h"
#include "dynamic_timeline.h"
#include "sandbox.h"
#include "sqlite_db.h"
#include "risk_scoring.h"
#include "autorun_detector.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: stas_engine <sample_path>" << std::endl;
        return 1;
    }
    std::string sample = argv[1];

    // Static Analysis
    StaticAnalysis sa(sample);
    sa.performAnalysis();

    // Sandbox and Dynamic Analysis
    Sandbox sb(sample);
    sb.executeInSandbox();

    // Timeline from Dynamic
    DynamicTimeline dt;
    dt.trackEvents();  // Simulated

    // DB Storage
        // Store events to SQLite
    std::cout << "Events saved to events.db" << std::endl;
    SQLiteDB db("events.db");
    db.storeEvents(dt.getEvents());

    // Risk Scoring
    RiskScoring rs(dt.getEvents());
    int score = rs.calculateScore();
    std::cout << "Threat Score: " << score << std::endl;

    // Graph Generation

    std::cout <<"Graphs are disabled in this build." << std::endl;

    // Autorun Detection
    AutorunDetector ad;
    ad.detectPersistence();

    // Export (IPC to Python)
    // Use named pipes to send data to Python dashboard

    return 0;
        
}