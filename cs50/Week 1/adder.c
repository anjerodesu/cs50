//
//  adder.c
//  cs50
//
//  Created by Angelo Villegas on 29/12/15.
//  Copyright © 2015 Angelo Villegas. All rights reserved.
//

#include "cs50.h"
#include <stdio.h>

int main(void) {
	printf("Give me an integer: ");
	int x = GetInt();
	printf("Give me another integer: ");
	int y = GetInt();
	
	printf("The sum of %i and %i is %i!\n", x, y, x + y);
}