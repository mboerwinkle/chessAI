//INCLUDED IN CBOARD.CPP
//BEGIN NASTY CODE DUPLICATION AND DATA CODING
if(start&PAWN){
	int dir = 1;
	if(t == 0){
		dir = -1;
	}
	if(y+dir == dy){
		if(kills){
			if(abs(x-dx) == 1){
				return 1;
			}
			return 0;
		}
		return 1;
	}
	return 0;
}
else if(start&ROOK){
	int ox = dx-x;//o for offset
	int oy = dy-y;
	if(ox != 0 && oy != 0) return 0;
	int dirx = 0;//dir for direction.
	int diry = 0;
	if(ox != 0) dirx = ox/abs(ox);
	if(oy != 0) diry = oy/abs(oy);
	printf("dir %d %d\n", dirx, diry);
	int tx = x+dirx;//t for test
	int ty = y+diry;
	while(tx != dx || ty != dy){
		if(tokens[tx+ty*xs] != 0) return 0;
		tx+=dirx;
		ty+=diry;
	}
	return 1;
}
else if(start&NIGHT){
	if((abs(dx-x) == 2 && abs(dy-y) == 1) || (abs(dx-x) == 1 && abs(dy-y) == 2)){
		return 1;
	}
	return 0;
}
else if(start&BISHOP){
	int ox = dx-x;//o for offset
	int oy = dy-y;
	if(abs(ox) != abs(oy)) return 0;
	int dirx = 0;//dir for direction.
	int diry = 0;
	if(ox != 0) dirx = ox/abs(ox);
	if(oy != 0) diry = oy/abs(oy);
	int tx = x+dirx;//t for test
	int ty = y+diry;
	while(tx != dx || ty != dy){
		if(tokens[tx+ty*xs] != 0) return 0;
		tx+=dirx;
		ty+=diry;
	}
	return 1;
}
else if(start&QUEEN){
	int ox = dx-x;//o for offset
	int oy = dy-y;
	if((ox != 0 && oy != 0) && (abs(ox) != abs(oy)))return 0;
	int dirx = 0;//dir for direction.
	int diry = 0;
	if(ox != 0) dirx = ox/abs(ox);
	if(oy != 0) diry = oy/abs(oy);
	int tx = x+dirx;//t for test
	int ty = y+diry;
	while(tx != dx || ty != dy){
		if(tokens[tx+ty*xs] != 0) return 0;
		tx+=dirx;
		ty+=diry;
	}
	return 1;
}
else if(start&KING){
	if(abs(dx-x) > 1 || abs(dy-y) > 1) return 0;
	return 1;
}
