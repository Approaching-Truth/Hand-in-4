#include <iostream>
#include <sstream>
#include <string>

#include "binary_heap_max.h"
using namespace std;

int main(void){
    BinaryHeap<int> h;
    h.insert(10);
    h.insert(6);
    h.insert(5);
    h.insert(40);
    h.insert(20);
    h.insert(30);
    h.insert(21);
    
	h.printHeapArray();

    return 0;
}

/*
after line 15
        30
    21      6
10     20  5

after line 16
        40
    21        30
10     20   5    6

after line 18
        30
    21      6
10     20  5


             40
    21              30
30      10      6          5


*/
