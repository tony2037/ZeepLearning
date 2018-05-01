#include "model.h"
#include <stdio.h>
#include <stdlib.h>

int init_model(model * m)
{
	m->FC_head = NULL;
	m->layers_num = 0;
	return 0;
}

int  model_add(model *m, FC *f) {
	// add layer

	// find the tail
	if (m->FC_head == NULL)
		m->FC_head = f;
	else {
		FC *tail;
		tail = m->FC_head;
		while (tail->next_layer != NULL) {
			tail = tail->next_layer;
		}
		tail->next_layer = f;
	}

	// add layers number
	++m->layers_num;

	return 0;
}
double forward(model * m, double *x, double(*LOSS)(double, double), double y)
{
	double *current_input;
	current_input = x;
	double *current_output;
	FC *travel = m->FC_head;
	if (travel == NULL)
		return NULL;
	else {
		while (travel != NULL) {
			current_output = (double*)malloc(sizeof(double) * travel->output_size);
			for (size_t i = 0; i < travel->output_size; i++) {
				for (size_t j = 0; j < travel->input_size; j++)
					current_output[i] += travel->Weights[i][j] * current_input[j] + travel->Bias[i];
			}
			current_input = current_output;
			travel = travel->next_layer;
		}
	}
	return LOSS(current_input[0], y);
}
;

int summary_model(model *m) {
	if (m->FC_head == NULL)
		printf("empty model \n");
	else {
		FC *travel;
		travel = m->FC_head;
		while (travel != NULL) {
			summary_FC(travel);
			travel = travel->next_layer;
		}
	}
	return 0;
}