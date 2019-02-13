//
//  main.cpp
//  Interview Practice
//
//  Created by Jesse Mihigo on 1/30/19.
//  Copyright © 2019 Jesse. All rights reserved.
//

#include <iostream>
#include "StringBuilder.cpp"
#include "ArrayList.cpp"
#include "HashTable.cpp"
#include "SinglyLinkedList.cpp"
#include <unordered_map>
#include <string>
#include <stack>
#include <unordered_set>

using namespace std;

template <class T>
LinkedListNode<T> * reverseLinkedListIterative(LinkedListNode<T> * head) {
    if(head == nullptr || head->next == nullptr)
        return head;
    LinkedListNode<T> * reversedHead;
    LinkedListNode<T> * node;
    reversedHead = head;
    node = head->next;
    reversedHead->next = nullptr;
    while(node != nullptr) {
        LinkedListNode<T> * temp = node->next;
        node->next = reversedHead;
        reversedHead = node;
        node = temp;
    }
    return reversedHead;
}

template <class T>
LinkedListNode<T> * reverseLinkedListRecursive(LinkedListNode<T> * head) {
    if(head == nullptr || head->next == nullptr)
        return head;
    LinkedListNode<T> * reversedHead;
    LinkedListNode<T> * node;
    reversedHead = head;
    node = head->next;
    reversedHead->next = nullptr;
    while(node != nullptr) {
        LinkedListNode<T> * temp = node->next;
        node->next = reversedHead;
        reversedHead = node;
        node = temp;
    }
    return reversedHead;
}

int findLongestSubstringWithAtMostKCharactersSubroutine(string s, unordered_map<char,int> &map, int start) {
    char characterToRemove = s[start];
    for(int i = start; i < s.length(); i++) {
        char current = s[i];
        map[current]--;
        if(map[current] == 0) {
            map.erase(map.find(current));
        }
        if(current == characterToRemove && map.find(characterToRemove) == map.end()) {
            return i+1;
        }
    }
    return -1;
}

int findLongestSubstringWithAtMostKCharacters(string s, int k) {
    int start = 0;
    unordered_map<char,int> map;
    int answer = 0;
    for(int i = 0; i < s.length(); i++) {
        char c = s[i];
        if(map.find(c) == map.end()) {
            map[c] = 1;
        }
        else map[c]++;
        if(map.size() == k && (i - start + 1) > answer) {
            answer = i - start + 1;
            start = findLongestSubstringWithAtMostKCharactersSubroutine(s, map, start);
        }
    }
    if(answer == 0) return (int)s.length();
    return answer;
}


string reverseInParenthesesSubroutine(string s, int &start) {
    string result;
    stack<string> aStack;
    for(int i = start+1; i < s.length(); i++) {
        char c = s[i];
        if(c != '(' && c != ')')
            aStack.push(string(s,i,1));
        else if(s[i] == '('){
            aStack.push(reverseInParenthesesSubroutine(s,i));
        }
        else {
            start = i;
            break;
        }
    }
    while(!aStack.empty()) {
        result += aStack.top();
        aStack.pop();
    }
    return result;
}
std::string reverseInParentheses(std::string inputString) {
    string result;
    for(int i = 0; i < inputString.length(); i++) {
        if(inputString[i] != '(')
            result += string(inputString, i, 1);
        else
            result += reverseInParenthesesSubroutine(inputString, i);
    }
    return result;
}
void swapCharactersInString(string & s, int a, int b) {
    if(a == b)
        return;
    char temp = s[a];
    s[a] = s[b];
    s[b] = temp;
}

void printStringPermutationRecursiveRoutine(string & s, int start) {
    if(start == (s.size()-1))
        cout<<s<<endl;
    for(int i = start; i < s.length(); i++) {
        swapCharactersInString(s, start, i);
        printStringPermutationRecursiveRoutine(s, start + 1);
        swapCharactersInString(s, start, i);
    }
}

void printStringPermutation(string s) {
    printStringPermutationRecursiveRoutine(s, 0);
}

template <class T>
LinkedListNode<T> * returnKthToLastRecursiveSubroutine(LinkedListNode<T> * node, int k, int & i) {
    if(node == nullptr)
        return nullptr;
    LinkedListNode<T> * anotherNode = returnKthToLastRecursiveSubroutine(node->next, k, i);
    i++;
    if(i == k)
        return node;
    return anotherNode;
}

template <class T>
LinkedListNode<T> * returnKthToLast(SinglyLinkedList<T> * list, int k) {
    if(list->head == nullptr) {
        return nullptr;
    }
    int i = 0;
    return returnKthToLastRecursiveSubroutine(list->head, k, i);
}

template <class T>
bool binarySearch(vector<T> v, T n) {
    int low = 0;
    int high = (int)v.size()-1;
    while(low <= high) {
        int middle = (low + high)/2;
        if(n > v[middle])
            low = middle + 1;
        else if(n < v[middle])
            high = middle - 1;
        else return true;
    }
    return false;
}
template <class T>
void mergeSortedArrays(vector<T> & array, vector<T> & helper, int low, int middle, int high) {
    //copy to helper vector
    for(int i = low; i <= high; i++) {
        helper[i] = array[i];
    }
    int left = low;
    int right = middle + 1;
    int current = low;
    while(left <= middle && right <= high) {
        if(helper[left] <= helper[right]) {
            array[current] = helper[left];
            left++;
        }
        else {
            array[current] = helper[right];
            right++;
        }
        current++;
    }
    //if any leftover items remaining on the left side, copy it over. no need to do the same on the right
    //since the items are already there
    int remainingOnTheLeft = middle - left + 1;
    for(int i = 0; i < remainingOnTheLeft; i++) {
        array[current + i] = helper[left + i];
    }
}
template <class T>
void mergeSortHelper(vector<T> & array, vector<T> & helper, int low, int high) {
    if(low < high) {
        int middle = (low + high)/2;
        mergeSortHelper(array, helper, low, middle);
        mergeSortHelper(array, helper, middle + 1, high);
        mergeSortedArrays(array, helper, low, middle, high);
    }
}

template <class T>
void mergeSort(vector<T> & array) {
    vector<T> helper(array.size());
    mergeSortHelper(array, helper, 0, (int)array.size() - 1);
}

template<class T>
void printVector(vector<T> & v) {
    for(int i : v)
        cout<<i<<" ";
    cout<<endl;
}

int main(int argc, const char * argv[]) {
    StringBuilder stringBuilder;
    stringBuilder.addString("some string 1");
    stringBuilder.addString(" a second string");
    cout << "String builder result: " << stringBuilder.getString() << endl;
    ArrayList<int> anArrayList;
    for(int i = 0; i < 10; i++)
        anArrayList.push_back(i+1);
    for(int i = 0; i < 10; i++)
        cout<<" "<<anArrayList[i];
    cout<<endl;
    SinglyLinkedList<int> someLinkedList(0);
    for(int i = 1; i < 5; i++) {
        someLinkedList.appendToTail(i);
        string s;
        s += "swqs";
    }
    SinglyLinkedList<int>::print(someLinkedList.head);
    SinglyLinkedList<int>::print(reverseLinkedListIterative(someLinkedList.head));
    cout<<"Longest substring: "<<findLongestSubstringWithAtMostKCharacters("aabccba", 2)<<endl;
    cout<<"Longest substring: "<<findLongestSubstringWithAtMostKCharacters("aabcddccacbd", 3)<<endl;
    cout<<"Longest substring: "<<findLongestSubstringWithAtMostKCharacters("aaa", 3)<<endl;
    printStringPermutation("abc");
    cout<<binarySearch<int>({1,2,3,4}, 4)<<" "<<binarySearch<int>({1,2,3,4}, 0)<<endl;
    vector<int> v = {1, 4, 5, 0, 3, 6, 0};
    printVector(v);
    mergeSort(v);
    printVector(v);
    return 0;
}
