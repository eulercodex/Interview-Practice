//
//  StringBuilder.cpp
//  Interview Practice
//
//  Created by Jesse Mihigo on 1/30/19.
//  Copyright © 2019 Jesse. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>

class StringBuilder {
private:
    std::vector<char>storage;
public:
    void addString(std::string s);
    std::string getString();
};

void StringBuilder::addString(std::string s) {
    for(char c : s) {
        storage.push_back(c);
    }
}

std::string StringBuilder::getString() {
    return std::string(&storage[0],storage.size());
}
