#ifndef _SEARCH_H_
#define _SEARCH_H_

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// string to search for
extern const char* PATTERN;
// source to search in
extern char* SOURCE;
// length of our source as a constant, saves some time when
// our source is several mb large
extern const long SOURCE_SIZE;

bool naive_search();

bool kmp_search();

bool boyermoore_search();

#endif
