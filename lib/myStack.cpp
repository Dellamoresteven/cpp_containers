
template <typename T>
class myStack {
    public:
    myVector<T> container;

    myStack() {}

    void push(T val) {
        container.push(val);
    }

    T pop() {
        T ret = container.at(container.size()-1);
        container.remove(container.size()-1);
        return ret;
    }

    int size() {
        return container.size();
    }

    void print() {
        myVector<int>::print_vector(container);
    }
};
