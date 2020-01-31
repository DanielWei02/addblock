// addblock.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "filter.h"

HANDLE handle;


int priority = 0;

const char* blacklist_location = "C:\\Users\\Daniel Wei\\Documents\\addblock\\blacklist.txt";
//const char* blacklist_location = "C:\Users\Daniel Wei\Documents\addblock\blacklist.txt";

int main(){

    unsigned char packet[MAXBUF];
    UINT packet_len;
    WINDIVERT_ADDRESS addr;
    PWINDIVERT_IPHDR ip_header;
    PWINDIVERT_TCPHDR tcp_header;
    PVOID payload;
    UINT payload_len;

    DWORD DNSRev;
    struct sockaddr_in saGNI;
    char hostname[NI_MAXHOST];
    char servInfo[NI_MAXSERV];
    u_short port = 27015;

    std::fstream blacklist_file;

    std::cout << "Reading blacklist from \"" << blacklist_location << "\"\n";

    blacklist_file.open(blacklist_location, std::ios::in);

    if (!blacklist_file.is_open()) {
        std::cerr << "Failed to load blacklist\n";
        exit(EXIT_FAILURE);
    }

    BLACKLIST blacklist;// = BlacklistInit();

    // adds blacklist from file

    std::string data;
    while (getline(blacklist_file, data)) {
        if (data[0] == '#') continue;
        if (data[0] == '\0') continue;
        //std::cout<<data<<std::endl;
        blacklist.push_back(data);
    }

    BlacklistSort(&blacklist);

    std::cout << "Finished creating blacklist\n";
    blacklist_file.close();





/*
     handle = WinDivertOpen(
        "outbound &&" //outbound traffic only
        "!loopback &&" //no loopback traffic
        "ip &&" //ipv4 only
        "tcp.DstPort==80 &&" //http traffic
        "tcp.DstPort==443 &&" //https traffic
        ""
        , WINDIVERT_LAYER_NETWORK, priority, 0);
    
    */

    handle = WinDivertOpen(
        "tcp.DstPort==80" //http traffic
        , WINDIVERT_LAYER_NETWORK, priority, 0);
    
    if (handle == INVALID_HANDLE_VALUE) {
        std::cerr << "Error: Failed to open Windivert handle.\n Error code: " << GetLastError();
        exit(EXIT_FAILURE);
    }

    

    while (true) {
        
        if (!WinDivertRecv(handle, packet,sizeof(packet), &packet_len, &addr) ){
            std::cerr << "Warning: Failed to Read Packet";
            continue;
        }

        WinDivertHelperParsePacket(packet,packet_len,&ip_header,NULL,NULL,NULL,NULL,&tcp_header,NULL,&payload,&payload_len,NULL,NULL);

        //reverse ip searchup https sites

        /*
        if (ip_header == NULL || tcp_header == NULL || payload == NULL ||
            !BlackListPayloadMatch(blacklist, payload, (UINT16)payload_len))
        {
            // Packet does not match the blacklist; simply reinject it.
            if (!WinDivertSend(handle, packet, packet_len, NULL, &addr))
            {
                fprintf(stderr, "warning: failed to reinject packet (%d)\n",
                    GetLastError());
            }
            continue;
        }
        */


        //check if is http

        //check if is https


        //break;

        saGNI.sin_family = AF_INET;
        saGNI.sin_addr.s_addr = inet_addr("aaa");
        saGNI.sin_port = htons(port);

        DNSRev = getnameinfo((struct sockaddr*) & saGNI,
            sizeof(struct sockaddr),
            hostname,
            NI_MAXHOST, servInfo, NI_MAXSERV, NI_NUMERICSERV);

        if (DNSRev != 0) {
            printf("getnameinfo failed with error # %ld\n", WSAGetLastError());
            return 1;
        }
        else {
            printf("getnameinfo returned hostname = %s\n", hostname);
            return 0;
        }

    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
