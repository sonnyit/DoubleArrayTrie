/*
 * Copyright 2017 ZTE - VNG
 */

/* 
 * File:   dasc.h
 * Author: minhnh3
 *
 * Created on February 23, 2018, 5:05 PM
 */

#define INSERT_MODE 1 /* Indicate the insertion mode */
#define SEARCH_MODE 2 /* Indicate the search, or retrieval, mode */
#define DELETE_MODE 3 / * Indicate the deletion mode */
#define DUMP_MODE 4 /* Indicate the dump mode */
#define END_MODE 5 /* Indicate the end of program */
#define MIN_CODE 1 /* Minimum numerical code */
#define MAX_CODE 255 /* Maximum numerical code */
#define BC_INC 10 /* Increment of the double-array */
#define TAIL_INC 10 /* Increment of TAIL */
#define KEY_INC 5 /* Increment of the double-array */
#define TEMP_INC 5 /* Increment of TAIL */
#define TRUE -1
#define FALSE 0
#define NILL -1

FILE *KEY FILE; /* Key dictionary file */
char *KEY; /* Key */
char *TAIL; /* TAIL */
char *TEMP ; /* Buffer */
int *BC; /* BASE and CHECK*/
int MODE ; /* Flag indicating insertion, search, deletion, dump and end */
int BC_POS ; /* Current maximum index of the double-array */
int TAIL_POS; /* The current maximum index of TAIL */
int BC_MAX ; /* Maximum size of BASE and CHECK */
int TAIL_MAX; /* Maximum size of TAIL */
int KEY_MAX; /* Maximum size of KEY */
int TEMP_MAX; /* Maximum size of TEMP */

void BC_INSERT(), TAIL_INSERT(), W_BASE() W_CHECK();
char *MEM_STR() ;