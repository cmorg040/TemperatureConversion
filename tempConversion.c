/*=============================================================================
 |   Source code:  tempConversion.c
 |        Author:  Carrel Morgan
 |    Student ID:  3759826
 |    Assignment:  Program #1
 |
 |            Course:  COP 4338
 |           Section:  U04
 |        Instructor:  William Feild
 |        Due Date:  01/29/2019, at the beginning of class
 |
 |	I hereby certify that this collective work is my own
 |	and none of it is the work of any other person or entity.
 |	______________________________________ [Signature]
 |
 |        Language:  C
 |  Compile/Run:  Unzip all files.
 |				- type: gcc -o tempConversion tempConversion.c
 |				- type: ./tempConversion
 |
 |  +-----------------------------------------------------------------------------
 |
 |  Description:  This program prints a table of temperature conversions at regular user-defined intervals
 |
 |
 |
 |
 |        Input:  User should input a single digit integer value, between 1-9.
 |
 |
 |
 |       Output:  The program should output a formatted table displaying a temperature in Fahrenheit
 |				  and Celsius, and its converted value.
 |
 |     Process:
 |				1. Declare all relevant parameters as constants in Main
 |				2. Accept user input with scanf, then convert to integer with atoi.
 |				3. Validate user input.
 |				4. Initialize a for loop that starts at the initial temperature(from specs),
 |				   and prints the next value in user defined increments.
 |				5. Call a conversion function, that returns the temperature in F or C.
 |
 |
 |
 |
 |
 |   Required Features Not Included:
 |                All features should be included.
 |
 |
 |
 |
 |
 |
 |   Known Bugs:  No known bugs or errors.
 |  *===========================================================================*/

#include <stdio.h> //Standard input output functionality for C
#include <stdlib.h> //Standard library of functions.

#define STEP_MIN 1
#define STEP_MAX 9

#define FALSE 0
#define TRUE 1

#define MIN_TEMP -80.0
#define MAX_TEMP 320.0

#define INPUT_BUFFER 100

char getValidInput();
float convertFtoC(float fTemp);
float convertCtoF(float cTemp);
void printChart();

int main(void)
{
	char input = getValidInput();
	printf("User input is: %d\n", input);
	printChart(input);
	return 0;
}

/*---------------------------- getValidInput ---------------------
 |  Function: getValidInput
 |
 |  Purpose:  Takes and validates user input.
 |
 |  @param  none
 |
 |  @return  returns valid user input as a single char
 *----------------------------------------------------------*/
char getValidInput()
{
	//get input
	char input;
	int charCounter = 0;
	printf("Please input an integer from %d-%d: ", STEP_MIN, STEP_MAX);
	do
		{
			input = getchar();
			charCounter++;
		}
	while (getchar() != '\n');
	input = input - '0';
//validate input
	if (charCounter > 1)
		{
			printf(
					"Invalid input; too many characters. Please input a single integer from %d-%d.\n",
					STEP_MIN, STEP_MAX);
			return FALSE;
		}
	if (STEP_MIN > input || STEP_MAX < input)
		{
			printf("Invalid input. Please input an integer from %d-%d\n",
			STEP_MIN, STEP_MAX);
			return FALSE;
		}
	else
		{
			printf("Valid user input is: %d\n", input);
			return input;

		}
}

/*---------------------------- convertFtoC ---------------------
 |  Function: convertFtoC
 |
 |  Purpose:  Converts a Fahrenheit temperature to Celcius.
 |
 |	Formula:  C = (F - 32) * (5.0/9.0)
 |
 |  @param  fTemp - Fahrenheit temperature to be converted.
 |
 |  @return  returns temperature in Celsius.
 *-------------------------------------------------------------*/

float convertFtoC(float fTemp)
{
	float cTemp = 0.0;

	cTemp = (fTemp - 32) * (5.0 / 9.0);

	return cTemp;
}

/*---------------------------- convertCtoF ---------------------
 |  Function: convertCtoF
 |
 |  Purpose:  Converts a Celcius temperature to Fahrenheit.
 |
 |	Formula:  F = C * (9.0/5.0) + 32
 |
 |  @param  cTemp - Celsius temperature to be converted.
 |
 |  @return  returns temperature in Fahrenheit.
 *--------------------------------------------------------------*/
float convertCtoF(float cTemp)
{
	float fTemp = 0.0;

	fTemp = cTemp * (9.0 / 5.0) + 32;

	return fTemp;
}
/*---------------------------- printChart ---------------------
 |  Function: printChart
 |
 |  Purpose:  Takes and validates user input.
 |
 |  @param  none
 |
 |  @return  returns valid user input as a single char
 *----------------------------------------------------------*/

void printChart(int step)
{
	float tempCounter = MIN_TEMP;
	printf("\n\n%15s%15s%15s%15s\n", "Fahrenheit", "Celsius", "Fahrenheit", "Celsius");
	printf("____________________________________________________________\n");
	while (tempCounter <= MAX_TEMP)
		{
			//15.1f = 15 characters of width per 'column', one digit decimal precision for rounding/formatting.
			printf("%15.1f%15.1f%15.1f%15.1f\n", tempCounter,
					convertFtoC(tempCounter), tempCounter,
					convertCtoF(tempCounter));
			tempCounter += step;
		}
}
