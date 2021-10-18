/*
**************************************************************************************************************
@file      opeartion.c
@author    Zeyad Mohamed Abd El-Hamid
@id        1900959
@brief     This file controls the process of long division made on the numerator and denominator as it contains
           4 private functions , one public function and one private struct 
**************************************************************************************************************
*/

#include "operation.h"

/*
* This private struct is used in this file only as this struct contains two members which are degree and coefficient.
* The structure variable from this struct holds only one term in the poynomial expression
  But the structure variable from polynomial data type holds the whole polynomial expression 
*/
typedef struct
{
	int degree;
	float coeff;
}term;

/*
* The following private functions are diffrent from public functions as public functions are declared in header 
* file and defined in source file so that any file inlude the header file can use this function.
* But the private functions are declared and defined in source file only so that the source file can use this function
* only while other files can't use this function because the function declaration not found in header file.
* We have 4 private functions:
* 1) CheckDegree function: this function is used to check the degree entered by the user
*    for example: if the user entered the degree of numerator is 4
*                than he enterd the coefficients to be 0X^4+3X^2
*                so that the degree is 4 will be wrong and the correct degree is 3
*    This function performs the previous task
* 2) DivideHighestDegree function: This function performs the first step in long division by dividing the term
*     of the highest degree of numerator by the term of the highest degree of deominator and returns the result of division
* 3) Multiply : This function performs the second step in long divison by multiplying the resulted term 
*    (from DivideHIghestDegree function) by the denominator and returns the result
* 4) Subtruct function: This function performs the final step in long division by subtructing the polynomial resulted from Multiply
*    function by the numerator and returns the result that represents the reminder 
*/
void CheckDegree(polynomial* expression); //private function 
void DivideHighestDegree(polynomial** expressions, term* result); //private function
void Multiply(term* polynomialTerm, polynomial* expression, polynomial* result); //private function
void Subtruct(polynomial** result, polynomial* subtrahend); //private function


void CheckDegree(polynomial* expression)
{
	int i;
	/*
	* The next block is used to check on the degree by the following method:
	* The LongDivision function passes the refrence of expression to check if its degree is coreect or not
	* so this function recieved the refrence in pointer called expression, then this pointer access each coefficient
	* in the expression by the for loop to find the highest degree term which has coefficient not equal to zero
	* After finding this term,it modify the user's degree term then breaks from the for loop
	*/
	for (i = expression->degree; i >= 0; i--)
	{
		if (expression->coeff[i] != 0)
		{
			break;
		}
	}
	expression->degree = i;
}

/*
* This function is used to divide the largest degree term in denominator by the largest degree term in numerator
* by the following method: The long division function calls this function and passes two arguments which are
* pointer to pointer that points to array of pointers(defined in main function) while the second parameter is pointer
* to term (private datatype),this pointer refers to the result of devision
*/
void DivideHighestDegree(polynomial** expressions,term* result)
{
	/* if we look at main function we found that index 3 of this array refers to numerator while index 2
    * refers to the degree of denominator
	* we know mathematically that the degree of the result(get from division)
	* is the degree of numerator - the degree of denominator
	*/
	result->degree = expressions[3]->degree - expressions[2]->degree;
	// the coefficient of result is the coefficient of highest term in numerator divided by the coefficient
	// of highest term in denominator
	result->coeff = expressions[3]->coeff[expressions[3]->degree] / expressions[2]->coeff[expressions[2]->degree];
}

/*
* This function multiply term by polynomial so it has 3 parameters which are polynomialTerm,expression and the result
* where our storage 
*/
void  Multiply(term* polynomialTerm, polynomial* expression, polynomial* result)
{
	int i;
	int count;
	//The degree of the result (got from myltiplication) is the degree of polynomial term + the degree of expression
	result->degree = polynomialTerm->degree + expression->degree;
	count = result->degree;
	//we dynamically memory allocated the result of type float and the number of blocks is the degree of the the result
	result->coeff = (float*)calloc(result->degree, sizeof(float));
	// we check on the pointer before using it because it is probably that we request memory from heep 
	// by calloc function but the request will be refued as heep is full so our pointer will refer to null 
	// so the next if condition to prevent the derefrencing of null pointer
	if (result->coeff)
	{
		/*
		* The next block is used to multiply the coefficient of the term with the polynomial and store the result
		* in the result of index count(that is initialized by the degree of the result) and decrement it each 
		* iteration
		*/
		for (i = expression->degree; i >= 0; i--)
		{
			result->coeff[count] = polynomialTerm->coeff * expression->coeff[i];
			count--;
		}
	}
}

/*
* This function is used to subtruct polynomial by polynomial as it has two parameters which are pointer to pointer
* refers to the array of pointers(defined in main) and the second parameter is the subtrahend
* Note:
* if we has two polynomial expressions A , B and C then C = A - B
* so A is called subtructor, B is called subtrahend , C is called diffrence (in our case of long division is called Reminder)
*/
void Subtruct(polynomial** result, polynomial* subtrahend)
{
	int i;
	polynomial resultOld;
	//The degree of the result is the degree of numerator(index 3) which must equal to the degree of subtrahend
	resultOld.degree = result[3]->degree;
	// we dynamically memory allocate the result of type float and the number of allocated blocks equal to the degree
	// of the result
	resultOld.coeff = (float*)calloc(result[3]->degree, sizeof(float));
	/*
	* The next block is used to subtruct the coefficent of numerator by the coefficient if subtrahend and store the 
	* resulted coefficient in the result in the same index
	*/
	for (i = result[3]->degree; i >= 0; i--)
	{
		resultOld.coeff[i] = result[3]->coeff[i] - subtrahend->coeff[i];
	}
	CheckDegree(&resultOld); // to know the degree of the result after subtruction
	result[1]->degree = resultOld.degree;//store the correct degree in the reminder degree 
	/*
    * The next if-else condioton is used to check the reminder degree
	* if the reminder degree is grater than or equal to zero then modify the memory allocated in the heep to equal 
	* reminder degree + 1 (for contant term)
	* But if the degree is -1 which means that the all terms in the reminder equal zero so allocated one block 
	* and put zero in it (By default it is initiated to zero)
    */
	if (result[1]->degree >= 0)
	{
		result[1]->coeff = (float*)realloc(resultOld.coeff, (result[1]->degree + 1) * sizeof(float));
	}
	else
	{
		result[1]->coeff = (float*)realloc(resultOld.coeff, sizeof(float));
	}
}

/*
* This function represents the control unit in the long division process as it calls all the previous private 
* functions as it takes only one parameter which is pointer to pointer that points to array (defined in main)
* that contains the refrence of quotient,reminder,denominator,numerator then returns integer that represents the check error
*/
int LongDivision(polynomial** result)
{
	term polynomialTerm;
	polynomial subtrahend;

/*At first it checks the degree of numerator and denominator as shown before, after checking it compares
* the degree of numerator and denominator, if the degree of the numerator is less than the degree of denominator then
* prints error and return 1 (check error), but if the degree of numerator is greater than or equal the degree of 
*  denominator then return 0 (check error) and perform the following operation :
* The dgree of the quotient is equal to the degree of the numerator - the degree of the denominator then
* dynamically allocate in heep number of blocks equal to the degree of quotient of type float.
* then check on the pointer that points to the heep (if the request from heep sucess or fail)
* if faill then the pointer will be null pointer so return 0 (check error), if sucess then perform the following steps. 
*/
  	CheckDegree(result[3]);
	CheckDegree(result[2]);
	if (result[3]->degree >= result[2]->degree)
	{
		result[0]->degree = result[3]->degree - result[2]->degree;
		result[0]->coeff = (float*)calloc(result[0]->degree, sizeof(float));

/* The divison steps as following:
*  a) Divide the term of the highest degree of numerator by the term of the highest degree in denominator
*  b) Store the resulted term in the quotient at index suitable to term degree
*  c) Multiply the term by the denominator and store the result in subtrahend
*  d) Subtruct the numerator by the subtrahend and store the result in reminder
*  e) Store reminder in the numerator
*  f) Check if the degree of the reminder greater than or equal the degree of dinominator:
*   i) if true then repeat the loop with the new numerator
*  ii) if false then break from do-while loop
*/
		if (result[0]->coeff)
		{
			do
			{
				DivideHighestDegree(result, &polynomialTerm);
				result[0]->coeff[polynomialTerm.degree] = polynomialTerm.coeff;
				Multiply(&polynomialTerm, result[2], &subtrahend);
				Subtruct(result, &subtrahend);
				result[3] = result[1];
			} while (result[1]->degree >= result[2]->degree);
		}
		return 0;
	}
	else
	{
		printf("Error,The degree of denominator > The degree of numerator");
		return 1;
	}
}