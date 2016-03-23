//
//  bubbleSort.c
//  cs50
//
//  Created by Angelo Villegas on 21/3/16.
//  Copyright © 2016 Angelo Villegas. All rights reserved.
//

#include <stdio.h>
#include "cs50.h"

int main(void) {
	int list[5] = {4, 3, 5, 1, 2};
	int listCount = (int)(sizeof(list)/sizeof(int));
	
	bool isSorted;
	do {
		isSorted = true;
		printf("list: %i %i %i %i %i\n", list[0], list[1], list[2], list[3], list[4]);
		for (int i = 1; i < listCount; i++) {
			if (list[i - 1] > list[i]) {
				int n = list[i - 1];
				list[i - 1] = list[i];
				list[i] = n;
				isSorted = false;
			}
		}
	} while (!isSorted);
}
