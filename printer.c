#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cExLib.h"

main() {
	int choice;
	int maxLen = 100;
	char str[maxLen];

	while (1) {
		printf("\n*** Menu ***\n");
		printf("[1] Get Hamming Distance\n");
		printf("[2] Get Substring Pattern\n");
		printf("[3] Get String Validity\n");
		printf("[4] Get Skew\n");
		printf("[5] Get Max Skew\n");
		printf("[6] Get Min Skew\n");
		printf("[7] Exit\n");
		printf("Choice: ");

		fgets(str, maxLen, stdin);
		if (strlen(str) > 2 || strlen(str) < 2) {
			printf("Invalid choice\n\n");
			continue;
    	}

    	str[2] = '\0';
    	choice = atoi(str);

		if (choice == 7) {
			printf("Exited Program\n");
			break;
		}
		getStrings(choice);
	}
	printf("\nFor Nohr!\n");
	return 78;
}