#include <iostream>
#include "Multiset.h"

template <typename T>
void MultiSet<T>::addElement(const T &other)
{

    if (this->size == this->capacity)
    {
        this->resize();
    }

    this->elements[this->size++] = other;
}
template <typename T>
Set<T> *MultiSet<T>::clone() const
{
    return new MultiSet(*this);
}
