#pragma once
#include "Macros.h"

class Shape
{
private:
public:
	Shape(){};
	~Shape(){};

	virtual void Draw() = 0;
	virtual void SetColor(int colorId) = 0;
};

