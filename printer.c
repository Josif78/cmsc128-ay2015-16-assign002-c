#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cExLib.h"

main() {
	int choice;
	int maxLen = 100;
	char str[maxLen];

	while (1) {
		printf("[1] Hamming Distance\n");
		printf("[2] Get Substring Pattern\n");
		printf("[3] Check String Validity\n");
		printf("[4] Get Skew\n");
		printf("[5] Get Max Skew\n");
		printf("[6] Get Min Skew\n");
		printf("[7] Exit\n");
		printf("Choice: ");
		fgets(str, maxLen, stdin);
		if (strlen(str) > 2) {
			printf("Invalid choice\n\n");
			continue;
    	}
    	
    	str[2] = '\0';
    	choice = atoi(str);

		if (choice == 7) {
			printf("For Nohr!\n");
			break;
		}
		getStrings(choice);
	}
	return 78;
}