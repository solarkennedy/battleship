<html><body>

<?php



$username="battleship";
$password="Cheyi0re";
$database="battleship";
mysql_connect(localhost,$username,$password);
@mysql_select_db($database) or die( "Unable to select database");

if ($_GET[random])
{
	echo "We want a random one";
	$query = "SELECT * FROM `sixbysix` ORDER BY rand() LIMIT 1";
} else {
	$vert=mysql_real_escape_string($_GET['v']);
	$horiz=mysql_real_escape_string($_GET['h']);
	echo "Searching for a board with a vertical sum of $vert and a horizontal sum of $horiz";
	$query = "SELECT * FROM `sixbysix` WHERE `h` ='$horiz' AND `v` ='$vert'";
}


mysql_query($query);
$result=mysql_query($query);


$num = mysql_numrows($result);
echo "<br>There where $num rows";


$i=0;
while ($i < $num) {

$board=mysql_result($result,$i,"board");
$horiz=mysql_result($result,$i,"h");
$vert=mysql_result($result,$i,"v");
$board=str_replace("0","1",$board);

echo '<table border="2" cellpadding="0" cellspacing="0">';
$V=0;
while ($V<6)
{
	echo "<tr>\n";
	$H=0;
	while ($H<6)
	{
		echo '<td>';
		#echo "<img src=water.gif>";
		if ($board[($V*6)+$H] == 1)
			echo "<img src=blank.gif>\n";
		elseif ($board[($V*6)+$H] == 3)
		{
			if ($board[(($V-1)*6)+$H] == 1 || $board[(($V+1)*6)+$H] == 1) 
			#This means water to the top and bottom
			echo "<img src=3h.gif>\n";
			else
			echo "<img src=3v.gif>\n";
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
			echo "<img src=2r.gif>\n";
			elseif ($r == 2 || $r == 3)
			echo "<img src=2l.gif>\n";
                        elseif ($d == 2 || $d == 3)
                        echo "<img src=2u.gif>\n";
                        elseif ($u == 2 || $u == 3 )
                        echo "<img src=2d.gif>\n";
			else
			echo "I dont know!";

		}
		elseif ($board[($V*6)+$H] == 4)
			echo "<img src=4.gif>\n";
		else
			echo $board[($H*6)+$V];
		echo '</td>';
		echo "\n";
		$H++;
	}
	echo "<td>$vert[$V]</td>";
	echo "</tr>\n";
	$V++;

}
$H=0;
echo "<tr>";
while ($H<6)
{
	echo "<td>$horiz[$H]</td>";
	$H++;
}
echo "<td>&nbsp;</td>";
echo "</tr></table>";
echo "Board Code: $board<br>\n";
echo "Vertical Sum: $vert<br>\n";
echo "Horizontal Sum: $horiz<br>\n";

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
