#pragma once
#include <iostream>

template <typename T>
class Set
{
protected:
    T *elements = new T[1];
    size_t size = 0;
    size_t capacity = 1;
    static int id;
    char *name;

    void free();
    void copyFrom(const Set &other);
    void move(Set &&other);
    virtual void resize();

public:
    Set();
    Set(T *&elements, size_t size, char *&name) = delete;
    virtual ~Set();

    Set(const Set &other);
    Set &operator=(const Set &other);

    Set(Set &&other);
    Set &operator=(Set &&other);

    void print() const;
    void setName(const char *name);
    char *getName() const;
    size_t getSize() const;

    T &operator[](const int index) const;

    virtual void addElement(const T &el);
    virtual Set<T> *clone() const;

    friend void operator>>(std::istream &is, const T &element);
};

template <typename T>
int Set<T>::id = 0;

template <typename T>
bool operator==(const T &first, const T &second);
