//
//  crack.c
//  cs50
//
//  Created by Angelo Villegas on 4/3/16.
//  Copyright © 2016 Angelo Villegas. All rights reserved.
//

#include <stdio.h>
#include "cs50.h"
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>

string empstr();
string trmwsp(string s);
string getCharacters(string s, int c);

int main(int argc, string argv[]) {
	float startTime = (float)clock()/CLOCKS_PER_SEC;
	if (argc > 2) {
		printf("The number of arguments is more than the expected number of arguments!\n");
		exit(EXIT_FAILURE);
	}
	
	if (argc < 2) {
		printf("The number of arguments is less than the expected number of arguments!\n");
		exit(EXIT_FAILURE);
	}
	
	string hashed = argv[1];
	string salt = getCharacters(hashed, 2);
	bool isPasswordCracked = false;
	char c[8];
	c[0] = ' ';
	c[1] = ' ';
	c[2] = ' ';
	c[3] = ' ';
	c[4] = ' ';
	c[5] = ' ';
	c[6] = ' ';
	c[7] = ' ';
	
	int lastChar = (int)strlen(c) - 1;
	
	do {
		for (char i = '!'; i <= '~'; i++) {
			c[lastChar] = i;
			
			string trmC = trmwsp(c);
			string encP = crypt(trmC, salt);
			if (strcmp(encP, hashed) == 0) {
				printf("%s", c);
				isPasswordCracked = true;
			}
			free(trmC);
		}
		
		if ((c[lastChar] + 1) > '~') {
			c[lastChar] = '!';
			
			for (int p = 1; p < lastChar; p++) {
				c[lastChar - p]++;
				
				if ((c[lastChar - p] + 1) > '~') {
					c[lastChar - p] = '!';
					
					int p2 = p + 1;
					if (p2 >= 0) {
						c[lastChar - (p + 1)]++;
					}
				} else {
					break;
				}
			}
		}
	} while (!isPasswordCracked || strcmp(c, "~~~~~~~~") != 0);
	
	free(salt);
	
	float endTime = (float)clock()/CLOCKS_PER_SEC;
	float timeElapsed = endTime - startTime;
	printf("time: %f\n", timeElapsed);
	
	exit(EXIT_SUCCESS);
}

string getCharacters(string s, int c) {
	string fd = malloc(sizeof(char *) * c);
	for (int i = 0; i < c; i++) {
		fd[i] = s[i];
	}
	return fd;
}

string trmwsp(string s) {
	if (strlen(s) < 1) {
		return empstr();
	}
	
	while (isspace(*s)) s++;
	
	if (*s == 0) {
		return empstr();
	}
	
	string end = s + strlen(s) - 1;
	while (end > s && isspace(*end)) end--;
	end++;
	
	string ts = malloc(sizeof(char *) * strlen(s));
	size_t len = strlen(s) - strlen(end);
	memcpy(ts, s, len);
	return ts;
}

string empstr() {
	string s = "";
	return s;
}
