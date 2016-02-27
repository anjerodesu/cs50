//
//  vigenere.c
//  cs50
//
//  Created by Angelo Villegas on 27/2/16.
//  Copyright © 2016 Angelo Villegas. All rights reserved.
//

#include <stdio.h>
#include "cs50.h"
#include <ctype.h>
#include <string.h>

bool isstring(string s);
int indexOf(char k);
char e(char c, int k);

static string tr = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(int argc, string argv[]) {
	if (argc <= 1) {
		printf("The number of argument is invalid!\n");
		return 1;
	}
	
	if (!isstring(argv[1])) {
		printf("The argument given is not of type 'string'!\n");
		return 1;
	}
	
	if (argc > 2) {
		printf("The argument given is more than the number of expected!\n");
		return 1;
	}
	
	string k = argv[1];
	int l = strlen(k);
	string s = GetString();
	
	int j = 0;
	for (int i = 0, n = strlen(s); i < n; i++) {
		if (j >= l) {
			j = 0;
		}
		
		char key = k[j];
		int p = indexOf(key);
		char c = e(s[i], p);
		printf("%c", c);
		
		if (!isalpha(c)) {
			continue;
		}
		
		if (j < l) {
			j++;
		}
	}
	printf("\n");
}

bool isstring(string s) {
	for (int i = 0, n = strlen(s); i < n; i++) {
		if (!isalpha(s[i])) {
			return false;
		}
	}
	return true;
}

int indexOf(char k) {
	int p = -1;
	for (int i = 0, n = strlen(tr); i < n; i++) {
		if (tr[i] == toupper(k)) {
			p = i;
			break;
		}
	}
	return p;
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
