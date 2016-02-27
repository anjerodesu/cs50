//
//  greedy.c
//  cs50
//
//  Created by Angelo Villegas on 14/2/16.
//  Copyright © 2016 Angelo Villegas. All rights reserved.
//

#include <stdio.h>
#include "cs50.h"
#include <math.h>

int getPositiveFloat(void);

int main(void) {
    static int quarter = 25;
    static int dime = 10;
    static int nickel = 5;
    static int penny = 1;

    int n = getPositiveFloat();
    int t = 0;
    while (n > 0) {
        if (n >= quarter) {
            n = n - quarter;
        } else if (n >= dime) {
            n = n - dime;
        } else if (n >= nickel) {
            n = n - nickel;
        } else {
            n = n - penny;
        }
        t = t + 1;
    };
    printf("%i\n", t);
}

int getPositiveFloat(void) {
	float n;
	printf("O hai! ");
	do {
		printf("How much change is owed?\n");
		n = GetFloat();
	} while (n < 0);
	n = n * 100;
	int posInt = (int)roundf(n);
	return posInt;
}
