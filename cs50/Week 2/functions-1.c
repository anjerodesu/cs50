//
//  functions-1.c
//  cs50
//
//  Created by Angelo Villegas on 27/2/16.
//  Copyright © 2016 Angelo Villegas. All rights reserved.
//

#include <stdio.h>
#include "cs50.h"

int getPositiveInt(void);

int main(void) {
	int n = getPositiveInt();
	printf("Thanks for the %i\n", n);
	
}

int getPositiveInt(void) {
	int n;
	do {
		printf("Please give me a positive int: ");
		n = GetInt();
	} while (n < 1);
	return n;
}
