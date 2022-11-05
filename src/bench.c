#include "bench.h"

void benchmark_search(bool (*algorithm)(), const char* name) {
    // take start time
    long long start = millis();

    // run algorithm
    bool match = algorithm();

    // take end time and compute difference as passed time
    long long delta = millis() - start;

    printf("%s took: %lldms and found %s\n", name, delta, match ? "a match" : "nothing");
}

long long millis() {
    // stores current time
    struct timespec now;
    // get unix timestap
    timespec_get(&now, TIME_UTC);
    
    long long millis = 0;
    
    // convert seconds to millis and sum
    millis += ((long long) now.tv_sec) * 1000;
    // convert nanos to millis and sum
    millis += ((long long) now.tv_nsec) / 1000000;

    return millis;
}

