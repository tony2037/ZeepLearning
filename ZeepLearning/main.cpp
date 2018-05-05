#include "Fully_Connect.h"
#include "model.h"
#include "LossFunction.h"



double test_x[3] = {2,4,6};
double test_y[1] = {3};


int main() {
	/*
	FC fc1;
	init_FC(&fc1, 2, 3, "relu");
	summary_FC(&fc1);
	*/
	

	model m1;
	init_model(&m1);
	FC fc1;
	init_FC(&fc1, 3, 2, "relu");
	model_add(&m1, &fc1);

	FC fc2;
	init_FC(&fc2, 2, 4, "relu");
	model_add(&m1, &fc2);

	FC fc3;
	init_FC(&fc3, 4, 1, "sigmoid");
	model_add(&m1, &fc3);

	summary_model(&m1);

	forward(&m1, test_x, test_y, sqr_loss);
	return 0;
}