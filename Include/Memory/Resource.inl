template <typename T>
/* explicit */ Resource<T>::Resource()
: m_resource()
, m_available(true)
{
    // None
}

template <typename T>
inline T * Resource<T>::GetResource()
{
    return &m_resource;
}

template <typename T>
inline bool Resource<T>::IsAvailable()
{
    return m_available;
}

template <typename T>
inline void Resource<T>::SetAvailable(bool available)
{
    m_available = available;
}