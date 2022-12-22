#include "utils.h"

void matrizGen(int N,float A[][N], float B[][N])
{
  float x, y;
  srand(time(NULL));
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      x = (rand() % 10001) / 100.0f;
      y = (rand() % 10001) / 100.0f;
      A[i][j] = x;
      B[i][j] = y;
    }
  }
}

void matrizMul(int N, float A[][N], float B[][N], float C[][N]){
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      C[i][j] = 0;
      for (int k = 0; k < N; k++){
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}

void display(int N, float A[][N], float B[][N])
{
  printf("Matriz A:\n");
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      printf("%.2f ", A[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  printf("Matriz B:\n");
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      printf("%.2f ", B[i][j]);
    }
    printf("\n");
  }
}

void displayOne(int N, float A[][N])
{
  printf("Matriz C:\n");
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      printf("%.2f ", A[i][j]);
    }
    printf("\n");
  }
}
