#include "./lib/containers.h"

#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

int main() {
    myHashMap::myHashMap<int,int> map(10);
    for(int i = 0; i < 100; i++) {
        map.add(i, i);
    }
    //for(int i = 0; i < 100; i++) {
        //map.add(i, i);
    //}
    map.print();
    //for(int i = 0; i < 100; i++) {
        //printf("%d ", map.get(i));
    //}

    for(int i = 0; i < 100; i++) {
        printf("\n\n #### %d ####\n", i);
        map.remove(i);
        map.print();
    }
    for(int i = 0; i < 100; i++) {
        map.add(i, i);
    }
    map.print();
}
