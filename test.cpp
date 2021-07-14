#include "./lib/containers.h"

#include <stdlib.h>
#include <string>
#include <iostream>
#include <assert.h>
using namespace std;

int main() {
    //myHashMap::myHashMap<int,int> map(10);
    //for(int i = 0; i < 100; i++) {
        //map.add(i,i+1);
    //}
    //map.print();
    //printf("------------------\n");
    //printf("%d\n",map.get(50));
    //map.print();
    //printf("------------------\n");


    //myVector<int> vec;
    //vec.push(10);
    //vec.push(7);
    //vec.push(8);
    //vec.push(9);
    //vec.push(1);
    //vec.push(5);
    //myVector<float>::print_vector(vec);
    //sort::qsort(vec, 0, vec.size()-1);
    //cout << "Sorted array: \n";
    //myVector<float>::print_vector(vec);

    //printf("\n\n\n\n");

    //myVector<float> vecf;
    //vecf.push(10.5);
    //vecf.push(7.1);
    //vecf.push(7.2);
    //vecf.push(8.4);
    //vecf.push(1.5);
    //vecf.push(5.6);
    //myVector<float>::print_vector(vecf);
    //sort::qsort(vecf, 0, vecf.size()-1);
    //cout << "Sorted array: \n";
    //myVector<int>::print_vector(vecf);

    //myVector<float> vecf;
    //vecf.push(10.5);
    //vecf.push(7.1);
    //vecf.push(7.2);
    //vecf.push(8.4);
    //vecf.push(1.5);
    //vecf.push(5.6);
    //myVector<float>::print_vector(vecf);
    //sort::qsort(vecf, 0, vecf.size()-1);
    //cout << "Sorted array: \n";
    //myVector<int>::print_vector(vecf);


    mySet<int> sett(10);
    for(int i = 0; i < 50; i++) {
        sett.add(i);
    }
    sett.print();
    for(int i = 40; i < 50; i++) {
        sett.remove(i);
    }
    sett.print();
}
