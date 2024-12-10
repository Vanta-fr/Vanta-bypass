#ifndef DEVICENAMECHANGER_H
#define DEVICENAMECHANGER_H

#include <string>

class DeviceNameChanger {
public:
    // Constructor and Destructor
    DeviceNameChanger();
    ~DeviceNameChanger();

    // Method to generate a random device name and change it
    bool generateAndChangeDeviceName();

private:
    // Helper method to execute system commands
    bool executeCommand(const std::string& command);

    // Platform-specific methods
    bool changeLinuxDeviceName(const std::string& newName);
    bool changeWindowsDeviceName(const std::string& newName);

    // Helper method to generate a random device name
    std::string generateRandomDeviceName();
};

#endif
