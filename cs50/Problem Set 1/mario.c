//
//  mario.c
//  cs50
//
//  Created by Angelo Villegas on 14/2/16.
//  Copyright © 2016 Angelo Villegas. All rights reserved.
//

#include <stdio.h>
#include "cs50.h"

int getPositiveInt(void);

int main(void) {
    int n = getPositiveInt();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int m = n - i;
            if (j <= m) {
                printf(" ");
            } else if (j == n) {
                printf("##\n");
            } else {
                printf("#");
            }
        }
    }
}

int getPositiveInt(void) {
	int n;
	do {
		printf("Height: ");
		n = GetInt();
	} while (n < 0 || n > 23);
	return n;
}
