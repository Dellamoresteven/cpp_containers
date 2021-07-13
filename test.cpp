#include "./lib/containers.h"

#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

int main() {
    myHashMap::myHashMap<int,int> map(10);
    for(int i = 0; i < 10; i++) {
        map.add(i*5,i);
    }
    map.print();
    printf("------------------\n");
    for(int i = 0; i < 10; i++) {
        map.remove(i*5);
    }
    map.print();
    //for(int i = 0; i < 100; i++) {
        //map.add(i*5, 100+i);
    //}
    //printf("\nsize: %d\n", map.getSize());
    //for(int i = 0; i < 101; i++) {
        //printf("deleted %d\n", map.remove(i*5));
    //}
    //map.print();
    //printf("\nsize: %d\n", map.getSize());


    //for(int i = -100; i < 100; i++) {
        //if(map.contains(i))
            //printf("%d %d\n", i, map.get(i));
    //}
    //printf("\n\n\n\n\n");

    //for(int i = 0; i < 500; i++) {
        //printf("%d, %d\n", i*5, map.remove(i*5));
    //}
    //printf("\nsize: %d\n", map.getSize());
    //map.remove(2495);
    //printf("%d\n",map.get(2495));
    //printf("\nsize: %d\n", map.getSize());
    //map.print();

    //for(int i = 0; i < 5000; i++) {
        //map.add(i, 100+i);
    //}
    //map.print();
    //printf("\nsize: %d\n", map.getSize());

    //map.remove(4987);
    //map.print();
    //printf("\nsize: %d\n", map.getSize());
}
