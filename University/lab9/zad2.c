#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define size 10

struct wektor
{
  int x;
  int y;
  int z;
};

struct abc
{
  struct wektor w;
  float dlugosc;
};

float dlugosc(struct wektor w)
{
  int a;
  float b;

  a = w.x * w.x + w.y * w.y + w.z * w.z;
  b = sqrt(a);

  return b;
}

int compare1(const void *a, const void *b)
{
  float zm1 = *(float *)a;
  float zm2 = *(float *)b;
  if (zm1 <= zm2)
    return -1;
  if (zm1 == zm2)
    return 0;
  else
    return 1;
}
int compare2(const void *a, const void *b)
{
  float zm1 = *(float *)a;
  float zm2 = *(float *)b;
  if (zm1 < 0.99 * zm2)
    return -1;
  if (zm1 > 1.01 * zm2)
    return 1;
  else
    return 0;
}

int main()
{
  struct wektor array[size];
  struct abc array1[size];

  srand(time(NULL));

  float szukana = 10.8;
  float wektory[size];
  int koniec = 1;
  int ilosc = 0;
  float *znaleziony;

  int i;
  for (i = 0; i < size; i++)
  {
    array[i].x = ((((rand() % 10) * (2 + i)) % 10) + 1);
    array[i].y = ((((rand() % 10) * (3 + i)) % 10) + 1);
    array[i].z = ((((rand() % 10) * (4 + i)) % 10) + 1);

    printf("X=%d \t Y=%d \t Z=%d \n", array[i].x, array[i].y, array[i].z);

    array1[i].dlugosc = dlugosc(array[i]);

    printf("dlugosc wektora=%g \n\n", array1[i].dlugosc);
  }

  for (i = 0; i < size; i++)
  {
    wektory[i] = array1[i].dlugosc;
  }

  qsort(&wektory, size, sizeof(float), *compare1);

  while (koniec != 0)
  {
    znaleziony = bsearch(&szukana, &wektory, size, sizeof(float), *compare2);

    if (znaleziony != 0)
    {
      ilosc++;
      printf("Znaleziony wektor to %f \n", *znaleziony);
      *znaleziony = 0;
    }
    if (znaleziony == 0)
    {
      koniec = 0;
    }
  }
  printf("Szukana:%g\ntolerancja:%g\nprzedzial:<%g,%g> \n", szukana, 0.01 * szukana, 0.99 * szukana, 1.01 * szukana);
  printf("Ile wektorow znaleziono: %d \n", ilosc);

  return 0;
}
