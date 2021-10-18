/*
**********************************************************************************************************
@file      main.c
@author    Zeyad Mohamed Abd El-Hamid
@id        1900959
@brief     This file contains the main process that control the flow of the program
*********************************************************************************************************
*/

#include<conio.h>
#include <stdio.h>
#include"operation.h"
#include"polynomial_entry.h"
#include"data_types.h"
#include "polynomial_output.h"

int main()
{
	char decision; // variable holds the decision of the user to continue the program or not
	polynomial quotient, reminder,denominator,numerator; //structure variables
	//array of pointers to structure which will hold the refrences of quotient,reminder,denominator,numerator
	polynomial* result[] = {&quotient,&reminder, &denominator,&numerator }; 
	const int size = sizeof(result) / sizeof(polynomial*); // size of array (result)
	int count; 
	int errorCheck; /* 
					 *  To check if the degree of denominator grater(it stores 0) 
					 * or less than the degree of numerator(it stores 1) 
					 */
	printf("\t\t****Polynomial Long Division Calculator*****\r\n");

	/*  
	*   The following do-while loop is the central unit of long division, it request from the user to enter the 
	*   first and the second polynomial by calling the function EnterPolynomial then the refrence of result array
	*   is passed as arguments to LongDivision function, this function will call  checkDegree function 
	*   at first to check the degree of numerator and denominator. 
	*   if the degree of denominator is greater than numerator then LongDivision function will be applied, 
	*   else it prints error in the user entry.
	*	In the case of the degree of denominator is greater the main function will call PrintResult function 
	*	which prints the quotient,reminder and denominator.
	*	Then we ask the user to continue or not , if he want to continue then press y so the loop will repeated again
	*   else he press any other key to terminate the program.
	*/
	do 
	{
		printf("\r\n");
		count = 1;
		EnterPolynomial(result[3],count);
		count = 2;
		EnterPolynomial(result[2],count);
		errorCheck = LongDivision(result);
		if (errorCheck == 0)
		{
			PrintResult(result, size);
		}
		printf("\r\n\n");
		printf("Do you want to continue Y/N?\r\n");
		decision = _getch();
	}while ((decision == 'y')|| (decision == 'Y'));
	return 0;
}