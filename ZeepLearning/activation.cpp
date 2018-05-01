#include "activation.h"
#include <math.h>

double activate(double x, char * activation_function)
{
	if (activation_function == "relu")
		return relu(x);
	else if (activation_function == "sigmoid")
		return sigmoid(x);
}

double relu(double x)
{
	return (x<0)?0.0:x;
}

double sigmoid(double x)
{
	// 1/(1+e^-x)
	return 1 / (1 + exp(-x));
}
