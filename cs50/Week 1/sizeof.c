//
//  sizeof.c
//  cs50
//
//  Created by Angelo Villegas on 13/2/16.
//  Copyright © 2016 Angelo Villegas. All rights reserved.
//

#include <stdio.h>
#include "cs50.h"

int main (void) {
	char c;
	double d;
	float f;
	int i;
	
	printf("char: %lu\n", sizeof(c));
	printf("double: %lu\n", sizeof(d));
	printf("float: %lu\n", sizeof(f));
	printf("int: %lu\n", sizeof(i));
}
