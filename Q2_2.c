/*
* 0931679
* Sean Chow
* CIS 3490 - A3
* Mar 13th, 2017
* Q2_3.c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include <sys/timeb.h>

int t[500];

void createTable(char* p) {
  int i, j, m;
  m = strlen(p);
  for (i = 0; i < 500; i++)
    t[i] = m;
  for (j = 0; j < m - 1; j++)
    t[p[j]] = m - 1 - j;
}

void runQ2_2() {

  char search_test[100];
  char str[100];

  printf("string/pattern to search for: ");
  scanf("%s", search_test);

  int count = strlen(search_test);
  int search_count = 0;
  int pattern_switch_counter = 0;
  struct timeb start, end;
  ftime(&start);

  FILE *data;
  data = fopen("data_5.txt", "r");
  int m = strlen(search_test);

  createTable(search_test);

  int i, j, k;

  // horspool
  while (fgets(str, 255, data) != NULL) {

    int n = strlen(str);
    i = m - 1;
    while (i < n) {
      k = 0;
      while ((k < m) && (search_test[m - 1 - k] == str[i - k]))
        k++;
      if (k == m) {
        search_count++;
        break;
      } else {
        i += t[str[i]];
      }
    }
  }

  ftime(&end);
  int diff1 =
      (int)(1000.0 * (end.time - start.time) + (end.millitm - start.millitm));
  printf("Total number of search patterns found for string: %s is %d. Number "
         "of pattern switches was %d. Total "
         "elapsed time was: %d milliseconds.\n",
         search_test, search_count, pattern_switch_counter, diff1);
  return;
}
