//
//  crypt.c
//  cs50
//
//  Created by Angelo Villegas on 6/3/16.
//  Copyright © 2016 Angelo Villegas. All rights reserved.
//

#include <stdio.h>
#include "cs50.h"
#include <unistd.h>

int main(void) {
	printf("%s\n", crypt("12345", "50"));
}
