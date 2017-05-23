#define TEAM 1
#define PAWN 2
#define ROOK 4
#define NIGHT 8
#define BISHOP 16
#define QUEEN 32
#define KING 64
class Cboard{
public:
	Cboard(int xs, int ys, char* l);
	~Cboard();
	void display();
	void act(int team);
	int isValidToken(int team, int x, int y);
	int isValidMove(int x, int y, int dx, int dy);
	void move(int team, int x, int y, int dx, int dy);
	char* tokens;
	int xs, ys;

	int moves = 0;
	int winner = 0;
	int ended = 0;
	int score[2];//scored like golf with captures and checks giving point reductions.
};
extern char tokenToChar(char t);
