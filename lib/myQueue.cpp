

template <typename T>
class myQueue {
    public:
    myVector<T> container;

    myQueue() {}
    ~myQueue() {
    }

    void push(T val) {
        container.push(val);
    }

    T pop() {
        T ret = container.at(0);
        container.remove(0);
        return ret;
    }

    int size() {
        return container.size();
    }

    void print() {
        myVector<int>::print_vector(container);
    }
};
