#!/usr/bin/python
import psyco
psyco.full()
import MySQLdb
conn = MySQLdb.connect (host = "localhost",
                        user = "root",
                         passwd = "woodall42",
                          db = "battleship")
cursor = conn.cursor ()
conn.autocommit(True)





from Numeric import *
#Legend:
# 0 = unknown
# 1 = Water
# 2 = End of ship
# 3 = Middle of ship
# 4 = Submarine
#
# Battleship = 4 lengths
# Cruisers   = 3 lengths
# Desroyers  = 2 lengths
# Submarines = 1 length

#for a 6x6 board
Battleships = 0
Cruisers = 1
Destroyers = 2
Submarines = 3

global board
board = zeros([12,12], Int)


def PrintBoard():
	global board
	string = ""
	print "we have a good board"
	vcounter = zeros([6], Int)
	hcounter = zeros([6], Int)
	vstring=""
	hstring=""
	print take(take(board, (0,1,2,3,4,5),1),(0,1,2,3,4,5))
	for H in range(0,6):
		for V in range(0,6):
			if board[H,V] != 1 and board[H,V] != 0:
				#Increment our counters
				vcounter[H] += 1
				hcounter[V] += 1
			string += str(board[H,V])
	for H in range(0,6):
		vstring += str(vcounter[H])
		hstring += str(hcounter[H])

	print "The boardstring is: ", string
	print "The horizontal sum is: ", vstring
	print "The vertical sum is: ", hstring

	try:
		cursor.execute ("""INSERT INTO `battleship`.`sixbysix` (`board` ,`h` ,`v`) VALUES (%s, %s, %s);""", (string, hstring, vstring))
	except:
		print "An error occured"


def PlaceBattleship(Where, Rotation):
	global board
	H = Where % 6
	V = Where / 6
	#First Case, Horizontal, has to be either 0 or 1 for a battleship
	if Rotation == 0:
		if H < 2:
			if board[H,V] == board[H+1,V] == board[H+2,V] == board[H+3,V] == 0:
				#If all of them are empty, lets place
				InsertBattleship(Where,0)
				return 1
	#If we have not returned yet, that means we need to try vertical
	elif Rotation == 1:
		if V < 2:
			if board[H,V] == board[H,V+1] == board[H,V+2] == board[H,V+3] == 0:
				#If all of them are empty, lets place
				InsertBattleship(Where,1)
				return 1
	return 0 #We can't fit it

def InsertBattleship(Where, Rotation):
	global board
	H = Where % 6
        V = Where / 6	
	if Rotation == 0:
		#We are Horiz
		board[H-1,V+1] = board[H,V+1] = board[H+1,V+1] = board[H+2,V+1] = board[H+3,V+1] = board[H+4,V+1] = 1
		board[H-1,V]  = board[H+4,V] = 1
		board[H-1,V-1] = board[H,V-1] = board[H+1,V-1] = board[H+2,V-1] = board[H+3,V-1] = board[H+4,V-1] = 1 #Water
		board[H,V] = board[H+3,V] = 2 #Ship ends
		board[H+1,V] = board[H+2,V] = 3 #ship middle
	else: #Rotation = 1
		#This means Vertical
		board[H-1,V-1] = board[H,V-1] = board[H+1,V-1] = 1
		board[H-1,V] = board[H+1,V] = board[H-1,V+1] = board[H+1,V+1] = board[H-1,V+2] = board[H+1,V+2] = board[H-1,V+3] = board[H+1,V+3] = 1
		board[H-1,V+4] = board[H,V+4] = board[H+1,V+4] = 1
		board[H,V] = board[H,V+3] = 2
		board[H,V+1] = board[H,V+2] = 3
		
def PlaceCruiser(Where, Rotation):
	global board
        H = Where % 6
        V = Where / 6
        #First Case, Horizontal, has to be either 0 or 1 for a battleship
        if Rotation == 0:
                if H < 3:
                        if board[H,V] == board[H+1,V] == board[H+2,V] == 0:
                                #If all of them are empty, lets place
                                InsertCruiser(Where,0)
                                return 1
        #If we have not returned yet, that means we need to try vertical
        elif Rotation == 1:
                if V < 3:
                        if board[H,V] == board[H,V+1] == board[H,V+2] == 0:
                                #If all of them are empty, lets place
                                InsertCruiser(Where,1)
                                return 1
        return 0 #We can't fit it

def InsertCruiser(Where, Rotation):
        H = Where % 6
        V = Where / 6
        if Rotation == 0:
                #We are Horiz
                board[H-1,V+1] = board[H,V+1] = board[H+1,V+1] = board[H+2,V+1] = board[H+3,V+1] = 1
                board[H-1,V]  = board[H+3,V] = 1
                board[H-1,V-1] = board[H,V-1] = board[H+1,V-1] = board[H+2,V-1] = board[H+3,V-1] = 1 #Water
                board[H,V] = board[H+2,V] = 2 #Ship ends
                board[H+1,V] = 3 #ship middle
        else: #Rotation = 1
                #This means Vertical
                board[H-1,V-1] = board[H,V-1] = board[H+1,V-1] = 1
                board[H-1,V] = board[H+1,V] = board[H-1,V+1] = board[H+1,V+1] = board[H-1,V+2] = board[H+1,V+2] = 1
                board[H-1,V+3] = board[H,V+3] = board[H+1,V+3] = 1
                board[H,V] = board[H,V+2] = 2
                board[H,V+1] = 3

#	print take(take(board, (0,1,2,3,4,5),1),(0,1,2,3,4,5))


def PlaceDestroyer(Where, Rotation):
	global board
        H = Where % 6
        V = Where / 6
        #First Case, Horizontal, has to be either 0 or 1 for a battleship
        if Rotation == 0:
                if H < 4:
                        if board[H,V] == board[H+1,V] == 0:
                                #If all of them are empty, lets place
                                InsertDestroyer(Where,0)
                                return 1
        #If we have not returned yet, that means we need to try vertical
        elif Rotation == 1:
                if V < 4:
                        if board[H,V] == board[H,V+1] == 0:
                                #If all of them are empty, lets place
                                InsertDestroyer(Where,1)
                                return 1
        return 0 #We can't fit it

def InsertDestroyer(Where, Rotation):
	global board
        H = Where % 6
        V = Where / 6
        if Rotation == 0: 
                #We are Horiz
                board[H-1,V+1] = board[H,V+1] = board[H+1,V+1] = board[H+2,V+1] = 1
                board[H-1,V]  = board[H+2,V] = 1
                board[H-1,V-1] = board[H,V-1] = board[H+1,V-1] = board[H+2,V-1] = 1 #Water
                board[H,V] = board[H+1,V] = 2 #Ship ends
        else: #Rotation = 1
                #This means Vertical
                board[H-1,V-1] = board[H,V-1] = board[H+1,V-1] = 1
                board[H-1,V] = board[H+1,V] = board[H-1,V+1] = board[H+1,V+1] = 1
                board[H-1,V+2] = board[H,V+2] = board[H+1,V+2] = 1
                board[H,V] = board[H,V+1] = 2
               
#	print take(take(board, (0,1,2,3,4,5),1),(0,1,2,3,4,5))



def PlaceSubmarine(Where):
	global board
        H = Where % 6
        V = Where / 6
        if board[H,V] == 0:
               #If all of them are empty, lets place
               InsertSubmarine(Where)
               return 1
        return 0 #We can't fit it

def InsertSubmarine(Where):
	global board
        H = Where % 6
        V = Where / 6
        board[H-1,V+1] = board[H,V+1] = board[H+1,V+1] = 1
        board[H-1,V]  = board[H+1,V] = 1
        board[H-1,V-1] = board[H,V-1] = board[H+1,V-1] = 1 #Water
        board[H,V] = 4 #Ship ends

	#print take(take(board, (0,1,2,3,4,5),1),(0,1,2,3,4,5))
	

for A in range(0, 36):
	for B in range (0, 36):
		for C in range (0, 36):
			print "Status: ", A,B,C
#			print take(take(board, (0,1,2,3,4,5),1),(0,1,2,3,4,5))
			for D in range (0, 36):
				for E in range (0, 36):
					for F in range (0, 36):
						if A==B or A==C or A==D or A==E or A==F or B==C or B==D or B==E or B==F or C==D or C==E or C==F or D==E or D==F or E==F:
							Theyarethesame=1
						else:

							board = zeros([12,12], Int)
							if PlaceCruiser(A,0):
								if PlaceDestroyer(B,0):
                        	                                       if PlaceDestroyer(C,0):
                                	                                       if PlaceSubmarine(D):
                                        	                                       if PlaceSubmarine(E):
                                                	                                       if PlaceSubmarine(F):
                                                        	                                        PrintBoard()
							board = zeros([12,12], Int)
        	                                        if PlaceCruiser(A,0):
                	                                        if PlaceDestroyer(B,0):
                        	                                       if PlaceDestroyer(C,1):
                                	                                       if PlaceSubmarine(D):
                                        	                                       if PlaceSubmarine(E):
                                                	                                       if PlaceSubmarine(F):
                                                        	                                        PrintBoard()

							board = zeros([12,12], Int)
        	                                        if PlaceCruiser(A,0):
								if PlaceDestroyer(B,1):
									if PlaceDestroyer(C,0):
										if PlaceSubmarine(D):
											if PlaceSubmarine(E):
												if PlaceSubmarine(F):
													PrintBoard()
							board = zeros([12,12], Int)
        	                                        if PlaceCruiser(A,0):
                	                                        if PlaceDestroyer(B,1):
                        	                                 	if PlaceDestroyer(C,1):
                                	                                       if PlaceSubmarine(D):
                                        	                                       if PlaceSubmarine(E):
                                                	                                       if PlaceSubmarine(F):
                                                        	                                        PrintBoard()
						
							board = zeros([12,12], Int)
							if PlaceCruiser(A,1):
								if PlaceDestroyer(B,0):
									if PlaceDestroyer(C,0):
										if PlaceSubmarine(D):
											if PlaceSubmarine(E):
												if PlaceSubmarine(F):
													PrintBoard()
	                                                board = zeros([12,12], Int)
        	                                        if PlaceCruiser(A,1):
                	                                        if PlaceDestroyer(B,0):
							                if PlaceDestroyer(C,1):
                                	                                       if PlaceSubmarine(D):
                                        	                                       if PlaceSubmarine(E):
                                                	                                       if PlaceSubmarine(F):
                                                        	                                        PrintBoard()
	
	                                                board = zeros([12,12], Int)
        	                                        if PlaceCruiser(A,1):
								if PlaceDestroyer(B,1):
                        	                                       if PlaceDestroyer(C,0):
                                	                                       if PlaceSubmarine(D):
                                        	                                       if PlaceSubmarine(E):
                                                	                                       if PlaceSubmarine(F):
                                                        	                                        PrintBoard()

	                                                board = zeros([12,12], Int)
        	                                        if PlaceCruiser(A,1):
                	                                        if PlaceDestroyer(B,1):
                        	                                       if PlaceDestroyer(C,1):
                                	                                       if PlaceSubmarine(D):
                                        	                                       if PlaceSubmarine(E):
                                                	                                       if PlaceSubmarine(F):
                                                        	                                        PrintBoard()
					
cursor.close ()
conn.close ()
