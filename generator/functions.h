#include "functions.c"

#define SIZEOFBOARD 10
#define SIZEOFBOARDX2  SIZEOFBOARD * 2


int PrintBoard(int boardtoprint[SIZEOFBOARDX2][SIZEOFBOARDX2]);
int PlaceCruiser(int Where, int Rotation, int board[SIZEOFBOARDX2][SIZEOFBOARDX2]);
int InsertCruiser(int Where, int Rotation, int board[SIZEOFBOARDX2][SIZEOFBOARDX2]);
int PlaceDestroyer(int Where, int Rotation, int board[SIZEOFBOARDX2][SIZEOFBOARDX2]);
int InsertDestroyer(int Where, int Rotation, int board[SIZEOFBOARDX2][SIZEOFBOARDX2]);
int PlaceSubmarine(int Where, int board[SIZEOFBOARDX2][SIZEOFBOARDX2]);
int InsertSubmarine(int Where, int board[SIZEOFBOARDX2][SIZEOFBOARDX2]);
int ZeroArray(int board[SIZEOFBOARDX2][SIZEOFBOARDX2]);
void BoardCopy(int boarda[SIZEOFBOARDX2][SIZEOFBOARDX2], int boardb[SIZEOFBOARDX2][SIZEOFBOARDX2]);
