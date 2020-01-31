// filter.h
//
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <initializer_list>
#include <ws2tcpip.h>

#include "windivert.h"

#define MAXBUF WINDIVERT_MTU_MAX
#define MAX_IP_LENGTH 11

typedef std::vector<std::string> BLACKLIST, * PBLACKLIST;

typedef std::vector<std::string> BLACKLIST_IP, * PBLACKLIST_IP;

//WINDIVERT_ADDRESS addr_source, addr_dest;


//how the blacklist will be stored (currently unneeded)
void BlacklistSort(PBLACKLIST);

static BOOL BlackListPayloadMatch(PBLACKLIST blacklist, char* data, UINT16 len);

