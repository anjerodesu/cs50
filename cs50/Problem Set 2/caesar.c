//
//  caesar.c
//  cs50
//
//  Created by Angelo Villegas on 27/2/16.
//  Copyright © 2016 Angelo Villegas. All rights reserved.
//

#include <stdio.h>
#include "cs50.h"
#include <string.h>

char e(char c, int k);

int main(int argc, string argv[]) {
	if (argc <= 1) {
		printf("The number of argument is invalid!\n");
		return 1;
	}
	
	int k = atoi(argv[1]);
	string s = GetString();
	
	for (int i = 0, n = strlen(s); i < n; i++) {
		char c = e(s[i], k);
		printf("%c", c);
		
	}
	printf("\n");
	
	return 0;
}

char e(char c, int k) {
	if (c >= 'A' && c <= 'Z') {
		c = c + k;
		while (c > 'Z') {
			int r = ((int)c - (int)'Z') - 1;
			c = 'A';
			c = c + (char)r;
		};
		return c;
	} else if (c >= 'a' && c <= 'z') {
		c = c + k;
		while (c > 'z' || c < 0) {
			int r = ((int)c - (int)'z') - 1;
			c = 'a';
			c = c + (char)r;
		};
		return c;
	} else {
		return c;
	}
}
