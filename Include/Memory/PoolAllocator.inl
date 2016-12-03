#include "Memory/PoolAllocator.hpp"

template <typename T>
/* explicit */ inline PoolAllocator<T>::PoolAllocator()
{
    // None
}

template <typename T>
inline PoolAllocator<T>::~PoolAllocator()
{
    // None
}

template <typename T>
void PoolAllocator<T>::Init(unsigned int size)
{
    for(unsigned int i = 0; i < size; ++i)
        m_resources.push_back(Resource<T>());
}

template <typename T>
T * PoolAllocator<T>::Allocate()
{
    for(auto& it : m_resources)
    {
        if(it.IsAvailable())
        {
            it.SetAvailable(false);
            return it.GetResource();
        }

    }

    // Need to allocate a new one
    m_resources.push_back(Resource<T>());
    m_resources.back().SetAvailable(false);

    return m_resources.back().GetResources();
}

template <typename T>
void PoolAllocator<T>::Deallocate(T * resource)
{
    for(auto& it : m_resources)
    {
        if(it.GetResource() == resource)
        {
            it.SetAvailable(true);
            break;
        }
    }
}
