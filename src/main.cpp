/*
 * Copyright 2017 ZTE - VNG
 */

/* 
 * File:   main.cpp
 * Author: minhnh3
 *
 * Created on February 23, 2018, 5:33 PM
 */

#include <cstdlib>
#include "dasc.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

	return 0;
}

void SELECTION() {
	char key_name[30];
	printf(" 1. Insert 2. Search 3. Delete 4. Dump 5. End \n");
	scanf("%d%*c", &MODE);
	if (MODE == END_MODE) exit(0);
	if (MODE != DUMP_MODE) {
		printf("key_file = ");
		scanf("%s%*c", key_name);
		KEY_FILE = fopen(key_name, "r");
		if (KEY FILE == NULL) {
			printf("\nkey_dic can’t open\n");
			exit(0);
		}
	}
}

void INITIALIZE() {
	int i;
	BC_MAX = BC_INC;
	BC_POS = 1;
	TAIL_POS = 1;

	if (BC = (int *) malloc(sizeof (int) *2 * BC_MAX)) == NULL) {
			fprint(stderr, "BC malloc error!!");
			exit(-1);
		}
	memset(BC, sizeof (BC), 0);
	W_BASE(1, 1);
	BC_POS = 1;
	TAIL = MEM STR("TAIL", &TAIL_MAX, TAIL_INC);
	TAIL_POS = -1;
	TAIL[0] = '#';
	TEMP = MEM_STR("TEMP", &TEMP_MAX, TEMP_INC);
	KEY = MEM_STR("KEY", &KEY_MAX, KEY_INC);
}