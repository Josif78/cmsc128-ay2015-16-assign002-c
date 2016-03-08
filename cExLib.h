#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	//function for inputs
void getStrings();
	//main functions
int getHammingDistance(char *str1, char *str2);
int getSubstrPattern(char *str1, char *str2);
int isStringValid(char *str1, char *str2);

void getStrings () {
	int maxLen = 100;	//defines max string length
	int choice = 3;
	int retVal;
	int skip = 0;
	char str1[maxLen], str2[maxLen];

	printf("Input #1: ");
	fgets(str1, maxLen, stdin);
    str1[strlen(str1)-1] = '\0';

	printf("Input #2: ");
	fgets(str2, maxLen, stdin);
    str2[strlen(str2)-1] = '\0';

    switch (choice) {
    	case 1:
			retVal = getHammingDistance(str1, str2);
			skip = 1;
		case 2:
			if (!skip) {
				retVal = getSubstrPattern(str1, str2);
			}
			switch (retVal) {
				case -1: 
					printf("Missing input!");
					break;
				case -2:
					printf("Error! String Lengths are not equal!");
					break;
				default:
					printf("%d", retVal);
			}
			break;
		case 3:
			switch (isStringValid(str1, str2)) {
				case -1:
					printf("Missing input!");
					break;
				case 0:
					printf("Invalid\n");
					break;
				default:
					printf("Valid\n");
			}
			break;
		default:
			printf("Nepu-nepu");
    }
    printf("\n");

    skip = 0;
}



int getHammingDistance (char *str1, char *str2) {
	int val = 0;
	int i;

	if (!strlen(str1) || !strlen(str2)) {
		return -1;
	}
	if (strlen(str1) != strlen(str2)) {
		return -2;
	}

	for (i=0; i<strlen(str1); i+=1) {
		if(str1[i] != str2[i]) {
			val+=1;
		}
		printf("\n");
	}

	return val;
}

int getSubstrPattern (char *str1, char *str2) {
	int val = 0;
	int check = 1;
	int i, j;

	if (!strlen(str1) || !strlen(str2)) {
		return -1;
	}
		//checks each letter of first string
	for (i=0; i<strlen(str1); i+=1) {
			//finds if a letter matches
		if (str1[i] == str2[0]) {
				//checks every letter of the second string
			for (j=0; j<strlen(str2); j+=1) {
					//if non-matching, goes to next character to check
				if (str1[i+j] != str2[j]) {
					check = 0;
					break;
				}
			}
			if (!check) {
				check = 1;
				continue;
			}
			val+=1;
		}
	}

	return val;
}

int isStringValid (char *str1, char *str2) {
	int i, j;
	int check = 1;
	
	if (!strlen(str1) || !strlen(str2)) {
		return -1;
	}
	for (i=0; i<strlen(str1); i+=1) {
		for (j=0; j<strlen(str2); j+=1) {
			if (str1[i] == str2[j]) {
				check = 0;
			}
		}
		if (check) {
			return 0;
		}
		check = 1;
	}

	return 1;
}