/*!
 * \brief   Header of the class Singleton
 * \file    Singleton.hpp
 * \author  Aredhele
 * \version 0.1
 * \date    30/11/2026
 */

#ifndef __SINGLETON_HPP
#define __SINGLETON_HPP

/// \class  Singleton
/// \brief  Template for the pattern singleton
template <typename T>
class Singleton
{
public:

    /*!
     * \brief   Return the global instance of type T
     * \return  A pointer on the global instance of type T
     */
    static T * Instance()
    {
        if(m_sInstance == nullptr)
            m_sInstance = new T();

        return m_sInstance;
    }

protected:

    /*!
     * \brief   Default Constructor
     */
    Singleton()
    {
        // None
    };

    static T * m_sInstance; ///< The static field containing the T instance

};

template <typename T> T * Singleton<T>::m_sInstance = nullptr;

#endif // __SINGLETON_HPP
