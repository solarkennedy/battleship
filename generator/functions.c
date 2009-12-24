//extern int SIZEOFBOARD, SIZEOFBOARDX1;

#define SIZEOFBOARD 8
#define SIZEOFBOARDX2  SIZEOFBOARD * 2


/*
Cheat Sheet
0 = Unfilled Empty
1 = Water

3 = ^
4 = v
5 = <
6 = >

8 = inside a ship
9 = Submarine

*/

int PrintBoard(int boardtoprint[SIZEOFBOARDX2][SIZEOFBOARDX2])
{
	int H,V;
	char boardstring[((SIZEOFBOARD * SIZEOFBOARD))+1]="0000000000000000000000000000000000000000000000000000000000000000";
	char hcounter[SIZEOFBOARD+1] = "00000000";
	char vcounter[SIZEOFBOARD+1] = "00000000";
	for (H=0; H<SIZEOFBOARD; H++)
	{
		for (V=0;V<SIZEOFBOARD;V++)
		{
			if (boardtoprint[V][H] == 0)
				boardtoprint[V][H] = 1;
			boardstring[H*SIZEOFBOARD+V] = boardtoprint[V][H]+48;		
			if (boardtoprint[V][H] != 1)
			{
				vcounter[H]++;
				hcounter[V]++;
			}
		}
	}	
	printf("%s,%s,%s\n",boardstring,vcounter,hcounter);

}//end printboard


int PlaceBattleship(int Where, int Rotation, int board[SIZEOFBOARDX2][SIZEOFBOARDX2]){
	int H, V;
	H = Where % SIZEOFBOARD;
	V = Where / SIZEOFBOARD;
	if (Rotation == 0){
		if (H <= (SIZEOFBOARD - 4)){
			if (board[H][V] == 0 && board[H+1][V] == 0 && board[H+2][V] == 0 && board[H+3][V] == 0){
				return InsertBattleship(Where,0,board);
			}
		}
	}
	else if (Rotation == 1){
		if (V <= (SIZEOFBOARD - 4)){
			if (board[H][V] == 0 && board[H][V+1] == 0 && board[H][V+2] == 0 && board[H][V+3] == 0){
				return InsertBattleship(Where,1,board);
			}
		}
	}
	else {
		printf("I have no idea what direction you want me to go, you said %d \n",Rotation);
		exit(1);
	}
	return 0;
}//End Place Battleship


int InsertBattleship(int Where, int Rotation, int board[SIZEOFBOARDX2][SIZEOFBOARDX2]){
	int H, V;
	H = Where % SIZEOFBOARD;
        V = Where / SIZEOFBOARD;	
//	printf("Inserting Battleship at %d %d\n", H, V);
	if (Rotation == 0)
	{
		board[H-1][V+1] = board[H][V+1] = board[H+1][V+1] = board[H+2][V+1] = board[H+3][V+1] = board[H+4][V+1] = 1;
		board[H-1][V]  = board[H+4][V] = 1;
		board[H-1][V-1] = board[H][V-1] = board[H+1][V-1] = board[H+2][V-1] = board[H+3][V-1] = board[H+4][V-1] = 1;
		board[H][V] = 5;
		board[H+3][V] = 6;
		board[H+1][V] = board[H+2][V] = 8;
		return 1;
	}
	else if (Rotation == 1)
	{
		board[H-1][V-1] = board[H][V-1] = board[H+1][V-1] = 1;
		board[H-1][V] = board[H+1][V] = board[H-1][V+1] = board[H+1][V+1] = board[H-1][V+2] = board[H+1][V+2] = board[H-1][V+3] = board[H+1][V+3] = 1;
		board[H-1][V+4] = board[H][V+4] = board[H+1][V+4] = 1;
		board[H][V] = 3;
		board[H][V+3] = 4;
		board[H][V+1] = board[H][V+2] = 8;
		return 1;
	}
	else
	{
		return 0;
	}
}

	
	
int PlaceCruiser(int Where, int Rotation, int board[SIZEOFBOARDX2][SIZEOFBOARDX2]){
	int H, V;
        H = Where % SIZEOFBOARD;
        V = Where / SIZEOFBOARD;
        if (Rotation == 0){
                if (H <= (SIZEOFBOARD - 3)){
                        if (board[H][V] == 0 &&  board[H+1][V] == 0 && board[H+2][V] == 0){
                                return InsertCruiser(Where,0,board);
			}
		}
	}
        else if (Rotation == 1){
                if (V <= (SIZEOFBOARD - 3)){
                        if (board[H][V] == 0 && board[H][V+1] == 0 && board[H][V+2] == 0){
                                return InsertCruiser(Where,1,board);
			}
		}
	}
	return 0;
}

int InsertCruiser(int Where, int Rotation, int board[SIZEOFBOARDX2][SIZEOFBOARDX2]){
	int H, V;
        H = Where % SIZEOFBOARD;
        V = Where / SIZEOFBOARD;
//	printf("Inserting Cruiser at %d %d with a rotation of %d\n", H, V,Rotation);
        if (Rotation == 0)
	{
                board[H-1][V+1] = board[H][V+1] = board[H+1][V+1] = board[H+2][V+1] = board[H+3][V+1] = 1;
                board[H-1][V]  = board[H+3][V] = 1;
                board[H-1][V-1] = board[H][V-1] = board[H+1][V-1] = board[H+2][V-1] = board[H+3][V-1] = 1; //Water
                board[H][V] = 5;
		board[H+2][V] = 6; //Ship ends
                board[H+1][V] = 8; //ship middle
		return 1;
	}
        else if (Rotation == 1)
	{
                board[H-1][V-1] = board[H][V-1] = board[H+1][V-1] = 1;
                board[H-1][V] = board[H+1][V] = board[H-1][V+1] = board[H+1][V+1] = board[H-1][V+2] = board[H+1][V+2] = 1;
                board[H-1][V+3] = board[H][V+3] = board[H+1][V+3] = 1;
                board[H][V] = 3;
		board[H][V+2] = 4;
                board[H][V+1] = 8;
		return 1;
	}
	else {
		return 0;
	}
}

int PlaceDestroyer(int Where, int Rotation, int board[SIZEOFBOARDX2][SIZEOFBOARDX2])
{
	int H, V;
        H = Where % SIZEOFBOARD;
        V = Where / SIZEOFBOARD;
	//printf("We are trying to place a Destroyer at %d %d with a rotation of %d\n", H, V,Rotation);
        if (Rotation == 0) {
                if (H <= (SIZEOFBOARD - 2)) { 
                 	if (board[H][V] == 0 && board[H+1][V] == 0) {
				return InsertDestroyer(Where,0,board);
			}
		}
	}
        else if (Rotation == 1){
                if (V <= (SIZEOFBOARD - 2)){
                        if (board[H][V] == 0 && board[H][V+1] == 0){
                                return InsertDestroyer(Where,1,board);
			}
		}
	}
	return 0;
}

int InsertDestroyer(int Where, int Rotation, int board[SIZEOFBOARDX2][SIZEOFBOARDX2])
{
	int H, V;
        H = Where % SIZEOFBOARD;
        V = Where / SIZEOFBOARD;
//	printf("Inserting Destroyer at %d %d with a rotation of %d\n", H, V,Rotation);
        if (Rotation == 0)
	{
                //We are Horiz
                board[H-1][V+1] = board[H][V+1] = board[H+1][V+1] = board[H+2][V+1] = 1;
                board[H-1][V]  = board[H+2][V] = 1;
                board[H-1][V-1] = board[H][V-1] = board[H+1][V-1] = board[H+2][V-1] = 1; //Water
                board[H][V] = 5;
		board[H+1][V] = 6; //Ship ends
		return 1;
        }
	else if (Rotation ==1)
	{
                //This means Vertical
                board[H-1][V-1] = board[H][V-1] = board[H+1][V-1] = 1;
                board[H-1][V] = board[H+1][V] = board[H-1][V+1] = board[H+1][V+1] = 1;
                board[H-1][V+2] = board[H][V+2] = board[H+1][V+2] = 1;
                board[H][V] = 3;
		board[H][V+1] = 4;
		return 1;
	}
	else
		return 0;
}


int PlaceSubmarine(int Where, int board[SIZEOFBOARDX2][SIZEOFBOARDX2])
{
	int H, V;
        H = Where % SIZEOFBOARD;
        V = Where / SIZEOFBOARD;
        if (board[H][V] == 0)
               return InsertSubmarine(Where,board);
        else
		return 0; //We can't fit it
}

int InsertSubmarine(int Where, int board[SIZEOFBOARDX2][SIZEOFBOARDX2])
{
	int H, V;
        H = Where % SIZEOFBOARD;
        V = Where / SIZEOFBOARD;
        board[H-1][V+1] = board[H][V+1] = board[H+1][V+1] = 1;
        board[H-1][V]  = board[H+1][V] = 1;
        board[H-1][V-1] = board[H][V-1] = board[H+1][V-1] = 1; //Water
        board[H][V] = 9; //Ship ends
	return 1;
}

int ZeroArray(int board[SIZEOFBOARDX2][SIZEOFBOARDX2]){
/*	int H, V;
        for (H=0; H<SIZEOFBOARDX2; H++)
        {
                for (V=0;V<SIZEOFBOARDX2;V++)
                {
                      board[H][V] = 0;
                }
        }
*/
//board[SIZEOFBOARDX2][SIZEOFBOARDX2] = {{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0}};
memset(board, 0, sizeof(int) * SIZEOFBOARDX2 * SIZEOFBOARDX2);
}


void BoardCopy2( int src[SIZEOFBOARDX2][SIZEOFBOARDX2], int dst[SIZEOFBOARDX2][SIZEOFBOARDX2]){
	int H, V;
        for (H=0; H<SIZEOFBOARDX2; H++)
        {
                for (V=0;V<SIZEOFBOARDX2;V++)
                {
                      dst[H][V] = src[H][V];
                }
        }
}

void BoardCopy(int src[SIZEOFBOARDX2][SIZEOFBOARDX2], int dst[SIZEOFBOARDX2][SIZEOFBOARDX2]) {
 memcpy(dst, src, sizeof(int) * (SIZEOFBOARDX2 * SIZEOFBOARDX2) ); 
}
