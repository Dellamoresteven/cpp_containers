#include "myHashMap.cpp"

template <typename T>
class mySet {
    private:
    myHashMap::myHashMap<T,bool> myMap;

    public:

    mySet(int num_buckets) : myMap(myHashMap::myHashMap<T,bool>(num_buckets)) {

    }

    void add(T key) {
        myMap.add(key, false);
    }

    bool contains(T key) {
        return myMap.contains(key);
    }

    bool remove(T key) {
        return myMap.remove(key);
    }

    bool getSize(T key) {
        return myMap.getSize(key);
    }

    void print() {
        myMap.print();
    }
};
