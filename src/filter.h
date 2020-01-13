// filter.h
//
#pragma once
#include "windivert.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <initializer_list>

//how urls will be stored
/*
typedef struct  {
    char* domain;
} URL_STRUCT;//URL, * PURL;
*/
//typedef std::vector<URL_STRUCT> URL, * PURL;

typedef std::vector<char*> URL, * PURL;

//how the blacklist will be stored

typedef struct {
    // UINT size; //mem size
    UINT length = 0; //number of entries
    URL urls;
} BLACKLIST, * PBLACKLIST;

//typedef std::vector<BLACKLIST_STRUCT> BLACKLIST, *PBLACKLIST;


//Blacklist prototypes
//PBLACKLIST BlacklistInit(void);
//void BlackListAdd(const PBLACKLIST blacklist, const PURL entry);