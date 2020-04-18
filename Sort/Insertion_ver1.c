/***************************************************************************
*=====================      Copyright by Don Issac      ===============
****************************************************************************
* Title        : Sort by insertion
*
*
* Environment  : Simulated
*
* Responsible  : Issac Jiménez
*****************************************************************************************************/

#include <stdio.h>
#include <conio.h>


#define SIZE   10 /*array size*/


/***************************************************************************
* Interface Description: INSERTION__sort
*
* Implementation       : Used to sort the array.
*
* Return Value         : void
*
* Author               : Issac Jiménez
****************************************************************************/

void INSERTION__sort(

	int u32array[]
	/*An array is automatically passed by reference*/

);


void main(int argc, const char * argv[])
{
	int u32Array[SIZE] = {12,9,0,2,3,0,7,13,11,1};
	char u8count;

	printf("\n Apilcation for sort an array by Insertion sort method \n");

	for (u8count = 0; u8count<SIZE; u8count++)
	{
		printf(" %d", u32Array[u8count]);
	}


	INSERTION__sort(u32Array);

	printf("\n Array sorted \n");
	for (u8count = 0; u8count<SIZE; u8count++)
	{
		printf(" %d", u32Array[u8count]);
	}

	_getch();
}


void INSERTION__sort(int u32array[])
{
	char u8count_a, u8count_b, u8temp;

	for (u8count_a=1; u8count_a<SIZE; u8count_a++) /*first search*/
	{
		u8temp = u32array[u8count_a];
		u8count_b = u8count_a - 1;

		while ((0 <= u8count_b) && (u32array[u8count_b] > u8temp))
		{
			u32array[u8count_b + 1] = u32array[u8count_b];
			u8count_b--;
		}

		u32array[u8count_b + 1] = u8temp;
	}

}