/***************************************************************************
*=====================      Copyright by Don Issac      ===============
****************************************************************************
* Title        : Sort by insertion
*
* Environment  : Simulated  
*
* Responsible  : Issac Jimenez
*****************************************************************************************************/

#include <stdio.h>
#include <conio.h>

typedef _Bool(*mycallback)(char, unsigned int, unsigned int);

/***************************************************************************
* Interface Description: INSERTION__sort
*
* Implementation       : Used to sort the array.
*
* Return Value         : void
*
* Author               : Issac Jim�nez
****************************************************************************/
/*An array is automatically passed by reference*/
/*void INSERTION__vSort(

	unsigned int u32array[], 
    unsigned char u32nelemns,
	mycallback CallFunc
);*/

//_Bool CallFunc_bCmp(char s8Counter, unsigned int u32array_element, unsigned int u32Temp);

void INSERTION__vSort(unsigned int u32array[], unsigned int u32Num_elements, mycallback CallFunc)
{
	char s8count_a, s8count_b;
	unsigned int u32temp;

	for (s8count_a=1; s8count_a<u32Num_elements; s8count_a++) /*first search*/
	{
		u32temp = u32array[s8count_a];
		s8count_b = s8count_a - 1;

		while (CallFunc(s8count_b, u32array[s8count_b], u32temp)) /*-> call back function*/
		{
			u32array[s8count_b + 1] = u32array[s8count_b];
			s8count_b--;
		}

		u32array[s8count_b + 1] = u32temp;
	}

}


_Bool CallFunc_bCmp(char s8Counter, unsigned int u32array_element, unsigned int u32Temp)
{
	_Bool boflag = 0;

	if ((0 <= s8Counter) && (u32array_element > u32Temp))
	{
		boflag = 1;
	}
	else {
		boflag = 0;
	}
	return boflag;
}


int main(int argc, const char * argv[])
{
	unsigned int u32Array[] = {10,9,0,2,3,0,7,13,11,1,4,5,12};
	unsigned int u32Nelemnts;
	char s8count;

	u32Nelemnts = sizeof(u32Array)/sizeof(int);

	printf("\n Apilcation for sort an array by Insertion sort method \n");

	for (s8count = 0; s8count<(char)u32Nelemnts; s8count++)
	{
		printf(" %d", u32Array[s8count]);
	}


	INSERTION__vSort(u32Array, u32Nelemnts, CallFunc_bCmp);

	printf("\n\n Array sorted \n");
	for (s8count = 0; s8count<(char)u32Nelemnts; s8count++)
	{
		printf(" %d", u32Array[s8count]);
	}

	_getch();
	return 0;
}



