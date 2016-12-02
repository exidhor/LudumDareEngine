#include "Physic/Location/StationaryLocation.hpp"

StationaryLocation::StationaryLocation()
	: StationaryLocation(Vec2())
{
	// nothing
}

StationaryLocation::StationaryLocation(Vec2 const& position, 
									   float orientation)
	: m_position(position),
	m_orientation(orientation)
{
	// nothing
}

Vec2 StationaryLocation::GetPosition() const
{
	return m_position;
}

float StationaryLocation::GetOrientation() const
{
	return m_orientation;
}