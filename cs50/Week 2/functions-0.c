//
//  functions-0.c
//  cs50
//
//  Created by Angelo Villegas on 27/2/16.
//  Copyright © 2016 Angelo Villegas. All rights reserved.
//

#include <stdio.h>
#include "cs50.h"

void PrintName(string name);

int main(void) {
	printf("Your name: ");
	string s = GetString();
	PrintName(s);
}

void PrintName(string name) {
	printf("Hello, %s\n", name);
}
