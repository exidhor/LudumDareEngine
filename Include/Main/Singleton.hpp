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
        if(m_instance == nullptr)
            m_instance = new T();

        return m_instance;
    }

protected:

    /*!
     * \brief   Default Constructor
     */
    Singleton()
    {
        // None
    };

    static T * m_instance; ///< The static field containing the T instance

};

template <typename T> T * Singleton<T>::m_instance = nullptr;

#endif // __SINGLETON_HPP
