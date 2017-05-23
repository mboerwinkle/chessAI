#include <stdio.h>
#include <stdlib.h>
#include "cboard.h"

int Cboard::isValidMove(int x, int y, int dx, int dy){
	char start = tokens[x+y*xs];
	char dest = tokens[dx+dy*xs];
	if(start == 0) return 0;
	int t = start&TEAM;
	int kills = 0;
	if(dest != 0){
		if(!((start&TEAM)^(dest&TEAM))){
			//they're the same team
			return 0;
		}
		kills = 1;
	}
	#include "tokencode.h"
	return 0;
}
void Cboard::move(int team, int x, int y, int dx, int dy){
	score[team]++;
	moves++;
	char start = tokens[x+y*xs];
	char dest = tokens[dx+dy*xs];
	if(dest != 0){
		if(team != (TEAM&dest)){//FIXME speed
			score[team]--;
			if(dest&KING){
				score[team] = 0;
				winner = team;
				ended = 1;
				return;
			}
		}else{
			puts("landing on your own piece. FATAL");
		}
	}
	tokens[dx+dy*xs] = start;
	tokens[x+y*xs] = 0;
}
int Cboard::isValidToken(int team, int x, int y){
	if(tokens[x+y*xs]==0) return 0;
	if(team == (TEAM&tokens[x+y*xs])){
		return 1;
	}
	return 0;
}
void Cboard::act(int team){
	int x, y, dx, dy;
	do{
		printf("input command team %d: ", team);
		scanf("%d %d %d %d", &x, &y, &dx, &dy);
		if(x < 0 || y < 0 || dx < 0 || dy < 0 || x >= xs || y >= ys || dx >= xs || dy >= ys) continue;
	}while(!isValidToken(team, x, y) || !isValidMove(x, y, dx, dy));
	move(team, x, y, dx, dy);
}
Cboard::Cboard(int xs, int ys, char* l){
	this->xs = xs;
	this->ys = ys;
	score[0] = 0; score[1] = 0;
	tokens = (char*)calloc(xs*ys, 1);
	for(int i = 0; i < xs*ys; i++){
		if(l[i] == ' ') continue;
		if(l[i] < 97) tokens[i] |= TEAM;
		if(l[i] == 'p' || l[i] == 'P') tokens[i] |= PAWN;
		if(l[i] == 'r' || l[i] == 'R') tokens[i] |= ROOK;
		if(l[i] == 'n' || l[i] == 'N') tokens[i] |= NIGHT;
		if(l[i] == 'b' || l[i] == 'B') tokens[i] |= BISHOP;
		if(l[i] == 'q' || l[i] == 'Q') tokens[i] |= QUEEN;
		if(l[i] == 'k' || l[i] == 'K') tokens[i] |= KING;
	}
}
Cboard::~Cboard(){
	free(tokens);
}
void Cboard::display(){
	char output[xs+1];
	output[xs] = 0;
	for(int y = 0; y < ys; y++){
		for(int x = 0; x < xs; x++){
			output[x] = tokenToChar(tokens[x+y*xs]);
		}
		printf("%s\n", output);
	}
	printf("\n");
}
char tokenToChar(char t){
	if(t == 0) return ' ';
	char output = 0;
	if(t&PAWN) output = 'p';
	if(t&ROOK) output = 'r';
	if(t&NIGHT) output = 'n';
	if(t&BISHOP) output = 'b';
	if(t&QUEEN) output = 'q';
	if(t&KING) output = 'k';
	if(t&TEAM) output -= 32;
	return output;
}
