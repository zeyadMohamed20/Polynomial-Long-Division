/*
************************************************************************************************************
@file      polynomial_output.c
@author    Zeyad Mohamed Abd El-Hamid
@id        1900959
@brief     This file controls the process of printing the whole result calculated by LongDivision function 
************************************************************************************************************
*/

#include "polynomial_output.h"

/*
* This function only one polynomial so it takes only one arguments which is the refrence of polynomial that will
* be printed
*/
void PrintPolynomial(polynomial* expression);//private function

void PrintPolynomial(polynomial* expression)
{
	int i;
	/*
	* There are 4 cases of the term in the polynomial:
	* a) The term of highest degree
	* b) The term of degree equal to one
	* c) The term of degree equal to zero
	* d) The term of any degree except a,b,c
	* if a is satisfied:
	* then there are two conditions:
	*   i) if the degree of polynomial is equal to zero 
	*   ii) if the degree not equal zero
	*	if i is satsified:
	*	  1) if the coeff is +ve
	*	  2) if the coeff is -ve
	*	  if 1) is satisfied then print the number without postive sign before
	*	  if 2) is satisfied then print the number with negative sign before
	*	if ii is satisfied then 1) then prints the number with postive sign before
	*	                   then 2) then prints the number with negative sign before
	* The same behaviour we do in case b,c,d
	* We notice that all cases a,b,c,d under the main condition that the coefficient not equal to zero 
	* as it is meaningless to prints coefficient equal to zero
	*/
	for (i = expression->degree; i >= 0; i--)
	{
		if (expression->coeff[i] != 0)
		{
			if (i == 0)
			{
				if (i == expression->degree)
				{
					if (expression->coeff[i] > 0)
					{
						printf("%.1f ", fabs(expression->coeff[i]));
					}
					else if (expression->coeff[i] < 0)
					{
						printf("- %.1f ", fabs(expression->coeff[i]));
					}
				}
				else
				{
					if (expression->coeff[i] > 0)
					{
						printf("+ %.1f ", fabs(expression->coeff[i]));
					}
					else if (expression->coeff[i] < 0)
					{
						printf("- %.1f ", fabs(expression->coeff[i]));
					}
				}
			}
			else if (i == 1)
			{
				if (i == expression->degree)
				{
					if (expression->coeff[i] == 1)
					{
						printf("X ");
					}
					else if (expression->coeff[i] == -1)
					{
						printf("-X ");
					}
					else if (expression->coeff[i] > 0)
					{
						printf("%.1f X ", fabs(expression->coeff[i]));
					}
					else if (expression->coeff[i] < 0)
					{
						printf("- %.1f X ", fabs(expression->coeff[i]));
					}
				}
				else
				{
					if (expression->coeff[i] == 1)
					{
						printf("+ X ");
					}
					else if (expression->coeff[i] == -1)
					{
						printf("- X ");
					}
					else if (expression->coeff[i] > 0)
					{
						printf("+ %.1f X ", fabs(expression->coeff[i]));
					}
					else if (expression->coeff[i] < 0)
					{
						printf("- %.1f X ", fabs(expression->coeff[i]));
					}
				}
			}
			else if (i == expression->degree)
			{
			    if (expression->coeff[i] == 1)
			    {
				   printf("X^%d ", i);
			    }
			    else if (expression->coeff[i] == -1)
			    {
				   printf("-X^%d ", i);
			    } 
				else
				{
					printf("%.1f X^%d ", expression->coeff[i], i);
				}
				
			}
			else
			{
		        if (expression->coeff[i] == 1)
		        {
			       printf("+ X^%d ", i);
		        }
		        else if (expression->coeff[i] == -1)
		        {
			       printf("- X^%d ", i);
		        }
				else if (expression->coeff[i] > 0)
				{
					printf("+ %.1f X^%d ", fabs(expression->coeff[i]), i);
				}
				else if (expression->coeff[i] < 0)
				{
					printf("- %.1f X^%d ", fabs(expression->coeff[i]), i);
				}
			}
		}	
	}
}


//This function prints the whole result which consists of 3 polynomials which are quotient,reminder,denominator
void PrintResult(polynomial** result, const int size)
{
	int i;
	printf("The result is: ");

	/*
	* The putput format of quotient, reminder and denominator differ from each other 
	* so we separate them by conditions:
	* 1) if we print the quotient then we call the PrintPolynomial function only
	* 2) if we print the reminder then we put postive sign and two brackets between the reminder 
	*    that will be prined by PrintPolynomial function
	* 3) if we print the denominator then we put devision opeartor and two brackets between the denominator
	*    that will be printed by the PrintPolynomial function
	*/
	for (i = 0; i < size - 1; i++)
	{
		if (i == 0)
		{
			PrintPolynomial(result[i]);
		}
		else if (i == 1)
		{
			if (result[i]->degree == -1)
			{
				break;
			}
			else
			{
				printf(" + %c", '(');
				PrintPolynomial(result[i]);
				printf("%c", ')');
			}
		}
		else if (i == 2)
		{
			printf(" %c ", '/');
			printf("%c", '(');
			PrintPolynomial(result[i]);
			printf("%c", ')');
		}
	}
}