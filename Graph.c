/*
 *	A program that draws a graph of an answer for a given equation
 *	An equation to draw can be modifed by changing the f function.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Define range of X and Y
#define X_SEMIRANGE 3
#define Y_SEMIRANGE 1

double f(double);
void plotGraph(char*);
int doubleToInt(double);

int main(){
	//Create array containing characters
	char graph[Y_SEMIRANGE*20 + 1][X_SEMIRANGE*20 + 1];
	//Call function plotGraph to graph the function
	plotGraph(&graph[0][0]);
	return 0;
}

//This function determines the function to be graphed.
double f(double x) {
	double answer;
	//Change this to change the formula
	if (x == 0) {
		return 0;
	}
	answer = exp(-1/(x*x));
	answer = answer * 10;
	return answer;
}

//This function will place right characters at right place in graph array
//and print the graph
void plotGraph(char *a){
	int i;
	int j;
	double calculation;
	int calculationInt;
	//For loop to check every Y values
	for (i = 0; i <= (20*Y_SEMIRANGE); i++) {
		//For loop to check every X values
		for (j = 0; j <= (20*X_SEMIRANGE); j++) {
			/*Call function 'calculation' by using return value of function 'f'.
			 *Reason why parameter is ((j-(10*X_SEMIRANGE))/10.0) because j does not
			 *contain negative value but actual graph does, and every j indicates 1/10 of actual
			 *value of X. This calculation will be made for every single X value regardless of Y value.*/
			calculation = f((j-(10*X_SEMIRANGE))/10.0);
			//Call function 'doubltToInt' to convert calculation to int value
			calculationInt = doubleToInt(calculation);
			//Calculate the right Y value to place 'o'
			if (calculationInt + (10*Y_SEMIRANGE) <= (10*Y_SEMIRANGE)+1) {
				calculationInt = (20*Y_SEMIRANGE) - calculationInt - (10*Y_SEMIRANGE);
			} else if (calculationInt + (10*Y_SEMIRANGE) >= (10*Y_SEMIRANGE)+1) {
				calculationInt = (10*Y_SEMIRANGE) - calculationInt;
			}
			//If-else statements to place characters in array.
			//If current Y-value is equal to calculationInt, place 'o'
			if (i == calculationInt) {
				*(a + i + j) = 'o';
			//If current Y-value is not (10*Y_SEMIRANGE), which is X-axis
			//and X-value is not (10*X_SEMIRANGE), which is Y-axis, place ' '
			} else if (i != (10*Y_SEMIRANGE) && j != (10*X_SEMIRANGE)) {
				*(a + i + j) = ' ';
			//If current Y-value is not on X-axis, place '|'
			} else if (i != (10*Y_SEMIRANGE)) {
				*(a + i + j) = '|';
			//If Y-value and X-value is on X-axis and Y-axis, it is the middle
			//Place '+'
			} else if (i == (10*Y_SEMIRANGE) && j == (10*X_SEMIRANGE)) {
				*(a + i + j) = '+';
			//Else it is X-axis. Place '-'
			} else {
				*(a + i + j) = '-';
			}
			printf("%c", *(a+i+j));
		}
		printf("\n");
	}
}

int doubleToInt (double calculation) {
	int answer;
	//If calculation is greater than 0, add 0.5 and convert it to int
	//Otherwise subtract 0.5 and convert it to int
	if (calculation >= 0)
		answer = (int)(calculation + 0.5);
	else
		answer = (int)(calculation - 0.5);
	return answer;
}
