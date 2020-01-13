//filter.cpp
//

#include "filter.h"

/*
PBLACKLIST BlacklistInit(void) {
    UINT size = 1024;

    PBLACKLIST blacklist = (PBLACKLIST)malloc(sizeof(BLACKLIST));
    if (blacklist == NULL) {
        goto memory_error;
    }

    blacklist->urls = (PURL*)malloc(sizeof(PURL)*size);
    if (blacklist->urls == NULL) {
        goto memory_error;
    }

    blacklist->size = size;
    blacklist->length = 0;

    return blacklist;

memory_error:
    std::cerr << "Failed to allocate memory";
    exit(EXIT_FAILURE);
}
*/
/*
PBLACKLIST BlacklistInit(void) {
    UINT size = 1024;

    static BLACKLIST aaa;
    

    PBLACKLIST blacklist;
       
    blacklist.resize();

    return blacklist;

memory_error:
    std::cerr << "Failed to allocate memory";
    exit(EXIT_FAILURE);
}
*/


/*
void BlackListAdd(PBLACKLIST blacklist, PURL entry) {



    if (blacklist->length >= blacklist->size) {

        
        //blacklist->urls = (PURL*)realloc(blacklist->urls, sizeof(PURL)*blacklist->size);
        if (blacklist == NULL) {
            goto memory_error;
        }
        
        //vector
    }
    
    
    //blacklist->urls[blacklist->length++] = entry;
    

    std::cout << "Included " << entry->domain << "\n";

memory_error:
    std::cerr << "Failed to allocate memory";
    exit(EXIT_FAILURE);
}

*/

void BlackListSort() {

}