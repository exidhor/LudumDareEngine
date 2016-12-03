#include "AI/SteeringOutput.hpp"

SteeringOutput::SteeringOutput()
	: SteeringOutput(Vec2(), 0, false)
{
	// nothing
}

SteeringOutput::SteeringOutput(Vec2 const& linear, float angular, bool isKinematic)
	: linear(linear),
	angular(angular),
	isKinematic(isKinematic)
{
	// nothing
}