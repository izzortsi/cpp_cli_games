#include <stdlib.h>
#include <stdio.h>
#include <time.h> /* time */

void init_game( int *dsize,  int *maxturns) {

  printf("Game rules: \n"
          "At each turn, you must roll a n-faced dice. Sum up the result to your accumulation pool. \n"
          "You then must opt for either finish or continue the game. If both players (you and I) \n"
          "agree on ending the game, it then follows to the resolution phase; otherwise, it proceeds to the next turn. \n"
          "At the resolution phase, the accumulated totals are compared, and wins the player with the smallest total. \n"
          "When the game reaches the maximum number of turns N, the resolution phase is forced. \n");

  printf("What is the number of faces for the dice?\n"); scanf("%u", dsize);
  printf("What is the maximum number of turns?\n"); scanf("%u", maxturns);
//  printf("Qual o modo de jogo? (M ou m)\n"); scanf("%c", mode); o modo de jogo tem que ser o "mais distante da m�dia" sl


}

int machine_decision(int total2, int cturn, int dsize) {

  int mean = (cturn*dsize)/2;

  if (total2 <= mean*(1 - 0.2/(cturn*0.8)))  {
    return 0;
  }
  else {
    if ((total2 > mean) && (total2 <= mean + 0.2*mean/cturn*0.8)) {
      return 0;
    }
    else {
      return 1;
    }
  }
}


void turn( int *total1,  int *total2,  int *cturn,  int *out,  int dsize, int maxturns) {
  srand(time(NULL));
  printf("It's turn %u.", *cturn);
  printf("Throw the dice! (type anything and press Enter). \n"); getchar(); 
  // scanf("%*s");
  int roll1 = rand() % dsize +1;
  int roll2 = rand() % dsize +1;
  *total1 += roll1;
  printf("Your roll is: %i. \n", roll1);
  *total2 += roll2;
  printf("Your cumulated total is: %i. \n", *total1);

  int vote1;
  printf("Vote to either continue or resolve the game: \n "
         "1 for continuing it; 0 to resolve it. \n"
         "Rembember: it does not depend only on you! \n");

  int vote2 = machine_decision(*total2, *cturn, dsize);

  printf("The computer has already voted... \n");
  scanf("%u", &vote1);
  
  while ((vote1 != 0) && (vote1 != 1)) {
   printf("Invalid vote (%u). Try again. \n", vote1);
   scanf("%u", &vote1);
  }
   
  *cturn += 1;
  if (*cturn >= maxturns) {
    printf("The game has reached the maximum number of turns. \n");
    printf("The computer summed a total of %i, and you a total of %i. \n", *total2, *total1);
    if (*total1 < *total2) {
      printf("Since your total is smaller than the computer's, you win!\n");

      // sleep(5);
      // return 0;
     // exit(0);
    }
    else {
      if (*total1 == *total2) {
        printf("Draw.\n");
        // exit(0);
        // sleep(5);
        // return 0;
      } else {
         printf("The computer's total is smaller than yours. You've lost. \n");
        //  sleep(5);
        //  return 0;
         // exit(0);
       }
    }
    // sleep(5);
    // return 0;
  }
  if (vote1 == vote2 ) {
    if (vote1 == 0) {
     // RESOLVE
     printf("Both players opted to resolve the game (zero).\n");
     printf("The computer summed a total of %i, and you a total of %i. \n", *total2, *total1);

     if (*total1 < *total2) {
       printf("Since your total is smaller than the computer's, you win!\n");
      //  sleep(5);
      //  return 0;
      //  exit(0);
     }
     else {
       if (*total1 == *total2) {
         printf("Draw.\n");
        //  sleep(5);
        //  return 0;
        //  exit(0);
       } else {
          printf("The computer's total is smaller than yours. You've lost. \n");
          // sleep(5);
          // return 0;
          // exit(0);
        }
      }
    //  sleep(5);
    //  return 0;
    }
    else {
      turn(total1, total2, cturn, out, dsize, maxturns);
      }
    }
}


int main() {
   int dsize;  int maxturns;

  // printf("dsize antes da init_game, %u \n", dsize);

  init_game(&dsize, &maxturns);

  // printf("dsize depois: %u \n", dsize);

   int total1 = 0;  int total2 = 0;
   int cturn = 1;  int out = 0;


  turn(&total1, &total2, &cturn, &out, dsize, maxturns);
  printf("Press anything to exit. \n");
  getchar(); 
}
