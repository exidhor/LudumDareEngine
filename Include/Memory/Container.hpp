/// \file    Container.hpp
/// \date    02/12/2016
/// \brief   Contains the header of the template Container
/// \author  Aredhele
/// \version 0.1.0

#ifndef __CONTAINER_HPP
#define __CONTAINER_HPP

#include <string>
#include <unordered_map>

/// \class  Container
/// \brief  Store resources in an associative array
template <typename T>
class Container
{
public :

    /// \brief  Default constructor
    explicit Container();
    
    /// \brief  Default destructor
    virtual ~Container();

    /// \brief   Return the resource referenced by the given key
    /// \param   key A const reference on the key
    /// \return  T * a pointer on the resource if it exists, else nullptr
    T *  GetResource(const std::string& key);

    /// \brief   Allocate a resource and return a pointer on the new resource
    /// \param   key A const reference
    /// \return  T * A pointer on the newly created resource, else nullptr
    T * LoadResource(const std::string& key);

    /// \brief   Deallocate the memory of the object referenced by the key
    /// \param   key A const reference on the key to find
    ///          the object to delete
    void UnloadResource(const std::string& key);

private:

    typename std::unordered_map <std::string, T*> ::iterator m_iterator; ///< Iterator buffer
    std::unordered_map <std::string, T*> m_resources;                    ///< Map of resources

    /// \brief   Check if the key exists in the resource map
    /// \param   key A const reference on the key to check
    /// \return  true if the key exists, else false
    bool CheckKey(const std::string& key);
};

#include "Memory/Container.inl"

#endif // __CONTAINER_HPP