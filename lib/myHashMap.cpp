

#pragma once

namespace myHashMap {

template <typename K, typename V>
struct node {
    node(const K &key, const V &value) : key(key), value(value), deleted(false) {}
    K key;
    V value;
    bool deleted;
};

template <typename K, typename V>
class myHashMap {
    private:
    node<K, V> ** container;
    unsigned int num_buckets;
    unsigned int curr_size;

    unsigned long hashFunc(int key) {
        return key % this->num_buckets;
    }

    void rehash() {
        this->num_buckets *= 2;
        printf("Rehashing %d -> %d\n", this->num_buckets/2, this->num_buckets);
        node<K,V> ** newContainer = new node<K,V>*[num_buckets];
        for(int i = 0; i < num_buckets/2; ++i) {
            if(container[i] != NULL) {
                int _hash = hashFunc(container[i]->key);
                while(newContainer[_hash] != NULL) {
                    _hash++;
                    _hash %= this->num_buckets;
                }
                newContainer[_hash] = container[i];
            }
        }
        delete[] container;
        container = newContainer;
    }

    void findCorrectHash(int &_hash, const K key) {
        while(this->container[_hash] != NULL && this->container[_hash]->key != key && this->container[_hash]->deleted == false) {
            _hash++;
            _hash %= this->num_buckets;
        }
    }

    public:
    myHashMap() = delete;
    myHashMap(unsigned int num_buckets) : container(new node<K,V>*[num_buckets]), num_buckets(num_buckets), curr_size(0) {
    }

    ~myHashMap() {
        for(int i = 0; i < this->num_buckets; ++i) {
            if(this->container[i] != NULL)
                delete container[i];
        }
        delete[] container;
    }


    void add(const K key, const V value) {
        int _hash = hashFunc(key);
        this->curr_size++;

        if(this->num_buckets < this->curr_size) {
            rehash();
        }

        findCorrectHash(_hash, key);
        if(this->container[_hash] != NULL && this->container[_hash]->deleted == false) {
            this->curr_size--;
            return;
        }
        this->container[_hash] = new node<K,V>(key, value);
    }

    bool contains(const K &key) {
        int _hash = hashFunc(key);
        findCorrectHash(_hash, key);
        return (this->container[_hash] != NULL && this->container[_hash]->key == key);
    }

    V get(const K &key) {
        int _hash = hashFunc(key);
        findCorrectHash(_hash, key);
        // This will SEGV if value is not in the container unsafe, but should call "contains" before "get"
        return this->container[_hash]->value;
    }

    bool remove(const K &key) {
        int _hash = hashFunc(key);
        while(this->container[_hash]->key != key && this->container[_hash]->deleted == true) {
            _hash++;
            _hash %= this->num_buckets;
        }

        if(this->container[_hash] == NULL || this->container[_hash]->deleted == true || this->container[_hash]->key != key) {
            return false;
        }
        this->container[_hash]->deleted = true;
        this->container[_hash]->value = -1;
        //this->curr_size--;
        return true;
    }

    int getSize() {
        return curr_size;
    }

    void print() {
        for (int i = 0; i < this->num_buckets; i++) {
            if(this->container[i] != NULL) {
                if(this->container[i]->deleted) {
                    printf("DELETED\n");
                } else {
                    printf("%d->%d,%d\n", this->container[i]->key, this->container[i]->value, this->container[i]->deleted);
                }
            } else {
                printf("NULL\n");
            }
        }
    }

};
}
