/*
 * Copyright 2017 ZTE - VNG
 */

/* 
 * File:   dasc.h
 * Author: minhnh3
 *
 * Created on February 23, 2018, 5:05 PM
 */

#include <cstdlib>
#include <stdio.h>
#include <cstring>

#define INSERT_MODE 1 /* Indicate the insertion mode */
#define SEARCH_MODE 2 /* Indicate the search, or retrieval, mode */
#define DELETE_MODE 3 /* Indicate the deletion mode */
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

FILE *KEY_FILE; /* Key dictionary file */
char *KEY; /* Key */
char *TAIL; /* TAIL */
char *TEMP; /* Buffer */
int *BC; /* BASE and CHECK*/
int MODE; /* Flag indicating insertion, search, deletion, dump and end */
int BC_POS; /* Current maximum index of the double-array */
int TAIL_POS; /* The current maximum index of TAIL */
int BC_MAX; /* Maximum size of BASE and CHECK */
int TAIL_MAX; /* Maximum size of TAIL */
int KEY_MAX; /* Maximum size of KEY */
int TEMP_MAX; /* Maximum size of TEMP */

void BC_INSERT(), TAIL_INSERT(), W_BASE(), W_CHECK(), REALLOC_BC();
char *MEM_STR();

int BASE(int n) /* BASE[n] */ {
    if (n > BC_POS) return (0);
    else return (BC[2 * n]);
}

int CHECK(int n) /* CHECK[n] */ {
    if (n > BC_POS) return (0);
    else return (BC[2 * n + 1]);
}

/* W_BASE (n, node) and W_CHECK (n, node) store node into BASE [n] and CHECK [n]
respectively */
void W_BASE(int n, int node) /* BASE [n] <= node*/ {
    while (n >= BC_MAX) REALLOC_BC();
    if (n > BC_POS) BC_POS = n;
    BC[2 * n] = node;
}

void W_CHECK(int n, int node) /*CHECK[n] <= node */ {
    while (n >= BC_MAX) REALLOC_BC();
    if (n > BC_POS) BC_POS = n;

    BC[2 * n + 1] = node;
}

char * MEM_STR(char *area_name, int *max) {
    char *area;
    if ((area = (char *) malloc(sizeof (char) * *max)) == NULL) {
        printf("%s malloc error! !\n", area_name);
    }
    memset(area, sizeof (area), '\0');
    return (area);
}

void REALLOC_BC() {
    int i, pre_bc;
    pre_bc = BC_MAX;
    BC_MAX += BC_INC;
    if ((BC = (int *) realloc(BC, sizeof (int) *2 * BC_MAX)) == NULL) {
        fprintf(stderr, "BC realloc error!!");
        exit(-1);
    }
    for (i = 2 * pre_bc; i < 2 * BC_MAX; i++) BC[i] = 0;
    fprintf(stderr, "*** BC realloc ***\n");
}

char *REALLOC_STR(char *area_name, char *area, int *max, int inc) {
    int i, pre_size;
    pre_size = *max;
    *max += inc;
    if ((area = (char*) realloc(area, sizeof (char) * *max)) == NULL) {
        printf("%s reallot error! !\n", area_name);
        exit(-1);
    }
    for (i = pre_size; i<*max; i++) area[i] == '\0';
    fprintf(stderr, "***%s realloc ***\n", area_name);
    return (area);
}

/* READ_TAIL() copies the requested single-string from TAIL*/
void READ_TAIL(int p) {
    int i = 0;
    while (TAIL[p] != '#') TEMP[i++] = TAIL[p++];
    TEMP[i++] = '#';
    TEMP[i] = '/0';
}

/* WRITE_ TAIL() stores the single-string into the requested address p of TAIL*/
void WRITE_TAIL(char *temp, int p) {
    int i = 0, tail_index;
    tail_index = p;
    while ((p + strlen(temp)) >= TAIL_MAX - 1)
        TAIL = REALLOC_STR("TAIL", TAIL, TAIL_INC);
    while (*(temp + i) != '\0')
        TAIL [tail_index++] = *(temp + i++);
    if ((p + i + 1) > TAIL_POS) TAIL_POS = p + i;
}

