//
//  capitalize-2.c
//  cs50
//
//  Created by Angelo Villegas on 27/2/16.
//  Copyright © 2016 Angelo Villegas. All rights reserved.
//

#include <stdio.h>
#include "cs50.h"
#include <string.h>
#include <ctype.h>

int main(void) {
	string s = GetString();
	for (int i = 0, n = (int)strlen(s); i < n; i++) {
		printf("%c", toupper(s[i]));
	}
	printf("\n");
}
