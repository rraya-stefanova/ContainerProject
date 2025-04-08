#include <iostream>
#include "Container.h"

void Container::free()
{
    for (int i = 0; i < size; i++)
    {
        delete collection[i];
    }
    delete[] collection;
}

void Container::copyFrom(const Container &other)
{
    this->max_capacity = other.max_capacity;
    this->size = other.size;
    this->collection = new Set<char> *[max_capacity];

    for (int i = 0; i < other.size; i++)
    {
        this->collection[i] = other.collection[i]->clone();
    }
}
Container::Container()
{
    max_capacity = 1;
    size = 0;
    collection = new Set<char> *[1];
}
Container::Container(Set<char> **&collection, const size_t size, const size_t max_capacity)
{
    this->max_capacity = max_capacity;
    this->size = size;
    this->collection = new Set<char> *[max_capacity];

    for (int i = 0; i < size; i++)
    {
        this->collection[i] = collection[i]->clone();
    }
}

Container::~Container()
{
    free();
}

Container::Container(const Container &other)
{
    copyFrom(other);
}

Container &Container::operator=(const Container &other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

Container::Container(Container &&other)
{
    size = other.size;
    max_capacity = other.max_capacity;

    collection = other.collection;
    other.collection = nullptr;
}

Container &Container::operator=(Container &&other)
{
    if (this != &other)
    {
        free();

        size = other.size;
        max_capacity = other.max_capacity;
        collection = other.collection;
        other.collection = nullptr;
    }
    return *this;
}

void Container::addSymbols(char *&list, size_t &listSize)
{
    for (int i = 0; i < listSize; i++)
    {
        this->collection[i]->addElement(list[i]);
        std::cout << "for : ";
        collection[i]->print();
    }
}
