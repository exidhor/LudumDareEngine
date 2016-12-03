#pragma once
#include <cstdlib>

namespace MathHelper
{

	/**
	 * \brief	Return a Random value between 0 and max		
	 * \param	max : the maximum value
	 * \return	the random value 
	 */
	float RandomFloat(float max);

	/**
	 * \brief	Return a random value with a binomial distribution
	 *			The random value is between -max and +max 
	 * \param	max : the negative and positive boundary 
	 * \return  a random value
	 */
	float RandomBinomial(float max);
}