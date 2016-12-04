#pragma once

/*
* \brief   It is a container to store an object
*          and it's collision bounds (a rect).
*/
template<class Object>
class QuadTreeContainer
{
public:
	/**
	 * \brief	Construct the QuadTreeContainer 
	 * \param	object : The object to store
	 * \param	rect : The collider
	 */
	QuadTreeContainer(const Object object, sf::FloatRect const& rect)
		: m_object(object),
		m_rect(rect)
	{
		// nothing
	}

	QuadTreeContainer<Object> & operator=(QuadTreeContainer const& other)
	{
		m_object = other.m_object;
		m_rect = other.m_rect;

		return *this;
	}

	/**
	 * \brief	Return the object stored
	 * \return	The object stored
	 */
	Object const& GetObject() const
	{
		return m_object;
	}

	/**
	 * \brief	Return the collider
	 * \return	The colllider
	 */
	sf::FloatRect const& GetRect() const
	{
		return m_rect;
	}

private:
	Object m_object;
	sf::FloatRect m_rect;
};