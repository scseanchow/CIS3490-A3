/*
* 0931679
* Sean Chow
* CIS 3490 - A2
* Feb 13th, 2017
* main.c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include <assert.h>

// function prototypes
void runQ1_1();
void runQ1_2();
void runQ2_1();
void runQ2_2();
void runQ2_3();

/*
* main program
*/
int main(int argc, char *argv[]) {

  int choice = 0;

  while (choice != 6) {
    printf("----------------->>>MENU<<<-----------------\n");
    printf("1: brute force anagrams\n");
    printf("2: presort anagrams\n");
    printf("3: brute force string search\n");
    printf("4: horspool algorithm\n");
    printf("5: boyer moore algorithm\n");
    printf("6: exit program\n");
    printf("----------------->>>END<<<------------------\n");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      runQ1_1();
      break;
    case 2:
      runQ1_2();
      break;
    case 3:
      runQ2_1();
      break;
    case 4:
      runQ2_2();
      break;
    case 5:
      runQ2_3();
      break;
    case 6:
      break;
    }
  }
}
