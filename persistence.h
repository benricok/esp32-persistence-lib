#pragma once

#include <Preferences.h>
#include "debug.h"

/**
 * @brief Persistence class
 *
 * @note Specify the type of data to be stored as a template parameter
*/
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
