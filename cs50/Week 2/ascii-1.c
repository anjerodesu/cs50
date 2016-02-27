//
//  ascii-1.c
//  cs50
//
//  Created by Angelo Villegas on 27/2/16.
//  Copyright © 2016 Angelo Villegas. All rights reserved.
//

#include <stdio.h>

int main(void) {
	for (char c = 'A'; c <= 'Z'; c++) {
		printf("%i is %c\n", (int)c, c);
	}
}
