#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql.h>
int Battleships = 0;
int Cruisers = 1;
int Destroyers = 2;
int Submarines = 3;
//int board[6][6] = {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0}};
//int board[12][12] = {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0}};
int board[12][12] ={{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0}};
MYSQL *conn;
MYSQL_RES *res;
MYSQL_ROW row;


int main()
{
int A, B, C, D, E, F;
ConnectToDB();
//int A=0;
for (A=0; A<36; A++){
	for (B=0; B<36; B++){
		for (C=0; C<36; C++){
			printf("Status: %i %i %i\n", A,B,C);
			for (D=0; D<36; D++){
				for (E=0; E<36; E++){
					for (F=0; F<36; F++){
						if ( A==B || A==C || A==D || A==E || A==F || B==C || B==D || B==E || B==F || C==D || C==E || C==F || D==E || D==F || E==F )
						// ( A==B)
						{
							int Theyarethesame=1;
						}
						else
						{
//							printf("Status: %i %i %i %i %i %i\n", A,B,C,D,E,F);
							ZeroArray();
							if (PlaceCruiser(A,0)==1)
								if (PlaceDestroyer(B,0)==1)
                        	                                       if (PlaceDestroyer(C,0))
                                	                                       if (PlaceSubmarine(D)==1)
                                        	                                       if (PlaceSubmarine(E)==1)
                                                	                                       if (PlaceSubmarine(F)==1)
                                                        	                                        PrintBoard();
							ZeroArray();
        	                                        if (PlaceCruiser(A,0))
                	                                        if (PlaceDestroyer(B,0))
                        	                                       if (PlaceDestroyer(C,1))
                                	                                       if (PlaceSubmarine(D)==1)
                                        	                                       if (PlaceSubmarine(E)==1)
                                                	                                       if (PlaceSubmarine(F)==1)
                                                        	                                        PrintBoard();

							ZeroArray();
        	                                        if (PlaceCruiser(A,0))
								if (PlaceDestroyer(B,1))
									if (PlaceDestroyer(C,0))
										if (PlaceSubmarine(D)==1)
											if (PlaceSubmarine(E)==1)
												if (PlaceSubmarine(F)==1)
													PrintBoard();
							ZeroArray();
        	                                        if (PlaceCruiser(A,0))
                	                                        if (PlaceDestroyer(B,1))
                        	                                 	if (PlaceDestroyer(C,1))
                                	                                       if (PlaceSubmarine(D)==1)
                                        	                                       if (PlaceSubmarine(E)==1)
                                                	                                       if (PlaceSubmarine(F)==1)
                                                        	                                        PrintBoard();
						
							ZeroArray();
							if (PlaceCruiser(A,1))
								if (PlaceDestroyer(B,0))
									if (PlaceDestroyer(C,0))
										if (PlaceSubmarine(D)==1)
											if (PlaceSubmarine(E)==1)
												if (PlaceSubmarine(F)==1)
													PrintBoard();
							ZeroArray();
        	                                        if (PlaceCruiser(A,1))
                	                                        if (PlaceDestroyer(B,0))
							                if (PlaceDestroyer(C,1))
                                	                                       if (PlaceSubmarine(D)==1)
                                        	                                       if (PlaceSubmarine(E)==1)
                                                	                                       if (PlaceSubmarine(F)==1)
                                                        	                                        PrintBoard();
	
							ZeroArray();
        	                                        if (PlaceCruiser(A,1))
								if (PlaceDestroyer(B,1))
                        	                                       if (PlaceDestroyer(C,0))
                                	                                       if (PlaceSubmarine(D)==1)
                                        	                                       if (PlaceSubmarine(E)==1)
                                                	                                       if (PlaceSubmarine(F)==1)
                                                        	                                        PrintBoard();

							ZeroArray();
        	                                        if (PlaceCruiser(A,1))
                	                                        if (PlaceDestroyer(B,1))
                        	                                       if (PlaceDestroyer(C,1))
                                	                                       if (PlaceSubmarine(D)==1)
                                        	                                       if (PlaceSubmarine(E)==1)
                                                	                                       if (PlaceSubmarine(F)==1)
                                                        	                                        PrintBoard();
							
						}//End if a==b==c...
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
	char boardstring[37] = {48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,0};
	printf("we have a good board\n");
	char vcounter[7] = {48,48,48,48,48,48,0}; //Ascii for 0
	char hcounter[7] = {48,48,48,48,48,48,0};
	int H;
	int V;
	for (H=0; H<6; H++)
	{
		for (V=0;V<6;V++)
		{
			printf("%d", board[V][H]);
			if (board[H][V] != 1 && board[H][V] != 0)
			{
				vcounter[H] += 1;
				hcounter[V] += 1;
			}
			boardstring[V*6+H] = board[H][V] + 48;
		}
		printf("\n");
	}	

	printf("The boardstring is: %s\n", boardstring);
	printf("The horizontal sum is: %s\n", vcounter);
	printf("The vertical sum is: %s\n", hcounter);
	char querystring[256];
	snprintf(querystring, sizeof(querystring), "REPLACE INTO `battleship`.`6x6` (`board` ,`h` ,`v`)VALUES ('%s', '%s', '%s');", boardstring, hcounter, vcounter);
	if (mysql_query(conn, querystring)) 
	      fprintf(stderr, "%s\n", mysql_error(conn));
	printf("\n\n");
}


int PlaceBattleship(int Where, int Rotation){
	int H, V;
	H = Where % 6;
	V = Where / 6;
	if (Rotation == 0){
		if (H <= 2){
			if (board[H][V] == 0 && board[H+1][V] == 0 && board[H+2][V] == 0 && board[H+3][V] == 0){
				return InsertBattleship(Where,0);
			}
		}
	}
	else{
		if (V <= 2){
			if (board[H][V] == 0 && board[H][V+1] == 0 && board[H][V+2] == 0 && board[H][V+3] == 0){
				return InsertBattleship(Where,1);
			}
		}
	}
	return 0;
}//End Place Battleship


int InsertBattleship(int Where, int Rotation){
	int H, V;
	H = Where % 6;
        V = Where / 6;	
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
        H = Where % 6;
        V = Where / 6;
        if (Rotation == 0){
                if (H <= 3){
                        if (board[H][V] == 0 &&  board[H+1][V] == 0 && board[H+2][V] == 0){
                                return InsertCruiser(Where,0);
			}
		}
	}
        else if (Rotation == 1){
                if (V <= 3){
                        if (board[H][V] == 0 && board[H][V+1] == 0 && board[H][V+2] == 0){
                                return InsertCruiser(Where,1);
			}
		}
	}
	return 0;
}

int InsertCruiser(int Where, int Rotation){
	int H, V;
        H = Where % 6;
        V = Where / 6;
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
        H = Where % 6;
        V = Where / 6;
	//printf("We are trying to place a Destroyer at %d %d with a rotation of %d\n", H, V,Rotation);
        if (Rotation == 0) {
                if (H <= 4) { 
                 	if (board[H][V] == 0 && board[H+1][V] == 0) {
				return InsertDestroyer(Where,0);
			}
		}
	}
        else if (Rotation == 1){
                if (V <= 4){
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
        H = Where % 6;
        V = Where / 6;
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
        H = Where % 6;
        V = Where / 6;
        if (board[H][V] == 0)
               return InsertSubmarine(Where);
        else
		return 0; //We can't fit it
}

int InsertSubmarine(int Where)
{
	int H, V;
        H = Where % 6;
        V = Where / 6;
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
