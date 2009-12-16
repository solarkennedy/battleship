#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

#define SIZEOFBOARD 6
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

/*
//int boarda[12][12] ={{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0}};
int boardb[12][12] ={{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0}};
int boardc[12][12] ={{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0}};
int boardd[12][12] ={{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0}};
int boarde[12][12] ={{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0}};
int boardf[12][12] ={{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0}};
*/

//Prottypes
int main(void);
int RecurseB(void);
int RecurseC(void);
int RecurseD(void);
int RecurseE(void);
int RecurseF(void);







int main()
{
int A=0;
for (A=0; A<(SIZEOFBOARD * SIZEOFBOARD); A++){
	if (PlaceCruiser(A,0,boarda)==1){
		BoardCopy(boarda,boardb);
        	RecurseB();
		ZeroArray(boarda);
		}
	if (PlaceCruiser(A,1,boarda)==1)
		{
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
        if (PlaceDestroyer(A,0,boardb)==1){
                BoardCopy(boardb,boardc);
                RecurseC();
		BoardCopy(boarda,boardb);
		}
        if (PlaceDestroyer(A,1,boardb)==1)
		{
                BoardCopy(boardb,boardc);
                RecurseC();
		BoardCopy(boarda,boardb);
		}
}//End A
}//End recurseB

int RecurseC(){
int A;
for (A=0; A<(SIZEOFBOARD * SIZEOFBOARD); A++){
        if (PlaceDestroyer(A,0,boardc)==1){
                BoardCopy(boardc,boardd);
                RecurseD();
                BoardCopy(boardb,boardc);
		}
        if (PlaceDestroyer(A,1,boardc)==1){
                BoardCopy(boardc,boardd);
                RecurseD();
                BoardCopy(boardb,boardc);
		}
}//End A
}//End recursec

int RecurseD(){
int A;
for (A=0; A<(SIZEOFBOARD * SIZEOFBOARD); A++){
        if (PlaceSubmarine(A,boardd)==1){
                BoardCopy(boardd,boarde);
                RecurseE();
                BoardCopy(boardc,boardd);
		}
}//End A
}//End recursed

int RecurseE(){
int A;
for (A=0; A<(SIZEOFBOARD * SIZEOFBOARD); A++){
        if (PlaceSubmarine(A,boarde)==1){
                BoardCopy(boarde,boardf);
                RecurseF();
                BoardCopy(boardd,boarde);
		}
}//End A
}//End recursee

int RecurseF(){
int A;
for (A=0; A<(SIZEOFBOARD * SIZEOFBOARD); A++){
        if (PlaceSubmarine(A,boardf)==1){
		PrintBoard(boardf);
                BoardCopy(boarde,boardf);
		}
}//End A
}//End recursef



/*
int ConnectToDB(){

   char *server = "localhost";
   char *user = "root";
   char *password = "woodall42"; 
   char *database = "battleship";

   conn = mysql_init(NULL);

   printf("Trying to connect to the db\n");
   if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
      fprintf(stderr, "%s\n", mysql_error(conn));
   }
   printf("Done..\n");

}

*/
