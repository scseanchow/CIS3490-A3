/*
* 0931679
* Sean Chow
* CIS 3490 - A3
* Feb 27th, 2017
* Q1_1.c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include <sys/timeb.h>

// brute force anagram
void runQ1_1() {

  char anagram_test[100];
  char str[100];
  int anagram_count = 0;

  printf("string to detect anagrams for: ");
  scanf("%s", anagram_test);

  struct timeb start, end;
  ftime(&start);
  char * temp = malloc(sizeof(char) * 30);

  FILE *data;
  data = fopen("data_4.txt", "r");
  for (int i = 0; i < 30000; i++) {
    fscanf(data, "%s", str);

    int length_string = strlen(str);
    int length_anagram = strlen(anagram_test);
    int flag = 0;

    temp = strcpy(temp,str);

      if (length_string == length_anagram) {
      for (size_t i = 0; i < length_anagram; i++) {
        flag = 1;
        for (size_t j = 0; j < length_string; j++) {
          if (anagram_test[i] == temp[j]){
            temp[j] = '!';
            flag = 0;
            break;
          }
        }
        if (flag == 1){
          break;
        }
      }
      if (flag == 0){
        printf("%s\n",str);
        anagram_count++;
      }
    }
  }
  ftime(&end);
  int diff1 =
      (int)(1000.0 * (end.time - start.time) + (end.millitm - start.millitm));
  printf("Total number of anagrams for string: %s is %d. Total elapsed time "
         "was: %d milliseconds.\n",
         anagram_test, anagram_count, diff1);
  return;
}
