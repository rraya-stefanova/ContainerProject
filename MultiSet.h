#pragma once
#include "Set.h"

template <typename T>
class MultiSet : public Set<T>
{

public:
    MultiSet() = default;
    void addElement(const T &element) override;
    Set<T> *clone() const override;
};
