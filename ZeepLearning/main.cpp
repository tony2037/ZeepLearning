#include "Fully_Connect.h"
#include "model.h"


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

	summary_model(&m1);

	return 0;
}