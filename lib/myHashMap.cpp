#pragma once

namespace myHashMap {

template <typename K, typename V>
struct node {
    node(const K &key, const V &value) : key(key), value(value), next(NULL) {}
    K key;
    V value;
    node * next;
};

template <typename K, typename V>
class myHashMap {
    private:
    node<K, V> ** container;
    unsigned int num_buckets;
    unsigned int curr_size;

    unsigned long hashFunc(const K &key) {
        //auto _hash =  reinterpret_cast<unsigned long>(key) % num_buckets;
        //return _hash;
        return key % this->num_buckets;
    }

    public:
    myHashMap() = delete;
    myHashMap(unsigned int num_buckets) : container(new node<K,V>*[num_buckets]), num_buckets(num_buckets), curr_size(0) {
        // WHAT
        for(int i = 0; i < num_buckets; i++) {
            container[i] = NULL;
        }
    }

    ~myHashMap() {
        for(int i = 0; i < this->num_buckets; ++i) {
            if(this->container[i] != NULL) {
                node<K,V> * curr_node = this->container[i];
                while(curr_node != NULL) {
                    node<K,V> * prev_node = curr_node;
                    curr_node = curr_node->next;
                    delete prev_node;
                }
            }
        }
        delete[] container;
    }


    void add(const K key, const V value) {
        int _hash = hashFunc(key);
        this->curr_size++;

        if(this->container[_hash] == NULL) {
            this->container[_hash] = new node<K,V>(key,value);
            return;
        }

        node<K,V> * curr_node = this->container[_hash];
        node<K,V> * prev_node = NULL;
        while(curr_node != NULL && curr_node->key != key) {
            prev_node = curr_node;
            curr_node = curr_node->next;
        }
        if(curr_node != NULL) {
            this->curr_size--;
            return;
        }
        prev_node->next = new node<K,V>(key, value);
    }

    bool contains(const K &key) {
        int _hash = hashFunc(key);
        node<K,V> * curr_node = this->container[_hash];
        if(curr_node == NULL)
            return false;
        while(curr_node != NULL && curr_node->key != key && curr_node->next != NULL) {
            curr_node = curr_node->next;
        }
        return curr_node->key == key;
    }

    V get(const K &key) {
        int _hash = hashFunc(key);
        node<K,V> * curr_node = this->container[_hash];
        while(curr_node != NULL && curr_node->key != key && curr_node->next != NULL) {
            curr_node = curr_node->next;
        }
        if(curr_node->key == key) {
            return curr_node->value;
        } else {
            throw "Could not find";
        }
    }

    bool remove(const K &key) {
        int _hash = hashFunc(key);
        node<K,V> * curr_node = this->container[_hash];
        node<K,V> * prev_node = NULL;
        while(curr_node != NULL && curr_node->key != key && curr_node->next != NULL) {
            prev_node = curr_node;
            curr_node = curr_node->next;
        }
        if(curr_node->key == key) {
            if(prev_node == NULL) {
                //delete curr_node;
                this->container[_hash] = curr_node->next;
            } else {
                prev_node->next = curr_node->next;
            }
            delete curr_node;
            this->curr_size--;
            return true;
        }
        return false;
    }

    int getSize() {
        return curr_size;
    }

    void print() {
        for (int i = 0; i < this->num_buckets; i++) {
            if(this->container[i] != NULL) {
                printf("[%d]->%d", this->container[i]->key, this->container[i]->value);
                node<K,V> * curr_node = this->container[i]->next;
                while(curr_node != NULL) {
                    printf(" + [%d]->%d", curr_node->key, curr_node->value);
                    curr_node = curr_node->next;
                }
                printf("\n");
            } else {
                printf("NULL\n");
            }
        }
    }

};
}
