#include <persistence.h>

template <typename T>
T Persistence<T>::getData()
{
    return data;
}

/**
 *@brief Loads data from esp32's non-volatile memory using the Preferences library
*/
template <typename T>
bool Persistence<T>::loadData()
{
    size_t len = this->getBytesLength(namespace_);
    byte buffer[len];
    this->getBytes(namespace_, buffer, len);
    if (len % sizeof(T))
        return false;
    memcpy(&data, buffer, sizeof(T));
    return true;
}

/**
 * @brief Stores data to esp32's non-volatile memory using the Preferences library
*/
template <typename T>
bool Persistence<T>::storeData()
{
    if (this->putBytes(namespace_, &data, sizeof(T)) > 0)
        return true;
    else
        return false;
}

/**
 * @brief Updates data in memory and optionally stores it to esp32's non-volatile memory
 * using the Preferences library
 * @param newData Pointer to new data
 * @param store If true, store data to esp32's non-volatile memory
*/
template <typename T>
bool Persistence<T>::updateData(T *newData, bool store)
{
    data = *newData;
    if (store)
    {
        return storeData();
    }
    return true;
}
