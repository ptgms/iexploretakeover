#include <iostream>
#include <string.h>
#include <fstream>
#include <streambuf>

using namespace std;

int main(int argc,
    char* argv[],
    char* envp[])
{
    int browser;
    int count;
    string cur;
    string str = "http";
    string toopen;

    std::ifstream t("browser.cfg");
    std::string config((std::istreambuf_iterator<char>(t)),
        std::istreambuf_iterator<char>());


    if (config == "") {
        cout << "Config file empty or not fault, will default to 'default' setting.";
        browser = 0;
    }
    else if (config == "default") {
        browser = 0;
    }
    else if (config == "chrome") {
        browser = 1;
    }
    else if (config == "firefox") {
        browser = 2;
    }
    else {
        cout << "A non-recognized browser was specified. Will try using it, but expect it not to work." << endl;
        browser = 3;
    }

    cout << "Config: " + config << endl;;

    
    for (count = 0; count < argc; count++) {
        cur = argv[count];
        if (cur.find(str) != string::npos) {
            toopen = cur;
        }
    }

    switch (browser) {
    case 0: {string finalcmd = "start " + toopen;
        const char* command = finalcmd.c_str();
        system(command); break; }
    case 1: {string finalcmd = "start chrome.exe " + toopen;
        const char* command = finalcmd.c_str();
        system(command); break; }
    case 2: {string finalcmd = "start firefox.exe " + toopen;
        const char* command = finalcmd.c_str();
        system(command); break; }
    case 3: {string finalcmd = "start " + config + " " + toopen;
        const char* command = finalcmd.c_str();
        system(command); break; }
    }
}