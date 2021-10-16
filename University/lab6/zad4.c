#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **podziel(char *str, int *size);
void sort(char **tab, int size);
char *sklej(char **tab, int size);

int main(int argc, char *argv[])
{

  if (argc > 1)
  {
    printf("Program dziala dla argumentu: \"%s\"\n", argv[1]);
    int i = 0;
    char **tab = podziel(argv[1], &i);

    sort(tab, i);
    char *tab1 = sklej(tab, i);

    printf("Rozmiar: %d, Wynik: %s\n", i, tab1);

    free(tab1);
    for (int j = 0; j < i; ++j)
    {
      free(tab[i]);
    }
    free(tab);
  }
  else
    printf("Niepoprawna liczba argumentow!\n");
  return 0;
}

char *sklej(char **tab, int size)
{
  int str_size = 1;
  char *result = calloc(1, sizeof(char));

  for (int i = 0; i < size; ++i)
  {
    str_size += strlen(tab[i]) + 2;
    result = realloc(result, sizeof(char) * str_size);
    strcat(result, tab[i]);
    strcat(result, " ");
  }

  return result;
}

int is_delim(char c)
{
  if (c == ',' || c == ';' || c == '.' || c == ':' || c == ' ')
    return 1;
  else
    return 0;
}

char **podziel(char *str, int *size)
{
  *size = 0;
  int i = 0;

  char **result = malloc(1 * sizeof(char *));
  char *actual_string = calloc(1, sizeof(char));
  int act_str_size = 0;

  for (i = 0; i <= strlen(str); ++i)
  {
    if (str[i] == '\0')
    {
      actual_string = realloc(actual_string, sizeof(char) * (act_str_size + 2));
      actual_string[act_str_size] = '\0';
      result = realloc(result, sizeof(char *) * (*size + 1));
      result[*size] = actual_string;
      *size += 1;
      act_str_size = 0;
    }
    else if (is_delim(str[i]))
    {
      while (is_delim(str[i + 1]))
        i++;

      actual_string = realloc(actual_string, sizeof(char) * (act_str_size + 1));
      actual_string[act_str_size] = '\0';

      result = realloc(result, sizeof(char *) * (*size + 1));
      result[*size] = actual_string;
      *size += 1;
      act_str_size = 0;
      actual_string = calloc(1, sizeof(char));
    }
    else
    {
      actual_string = realloc(actual_string, sizeof(char) * (act_str_size + 1));
      actual_string[act_str_size] = str[i];
      ++act_str_size;
    }
  }
  return result;
}

void sort(char **tab, int size)
{

  for (int i = 0; i < size; ++i)
  {
    for (int j = 1; j < size - i; ++j)
    {
      if (strcmp(tab[j], tab[j - 1]) < 0)
      {
        char *tmp = tab[j - 1];
        tab[j - 1] = tab[j];
        tab[j] = tmp;
      }
    }
  }
}
