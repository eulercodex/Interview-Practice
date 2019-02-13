//
//  ArrayList.cpp
//  Interview Practice
//
//  Created by Jesse Mihigo on 1/30/19.
//  Copyright © 2019 Jesse. All rights reserved.
//

#include <stdio.h>

template <class T>
class ArrayList {
private:
    size_t storageSize = 0;
    size_t arrayListLength = 0;
    T * storage;
public:
    void push_back(T element);
    T & operator[](size_t index);
    ~ArrayList();
};

template <class T>
void ArrayList<T>::push_back(T element) {
    if(storageSize == 0) {
        storageSize = 1;
        arrayListLength = 1;
        storage = new T[storageSize];
        storage[0] = element;
        return;
    }
    if(arrayListLength == storageSize) {
        storageSize *= 2;
        T * temp = new T[storageSize];
        memcpy(temp, storage, arrayListLength*sizeof(T));
        delete[] storage;
        storage = temp;
    }
    storage[arrayListLength] = element;
    arrayListLength++;
    return;
}

template <class T>
ArrayList<T>::~ArrayList() {
    delete[] storage;
}

template <class T>
T & ArrayList<T>::operator[](size_t index) {
    if(index >= arrayListLength)
        throw "Index ouf of bound";
    return storage[index];
}
