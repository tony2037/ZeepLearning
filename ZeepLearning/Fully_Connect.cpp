#include "Fully_Connect.h"
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

int init_FC(FC * fc, int input_size, int output_size , char *activation)
{
	// Initialize fc->Output
	fc->Output = (double*)malloc((output_size)* sizeof(double));
	memset(fc->Output, 0, sizeof(double)* output_size);
	// Initialize fc->OutputActivate
	fc->OutputActivate = (double*)malloc((output_size) * sizeof(double));
	memset(fc->OutputActivate, 0, sizeof(double)* output_size);
	// Initialize fc->Input
	fc->Input = (double*)malloc((input_size) * sizeof(double));
	memset(fc->Input, 0, sizeof(double)* input_size);
	// Initialize fc->input_size fc->output_size
	fc->input_size = input_size;
	fc->output_size = output_size;
	// Initialize fc->activation
	(fc->activation) = activation;
	// Initialize fc->Weights
	fc->Weights = (double **)malloc((output_size) * sizeof(double*));
	for (size_t i = 0; i < output_size; i++) {
		fc->Weights[i] = (double *)malloc((input_size) * sizeof(double));
		memset(fc->Weights[i], 0, sizeof(double)* input_size);
	}
	// Initialize fc->Bias
	fc->Bias = (double*)malloc((output_size) * sizeof(double));
	memset(fc->Bias, 0, sizeof(double)* output_size);
	// Initialize fc->next_layer
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

