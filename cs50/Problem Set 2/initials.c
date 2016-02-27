//
//  initials.c
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
	
	for (int i = 0, n = strlen(s); i < n; i++) {
		if (i == 0 || s[i - 1] == ' ') {
			printf("%c", toupper(s[i]));
		}
	}
	printf("\n");
}
