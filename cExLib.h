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
			printf("%d", retVal);
	}
	printf("\n");
}

int getHammingDistance (char *str1, char *str2) {
	int val = 0;
	int i;

	if (!strlen(str1) || !strlen(str2)) {
		return -2;
	}
	if (strlen(str1) != strlen(str2)) {
		return -1;
	}

	for (i=0; i<strlen(str1); i+=1) {
		if(str1[i] != str2[i]) {
			val+=1;
		}
	}

	return val;
}