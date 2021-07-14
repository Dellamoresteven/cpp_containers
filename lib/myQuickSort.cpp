
#pragma once

namespace sort {

//int partition(myVector<int> &vec, int low, int high) {
    //int pivot = vec.at(high);
    //int i = (low - 1);
    //for(int j = low; j <= high -1; j++) {
        //if(vec.at(j) < pivot) {
            //vec.swap(++i,j);
        //}
    //}
    //vec.swap(++i, high);
    //return i;
//}

//void qsort(myVector<int> &vec, int low, int high) {
    //if(low < high) {
        //int part = partition(vec, low, high);
        //qsort(vec, low, part-1);
        //qsort(vec, part+1, high);
    //}
//}





template <typename T>
int partition(myVector<T> &vec, int low, int high) {
    T pivot = vec.at(high);
    int i = (low - 1);
    for(int j = low; j <= high - 1; j++) {
        if(vec.at(j) < pivot) {
            vec.swap(++i,j);
        }
    }
    vec.swap(++i, high);
    return i;
}

template <typename T>
void qsort(myVector<T> &vec, int low, int high) {
    if(low < high) {
        int part = partition(vec, low, high);
        qsort(vec, low, part-1);
        qsort(vec, part+1, high);
    }
}
}
