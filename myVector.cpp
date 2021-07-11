#include <stdio.h>

#include "myString.cpp"

template <typename T>
class myVector {
    private:
    T * container = nullptr;
    unsigned int curr_size;
    unsigned int cap;
    public:
    myVector(unsigned int default_size) : container(new T[default_size]), cap(default_size), curr_size(0){}

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

    T get(int index) {
        return (index < curr_size ? container[index] : nullptr);
    }

    int size() {
        return curr_size;
    }

    T at(int index) {
        if(index >= curr_size) {
            throw "stop";
        }
        if(index < 0) {
            index = this->curr_size + index;
        }
        return this->container[index];
    }

    void print() {
        printf("[ ");
        for(int i = 0; i < curr_size; i++) {
            printf("%d ", this->container[i]);
        }
        printf("]\n");
    }
};

#include <iostream>
using namespace std;
int main () {
    //myVector<std::string> vec(10);
    myVector<myString> vec(10);
    vec.push("hello");
    vec.push(" ");
    vec.push("world");
    vec.push("\n");
    for(int i = 0; i < vec.size(); i++) {
        printf("%s", vec.at(i).c_str());
    }

    //for(int i = 0; i < 10000; i++) {
        //vec.push(i);
    //}
    //vec.print();
}
