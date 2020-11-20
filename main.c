/*
 -------------------------------------
 File:    main.c
 Project: onab4340_l03
 Purpose: ******
 -------------------------------------
 Author:  Alvin Onabolu
 ID:      190994340
 Email:   onab4340@mylaurier.ca
 Version  2020-09-29
 -------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>





 //Constants

#define FALSE 0
#define TRUE 1

int IsValid(char sentence[], int length) {
	int bool = TRUE, i, j;

	//Check validity of each char
	for (i = 0; i < length; i++) {

        //check if in alpabet, or a space
		if (((sentence[i] >= 'A' && sentence[i] <= 'Z')
				|| (sentence[i] >= 'a' && sentence[i] <= 'z')
				|| (sentence[i] == ' ')) == FALSE) { //THINK OF THIS AS LOGIC STAMENT, ONLY ONE OF THE Or's has to be true for this to = fALSE, THE FALSE IS LIKE A NOT OPERATOR,
			//If one of these condition is false, then set bool to false
			bool = FALSE;
		}
	}

	return (bool);
}

int main() {

    //standard output buffering
	setbuf(stdout, NULL);

	//declare variables
	char sentence[1000];
	int length = 0, bool, i, num_value, key;

	//get word and length from user
	printf("Please type a text of all characters and spaces: ");
	gets(sentence);
	length = strlen(sentence);
    	//have to subtract 1, because length inlcudes the null char
	

    	//get value to encrypt by
    	printf("\nPlease type the key value to encrypt by: ");
	scanf("%d", &key);

	//If no input, end program
	if (length <= 0) {
		printf("No sentence found. Program Terminating");
		exit(0);
	}

	//if input is not a string of chars, end program
	bool = IsValid(sentence, length);
	if (bool == FALSE) {
		printf(
				"\nIncorrect entry, Please enter only Letters and Spaces. Program Terminating");
		exit(0);
	}

	//traverse through sentence encrypting each character
	for (i = 0; i < length; i++) {
        //leave characters that are spaces
		if (sentence[i] != ' ') { 
			//Convert uppercase chars
			if (sentence[i] >= 'A' && sentence[i] <= 'Z') { 
                //check if adding the key will make it go past Z
                //if it will then add the key but subtract 26
				if ((sentence[i] + key) > 'Z')  
					sentence[i] = sentence[i] + key - 26;
				//if it wont, then simply add the key 
                else 
					sentence[i] += key;
				
			}
            //convert lower case chars
            //notice has to be lower case, becuase each char can either be lower case or upper case
            else {
                //do the same thing we did for uppercase
				if ((sentence[i] + key) > 'z') 
					sentence[i] = sentence[i] + key - 26;
				else 
					sentence[i] += key;
				

			}
		}
	}
	printf("\n%s", sentence);
	return (0);
}


