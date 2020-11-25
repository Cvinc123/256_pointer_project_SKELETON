/*
 * transform1.cpp
 *
 *  Created on: Oct 31, 2020
 *      Author: keith
 */

//TODO organize includes
#include "../includes/transform1.h"
#include "../includes/constants.h"

using namespace std;

/**
 * transforms a lowercase char to an uppercase one
 * for instance 'a' to 'A'. Has no effect on non-
 * alphabetic characters.  islower may be of use
 *
 * \param pchar char to transform
 * \return bool - 	true - transform occurred
 * 					false - either pchar is null or its not an alhabetic char
 */
bool transform(char *pchar) {

	if(!islower(*pchar)) {
		return false;
	}
	else {
		*pchar = toupper(*pchar);
		return true;
	}
}
