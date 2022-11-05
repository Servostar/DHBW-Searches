#include "search.h"
#include "bench.h"

// length of our source string to search in 
const long SOURCE_SIZE = 100000000;
// pattern to search in string
const char* PATTERN = "needle";

char* SOURCE;

void generate_source();

int main() {
    
    // allocate some space for our source string
    SOURCE = (char*) malloc(SOURCE_SIZE);
    
    // initalize source string with worst case search scenario for our pattern
    generate_source();

    // benachmark
    benchmark_search(&naive_search, "naive");
    benchmark_search(&kmp_search, "kmp");
    benchmark_search(&boyermoore_search, "boyer-moore");

    // free source string
    free(SOURCE);

    return 0;
}

void generate_source() {
    int patlen = strlen(PATTERN);

    // fill the source string with our pattern and replace every last char of 
    // our pattern with a binary 1 to assure a missmatch
    for (int i = 0; i < SOURCE_SIZE - patlen; i += patlen) {
        memcpy(SOURCE + i, PATTERN, patlen);
        SOURCE[i + patlen - 1] = 1;
    }

    // put our pattern at the end of our source,
    // this will be the matching part of our source 
    memcpy(SOURCE + SOURCE_SIZE - patlen - 1, PATTERN, patlen);
}

