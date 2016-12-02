#include "AI/MathHelper.hpp"

float MathHelper::RandomFloat(float max)
{
	return max * (float(rand()) / RAND_MAX);
}

float MathHelper::RandomBinomial(float max)
{
	return RandomFloat(max) - RandomFloat(max);
}