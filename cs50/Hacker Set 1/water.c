//
//  water.c
//  cs50
//
//  Created by Angelo Villegas on 28/2/16.
//  Copyright © 2016 Angelo Villegas. All rights reserved.
//

#include <stdio.h>
#include "cs50.h"

static int ouncesPerMinute = 192;
static int ouncesPerBottle = 16;

int getPositiveInt();

int main(void) {
	int n = getPositiveInt();
	int r = (ouncesPerMinute / ouncesPerBottle) * n;
	printf("bottles: %i\n", r);
}

int getPositiveInt() {
	int n;
	do {
		printf("minutes: ");
		n = GetInt();
	} while(n < 1);
	return n;
}
