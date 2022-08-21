#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rockPaperScissor(char p1[], char p2[]){
  printf("\t\t------ROCK-PAPER-SCISSOR------\n\n");
  printf("Price per game: Rs 50/-\n\n");
  int round =0, revenue =0, toPlay=1;
  int p1_choice,comp_choice;

  while(toPlay){
        round++;
  printf("Press 1 for rock, 2 for paper,3 for scissor: ");
  scanf("%d",&p1_choice);
  srand(time(NULL));
  comp_choice = rand() % 3 + 1;
  if(comp_choice == 1){
    printf("Computer have chosen rock\n");
  }
  else if(comp_choice == 2){
    printf("Computer have chosen paper\n");
  }
  else if(comp_choice == 3){
    printf("Computer have chosen scissor\n");
  }
  if(p1_choice==1){
                if(comp_choice==1){
                    printf("Draw\n");
                }
                if(comp_choice==2){
                    printf("Computer Wins!\n");
                }
                if(comp_choice==3){
                    printf("Player Wins\n");
                }
            }
  else  if(p1_choice==2){
                if(comp_choice==2){
                     printf("Draw\n");
                 }
                if(comp_choice==3){
                     printf("Player Wins!\n");
                 }
                if(comp_choice==1){
                     printf("Computer Wins!\n");
                 }
            }
  else if(p1_choice==3){
                if(comp_choice==3){
                     printf("Draw\n");
                 }
                if(comp_choice==2){
                     printf("Computer Wins!\n");
                 }
                if(comp_choice==1){
                     printf("Player Wins!\n");
                 }
            }
  else{
   printf("Wrong Input\n");
  }
  printf("\n\n\a");
char playAgain;
printf("Press Y to play again: ");
scanf("\n%c",&playAgain);
if(playAgain != 'Y'){
    toPlay =0;
}
}
printf("Total bill to pay is %d\n\n",round*50);
}
int main()
{
    char player1[100],player2[100];

    printf("Enter the player 1 name: ");
    scanf("%s",&player1);
    printf("Enter the player 2 name: ");
    scanf("%s",&player1);
    printf("\n\n");
    rockPaperScissor(player1,player2);

    return 0;
}
