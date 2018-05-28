#include <vector>
#include <iostream>
#include <functional>
#include <cstdlib>
#include "BloomFilter.h"

using namespace std;

template <class T>
BloomFilter<T>::BloomFilter(int size, int hash_count)
{
    vector<bool> vec(size, false);
    this->array = vec;
    this->hash_count = hash_count;
}

template <class T>
bool BloomFilter<T>::add(T elem)
{
    size_t hash_elem = hash<T>()(elem);
    for(int i=0;i<this->hash_count;i++) {
        int index = (int)(hash<size_t>()(hash_elem+i))%this->array.size();
        array[index] = true;
    }
    return true;
}

template <class T>
bool BloomFilter<T>::contains(T elem)
{
    size_t hash_elem = hash<T>()(elem);
    for(int i=0;i<this->hash_count;i++) {
        int index = (int)(hash<size_t>()(hash_elem+i))%this->array.size();
        if(array[index] == false)
            return false;
    }
    return true;
}

int main() {
    BloomFilter<int> bf(10000, 5);
    for(int i=0;i<5;i++) {
        bf.add(i);
    }
    for(int i=0;i<10;i++) {
        cout << bf.contains(i) << " ";
    }
}