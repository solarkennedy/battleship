import MySQLdb
conn = MySQLdb.connect (host = "localhost",
                        user = "root",
                         passwd = "woodall42",
                          db = "battleship")
cursor = conn.cursor ()
conn.autocommit(True)

board=232100111111221414111111221014111011
h=304030
v=331102
cursor.execute ("INSERT INTO `battleship`.`sixbysix` (`board` ,`h` ,`v`) VALUES ('%s', '%s', '%s');", (board,h,v))


cursor.close ()
conn.close ()
