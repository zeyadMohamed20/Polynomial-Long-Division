#ifndef OPERATION_H_
#define OPERATION_H_
#include<stdio.h>
#include<stdlib.h>
#include"polynomial_entry.h"
#include"data_types.h"

/*
* This function is used to make long divison on the two polynomials the user had enterd as it takes only one parameter
* which is pointer to pointer to polynomial as this double pointer points to the array of pointer 
* (defined in main which holds refrence of quotient,reminder,denominator,numerator) 
* then the function returns integer  that represents the check error 
* to check if the numerator degree grearer than denominator degree or not
*/
int LongDivision(polynomial** result);

#endif /*OPERATION_H_*/