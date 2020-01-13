// addblock.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "filter.h"

HANDLE handle;




const char* blacklist_location = "C:\\Users\\Daniel Wei\\Documents\\addblock\\blacklist.txt";
//const char* blacklist_location = "C:\Users\Daniel Wei\Documents\addblock\blacklist.txt";

int main(){

    std::fstream blacklist_file;

    std::cout << "Reading blacklist from \"" << blacklist_location << "\"\n";

    blacklist_file.open(blacklist_location, std::ios::in);

    if (!blacklist_file.is_open()) {
        std::cerr << "Failed to load blacklist\n";
        exit(EXIT_FAILURE);
    }

    BLACKLIST blacklist;// = BlacklistInit();

    // adds blacklist from file
    while (true) {
        char data[100];
        blacklist_file >> data;

        if (data[0] == EOF) {
            break;
        }

        //trim data?

        blacklist.urls.push_back(data);
        blacklist.length++;


    }
    

    std::cout << "Finished creating blacklist\n";
    blacklist_file.close();

     /*handle = WinDivertOpen(
        "outbound &&"
        "ip &&"
        ""
        ""
        , WINDIVERT_LAYER_NETWORK, priority, 0);
    
    
    
    */
    
    if (handle == INVALID_HANDLE_VALUE) {
        std::cerr << "Error: Failed to open Windivert handle.\n Error code: " << GetLastError();
        exit(EXIT_FAILURE);
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
