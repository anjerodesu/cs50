//
//  argv-2.c
//  cs50
//
//  Created by Angelo Villegas on 27/2/16.
//  Copyright © 2016 Angelo Villegas. All rights reserved.
//

#include <stdio.h>
#include "cs50.h"
#include <string.h>

int main(int argc, string argv[]) {
	for (int i = 0; i < argc; i++) {
		for (int j = 0, n = (int)strlen(argv[i]); j < n; j++) {
			printf("%c\n", argv[i][j]);
		}
	}
}
