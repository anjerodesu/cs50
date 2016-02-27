//
//  water.c
//  cs50
//
//  Created by Angelo Villegas on 14/2/16.
//  Copyright © 2016 Angelo Villegas. All rights reserved.
//

#include <stdio.h>
#include "cs50.h"

static int ouncesPerMinute = 192;
static int ouncesPerBottle = 16;

int main(void) {
    printf("minutes: ");
    int n = GetInt();
    int r = (ouncesPerMinute / ouncesPerBottle) * n;
    printf("bottles: %i\n", r);
}
