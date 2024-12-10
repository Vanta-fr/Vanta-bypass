# Vanta-bypass
Vanta Cleaner is a C++ tool developed by Wukey to forcefully delete files, bypassing protections like read-only attributes. It offers a color-coded console interface, providing feedback on success or failure. The program uses Windows API functions and wide-character strings for compatibility and robust error handling.



# Vanta Cleaner

**Vanta Cleaner** is a C++ tool developed by **Wukey** designed to forcefully delete files from your system, bypassing protections like read-only attributes. With a user-friendly, color-coded console interface, it provides feedback on whether the file was successfully deleted or not.

## Features

- **Forceful File Deletion**: Removes files even if they're read-only or protected.
- **User-friendly Console Interface**: Color-coded messages to indicate success (green) or failure (red).
- **Windows API Integration**: Uses Windows-specific functions to handle file deletion and attribute modification.
- **Error Handling**: Displays the error code if deletion fails, helping you diagnose issues.

## How to Use

1. **Clone the repository**:

   ```bash
   git clone https://github.com/yourusername/Vanta-Cleaner.git
   cd Vanta-Cleaner
Compile the program:

You can compile the code using any C++ compiler that supports Windows API. For example, with Visual Studio:
Open the solution in Visual Studio and build the project.
Run the program:

Once compiled, run the executable.
The program will prompt you for the file path of the file you want to delete.
It will attempt to delete the file and display a success or failure message in the console.
Example Usage
bash
Copy code
[+] Please enter the file path to delete: C:\path\to\file.txt
[+] Attempting to delete the file: C:\path\to\file.txt
[+] File deleted successfully: C:\path\to\file.txt
In case of failure:

bash
Copy code
[+] Please enter the file path to delete: C:\path\to\file.txt
[-] Failed to delete file: C:\path\to\file.txt
[!] Error code: 5
License
This project is licensed under the MIT License - see the LICENSE file for details.

Disclaimer
This tool is intended for educational purposes only. Use it responsibly and ensure you have the proper authorization to delete files.

vbnet
Copy code

### Explanation of Sections:

1. **Title**: Name of the project with a short description.
2. **Features**: A list of key features explaining what the tool can do.
3. **How to Use**: Step-by-step instructions on how to clone, compile, and run the project.
4. **Example Usage**: Example of the program’s output to guide users on what to expect.
5. **License**: Basic information on licensing, referring to a license file.
6. **Disclaimer**: A warning on responsible use of the tool, especially since it involves file deletion.

This README will give users clear instructions on how to get started with **Vanta Cleaner** while 
