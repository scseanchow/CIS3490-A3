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
void runQ1_2() {

  char anagram_test[100];
  char str[100];
  int anagram_count = 0;

  printf("string to detect anagrams for: ");
  scanf("%s", anagram_test);

  struct timeb start, end;
  ftime(&start);
  char *temp = malloc(sizeof(char) * 30);

  FILE *data;
  data = fopen("data_4.txt", "r");

  int anagram_int = atoi(anagram_test);
  int length_anagram = strlen(anagram_test);
  int anagram_array[length_anagram];

  int counter = 0;

  while (anagram_int > 0) {
    anagram_array[counter] = anagram_int % 10;
    anagram_int /= 10;
    counter++;
  }

  // bubble sort anagram array
  for (int i = 0; i < counter; i++) {
    for (int j = 0; j < counter - i - 1; j++) {
      if (anagram_array[j] > anagram_array[j + 1]) {
        int temp = anagram_array[j];
        anagram_array[j] = anagram_array[j + 1];
        anagram_array[j + 1] = temp;
      }
    }
  }

  for (int i = 0; i < 30000; i++) {
    fscanf(data, "%s", str);

    int str_int = atoi(str);
    int length_string = strlen(str);

    if (length_string == length_anagram) {
      // put it into an array
      int string_array[length_string];
      int counter = 0;
      while (str_int > 0) {
        string_array[counter] = str_int % 10;
        str_int /= 10;
        counter++;
      }
      // bubble sort str array
      for (int i = 0; i < counter; i++) {
        for (int j = 0; j < counter - i - 1; j++) {
          if (string_array[j] > string_array[j + 1]) {
            int temp = string_array[j];
            string_array[j] = string_array[j + 1];
            string_array[j + 1] = temp;
          }
        }
      }
      int flag = 0;
      for (int i = 0; i < counter; i++){
        if (anagram_array[i] != string_array[i]){
          flag = 1;
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
