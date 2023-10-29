#ifndef IOSTREAM
#include <iostream>
#endif

#ifndef FILESYSTEM
#include <filesystem>
#endif

#ifdef _WIN32 || _WIN64
const std::string os = "Win";
#ifndef WINDOWS_H
#include <windows.h>
#endif

#elif __APPLE__ || __MACH__
const std::string os = "iOS";
#ifndef TERMIOS_H
#include <termios.h>
#endif
#ifndef UNISTD_H
#include <unistd.h>
#endif

#elif __linux__
const std::string os = "Linux";
// We will work on this when we build code for Linux systesm
#elif __FreeBSD__
// We will work on this when we build code for FreeBSD systesm
#elif __unix || __unix__
// We will work on this when we build code for Unix systesm
#else
////We will work on this when we build code for any other systesm
#endif

class osRoutines
{
public:
    // static std::string getKeyHit();
    // std::string getResourcePath();
};