#pragma once

#include <Preferences.h>
#include "../lib/debug.h"

// -----------------------------------------------------------------------------
// Persistence
// -----------------------------------------------------------------------------
template <typename T>
class Persistence : private Preferences
{
public:
    Persistence(const char *newNamespace) : namespace_(newNamespace) {
        this->begin(namespace_);
    }
    ~Persistence() {
        this->end();
    };

    bool updateData(T *newData, bool store = true);
    bool loadData();
    bool storeData();
    T getData();

    T data;

private:
    const char *namespace_;
};

extern template class Persistence<int>;
