#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int GetFontSize(HANDLE windowHandle, COORD *size)
    {
    int font = 8;

    if (!GetCurrentConsoleFontEx(windowHandle, 0, &font))
        {
        return 0;
        }

    *size = font.dwFontSize;

    return 1;
    }

int SetFontSize(HANDLE windowHandle, COORD size)
    {
    int font = 8;

    if (!GetCurrentConsoleFontEx(windowHandle, 0, &font))
        {
        return 0;
        }

    font.dwFontSize = size;

    if (!SetCurrentConsoleFontEx(windowHandle, 0, &font))
        {
        return 0;
        }

    return 1;
    }

int main(void)
    {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD size;

    if (GetFontSize(h, &size))
        {
        /* Grow by 50% */
        size.X += (SHORT)(size.X * .5);
        size.Y += (SHORT)(size.Y * .5);
        SetFontSize(h, size);
        }

    puts("Blah blah text");

    return EXIT_SUCCESS;
    }
