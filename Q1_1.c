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

void runQ1_1() {

  char anagram_test[100];
  char str[100];
  int anagram_count = 0;

  printf("string to detect anagrams for: ");
  scanf("%s", anagram_test);

  struct timeb start, end;
  ftime(&start);

  FILE *data;
  data = fopen("data_4.txt", "r");
  for (int i = 0; i < 30000; i++) {
    fscanf(data, "%s", str);
    // test for anagram
    if (strlen(str) == strlen(anagram_test)) {
      int flag = 1;
      int first_bucket[26] = {0};
      int second_bucket[26] = {0};
      int char_to_test = 0;

      while (anagram_test[char_to_test] != '\0') {
        first_bucket[anagram_test[char_to_test] - 'a' + 49]++;
        char_to_test++;
      }

      char_to_test = 0;

      while (str[char_to_test] != '\0') {
        second_bucket[str[char_to_test] - 'a' + 49]++;
        char_to_test++;
      }

      for (int j = 0; j < 26; j++) {
        if (first_bucket[j] != second_bucket[j]){
          flag = 0;
          continue;
        }
      }
      if (flag == 1){
        printf("%s\n",str);
        anagram_count++;
      }
    }
  }
  ftime(&end);
  int diff1 = (int)(1000.0 * (end.time - start.time) +
                (end.millitm - start.millitm));
  printf("Total number of anagrams for string: %s is %d. Total elapsed time was: %d milliseconds.\n",anagram_test,anagram_count,diff1 );
  return;
}
