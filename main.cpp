#include <stdio.h>
#include <stdlib.h>
#include "cboard.h"
int main(){
	char classic[65] = "RNBQKBNRPPPPPPPP                                pppppppprnbqkbnr";
	Cboard m(8, 8, classic);
	int moveLimit = 300;
	while(true){
		for(int t = 0; t < 2; t++){
			m.display();
			m.act(t);
			if(m.ended){
				printf("winner: player %d\nscores: %d %d\n", m.winner, m.score[0], m.score[1]);
				return 0;
			}
			if(m.moves > moveLimit){
				printf("over the moveLimit\n");
				return 1;
			}
		}
	}
}
