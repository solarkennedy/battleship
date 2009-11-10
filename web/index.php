<html><body>
<?php
/* 
This is a web interface to access the battleship boards.
It uses mysql_real_escape to prevent sql injection.
Please don't hack me. :)
test
*/
function random_row($table, $column) {
      $max_sql = "SELECT max(" . $column . ") 
                  AS max_id
                  FROM " . $table;
      $max_row = mysql_fetch_array(mysql_query($max_sql));
      $random_number = mt_rand(1, $max_row['max_id']);
      $random_sql = "SELECT * FROM " . $table . "
                     WHERE " . $column . " >= " . $random_number . " 
                     ORDER BY " . $column . " ASC
                     LIMIT 1";
      $random_row = mysql_fetch_row(mysql_query($random_sql));
      if (!is_array($random_row)) {
          $random_sql = "SELECT * FROM " . $table . "
                         WHERE " . $column . " < " . $random_number . " 
                         ORDER BY " . $column . " DESC
                         LIMIT 1";
          $random_row = mysql_fetch_row(mysql_query($random_sql));
      }
      return $random_row;
}

function print_board($board, $horiz, $vert){
echo '<table border="2" cellpadding="0" cellspacing="0">';
$V=0;
while ($V<6)
{
	echo "<tr>";
	$H=0;
	while ($H<6)
	{
		echo '<td>';
//		echo "<a href=\"index.php?v=$vert&h=$horiz";
		echo "<a href=\"" . $_SERVER["REQUEST_URI"] . "&cell";
		echo  $V*6+$H . "=" . $board[($V*6)+$H] . "\">";
		if ($board[($V*6)+$H] == 1)
			echo "<img src=images/water.png border=0>";
		elseif ($board[($V*6)+$H] == 3)
		{
			if ($board[(($V-1)*6)+$H] == 1 || $board[(($V+1)*6)+$H] == 1) 
				#This means water to the top and bottom
				echo "<img src=images/centerh.png border=0>";
			else
				echo "<img src=images/centerv.png border=0>";
		}
		elseif ($board[($V*6)+$H] == 2)
		{
			$u=0; $d=0; $l=0; $r=0;
			if ($H != 0)
				$l=$board[($V*6)+$H-1];
			if ($H != 5)
				$r=$board[($V*6)+$H+1];
			if ($V != 0)
				$u=$board[(($V-1)*6)+$H];
			if ($V != 5)
				$d=$board[(($V+1)*6)+$H];
			if     ($l == 2 || $l == 3) 
				echo "<img src=images/right.png border=0>";
			elseif ($r == 2 || $r == 3)
				echo "<img src=images/left.png border=0>";
                        elseif ($d == 2 || $d == 3)
                	        echo "<img src=images/up.png border=0>";
                        elseif ($u == 2 || $u == 3 )
                        	echo "<img src=images/down.png border=0>";
			else
				echo "I dont know!";
		}
		elseif ($board[($V*6)+$H] == 4)
			echo "<img src=images/sub.png border=0>";
		else
			echo $board[($H*6)+$V];
		echo '</a>';
		echo '</td>';
#		echo "\n";
		$H++;
	}# End while ($H<6)
	echo "<td>$horiz[$V]</td>";
#	echo "</tr>\n";
	$V++;
$H=0;
echo "<tr>";
}
	while ($H<6)
	{
		echo "<td>$vert[$H]</td>";
		$H++;
	}
	echo "<td>&nbsp;</td>";
	echo "</tr></table>\n";
#	echo "Board Code: $board<br>\n";
#	echo "Vertical Sum: $vert<br>\n";
#	echo "Horizontal Sum: $horiz<br>\n";

}#End Print_board function


$username="xkyle_battleship";
$password="ree7Go7I";
$database="xkyle_battleship";
mysql_connect("mysql.xkyle.com",$username,$password);
@mysql_select_db($database) or die( "Unable to select database");

if ($_GET[random])
{
	echo "We want a random one";
	$query = "SELECT * FROM `6x6` ORDER BY rand() LIMIT 1";
	mysql_query($query);
	$result=mysql_query($query);
} else {
	$vert=mysql_real_escape_string($_GET['v']);
	$horiz=mysql_real_escape_string($_GET['h']);
	echo "Searching for a board with a vertical sum of $vert and a horizontal sum of $horiz \n";
	$query = "SELECT * FROM `6x6` WHERE `h` ='$horiz' AND `v` ='$vert'";
	$i=0;
	while ($i<36){
		if ($_GET["cell$i"] != "")
			$auxquery="$auxquery and SUBSTRING(`board`, " . ($i+1) . ",1)=" . $_GET["cell$i"];
		$i++;
	}
#	echo "Our Aux query is $auxquery";
	$query=$query . $auxquery;
	mysql_query($query);
	$result=mysql_query($query);
}


#Example substring quesry
#SELECT *  FROM `6x6` WHERE `h` = CONVERT(_utf8 '301204' USING latin1) COLLATE latin1_swedish_ci AND `v` = CONVERT(_utf8 '022222' USING latin1) COLLATE latin1_swedish_ci and SUBSTRING(`board`,7,1)=4;

$num = mysql_numrows($result);
echo "<br>There where $num rows \n";
$i=0;
while ($i < $num) {
	$board=mysql_result($result,$i,"board");
	$horiz=mysql_result($result,$i,"h");
	$vert=mysql_result($result,$i,"v");
	$board=str_replace("0","1",$board);
	print_board($board, $horiz, $vert);
	$i++;
}#End board result loop

echo "
<p>Search!
<form action=\"index.php\" method=\"get\">
Vertical Sum: <input type=\"text\" name=\"v\" value=\"$vert\"><br>
Horizontal Sum: <input type=\"text\" name=\"h\" value=\"$horiz\"><br>
<input type=\"Submit\"></p>
</form>
<p><a href=\"index.php?random=1\">Give me a random board</a></p>
";
mysql_close();
?>
</body></html>
