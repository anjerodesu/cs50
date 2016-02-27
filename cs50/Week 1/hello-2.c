//
//  hello-2.c
//  cs50
//
//  Created by Angelo Villegas on 29/12/15.
//  Copyright © 2015 Angelo Villegas. All rights reserved.
//

#include "cs50.h"
#include <stdio.h>

int main(void) {
	printf("Your name please: ");
	string s = GetString();
	char c[16] = "How's it going?";
	printf("hello, %s\n%s\n", s, c);
}