#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql.h>
int Battleships = 1;
int Cruisers = 2;
int Destroyers = 3;
int Submarines = 4;
//int board[6][6] = {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0}};
//int board[12][12] = {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0}};
//int board[16][16] ={{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0}};
int board[12][12] ={{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0}};
MYSQL *conn;
MYSQL_RES *res;
MYSQL_ROW row;


int main()
{
int A, B, C, D, E, F, G, H, I, J;
ConnectToDB();

//int A=0;
for (A=0; A<64; A++){
	for (B=2; B<64; B++){
		for (C=4; C<64; C++){
			for (D=6; D<64; D++){
				for (E=14; E<64; E++){
					printf("Status: %i %i %i %i %i\n", A,B,C,D,E);
					for (F=18; F<64; F++){
//						if ( A!=B && A!=C && A!=D && A!=E && A!=F && B!=C && B!=D && B!=E && B!=F && C!=D && C!=E && C!=F && D!=E && D!=F && E!=F)
						for (G=0; G<64; G++){
							for (H=0; H<64; H++){
								for (I=0; I<64; I++){
									printf("Status: %i %i %i %i %i %i %i %i %i\n", A,B,C,D,E,F,G,H,I);
									for (J=0; J<64; J++){
											ZeroArray();
											if (PlaceDestroyer(A,0)==1)
												if (PlaceCruiser(B,0)==1)
													if (PlaceCruiser(C,0)==1)
														if (PlaceDestroyer(D,0)==1)
															if (PlaceDestroyer(E,0)==1)
						        	                	                                       if (PlaceDestroyer(F,0)==1)
							                                	                                       if (PlaceSubmarine(G)==1)
								                                	                                       if (PlaceSubmarine(H)==1)
								                                        	                                       if (PlaceSubmarine(I)==1)
								                                                	                                       if (PlaceSubmarine(J)==1)
								                                                        	                                        PrintBoard();
									
											ZeroArray();
											if (PlaceDestroyer(A,0)==1)
												if (PlaceCruiser(B,0)==1)
													if (PlaceCruiser(C,0)==1)
														if (PlaceDestroyer(D,0)==1)
															if (PlaceDestroyer(E,0)==1)
						        	                	                                       if (PlaceDestroyer(F,1)==1)
							                                	                                       if (PlaceSubmarine(G)==1)
								                                	                                       if (PlaceSubmarine(H)==1)
								                                        	                                       if (PlaceSubmarine(I)==1)
								                                                	                                       if (PlaceSubmarine(J)==1)
								                                                        	                                        PrintBoard();
											ZeroArray();
											if (PlaceDestroyer(A,0)==1)
												if (PlaceCruiser(B,0)==1)
													if (PlaceCruiser(C,0)==1)
														if (PlaceDestroyer(D,0)==1)
															if (PlaceDestroyer(E,1)==1)
						        	                	                                       if (PlaceDestroyer(F,1)==1)
							                                	                                       if (PlaceSubmarine(G)==1)
								                                	                                       if (PlaceSubmarine(H)==1)
								                                        	                                       if (PlaceSubmarine(I)==1)
								                                                	                                       if (PlaceSubmarine(J)==1)
								                                                        	                                        PrintBoard();


											ZeroArray();
											if (PlaceDestroyer(A,0)==1)
												if (PlaceCruiser(B,0)==1)
													if (PlaceCruiser(C,0)==1)
														if (PlaceDestroyer(D,1)==1)
															if (PlaceDestroyer(E,1)==1)
						        	                	                                       if (PlaceDestroyer(F,1)==1)
							                                	                                       if (PlaceSubmarine(G)==1)
								                                	                                       if (PlaceSubmarine(H)==1)
								                                        	                                       if (PlaceSubmarine(I)==1)
								                                                	                                       if (PlaceSubmarine(J)==1)
								                                                        	                                        PrintBoard();
											ZeroArray(); //0 01 000
											if (PlaceDestroyer(A,0)==1)
												if (PlaceCruiser(B,0)==1)
													if (PlaceCruiser(C,1)==1)
														if (PlaceDestroyer(D,0)==1)
															if (PlaceDestroyer(E,0)==1)
						        	                	                                       if (PlaceDestroyer(F,0)==1)
							                                	                                       if (PlaceSubmarine(G)==1)
								                                	                                       if (PlaceSubmarine(H)==1)
								                                        	                                       if (PlaceSubmarine(I)==1)
								                                                	                                       if (PlaceSubmarine(J)==1)
								                                                        	                                        PrintBoard();
											ZeroArray();//0 01 001
											if (PlaceDestroyer(A,0)==1)
												if (PlaceCruiser(B,0)==1)
													if (PlaceCruiser(C,1)==1)
														if (PlaceDestroyer(D,0)==1)
															if (PlaceDestroyer(E,0)==1)
						        	                	                                       if (PlaceDestroyer(F,1)==1)
							                                	                                       if (PlaceSubmarine(G)==1)
								                                	                                       if (PlaceSubmarine(H)==1)
								                                        	                                       if (PlaceSubmarine(I)==1)
								                                                	                                       if (PlaceSubmarine(J)==1)
								                                                        	                                        PrintBoard();

											ZeroArray();//0 01 011
											if (PlaceDestroyer(A,0)==1)
												if (PlaceCruiser(B,0)==1)
													if (PlaceCruiser(C,1)==1)
														if (PlaceDestroyer(D,0)==1)
															if (PlaceDestroyer(E,1)==1)
						        	                	                                       if (PlaceDestroyer(F,1)==1)
							                                	                                       if (PlaceSubmarine(G)==1)
								                                	                                       if (PlaceSubmarine(H)==1)
								                                        	                                       if (PlaceSubmarine(I)==1)
								                                                	                                       if (PlaceSubmarine(J)==1)
								                                                        	                                        PrintBoard();


											ZeroArray(); //0 01 111
											if (PlaceDestroyer(A,0)==1)
												if (PlaceCruiser(B,0)==1)
													if (PlaceCruiser(C,1)==1)
														if (PlaceDestroyer(D,1)==1)
															if (PlaceDestroyer(E,1)==1)
						        	                	                                       if (PlaceDestroyer(F,1)==1)
							                                	                                       if (PlaceSubmarine(G)==1)
								                                	                                       if (PlaceSubmarine(H)==1)
								                                        	                                       if (PlaceSubmarine(I)==1)
								                                                	                                       if (PlaceSubmarine(J)==1)
								                                                        	                                        PrintBoard();
											ZeroArray(); //0 11 000											
											if (PlaceDestroyer(A,0)==1)
												if (PlaceCruiser(B,1)==1)
													if (PlaceCruiser(C,1)==1)
														if (PlaceDestroyer(D,0)==1)
															if (PlaceDestroyer(E,0)==1)
						        	                	                                       if (PlaceDestroyer(F,0)==1)
							                                	                                       if (PlaceSubmarine(G)==1)
								                                	                                       if (PlaceSubmarine(H)==1)
								                                        	                                       if (PlaceSubmarine(I)==1)
								                                                	                                       if (PlaceSubmarine(J)==1)
								                                                        	                                        PrintBoard();
											ZeroArray(); //0 11 001
											if (PlaceDestroyer(A,0)==1)
												if (PlaceCruiser(B,1)==1)
													if (PlaceCruiser(C,1)==1)
														if (PlaceDestroyer(D,0)==1)
															if (PlaceDestroyer(E,0)==1)
						        	                	                                       if (PlaceDestroyer(F,1)==1)
							                                	                                       if (PlaceSubmarine(G)==1)
								                                	                                       if (PlaceSubmarine(H)==1)
								                                        	                                       if (PlaceSubmarine(I)==1)
								                                                	                                       if (PlaceSubmarine(J)==1)
								                                                        	                                        PrintBoard();

											ZeroArray(); //0 11 011
											if (PlaceDestroyer(A,0)==1)
												if (PlaceCruiser(B,1)==1)
													if (PlaceCruiser(C,1)==1)
														if (PlaceDestroyer(D,0)==1)
															if (PlaceDestroyer(E,1)==1)
						        	                	                                       if (PlaceDestroyer(F,1)==1)
							                                	                                       if (PlaceSubmarine(G)==1)
								                                	                                       if (PlaceSubmarine(H)==1)
								                                        	                                       if (PlaceSubmarine(I)==1)
								                                                	                                       if (PlaceSubmarine(J)==1)
								                                                        	                                        PrintBoard();



											ZeroArray();// 0 11 111
											if (PlaceDestroyer(A,0)==1)
												if (PlaceCruiser(B,1)==1)
													if (PlaceCruiser(C,1)==1)
														if (PlaceDestroyer(D,1)==1)
															if (PlaceDestroyer(E,1)==1)
						        	                	                                       if (PlaceDestroyer(F,1)==1)
							                                	                                       if (PlaceSubmarine(G)==1)
								                                	                                       if (PlaceSubmarine(H)==1)
								                                        	                                       if (PlaceSubmarine(I)==1)
								                                                	                                       if (PlaceSubmarine(J)==1)
								                                                        	                                        PrintBoard();
											ZeroArray();
											if (PlaceDestroyer(A,1)==1)
												if (PlaceCruiser(B,0)==1)
													if (PlaceCruiser(C,0)==1)
														if (PlaceDestroyer(D,0)==1)
															if (PlaceDestroyer(E,0)==1)
						        	                	                                       if (PlaceDestroyer(F,0)==1)
							                                	                                       if (PlaceSubmarine(G)==1)
								                                	                                       if (PlaceSubmarine(H)==1)
								                                        	                                       if (PlaceSubmarine(I)==1)
								                                                	                                       if (PlaceSubmarine(J)==1)
								                                                        	                                        PrintBoard();
									
											ZeroArray();
											if (PlaceDestroyer(A,1)==1)
												if (PlaceCruiser(B,0)==1)
													if (PlaceCruiser(C,0)==1)
														if (PlaceDestroyer(D,0)==1)
															if (PlaceDestroyer(E,0)==1)
						        	                	                                       if (PlaceDestroyer(F,1)==1)
							                                	                                       if (PlaceSubmarine(G)==1)
								                                	                                       if (PlaceSubmarine(H)==1)
								                                        	                                       if (PlaceSubmarine(I)==1)
								                                                	                                       if (PlaceSubmarine(J)==1)
								                                                        	                                        PrintBoard();
											ZeroArray();
											if (PlaceDestroyer(A,1)==1)
												if (PlaceCruiser(B,0)==1)
													if (PlaceCruiser(C,0)==1)
														if (PlaceDestroyer(D,0)==1)
															if (PlaceDestroyer(E,1)==1)
						        	                	                                       if (PlaceDestroyer(F,1)==1)
							                                	                                       if (PlaceSubmarine(G)==1)
								                                	                                       if (PlaceSubmarine(H)==1)
								                                        	                                       if (PlaceSubmarine(I)==1)
								                                                	                                       if (PlaceSubmarine(J)==1)
								                                                        	                                        PrintBoard();


											ZeroArray();
											if (PlaceDestroyer(A,1)==1)
												if (PlaceCruiser(B,0)==1)
													if (PlaceCruiser(C,0)==1)
														if (PlaceDestroyer(D,1)==1)
															if (PlaceDestroyer(E,1)==1)
						        	                	                                       if (PlaceDestroyer(F,1)==1)
							                                	                                       if (PlaceSubmarine(G)==1)
								                                	                                       if (PlaceSubmarine(H)==1)
								                                        	                                       if (PlaceSubmarine(I)==1)
								                                                	                                       if (PlaceSubmarine(J)==1)
								                                                        	                                        PrintBoard();
											ZeroArray(); //0 01 000
											if (PlaceDestroyer(A,1)==1)
												if (PlaceCruiser(B,0)==1)
													if (PlaceCruiser(C,1)==1)
														if (PlaceDestroyer(D,0)==1)
															if (PlaceDestroyer(E,0)==1)
						        	                	                                       if (PlaceDestroyer(F,0)==1)
							                                	                                       if (PlaceSubmarine(G)==1)
								                                	                                       if (PlaceSubmarine(H)==1)
								                                        	                                       if (PlaceSubmarine(I)==1)
								                                                	                                       if (PlaceSubmarine(J)==1)
								                                                        	                                        PrintBoard();
											ZeroArray();//0 01 001
											if (PlaceDestroyer(A,1)==1)
												if (PlaceCruiser(B,0)==1)
													if (PlaceCruiser(C,1)==1)
														if (PlaceDestroyer(D,0)==1)
															if (PlaceDestroyer(E,0)==1)
						        	                	                                       if (PlaceDestroyer(F,1)==1)
							                                	                                       if (PlaceSubmarine(G)==1)
								                                	                                       if (PlaceSubmarine(H)==1)
								                                        	                                       if (PlaceSubmarine(I)==1)
								                                                	                                       if (PlaceSubmarine(J)==1)
								                                                        	                                        PrintBoard();

											ZeroArray();//0 01 011
											if (PlaceDestroyer(A,1)==1)
												if (PlaceCruiser(B,0)==1)
													if (PlaceCruiser(C,1)==1)
														if (PlaceDestroyer(D,0)==1)
															if (PlaceDestroyer(E,1)==1)
						        	                	                                       if (PlaceDestroyer(F,1)==1)
							                                	                                       if (PlaceSubmarine(G)==1)
								                                	                                       if (PlaceSubmarine(H)==1)
								                                        	                                       if (PlaceSubmarine(I)==1)
								                                                	                                       if (PlaceSubmarine(J)==1)
								                                                        	                                        PrintBoard();


											ZeroArray(); //0 01 111
											if (PlaceDestroyer(A,1)==1)
												if (PlaceCruiser(B,0)==1)
													if (PlaceCruiser(C,1)==1)
														if (PlaceDestroyer(D,1)==1)
															if (PlaceDestroyer(E,1)==1)
						        	                	                                       if (PlaceDestroyer(F,1)==1)
							                                	                                       if (PlaceSubmarine(G)==1)
								                                	                                       if (PlaceSubmarine(H)==1)
								                                        	                                       if (PlaceSubmarine(I)==1)
								                                                	                                       if (PlaceSubmarine(J)==1)
								                                                        	                                        PrintBoard();
											ZeroArray(); //0 11 000											
											if (PlaceDestroyer(A,1)==1)
												if (PlaceCruiser(B,1)==1)
													if (PlaceCruiser(C,1)==1)
														if (PlaceDestroyer(D,0)==1)
															if (PlaceDestroyer(E,0)==1)
						        	                	                                       if (PlaceDestroyer(F,0)==1)
							                                	                                       if (PlaceSubmarine(G)==1)
								                                	                                       if (PlaceSubmarine(H)==1)
								                                        	                                       if (PlaceSubmarine(I)==1)
								                                                	                                       if (PlaceSubmarine(J)==1)
								                                                        	                                        PrintBoard();
											ZeroArray(); //0 11 001
											if (PlaceDestroyer(A,1)==1)
												if (PlaceCruiser(B,1)==1)
													if (PlaceCruiser(C,1)==1)
														if (PlaceDestroyer(D,0)==1)
															if (PlaceDestroyer(E,0)==1)
						        	                	                                       if (PlaceDestroyer(F,1)==1)
							                                	                                       if (PlaceSubmarine(G)==1)
								                                	                                       if (PlaceSubmarine(H)==1)
								                                        	                                       if (PlaceSubmarine(I)==1)
								                                                	                                       if (PlaceSubmarine(J)==1)
								                                                        	                                        PrintBoard();

											ZeroArray(); //0 11 011
											if (PlaceDestroyer(A,1)==1)
												if (PlaceCruiser(B,1)==1)
													if (PlaceCruiser(C,1)==1)
														if (PlaceDestroyer(D,0)==1)
															if (PlaceDestroyer(E,1)==1)
						        	                	                                       if (PlaceDestroyer(F,1)==1)
							                                	                                       if (PlaceSubmarine(G)==1)
								                                	                                       if (PlaceSubmarine(H)==1)
								                                        	                                       if (PlaceSubmarine(I)==1)
								                                                	                                       if (PlaceSubmarine(J)==1)
								                                                        	                                        PrintBoard();



											ZeroArray();// 0 11 111
											if (PlaceDestroyer(A,1)==1)
												if (PlaceCruiser(B,1)==1)
													if (PlaceCruiser(C,1)==1)
														if (PlaceDestroyer(D,1)==1)
															if (PlaceDestroyer(E,1)==1)
						        	                	                                       if (PlaceDestroyer(F,1)==1)
							                                	                                       if (PlaceSubmarine(G)==1)
								                                	                                       if (PlaceSubmarine(H)==1)
								                                        	                                       if (PlaceSubmarine(I)==1)
								                                                	                                       if (PlaceSubmarine(J)==1)
								                                                        	                                        PrintBoard();
																						
							
									}//End J
								}//End I
							}//End H
						}//End G
					}//End F
				}//End E
			}//End D
		}//End C
	}//End B
}//End A
/*						
cursor.close ()
conn.close ()
*/
mysql_free_result(res);
mysql_close(conn);


	return 0;
}//End main()

int PrintBoard()
{
	char boardstring[65] = {48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,0};
	printf("we have a good board\n");
	char vcounter[9] = {48,48,48,48,48,48,48,48,0}; //Ascii for 0
	char hcounter[9] = {48,48,48,48,48,48,48,48,0};
	int H;
	int V;
	for (H=0; H<8; H++)
	{
		for (V=0;V<8;V++)
		{
			printf("%d", board[V][H]);
			if (board[H][V] != 1 && board[H][V] != 0)
			{
				vcounter[H] += 1;
				hcounter[V] += 1;
			}
			boardstring[V*8+H] = board[H][V] + 48;
		}
		printf("\n");
	}	

	printf("The boardstring is: %s\n", boardstring);
	printf("The horizontal sum is: %s\n", vcounter);
	printf("The vertical sum is: %s\n", hcounter);
	char querystring[256];
	snprintf(querystring, sizeof(querystring), "REPLACE INTO `battleship`.`8x8` (`board` ,`h` ,`v`)VALUES ('%s', '%s', '%s');", boardstring, hcounter, vcounter);
	if (mysql_query(conn, querystring)) 
	      fprintf(stderr, "%s\n", mysql_error(conn));
	printf("\n\n");
}


int PlaceBattleship(int Where, int Rotation){
	int H, V;
	H = Where % 8;
	V = Where / 8;
	if (Rotation == 0){
		if (H <= 4){
			if (board[H][V] == 0 && board[H+1][V] == 0 && board[H+2][V] == 0 && board[H+3][V] == 0){
				return InsertBattleship(Where,0);
			}
		}
	}
	else{
		if (V <= 4){
			if (board[H][V] == 0 && board[H][V+1] == 0 && board[H][V+2] == 0 && board[H][V+3] == 0){
				return InsertBattleship(Where,1);
			}
		}
	}
	return 0;
}//End Place Battleship


int InsertBattleship(int Where, int Rotation){
	int H, V;
	H = Where % 8;
        V = Where / 8;	
//	printf("Inserting Battleship at %d %d\n", H, V);
	if (Rotation == 0)
	{
		board[H-1][V+1] = board[H][V+1] = board[H+1][V+1] = board[H+2][V+1] = board[H+3][V+1] = board[H+4][V+1] = 1;
		board[H-1][V]  = board[H+4][V] = 1;
		board[H-1][V-1] = board[H][V-1] = board[H+1][V-1] = board[H+2][V-1] = board[H+3][V-1] = board[H+4][V-1] = 1;
		board[H][V] = board[H+3][V] = 2;
		board[H+1][V] = board[H+2][V] = 3;
		return 1;
	}
	else if (Rotation == 1)
	{
		board[H-1][V-1] = board[H][V-1] = board[H+1][V-1] = 1;
		board[H-1][V] = board[H+1][V] = board[H-1][V+1] = board[H+1][V+1] = board[H-1][V+2] = board[H+1][V+2] = board[H-1][V+3] = board[H+1][V+3] = 1;
		board[H-1][V+4] = board[H][V+4] = board[H+1][V+4] = 1;
		board[H][V] = board[H][V+3] = 2;
		board[H][V+1] = board[H][V+2] = 3;
		return 1;
	}
	else
	{
		return 0;
	}
}
	
	
int PlaceCruiser(int Where, int Rotation){
	int H, V;
        H = Where % 8;
        V = Where / 8;
        if (Rotation == 0){
                if (H <= 5){
                        if (board[H][V] == 0 &&  board[H+1][V] == 0 && board[H+2][V] == 0){
                                return InsertCruiser(Where,0);
			}
		}
	}
        else if (Rotation == 1){
                if (V <= 5){
                        if (board[H][V] == 0 && board[H][V+1] == 0 && board[H][V+2] == 0){
                                return InsertCruiser(Where,1);
			}
		}
	}
	return 0;
}

int InsertCruiser(int Where, int Rotation){
	int H, V;
        H = Where % 8;
        V = Where / 8;
//	printf("Inserting Cruiser at %d %d with a rotation of %d\n", H, V,Rotation);
        if (Rotation == 0)
	{
                board[H-1][V+1] = board[H][V+1] = board[H+1][V+1] = board[H+2][V+1] = board[H+3][V+1] = 1;
                board[H-1][V]  = board[H+3][V] = 1;
                board[H-1][V-1] = board[H][V-1] = board[H+1][V-1] = board[H+2][V-1] = board[H+3][V-1] = 1; //Water
                board[H][V] = board[H+2][V] = 2; //Ship ends
                board[H+1][V] = 3; //ship middle
		return 1;
	}
        else if (Rotation == 1)
	{
                board[H-1][V-1] = board[H][V-1] = board[H+1][V-1] = 1;
                board[H-1][V] = board[H+1][V] = board[H-1][V+1] = board[H+1][V+1] = board[H-1][V+2] = board[H+1][V+2] = 1;
                board[H-1][V+3] = board[H][V+3] = board[H+1][V+3] = 1;
                board[H][V] = board[H][V+2] = 2;
                board[H][V+1] = 3;
		return 1;
	}
	else {
		return 0;
	}
}

int PlaceDestroyer(int Where, int Rotation)
{
	int H, V;
        H = Where % 8;
        V = Where / 8;
	//printf("We are trying to place a Destroyer at %d %d with a rotation of %d\n", H, V,Rotation);
        if (Rotation == 0) {
                if (H <= 6) { 
                 	if (board[H][V] == 0 && board[H+1][V] == 0) {
				return InsertDestroyer(Where,0);
			}
		}
	}
        else if (Rotation == 1){
                if (V <= 6){
                        if (board[H][V] == 0 && board[H][V+1] == 0){
                                return InsertDestroyer(Where,1);
			}
		}
	}
	return 0;
}

int InsertDestroyer(int Where, int Rotation)
{
	int H, V;
        H = Where % 8;
        V = Where / 8;
//	printf("Inserting Destroyer at %d %d with a rotation of %d\n", H, V,Rotation);
        if (Rotation == 0)
	{
                //We are Horiz
                board[H-1][V+1] = board[H][V+1] = board[H+1][V+1] = board[H+2][V+1] = 1;
                board[H-1][V]  = board[H+2][V] = 1;
                board[H-1][V-1] = board[H][V-1] = board[H+1][V-1] = board[H+2][V-1] = 1; //Water
                board[H][V] = board[H+1][V] = 2; //Ship ends
		return 1;
        }
	else if (Rotation ==1)
	{
                //This means Vertical
                board[H-1][V-1] = board[H][V-1] = board[H+1][V-1] = 1;
                board[H-1][V] = board[H+1][V] = board[H-1][V+1] = board[H+1][V+1] = 1;
                board[H-1][V+2] = board[H][V+2] = board[H+1][V+2] = 1;
                board[H][V] = board[H][V+1] = 2;
		return 1;
	}
	else
		return 0;
}


int PlaceSubmarine(int Where)
{
	int H, V;
        H = Where % 8;
        V = Where / 8;
        if (board[H][V] == 0)
               return InsertSubmarine(Where);
        else
		return 0; //We can't fit it
}

int InsertSubmarine(int Where)
{
	int H, V;
        H = Where % 8;
        V = Where / 8;
        board[H-1][V+1] = board[H][V+1] = board[H+1][V+1] = 1;
        board[H-1][V]  = board[H+1][V] = 1;
        board[H-1][V-1] = board[H][V-1] = board[H+1][V-1] = 1; //Water
        board[H][V] = 4; //Ship ends
	return 1;
}

int ZeroArray(){
	int H, V;
        for (H=0; H<12; H++)
        {
                for (V=0;V<12;V++)
                {
                      board[H][V] = 0;
                }
        }
}

int ConnectToDB(){

   char *server = "localhost";
   char *user = "root";
   char *password = "woodall42"; /* set me first */
   char *database = "battleship";

   conn = mysql_init(NULL);

   printf("Trying to connect to the db\n");
   /* Connect to database */
   if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
      fprintf(stderr, "%s\n", mysql_error(conn));
   }
   printf("Done..\n");

}
