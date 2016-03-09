#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	//function for inputs
void getStrings();
	//main functions
int getHammingDistance(char *str1, char *str2);
int getSubstrPattern(char *str1, char *str2);
int isStringValid(char *str1, char *str2);
int getTypeSkew(char *str1, char *str2, int type);

int getSkew(char *str1, char *str2);
int getMaxSkew(char *str1, char *str2);
int getMinSkew(char *str1, char *str2);

	//function used to accept input 
		//and print results returned by main functions
void getStrings (int choice) {
	int maxLen = 100;	//defines max string length
	int retVal;
	int skip = 0;
	char str1[maxLen], str2[maxLen];

	printf("Input #1: ");
	fgets(str1, maxLen, stdin);
    str1[strlen(str1)-1] = '\0';

	printf("Input #2: ");
	fgets(str2, maxLen, stdin);
    str2[strlen(str2)-1] = '\0';

    if (!strlen(str1) || !strlen(str2)) {
    	printf("Missing Input!");
    }
    if (!1) {
		printf("Invalid input");
	}

    else {
	    switch (choice) {
	    		//checks cases for hamming distance and
	    			//checking substring pattern
	    				//used same case since error messages and outputs are the same
	    	case 1:
				retVal = getHammingDistance(str1, str2);
				skip = 1;
			case 2:
				if (!skip) {
					retVal = getSubstrPattern(str1, str2);
				}
				switch (retVal) {
					case -1:
						printf("Error! String Lengths are not equal!");
						break;
					default:
						printf("%d", retVal);
				}
				break;

				//checks if return value is valid or not
			case 3:
				if (isStringValid(str1, str2)) {
						printf("Valid");
						break;
				}
				printf("Invalid");
				break;
				//skew function
			case 4: 
				printf("Value: %d", getSkew(str1, str2));
				break;
			case 5:
				printf("Value: %d", getMaxSkew(str1, str2));
				break;
			case 6:
				printf("Value: %d", getMinSkew(str1, str2));
				break;
			default:
				printf("No match found");
	    }
	}
    printf("\n");
}



int getHammingDistance (char *str1, char *str2) {
	int val = 0;
	int i;
		//checks if string lengths don't match
	if (strlen(str1) != strlen(str2)) {
		return -1;
	}
		//gets difference in values
	for (i=0; i<strlen(str1); i+=1) {
		if(str1[i] != str2[i]) {
			val+=1;
		}
	}

	return val;
}

int getSubstrPattern (char *str1, char *str2) {
	int val = 0;
	int check = 1;
	int i, j;

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

		//loops at each letter of the first string
	for (i=0; i<strlen(str1); i+=1) {
			//loops at each letter of the "alphabet" to check if part
		for (j=0; j<strlen(str2); j+=1) {
				//if a match is found from the string
			if (str1[i] == str2[j]) {
				check = 0;
			}
		}
			//if no matching string is found in
				//the "alphabet", returns 0 or invalid
		if (check) {
			return 0;
		}
		check = 1;
	}
	return 1;
}
	//general skew function
int getTypeSkew (char *str1, char *str2, int type) {
	int num = atoi(str2);
	int max = 0, min = 0;
	int i;
	int val = 0;

		//checks for g's or c's
	for (i=0; i<num; i+=1) {
		if (str1[i] == 'G' || str1[i] == 'g') {
			val+=1;
		}
		if (str1[i] == 'C' || str1[i] == 'c') {
			val-=1;
		}
			//changes max value if exceeded by current value
		if (max < val) {
			max = val;
		}
			//changes min value if exceeded by current value
		if (min > val) {
			min = val;
		}
	}

	if (type == 1) {
		return max;
	}
	if (type == 2) {
		return min;
	}
	return val;
}

	//helper skew functions
int getSkew(char *str1, char *str2) {
		//type 0 is normal skew function
	getTypeSkew(str1, str2, 0);
}
int getMaxSkew(char *str1, char *str2) {
		//type 1 is get max value of skew
	getTypeSkew(str1, str2, 1);
}
int getMinSkew(char *str1, char *str2) {
		//type 2 is get min value of skew
	getTypeSkew(str1, str2, 2);
}