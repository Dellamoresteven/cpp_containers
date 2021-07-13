#include "./lib/containers.h"

#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

int main() {
    myHashMap::myHashMap<int,int> map(10);
    for(int i = 0; i < 21; i++) {
        map.add(i, 100+i);
    }
    map.print();
    for(int i = -100; i < 100; i++) {
        if(map.contains(i))
            printf("%d ", map.get(i));
    }
    printf("\n\n\n\n\n");

    for(int i = -100; i < 100; i++) {
        printf("%d\n", map.remove(i));
    }
    printf("\nsize: %d\n", map.getSize());

    for(int i = 0; i < 5000; i++) {
        map.add(i, 100+i);
    }
    map.print();
    printf("\nsize: %d\n", map.getSize());

    map.remove(4987);
    map.print();
    printf("\nsize: %d\n", map.getSize());
}
