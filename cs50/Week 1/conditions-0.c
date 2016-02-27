//
//  condition-0.c
//  cs50
//
//  Created by Angelo Villegas on 29/12/15.
//  Copyright © 2015 Angelo Villegas. All rights reserved.
//

#include "cs50.h"
#include <stdio.h>

int main(void) {
	printf("I'd like an integer please: ");
	int n = GetInt();
	
	if (n > 0) {
		printf("You picked a positive number!\n");
	} else {
		printf("You picked a negative number!\n");
	}
}