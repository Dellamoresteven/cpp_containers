#include <stdio.h>

#pragma once
template <typename T>
class myVector {
    private:
    T * container = nullptr;
    unsigned int curr_size;
    unsigned int cap;
    public:
    myVector() : container(new T[1]), cap(1), curr_size(0){}
    myVector(unsigned int default_size) : container(new T[default_size]), cap(default_size), curr_size(0){}
    myVector(const myVector &copyVec) {
        cap = copyVec.capacity();
        curr_size = copyVec.size();
        container = new T[cap];
        for(int i = 0; i < curr_size; i++) {
            container[i] = copyVec.at(i);
        }
    }

    ~myVector() {
        delete[] container;
    }

    void push(T d) {
        if(curr_size == cap) {
            cap *= 2;
            T* newContainer = new T[cap]; // Reallocate
             //copy(begin(container), end(container), begin(newContainer));
            for(int i = 0; i < cap/2; ++i) {
                newContainer[i] = container[i];
            }
            delete[] container;
            container = newContainer;
        }
        container[curr_size++] = d;
    }

    void setVal(int index, T val) {
        if(index >= curr_size) {
            return;
        }
        container[index] = val;
    }

    void remove(int index) {
        if(index > curr_size)
            return;
        for(int i = index; i < curr_size-1; i++) {
            container[i] = container[i+1];
        }
        curr_size--;
    }

    T get(int index) {
        return (index < curr_size ? container[index] : nullptr);
    }

    int size() const {
        return curr_size;
    }

    int capacity() const {
        return cap;
    }

    void swap(const int index1, const int index2) {
        if(index1 >= curr_size || index2 >= curr_size) {
            return;
        }
        T temp = container[index1];
        container[index1] = container[index2];
        container[index2] = temp;
    }

    T at(int index) const {
        if(index >= curr_size) {
            throw "stop";
        }
        if(index < 0) {
            index = this->curr_size + index;
        }
        return this->container[index];
    }

    static void print_vector(const myVector<int> &vec) {
        printf("[ ");
        for(int i = 0; i < vec.size(); i++) {
            printf("%d ", vec.at(i));
        }
        printf("]\n");
    }

    static void print_vector(const myVector<float> &vec) {
        printf("[ ");
        for(int i = 0; i < vec.size(); i++) {
            printf("%f ", vec.at(i));
        }
        printf("]\n");
    }
};
