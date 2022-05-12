//
// Created by lanranli-mac on 12/5/2022.
//

#ifndef CFG_HASH_H
#define CFG_HASH_H

#include <vector>

template<typename T>
class HashTable {
private:
    bool inited{};
    std::vector<T> vec;

    void init_hash();

public:

    HashTable() {
        this->inited = false;
    }

    void add(const T &);

    unsigned int hash_value(const T &);
};


template<typename T>
void HashTable<T>::init_hash() {
    std::sort(this->vec.begin(), this->vec.end());
    this->vec.erase(std::unique(this->vec.begin(), this->vec.end()), this->vec.end());
    this->inited = true;
}


template<typename T>
void HashTable<T>::add(const T &t) {
    vec.push_back(t);
}

template<typename T>
unsigned int HashTable<T>::hash_value(const T &t) {
    if (!this->inited) [[unlikely]] {
        this->init_hash();
    }
    auto res = std::lower_bound(this->vec.begin(), this->vec.end(), t);
    if (*res == t) {
        return (res - this->vec.begin()) + 1;
    }
    return 0;
}


#endif //CFG_HASH_H
