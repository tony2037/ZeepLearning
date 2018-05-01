#ifndef ZEEPLEARNING_MODEL
#define ZEEPLEARNING_MODEL
#include "Fully_Connect.h"
typedef struct model
{
	FC *FC_head;
	int layers_num;	// sizeof model shape - 1, numbers of FCs
}model;

int init_model(model *m);
int summary_model(model *m);
int model_add(model *m, FC *f);
double forward(model *m, double *x, double(*LOSS)(double,double));
#endif // !ZEEPLEARNING_MODEL
