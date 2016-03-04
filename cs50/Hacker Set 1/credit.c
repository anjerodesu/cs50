//
//  credit.c
//  cs50
//
//  Created by Angelo Villegas on 28/2/16.
//  Copyright © 2016 Angelo Villegas. All rights reserved.
//

#include <stdio.h>
#include "cs50.h"
#include <string.h>
#include <ctype.h>

/**
 *  Number structure for American Express cards.
 */
static string cardAMEX[2] = {"34", "37"};

/**
 *  Number structure for Master Card cards.
 */
static string cardMACA[5] = {"51", "52", "53", "54", "55"};

/**
 *  Number structure for Visa cards.
 */
static string cardVISA[1] = {"4"};

/**
 *  A function that scans for user input and accepts digits.
 *
 *  @return A string value of the accepted card number.
 */
string getCardNumber();

/**
 *  A function that reverses the given string.
 *
 *  @param cn The string to be reversed.
 *
 *  @return The reversed string value.
 */
string reverseString(string cn);

/**
 *  A function that multiples every other digit by 2, starting with the number’s second-to-last digit.
 *
 *  @param cn The string to apply the algorithm.
 *
 *  @return The string with multiplied numbers.
 */
string altMult(string cn);

/**
 *  A function to sum up the list of digits in string format.
 *
 *  @param cn The string to sum up.
 *
 *  @return The total sum of the string.
 */
int sum(string cn);

/**
 *  A function that will return the characters from the first character up to the given c.
 *
 *  @param cn The string to get the characters from.
 *  @param c  The total number of digits to get from the start.
 *
 *  @return The string containing the characters of the given string.
 */
string getCharacters(string cn, int c);

/**
 *  A function that checks if the given card number is an American Express credit card.
 *
 *  @param cn A validated credit card number.
 *
 *  @return True if the card is an American Express credit card, false otherwise.
 */
bool isAMEX(string cn);

/**
 *  A function that checks if the given card number is a Master Card credit card.
 *
 *  @param cn A validated credit card number.
 *
 *  @return True if the card is a Master Card credit card, false otherwise.
 */
bool isMACA(string cn);

/**
 *  A function that checks if the given card number is a Visa credit card.
 *
 *  @param cn A validated credit card number.
 *
 *  @return True if the card is a Visa credit card, false otherwise.
 */
bool isVISA(string cn);

/**
 *  A function that checks if the given string is a valid credit card number.
 *
 *  @param cn The string to be validated.
 *
 *  @return True if the number is a valid credit card number. false otherwise.
 */
bool isValidCreditCard(string cn);

int main(void) {
	string s = getCardNumber();
	string rString = reverseString(s);
	string multString = altMult(rString);
	bool isCCValid = isValidCreditCard(multString);
	
	if (isCCValid) {
		if (isAMEX(s)) {
			printf("AMEX\n");
		} else if (isMACA(s)) {
			printf("MASTERCARD\n");
		} else if (isVISA(s)) {
			printf("VISA\n");
		} else {
			printf("INVALID\n");
		}
	} else {
		printf("INVALID\n");
	}
	
	free(s);
	free(rString);
	free(multString);
}

string getCardNumber() {
	printf("Number: ");
	long long cn = GetLongLong();
	string s = malloc(sizeof(char *) * 20);
	sprintf(s, "%lld", cn);
	return s;
}

string reverseString(string cn) {
	char tmp;
	string src, dst, cnd = malloc(sizeof(char *) * 20);
	size_t len;
	strcpy(cnd, cn);
	if (cnd != NULL) {
		len = (int)strlen(cnd);
		if (len > 1) {
			src = cnd;
			dst = cnd + len - 1;
			while (src < dst) {
				tmp = *src;
				*src++ = *dst;
				*dst-- = tmp;
			}
		}
	}
	return cnd;
}

string altMult(string cn) {
	string newCN = malloc(sizeof(char *) * 20);
	for (int i = 0, n = (int)strlen(cn); i < n; i++) {
		if (i > 0 && i % 2 != 0) {
			int ch = cn[i] - '0';
			int d = ch * 2;
			if (d > 9) {
				string scon = malloc(sizeof(char *) * 3);
				sprintf(scon, "%i", d);
				strcat(newCN, scon);
				free(scon);
			} else {
				char con = d + '0';
				string ccn = malloc(sizeof(char *) * 2);
				ccn[0] = con;
				ccn[1] = '\0';
				strcat(newCN, ccn);
				free(ccn);
			}
		} else {
			string ccn = malloc(sizeof(char *) * 2);
			ccn[0] = cn[i];
			ccn[1] = '\0';
			strcat(newCN, ccn);
			free(ccn);
		}
	}
	return newCN;
}

int sum(string cn) {
	int sum = 0;
	for (int i = 0, n = (int)strlen(cn); i < n; i++) {
		int ch = cn[i] - '0';
		sum = sum + ch;
	}
	return sum;
}

string getCharacters(string cn, int c) {
	string fd = malloc(sizeof(char *) * c);
	for (int i = 0; i < c; i++) {
		fd[i] = cn[i];
	}
	return fd;
}

bool isAMEX(string cn) {
	bool isAMEX = false;
	string fd = getCharacters(cn, 2);
	for (int i = 0, n = sizeof(cardAMEX)/sizeof(cardAMEX[0]); i < n; i++) {
		if (strcmp(fd, cardAMEX[i]) == 0) {
			isAMEX = true;
			break;
		}
	}
	return isAMEX;
}

bool isMACA(string cn) {
	bool isMACA = false;
	string fd = getCharacters(cn, 2);
	for (int i = 0, n = sizeof(cardMACA)/sizeof(cardMACA[0]); i < n; i++) {
		if (strcmp(fd, cardMACA[i]) == 0) {
			isMACA = true;
			break;
		}
	}
	return isMACA;
}

bool isVISA(string cn) {
	bool isVISA = false;
	string fd = getCharacters(cn, 1);
	for (int i = 0, n = sizeof(cardVISA)/sizeof(cardVISA[0]); i < n; i++) {
		if (strcmp(fd, cardVISA[i]) == 0) {
			isVISA = true;
			break;
		}
	}
	return isVISA;
}

bool isValidCreditCard(string cn) {
	int sm = sum(cn);
	if (sm % 10 == 0) {
		return true;
	} else {
		return false;
	}
}
