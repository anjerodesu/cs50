//
//  insertionSort.c
//  cs50
//
//  Created by Angelo Villegas on 23/3/16.
//  Copyright © 2016 Angelo Villegas. All rights reserved.
//

#include <stdio.h>
#include "cs50.h"

int main(void) {
	int list[5] = {4, 3, 5, 1, 2};
	int listCount = (int)(sizeof(list)/sizeof(int));
	
	for (int i = 1; i < listCount; i++) {
		int j = i;
		while (j > 0 && list[j - 1] > list[j]) {
			int n = list[j - 1];
			list[j - 1] = list[j];
			list[j] = n;
			j = j - 1;
			printf("list: %i %i %i %i %i\n", list[0], list[1], list[2], list[3], list[4]);
		}
	}
}
