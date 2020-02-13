#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int game(int, int);

int main(void){// main
    int selectedNum;
	srand(time(NULL));
	int guessThis = (1 + (rand()%25));

	printf("\nLet's Play a game! Try to guess what number I am thinking.\nEnter a number between 1-25: ");
	scanf("%d", &selectedNum);
	

	while (selectedNum<1 || selectedNum>25){
		printf("Enter a number between 1-25: ");
		scanf("%d", &selectedNum);
	}
	while (game(selectedNum, guessThis)!=2){
		if (game(selectedNum, guessThis)==1){
			printf("Your number is too high. Enter again: ");
			scanf("%d", &selectedNum);
		}
		if (game(selectedNum, guessThis)==0){
			printf("Your number is too low. Enter again: ");
			scanf("%d", &selectedNum);
		}
	}
	printf("\nCongratulations!!! You won the game!!!\nYour number %d matched %d\n\n", selectedNum, guessThis);
    return 0;
}// end of main

int game (int num, int guessThis){
	if (num == guessThis){
		return 2;
	}
	if (num < guessThis){
		return 0;
	}
	if (num > guessThis){
		return 1;
	}
	return 5;	
}