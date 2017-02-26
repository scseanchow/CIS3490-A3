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

void runQ2_3() {

  char search_test[100];
  char str[100];

  printf("string/pattern to search for: ");
  scanf("%s", search_test);

  int count = strlen(search_test);
  int search_count = 0;

  struct timeb start, end;
  ftime(&start);

  FILE *data;
  data = fopen("data_5.txt", "r");

  for (int i = 0; i < 44049; i++) {
    fscanf(data, "%s", str);
    for (int i = 0; i < count; i++){
      int flag = 1;
      if (str[i] != search_test[i]){
        flag = 0;
        continue;
      }
    }
    if (flag == 1){
      search_count++;
    }
  }

  ftime(&end);
  int diff1 = (int)(1000.0 * (end.time - start.time) +
                (end.millitm - start.millitm));
  printf("Total number of search patterns found for string: %s is %d. Total elapsed time was: %d milliseconds.\n",search_test,search_count,diff1 );
  return;
}
