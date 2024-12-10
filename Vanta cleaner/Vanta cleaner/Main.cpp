#include <iostream>
#include <Windows.h>
#include <string>

void setConsoleTitle(const std::string& title) {
    // Convert std::string to std::wstring for wide-character support
    std::wstring wideTitle(title.begin(), title.end());
    SetConsoleTitle(wideTitle.c_str());
}

void setConsoleColor(WORD color) {
    // Get the console handle
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void forceDeleteFile(const std::string& filePath) {
    // Convert the file path from std::string to std::wstring
    std::wstring wFilePath(filePath.begin(), filePath.end());

    // Set file attributes to normal to remove any protection (like read-only)
    SetFileAttributes(wFilePath.c_str(), FILE_ATTRIBUTE_NORMAL);

    // Now try to delete the file
    if (DeleteFile(wFilePath.c_str())) {
        setConsoleColor(FOREGROUND_GREEN);
        std::wcout << L"[+] File deleted successfully: " << wFilePath << std::endl;
    }
    else {
        setConsoleColor(FOREGROUND_RED);
        std::wcout << L"[-] Failed to delete file: " << wFilePath << std::endl;
        std::wcout << L"[!] Error code: " << GetLastError() << std::endl;
    }

    // Reset color to default
    setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

int main() {
    // Set the console title with the wide-character string literal
    setConsoleTitle("Vanta Cleaner - made by Wukey - Build ID: 1.0");

    // Print a message in yellow, simulating getting the kernel or system information
    setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    std::cout << "[!] Getting kernel information..." << std::endl;

    // Simulate delay for getting kernel information (you can remove or replace it with actual functionality)
    Sleep(1000);  // Sleep for 1 second to simulate loading

    // Now, prompt for the file path
    setConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    std::string filePath;
    std::cout << "[+] Please enter the file path to delete: ";
    std::getline(std::cin, filePath);

    // Check if the file path is empty
    if (filePath.empty()) {
        setConsoleColor(FOREGROUND_RED);
        std::cout << "[!] File path cannot be empty!" << std::endl;
        return 1;
    }

    // Call the function to force delete the file
    forceDeleteFile(filePath);

    return 0;
}
