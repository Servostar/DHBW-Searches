#include "search.h"

#define MAX(i, j) (((i) > (j)) ? (i) : (j))

bool boyermoore_search() {
    
    int right[256];
    memset(right, -1, 256 * sizeof(int));

    int patlen = strlen(PATTERN);
    for (int i = 0; i < patlen; i++) {
        right[(unsigned int) PATTERN[i]] = i;
    }

    int skip = 0;
    for (int i = 0; i <= SOURCE_SIZE - patlen; i += skip) {
        skip = 0;
        for (int k = patlen-1; k >= 0; k--) {
            if (PATTERN[k] != SOURCE[i + k]) {
                skip = MAX(1, k - right[SOURCE[i + k]]);
                break;
            }
        }

        if (skip == 0) {
            return true;
        }
    }

    return false;
}

bool kmp_search() {
    
    int patlen = strlen(PATTERN);
    int* jumptable = (int*) calloc(patlen, sizeof(int));

    for (int i = 1, j = 0; i < patlen;) {
        if (PATTERN[i] == PATTERN[j]) {
            jumptable[i] = j + 1;
            i ++;
            j ++;
        } else if (j > 0) {
            j = jumptable[j - 1];
        } else {
            jumptable[i] = 0;
            i ++;
        }
    }
    
    const char* pat = PATTERN;
    
    int j = 0;
    // for every character in source compare it to a charactor of our pattern
    for (int i = 0; i < SOURCE_SIZE;) {
        if (PATTERN[j] == SOURCE[i]) {
            i ++;
            j ++;
        }

        if (j == patlen) {
            return true;
        } else if (i < SOURCE_SIZE && PATTERN[j] != SOURCE[i]) {
            if (j == 0) {
                i ++;
            } else {
                j = jumptable[j - 1];
            }
        }
    }

    free(jumptable);

    return false;
}

bool naive_search() {

    // loop through our source string
    for (int i = 0; i < SOURCE_SIZE; i++) {
        
        const char* src = SOURCE + i;
        for (const char* pat = PATTERN; *src != '\0';) {
            if (*pat != *src) {
                break;
            }

            pat ++;
            src ++;

            if (*pat == '\0') {
                return true;
            }
        }
    }

    return false;
}


