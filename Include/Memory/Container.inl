#include <iostream>
#include "Main/EngineString.hpp"

template <typename T>
Container<T>::Container()
{
    m_iterator = m_resources.begin();
}

template <typename T>
Container<T>::~Container()
{
    m_iterator = m_resources.begin();
    for(; m_iterator != m_resources.end(); ++m_iterator)
        delete m_iterator->second;
}

template <typename T>
T * Container<T>::GetResource(const std::string& key)
{
    if(!CheckKey(key))
    {
        std::cerr << EngineString::ENGINE_FAILURE_CKNF
                  << " (key = " << key << ")" << std::endl;
        return nullptr;
    }

    return m_iterator->second;
}

template <typename T>
T * Container<T>::LoadResource(const std::string& key)
{
    if(CheckKey(key))
    {
        std::cerr << EngineString::ENGINE_FAILURE_CKAE
                  << " (key = " << key << ")" << std::endl;
        return nullptr;
    }

    T * resource = new T();
    m_resources.emplace(key, resource);

    return resource;
}

template <typename T>
void Container<T>::UnloadResource(const std::string& key)
{
    if(!CheckKey(key))
    {
        std::cerr << EngineString::ENGINE_FAILURE_CKNF
                  << " (key = " << key << ")" << std::endl;
        return;
    }

    delete m_iterator->second;
    m_resources.erase(m_iterator);
}

template <typename T>
bool Container<T>::CheckKey(const std::string& key)
{
    m_iterator = m_resources.find(key);
    return m_iterator != m_resources.end();
}