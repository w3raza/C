#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

struct wektor
{
  int x, y, z;
};

struct abc
{
  struct wektor w;
  int length;
};

int wektorLength(struct wektor w)
{
  int underSqrt = 0;
  underSqrt = pow(w.x, 2) + pow(w.y, 2) + pow(w.z, 2);
  return sqrt(underSqrt);
}

int compareWektorLength(const void *a, const void *b)
{
  struct abc wektorA = *(struct abc *)a;
  struct abc wektorB = *(struct abc *)b;
  return wektorB.length - wektorA.length;
}

int main(int argc, char const *argv[])
{
  srand(time(NULL));
  struct abc wektory[10];

  int i;

  struct abc wektor;
  wektor.w.x = 1;
  wektor.w.y = 1;
  wektor.w.z = 1;
  wektor.length = 1;

  for (i = 0; i < 10; i++)
  {
    wektory[i].w.x = rand() % 10;
    wektory[i].w.y = rand() % 10;
    wektory[i].w.z = rand() % 10;

    wektory[i].length = wektorLength(wektory[i].w);

    printf("x: %d y: %d z: %d l: %d\n", wektory[i].w.x, wektory[i].w.y, wektory[i].w.z, wektory[i].length);
  }

  return 0;
}