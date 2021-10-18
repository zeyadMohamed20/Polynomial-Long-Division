#ifndef POLYNOMIAL_OUTPUT_H_
#define POLYNOMIAL_OUTPUT_H_
#include<math.h>
#include<stdio.h>
#include"data_types.h"

/*
* This function is used to print the whole result so this function takes to parameters which are pointer to pointer
* that points to the array of pointers(defined in main function) and the size of array of pointers
*/
void PrintResult(polynomial** result, const int size);

#endif /*POLYNOMIAL_OUTPUT_H_*/