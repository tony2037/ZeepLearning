#include "Fully_Connect.h"
#include <stdlib.h>
#include <stdio.h>

int init_FC(FC * fc, int input_size, int output_size , char *activation)
{
	fc->input_size = input_size;
	fc->output_size = output_size;
	printf("%c", *activation);
	(fc->activation) = activation;
	fc->Weights = (double **)malloc((output_size) * sizeof(double*));
	for (size_t i = 0; i < output_size; i++) {
		fc->Weights[i] = (double *)malloc((input_size) * sizeof(double));
	}
	fc->Bias = (double*)malloc((output_size) * sizeof(double));
	fc->next_layer = NULL;
	return 0;
}

int summary_FC(FC * fc)
{
	printf("===========================\n");
	printf("input size : %d \n", fc->input_size);
	printf("output size : %d \n", fc->output_size);
	printf("parameters numbers : %d \n", ((fc->input_size)*(fc->output_size)+fc->output_size));
	printf("===========================\n");
	return 0;
}

