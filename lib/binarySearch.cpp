

int binarySearch(myVector<int> &vec, int search) {
    myVector<int>::print_vector(vec);
    int l = 0;
    int r = vec.size()-1;
    int m = l+(r-l)/2;
    while(l <= r) {
        printf("%d %d %d\n", l, m ,r);
        if(vec.at(m) < search) {
            l = m+1;
            m = l+(r-l)/2;
        } else if(vec.at(m) > search) {
            r = m-1;
            m = l+(r-l)/2;
        } else {
            return m;
        }
    }
    return -1;
}
