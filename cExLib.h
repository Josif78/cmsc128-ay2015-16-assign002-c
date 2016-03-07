#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	//helper function used to call getHammingDistance
void hammingDistance () {
	int maxLen = 100;	//defines max string length
	char str1[maxLen], str2[maxLen];
	int retVal;

	printf("Input #1: ");
	fgets(str1, maxLen, stdin);
    str1[strlen(str1)-1] = '\0';

	printf("Input #2: ");
	fgets(str2, maxLen, stdin);
    str2[strlen(str2)-1] = '\0';

	retVal = getHammingDistance(str1, str2);

		//used switch case to check for error cases
	switch (retVal) {
		case -1: 
			printf("Error! String Lengths are not equal!");
			break;
		case -2:
			printf("Missing input!");
			break;
		default:
			printf("Nepchan is best chan");
	}
	printf("\n");
}

int getHammingDistance (char *str1, char *str2) {
	int val = 0;

	if (!strlen(str1) || !strlen(str2)) {
		return -2;
	}
	if (strlen(str1) != strlen(str2)) {
		return -1;
	}
	
	printf("1: %s; 2: %s\n", str1, str2);

	return val;
}