// Copyright 2022 UNN-IASR
#include "fun.h"

unsigned int faStr1(const char *str) {
    int count = 0;
    int count_with_number = 0;
	bool with_number = false;
	bool in_word = false;
    while (*str) {
        if ((*str != ' ') && (in_word == false)) {
            count++;
			in_word = true;
        }
		if ((*str != ' ') && (*str >= '0') && (*str <= '9')) {
			with_number = true;
        }
		if ((*str == ' ') && (in_word == true) && (with_number == true)) {
            count_with_number++;
            in_word = false;
            with_number = false;
        }
        if ((*str == ' ') && (in_word == true) && (with_number == false)) {
            in_word = false;
        }
        str++;
    }
    return (count-count_with_number);
}

unsigned int faStr2(const char *str) {
    int count = 0;
	bool first = false;
	bool flag1 = false;
	bool flag2 = false;
    bool in_word = false;
	while (*str) {
        if ((*str != ' ') && (in_word == false)) {
            in_word = true;
			if ((*str >= 'A') && (*str <= 'Z')) {
                flag1 = true;
				first = true;
            }
        }
        if (*str != ' ') {
            if ((((*str >= 'a') && (*str <= 'z')) || (first == true)) && (flag1 == true) && (in_word == true)) {
                flag2 = true;
                if (first == true) {
                    first = false;
                }
            } else {
                flag2 = false;
            }
        }
        if ((*str == ' ') && (in_word == true) && (flag1 == true)&&(flag2 == true)) {
            count++;
			in_word = false;
			flag1 = false;
			flag2 = false;
        }
        if ((*str == ' ') && (in_word == true) && ((flag1 == false) || (flag2 == false))) {
			in_word = false;
			flag1 = false;
			flag2 = false;
        }
        str++;
    }
    return count;
}

unsigned int faStr3(const char *str) {
    int count = 0;
	int length = 0;
	bool in_word = false;
    while (*str) {
        if (*str != ' ') {
            if (in_word == false) {
                count++;
                in_word = true;
            }
            length++;
        }
        if ((*str == ' ') && (in_word == true)) {
            in_word = false;
        }
        str++;
    }
    return (length + 1) / count;
}
