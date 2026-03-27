#pragma once
#include <cstdlib>

class Utility
{
public:
	static float RandFloat(float min, float max)
	{
		return ((max - min) * ((float)rand() / RAND_MAX)) + min;
	}
};