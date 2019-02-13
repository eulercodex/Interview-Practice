//
//  HashTable.cpp
//  Interview Practice
//
//  Created by Jesse Mihigo on 1/30/19.
//  Copyright © 2019 Jesse. All rights reserved.
//

#include <stdio.h>
#include <list>
#include <vector>

#define DEFAULT_CAPACITY 16

template <class T, class U>
struct hashItem {
    T key;
    U value;
};

template <class T, class U>
class HashTable {
private:
    std::vector<std::list<hashItem<T,U>>>bucket = std::vector<std::list<hashItem<T,U>>>(DEFAULT_CAPACITY);
public:
    U & operator[](T key);
};

template <class T, class U>
U & HashTable<T,U>::operator[](T key) {
    std::hash<T> hashFunction;
    size_t bucketIndex = hashFunction(key)%DEFAULT_CAPACITY;
    std::list<hashItem<T,U>> aList = bucket[bucketIndex];
    for(typename std::list<hashItem<T,U>>::iterator it = aList.begin(); it != aList.end(); it++) {
        if((*it).key == key)
            return (*it).data;
    }
    hashItem<T, U> newItem;
    newItem.key = key;
    aList.push_back(newItem);
    return aList.back().data;
}
