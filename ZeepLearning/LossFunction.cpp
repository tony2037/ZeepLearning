#include "LossFunction.h"
#include <math.h>

double sqr_loss(double y, double y_)
{
	return (1 / 2)* (y - y_)* (y - y_);
}
