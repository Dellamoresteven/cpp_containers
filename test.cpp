#include "./lib/containers.h"

#include <stdlib.h>
#include <string>
#include <iostream>
#include <assert.h>
using namespace std;

int main() {
    myHashMap::myHashMap<int,int> map(10);
    for(int i = 0; i < 100; i++) {
        map.add(i,i+1);
    }
    map.print();
    printf("------------------\n");
    printf("%d\n",map.get(50));
    map.print();
    printf("------------------\n");
}
