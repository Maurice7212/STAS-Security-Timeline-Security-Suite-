cmake_minimum_required(VERSION 3.10)
project(STAS)

set(CMAKE_CXX_STANDARD 17)

find_package(SQLite3 REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(unofficial-libyara CONFIG REQUIRED)

add_executable(stas_engine
    src/cpp/main.cpp
    src/cpp/static_analysis.cpp
    src/cpp/dynamic_timeline.cpp
    src/cpp/sandbox.cpp
    src/cpp/sqlite_db.cpp
    src/cpp/risk_scoring.cpp
    src/cpp/autorun_detector.cpp
)

target_link_libraries(stas_engine
    SQLite::SQLite3
    OpenSSL::SSL
    OpenSSL::Crypto
    unofficial::libyara::libyara
)

target_include_directories(stas_engine PRIVATE src/cpp)