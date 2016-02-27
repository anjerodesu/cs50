//
//  f2c.c
//  cs50
//
//  Created by Angelo Villegas on 6/1/16.
//  Copyright © 2016 Angelo Villegas. All rights reserved.
//

#include "cs50.h"
#include <stdio.h>

int main(void) {
	printf("Temperature in F: ");
	float f = GetFloat();
	
	float c = 5.0 / 9.0 * (f - 32.0);
	
	printf("%.1f\n", c);
}