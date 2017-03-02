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

// A utility function to get maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }

// The preprocessing function for Boyer Moore's bad character heuristic
void badCharHeuristic(char *str, int size, int badchar[256]) {
  int i;

  // Initialize all occurrences as -1
  for (i = 0; i < 256; i++)
    badchar[i] = -1;

  // Fill the actual value of last occurrence of a character
  for (i = 0; i < size; i++)
    badchar[(int)str[i]] = i;
}

void runQ2_3() {

  char search_test[100];
  char txt[100];

  printf("string/pattern to search for: ");

  // consume new line
  fgetc(stdin);
  fgets(search_test,100,stdin);

  strtok(search_test, "\n");

  int search_count = 0;

  struct timeb start, end;
  ftime(&start);

  FILE *data;
  data = fopen("data_5.txt", "r");

  int m = strlen(search_test);

  int badchar[256];
  int pattern_switch_counter = 0;
  badCharHeuristic(search_test, m, badchar);

  while (fgets(txt, 255, data) != NULL) {
    int n = strlen(txt);

    int s = 0; // s is shift of the pattern with respect to text

    // refernced: http://www-igm.univ-mlv.fr/~lecroq/string/node14.html#SECTION00140
    while (s <= (n - m)) {
      int j = m - 1;

      while (j >= 0 && search_test[j] == txt[s + j]) {
        j--;
      }
      if (j < 0) {
        search_count++;
        s += (s + m < n) ? m - badchar[txt[s + m]] : 1;
      }

      else {
        pattern_switch_counter++;
        s += max(1, j - badchar[txt[s + j]]);
      }
    }
  }

  // time & end
  ftime(&end);
  int diff1 =
      (int)(1000.0 * (end.time - start.time) + (end.millitm - start.millitm));
  printf("Total number of search patterns found for string: %s is %d.\n Number of pattern switches was %d. Total elapsed time was: %d milliseconds.\n",
         search_test, search_count, pattern_switch_counter, diff1);
  return;
}
