#ifndef _UTILS_H_
#define _UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
void matrizGen(int N, float A[][N], float B[][N]);
void matrizMul(int N, float A[][N], float B[][N], float C[][N]);
void display(int N, float A[][N], float B[][N]);
void displayOne(int N, float A[][N]);

#endif