#include "NameSpoofer.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <sstream>
#include <iomanip>

#ifdef _WIN32
#include <windows.h>
#endif

DeviceNameChanger::DeviceNameChanger() {
    // Constructor (no initialization needed for this example)
}

DeviceNameChanger::~DeviceNameChanger() {
    // Destructor (no cleanup needed for this example)
}

bool DeviceNameChanger::generateAndChangeDeviceName() {
    // Generate a random device name
    std::string newName = generateRandomDeviceName();

    // Platform-dependent device name change
#ifdef _WIN32
    return changeWindowsDeviceName(newName);
#else
    return changeLinuxDeviceName(newName);
#endif
}

bool DeviceNameChanger::executeCommand(const std::string& command) {
    // Use system() to execute the shell command
    int result = std::system(command.c_str());
    return result == 0;
}

bool DeviceNameChanger::changeLinuxDeviceName(const std::string& newName) {
    // Form the command to change the hostname using hostnamectl
    std::string command = "sudo hostnamectl set-hostname " + newName;

    // Execute the command
    if (executeCommand(command)) {
        std::cout << "Device name successfully changed to " << newName << std::endl;
        return true;
    }
    else {
        std::cerr << "Error: Failed to change device name on Linux." << std::endl;
        return false;
    }
}

bool DeviceNameChanger::changeWindowsDeviceName(const std::string& newName) {
    // Use WMIC to change the computer name
    std::string command = "wmic computersystem where name=\"%COMPUTERNAME%\" call rename name=\"" + newName + "\"";

    // Execute the command
    if (executeCommand(command)) {
        std::cout << "Device name successfully changed to " << newName << std::endl;
        return true;
    }
    else {
        std::cerr << "Error: Failed to change device name on Windows." << std::endl;
        return false;
    }
}

std::string DeviceNameChanger::generateRandomDeviceName() {
    // Seed random number generator
    std::srand(std::time(0));

    // Generate a random alphanumeric string
    std::stringstream ss;
    ss << "PC-" << std::setw(6) << std::setfill('0') << std::rand() % 1000000;

    return ss.str(); // return as string
}
