#include "AI/SteeringOutput.hpp"

SteeringOutput::SteeringOutput()
	: SteeringOutput(Vec2(), 0)
{
	// nothing
}

SteeringOutput::SteeringOutput(Vec2 const& linear, float angular)
	: linear(linear),
	angular(angular)
{
	// nothing
}