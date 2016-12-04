/// \file    PoolAllocator.hpp
/// \date    03/12/2016
/// \brief   Contains the header of the class PoolAllocator
/// \author  Aredhele
/// \version 0.1.0

#ifndef __POOL_ALLOCATOR_HPP
#define __POOL_ALLOCATOR_HPP

#include <vector>
#include "Memory/Resource.hpp"

/// \class  PoolAllocator
/// \brief  Handle memory for a type T
template <typename T>
class PoolAllocator
{
public :

    /// \brief  Default constructor
    explicit PoolAllocator();

    /// \brief  Default destructor
    ~PoolAllocator();

    /// \brief  Initialize the pool with size objects
    /// \param  size The number of objects
    void Init(unsigned int size);

    /// \brief  Always returns a resource of type T
    /// \return T* A pointer on a resource
    T * Allocate();

    /// \brief  Free a resource
    /// \param  resource The pointer on the resource
    void Deallocate(T * resource);

private :

    std::vector < Resource < T > > m_resources;
};

#include "Memory/PoolAllocator.inl"

#endif // __POOL_ALLOCATOR_HPP