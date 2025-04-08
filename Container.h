#pragma once
#include "Multiset.h"

class Container
{

    size_t max_capacity;
    Set<char> **collection;
    size_t size;

    void free();
    void copyFrom(const Container &other);

public:
    Container();
    ~Container();
    Container(Set<char> **&collection, const size_t size, const size_t max_capacity);

    Container(const Container &other);
    Container &operator=(const Container &other);

    Container(Container &&other);
    Container &operator=(Container &&other);

    void addSymbols(char *&list, size_t &listSize);
};
