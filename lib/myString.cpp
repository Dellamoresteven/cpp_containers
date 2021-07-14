
#pragma once
int char_size(const char* str) {
    int i = 0;
    while(str[i] != '\0') { i++; }
    return i;
}

void mystrncpy(char *dst, const char *src, unsigned int n) {
   char *temp = dst;
   for (int i = 0; i < n; i++)
       dst[i] = src[i];
   dst[n] = '\0';
}


class myString {
    private:
    char* container = nullptr;
    unsigned int size = 0;
    public:

    myString() : container(nullptr), size(0) {}

    myString(const char* convert) {
        size = char_size(convert);
        container = new char[size+1];
        mystrncpy(container, convert, size);
    }

    myString(const myString& obj) {
        size = obj.size;
        container = new char[size+1];
        mystrncpy(container, obj.container, size);
    }

    ~myString() {
        delete[] container;
    }

    char* c_str() const {
        return container;
    }

    char at(int index) {
        if(index >= size) {
            throw "Index out of bounds. Stop";
        }
        if(index < 0) {
            index = size + index;
        }
        return this->container[index];
    }

    unsigned int length() const {
        return size;
    }

    myString operator+(const myString& concat) {
        myString newString;
        newString.size = this->size + concat.size;
        newString.container = new char[newString.size + 1];
        mystrncpy(newString.container, this->container, this->size);
        mystrncpy(newString.container+this->size, concat.container, concat.size);
        return newString;
    }

    myString& operator+=(const myString& concat) {
        myString temp(this->container);
        temp = temp + concat;
        *this = temp;
        return *this;
    }

    myString& operator+=(const char& concat) {
        myString temp;
        temp.size = this->size + 1;
        temp.container = new char[temp.size + 1];
        mystrncpy(temp.container, this->container, this->size);
        temp.container[this->size] = concat;
        temp.container[this->size+1] = '\0';
        *this = temp;
        return *this;
    }

    myString& operator=(const myString& obj) {
        delete[] container;
        size = obj.size;
        container = new char[size + 1];
        mystrncpy(this->container, obj.container, obj.size);
        this->container[size] = '\0';
        return *this;
    }
};
