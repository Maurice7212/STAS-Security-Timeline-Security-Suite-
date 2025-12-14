#include "sandbox.h"
#include <windows.h>

Sandbox::Sandbox(const std::string& sample) : samplePath(sample) {}

void Sandbox::executeInSandbox() {
    // Create suspended process
    STARTUPINFO si = {};
    PROCESS_INFORMATION pi = {};
    CreateProcess(NULL, (LPSTR)samplePath.c_str(), NULL, NULL, FALSE, CREATE_SUSPENDED, NULL, NULL, &si, &pi);

    // Inject DLL or hooks
    // ResumeThread(pi.hThread);

    // Monitor with job object, limits
}