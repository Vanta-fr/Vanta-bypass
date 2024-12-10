#include <iostream>
#include "NameSpoofer.h"

int main() {
    // Create a DeviceNameChanger object
    DeviceNameChanger deviceChanger;

    // Generate and change the device name
    if (deviceChanger.generateAndChangeDeviceName()) {
        std::cout << "Device name has been changed successfully." << std::endl;
    }
    else {
        std::cout << "Failed to change the device name." << std::endl;
    }

    return 0;
}
