//
//  ascii-0.c
//  cs50
//
//  Created by Angelo Villegas on 27/2/16.
//  Copyright © 2016 Angelo Villegas. All rights reserved.
//

#include <stdio.h>

int main(void) {
	for (int i = 65; i < 65 + 26; i++) {
		printf("%i is %c\n", i, (char)i);
	}
}
