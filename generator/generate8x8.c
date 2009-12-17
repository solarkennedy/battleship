#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "functions.h"

#define SIZEOFBOARD 8
#define SIZEOFBOARDX2  SIZEOFBOARD * 2


int Battleships = 0;
int Cruisers = 1;
int Destroyers = 2;
int Submarines = 3;
int boarda[SIZEOFBOARDX2][SIZEOFBOARDX2];
int boardb[SIZEOFBOARDX2][SIZEOFBOARDX2];
int boardc[SIZEOFBOARDX2][SIZEOFBOARDX2];
int boardd[SIZEOFBOARDX2][SIZEOFBOARDX2];
int boarde[SIZEOFBOARDX2][SIZEOFBOARDX2];
int boardf[SIZEOFBOARDX2][SIZEOFBOARDX2];
int boardg[SIZEOFBOARDX2][SIZEOFBOARDX2];
int boardh[SIZEOFBOARDX2][SIZEOFBOARDX2];
int boardi[SIZEOFBOARDX2][SIZEOFBOARDX2];
int boardj[SIZEOFBOARDX2][SIZEOFBOARDX2];

//Prottypes
int RecurseB(void);
int RecurseC(void);
int RecurseD(void);
int RecurseE(void);
int RecurseF(void);

int DirectionA;
int DirectionB;
int DirectionC;
int DirectionD;
int DirectionE;
int DirectionF;



int main(int argc,char *argv[])
{
if ( argc != 7 ){
	printf("Dude, you need 6 arguments, like this: generate8x8 0 0 0 0 0 0\n");
	exit(1);
} else {
	DirectionA = argv[1][0]-48;
	DirectionB = argv[2][0]-48;
	DirectionC = argv[3][0]-48;
	DirectionD = argv[4][0]-48;
	DirectionE = argv[5][0]-48;
	DirectionF = argv[6][0]-48;
}

int A=0;
for (A=0; A<(SIZEOFBOARD * SIZEOFBOARD); A++){
	if (PlaceBattleship(A,DirectionA,boarda)==1){
		BoardCopy(boarda,boardb);
        	RecurseB();
		ZeroArray(boarda);
		}
}//End A

return 0;
}//End main()

int RecurseB(){
int A;
for (A=0; A<(SIZEOFBOARD * SIZEOFBOARD); A++){
        if (PlaceCruiser(A,DirectionB,boardb)==1){
                BoardCopy(boardb,boardc);
                RecurseC();
		BoardCopy(boarda,boardb);
		}
}//End A
}//End recurseB

int RecurseC(){
int A;
for (A=0; A<(SIZEOFBOARD * SIZEOFBOARD); A++){
        if (PlaceCruiser(A,DirectionC,boardc)==1){
                BoardCopy(boardc,boardd);
                RecurseD();
                BoardCopy(boardb,boardc);
		}
}//End A
}//End recursec

int RecurseD(){
int A;
for (A=0; A<(SIZEOFBOARD * SIZEOFBOARD); A++){
        if (PlaceDestroyer(A,DirectionD,boardd)==1){
                BoardCopy(boardd,boarde);
                RecurseE();
                BoardCopy(boardc,boardd);
                }

}//End A
}//End recursec

int RecurseE(){
int A;
for (A=0; A<(SIZEOFBOARD * SIZEOFBOARD); A++){
        if (PlaceDestroyer(A,DirectionE,boarde)==1){
                BoardCopy(boarde,boardf);
                RecurseF();
                BoardCopy(boardd,boarde);
                }
}//End A
}//End recursec

int RecurseF(){
int A;
for (A=0; A<(SIZEOFBOARD * SIZEOFBOARD); A++){
        if (PlaceDestroyer(A,DirectionF,boardf)==1){
                BoardCopy(boardf,boardg);
                RecurseG();
                BoardCopy(boarde,boardf);
                }
}//End A
}//End recursec


int RecurseG(){
int A;
for (A=0; A<(SIZEOFBOARD * SIZEOFBOARD); A++){
        if (PlaceSubmarine(A,boardg)==1){
                BoardCopy(boardg,boardh);
                RecurseH();
                BoardCopy(boardf,boardg);
		}
}//End A
}//End recursed

int RecurseH(){
int A;
for (A=0; A<(SIZEOFBOARD * SIZEOFBOARD); A++){
        if (PlaceSubmarine(A,boardh)==1){
                BoardCopy(boardh,boardi);
                RecurseI();
                BoardCopy(boardg,boardh);
                }
}//End A
}//End recursed

int RecurseI(){
int A;
for (A=0; A<(SIZEOFBOARD * SIZEOFBOARD); A++){
        if (PlaceSubmarine(A,boardi)==1){
                BoardCopy(boardi,boardj);
                RecurseJ();
                BoardCopy(boardh,boardi);
                }
}//End A
}//End recursed

int RecurseJ(){
int A;
for (A=0; A<(SIZEOFBOARD * SIZEOFBOARD); A++){
        if (PlaceSubmarine(A,boardj)==1){
		PrintBoard(boardj);
                BoardCopy(boardi,boardj);
                }
}//End A
}//End recursed

