

#pragma once

namespace myHashMap {

template <typename K, typename V>
struct node {
    node(const K key, const V value) : key(key), value(value), next(nullptr) {}
    K key;
    V value;
    node * next;
};

template <typename K, typename V>
class myHashMap {
    private:
    node<K, V> ** container;
    unsigned int num_buckets;

    unsigned long hashFunc(const K &key) {
        //auto _hash =  reinterpret_cast<unsigned long>(key) % num_buckets;
        //return _hash;
        return key % this->num_buckets;
    }

    public:
    myHashMap() = delete;
    myHashMap(unsigned int num_buckets) : container(new node<K,V>*[num_buckets]), num_buckets(num_buckets) {}

    ~myHashMap() {
        for(int i = 0; i < this->num_buckets; ++i) {
            node<K,V> * curr_node = this->container[i];
            while(curr_node != nullptr) {
                node<K,V> * prev_node = curr_node;
                curr_node = curr_node->next;
                delete prev_node;
            }
            this->container[i] = nullptr;
        }
        delete[] container;
    }

    void add(const K key, const V value) {
        int _hash = hashFunc(key);
        node<K,V> * curr_node = container[_hash];
        if(curr_node == NULL) {
            container[_hash] = new node<K,V>(key, value);
            return;
        }
        while(curr_node->next != nullptr) {
            if(curr_node->key == key) { return; }
            curr_node = curr_node->next;
        }
        curr_node->next = new node<K,V>(key, value);
    }

    V get(const K &key) {
        int _hash = hashFunc(key);
        node<K,V> *curr_node = this->container[_hash];
        while(curr_node->key != key && curr_node->next != nullptr) {
            curr_node = curr_node->next;
        }
        if(curr_node->next == nullptr && curr_node->key != key) { throw "out of bounds"; }
        if(curr_node->key == key) { return curr_node->value; }
    }

    bool remove(const K &key) {
        int _hash = hashFunc(key);
        node<K,V> *curr_node = this->container[_hash];
        node<K,V> *prev_node = NULL;
        while(curr_node->key != key && curr_node->next != nullptr) {
            prev_node = curr_node;
            curr_node = curr_node->next;
        }

        if(prev_node == NULL) {
            this->container[_hash] = this->container[_hash]->next;
            delete curr_node;
            return true;
        }

        if(curr_node->key == key) {
            if(curr_node->next != nullptr) {
                prev_node->next = curr_node->next;
            } else {
                prev_node->next = nullptr;
            }
            delete curr_node;
            return true;
        };
        return false;
    }

    void print() {
        for (int i = 0; i < this->num_buckets; i++) {
            if(this->container[i] != nullptr) {
                node<V,K> * curr_node = this->container[i];
                printf("%d", curr_node->value);
                while(curr_node->next != nullptr) {
                    curr_node = curr_node->next;
                    printf(" -> %d", curr_node->value);
                }
                printf("\n");
            }
        }
    }

};
}
