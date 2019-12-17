#pragma once

#include <iostream>
#include "windivert.h"

//how urls will be stored
typedef struct {
	UINT length;
	char* domain;
}URL, *PURL;

//how the blacklist will be stored
typedef struct {
	UINT size;
	UINT length;
	PURL *url;
}BLACKLIST, *PBLACKLIST;

PBLACKLIST BlacklistInit() {
	UINT size = 1024;

	PBLACKLIST blacklist = (PBLACKLIST)malloc(sizeof(BLACKLIST));
	if (blacklist == NULL) {
		goto memory_error;
	}

	blacklist->url = (PURL*)malloc(sizeof(URL));
	if (blacklist->url == NULL) {
		goto memory_error;
	}

	blacklist->size = size; //memory size
	blacklist->length = 0; //number of urls

	return blacklist;
memory_error:
	std::cerr << "Failed to allocate memory";
	exit(EXIT_FAILURE);
}

void BlacklistAdd(PBLACKLIST blacklist, char* list) {



memory_error:
	std::cerr << "Failed to allocate memory";
	exit(EXIT_FAILURE);
}



