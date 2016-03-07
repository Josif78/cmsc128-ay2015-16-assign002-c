#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hammingDistance () {

	int retVal = getHammingDistance();
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

int getHammingDistance () {
	int val = 0
	return val;
}