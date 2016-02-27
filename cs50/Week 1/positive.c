//
//  positive.c
//  cs50
//
//  Created by Angelo Villegas on 31/12/15.
//  Copyright © 2015 Angelo Villegas. All rights reserved.
//

#include "cs50.h"
#include <stdio.h>

int main(void) {
	int n;
	do {
		printf("Please give me a positive int: ");
		n = GetInt();
	} while (n < 1);
	printf("Thanks for the positive int!\n");
}