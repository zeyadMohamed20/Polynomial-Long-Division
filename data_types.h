/*
* Header guard is used in all header files to prevent the redefinition of files and functions
* for example: if file A include file B and file C and file B include file C
* so that file A include file C twice so that the functions will be redefined which causes error
* but header guard prevents this error by defining  macro and check when the compliler enters the file 
* so if the file and the functions are defined before the compiler wont't define the functions again , if the macro 
* is not defined before then the compiler will define the functons because it is the first time of definition
*/ 

#ifndef DATA_TYPES_H 
#define DATA_TYPES_H

/*
* The following struct holds two members which are degree and pointer to float called coeff
* degree: holds the degree of any polynomial
* coeff ponter: holds the address of array of coefficients stored in the heep (dynamic memory allocation)
* The following struct is typedef to make alias for struct polynomial to polynomial only 
*  (so that datatype is used esily)
*/
typedef struct
{
	int degree;
	float* coeff;
}polynomial;

#endif /*DATA_TYPES_H*/