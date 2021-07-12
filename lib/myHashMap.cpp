
template <typename T>
class myHashMap {
    private:
    T * container;
    unsigned int num_buckets;
    public:
    myHashMap() : container(nullptr), num_buckets(0) {}
};
