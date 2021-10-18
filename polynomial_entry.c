/*
**********************************************************************************************************
@file      polynomial_entry.c
@author    Zeyad Mohamed Abd El-Hamid
@id        1900959
@brief     This file controls the process of enetring polynomial by the user
*********************************************************************************************************
*/

#include"polynomial_entry.h"

void EnterPolynomial(polynomial* expression, int count)
{
	int i;
	// main function pass the value of count to know which polynomial the user will enter (1st or 2nd) 
	if (count == 1) 
	{
		printf("Enter the degree of the %dst polynomial: ", count);
	}
	else if (count == 2)
	{
		printf("Enter the degree of the %dnd polynomial: ", count);
	}
	//store the enterd degree in the degree member inside the expression (refrence of structure variable that points to)
	scanf_s("%d", &expression->degree); 

	/*
	* we use calloc function to allocate block of memory inside heep , this block of type float and the number of blocks
	* allocated will be the degree of polynomial the user has entered but calloc returns void pointer so we typecast it
	* to float ponter and store it inside coeff pointer (member inside structure variable) so that coeff pointer 
	* (stored in the stack) holds the address of the coefficients stored in the heep.
	* we use calloc function instead of malloc to initialize the empty places inside the allocation by zero
	*/
	expression->coeff = (float*)calloc(expression->degree, sizeof(float));
	if (expression->coeff)
	{
		/*
		* The next for loop is used to allow the user to enter the coefficients but we make somme conditions 
		* on the counter: 1) if the counter equal 0 -> then prints the constant term instead of X^0
		*                 2) if the counter equal 1 -> then prints X instead of X^1  
		*/
		for (i = expression->degree; i >= 0; i--)
		{
			if (i == 0)
			{
				printf("Enter the constant term: ");
				scanf_s("%f", &expression->coeff[i]);
			}
			else if (i == 1)
			{
				printf("Enter the coefficient of X: ");
				scanf_s("%f", &expression->coeff[i]);
			}
			else
			{
				printf("Enter the coefficient of X^%d: ", i);
				scanf_s("%f", &expression->coeff[i]);
			}
		}
	}
}