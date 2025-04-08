#include <iostream>
#include <cstring>
#include "Set.h"

template <typename T>
void Set<T>::free()
{
    delete[] elements;
    delete[] name;
}

template <typename T>
void Set<T>::copyFrom(const Set<T> &other)
{
    size = other.size;
    capacity = other.capacity;

    elements = new T[capacity];

    for (int i = 0; i < size; i++)
    {
        elements[i] = other.elements[i];
    }

    if (other.name == nullptr)
    {
        name = nullptr;
    }
    else
    {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }
}

template <typename T>
void Set<T>::move(Set &&other)
{
    size = other.size;
    capacity = other.capacity;

    elements = other.elements;
    other.elements = nullptr;

    name = other.name;
    other.name = nullptr;

    id = other.id;
}
template <typename T>
void Set<T>::resize()
{
    capacity *= 2;

    T *buffer = new T[capacity];

    for (int i = 0; i < size; i++)
    {
        buffer[i] = elements[i];
    }

    delete[] elements;
    elements = buffer;
}

template <typename T>
Set<T>::~Set()
{
    free();
}

template <typename T>
Set<T>::Set()
{
    name = nullptr;
    elements = new T[1];
    size = 0;
    capacity = 1;
}

template <typename T>
Set<T>::Set(const Set &other)
{
    copyFrom(other);
}

template <typename T>
Set<T> &Set<T>::operator=(const Set &other)
{
    std::cout << "op = " << std::endl;
    if (this != &other)
    {

        free();
        copyFrom(other);
    }
    return *this;
}

template <typename T>
Set<T>::Set(Set &&other)
{
    move(other);
}

template <typename T>
Set<T> &Set<T>::operator=(Set &&other)
{
    if (this != &other)
    {

        free();
        move(other);
    }
    return *this;
}

template <typename T>
void Set<T>::addElement(const T &element)
{
    if (size == capacity)
    {
        resize();
    }
    try
    {
        for (int i = 0; i < size; i++)
        {
            if (elements[i] == element)
            {
                throw element;
            }
        }
        elements[size++] = element;
    }
    catch (const T &e)
    {
        std::cout << e << " is already in Set" << std::endl;
        return;
    }
}

template <typename T>
void Set<T>::print() const
{
    for (int i = 0; i < size; i++)
    {
        std::cout << elements[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
size_t Set<T>::getSize() const
{
    return size;
}

template <typename T>
void Set<T>::setName(const char *name)
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

template <typename T>
char *Set<T>::getName() const
{
    return this->name;
}

template <typename T>
bool operator==(const T &first, const T &second)
{
    return first == second;
}

template <typename T>
T &Set<T>::operator[](const int index) const
{
    try
    {
        if (index < 0 || index >= size)
        {
            throw index;
        }
        return elements[index];
    }
    catch (const int &e)
    {
        std::cout << e << " is not a valid index; returning 0th element of set" << std::endl;
        return elements[0];
    }
}
template <typename T>
Set<T> *Set<T>::clone() const
{
    return new Set<T>(*this);
}

template <typename T>
void operator>>(std::istream &is, const T &element)
{
    is >> element;
    addElement(element);
}
