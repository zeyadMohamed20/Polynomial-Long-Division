#ifndef POLYNIMOAL_ENTRY_H_
#define POLYNIMOAL_ENTRY_H_
#include <stdio.h>
#include <stdlib.h>
#include "data_types.h"

/*
* This function is used to allow the user to enter polynomial as this function takes two parameters which are 
* the refrence of the expression that the user will enter its degree and coefficients 
* and the count to know which polynomial the user enter (1st polynomial or second one)
*/
void EnterPolynomial(polynomial* expression, int count);

#endif  /*POLYNIMOAL_ENTRY_H_*/