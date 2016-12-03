/// \file    Resource.hpp
/// \date    03/12/2016
/// \brief   Contains the header of the class Resource
/// \author  Aredhele
/// \version 0.1.0

#ifndef __RESOURCE_HPP
#define __RESOURCE_HPP

/// \class  Resource
/// \brief  Base class for all texture
template <typename T>
class Resource
{
public :

    /// \brief  Construct the resource from a resource
    explicit Resource();

    /// \brief  Return the resource
    /// \return A pointer on the resource
    T * GetResource();

    /// \brief  Tells if the component is available
    bool IsAvailable();

    /// \brief  Set the status of the resource
    /// \param  available The status of the resource
    void SetAvailable(bool available);

private:

    T m_resource;     ///< The resource
    bool m_available; ///< The status of the resource
};

#include "Memory/Resource.inl"

#endif // __RESOURCE_HPP