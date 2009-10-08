<html><body>

<?php
$board="232112111112221111111141011111014114";
$board=str_replace("0","1",$board);
$horiz="422101";
$vert="301303";
$username="battleship";
$password="Cheyi0re";
$database="battleship";


#mysql_connect(localhost,$username,$password);
#@mysql_select_db($database) or die( "Unable to select database");

#$query = "SELECT * FROM `sixbysix` ORDER BY rand() LIMIT 1";
#mysql_query($query);
#$result=mysql_query($query);
#$board=mysql_result($result,$i,"board");
#$horiz=mysql_result($result,$i,"h");
#$vert=mysql_result($result,$i,"v");
#mysql_close();

echo "$board\n";
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
			if     ($board[($V*6)+$H-1] == 2 || $board[($V*6)+$H-1] == 3) 
			echo "<img src=2r.gif>\n";
			elseif ($board[($V*6)+$H+1] == 2 || $board[($V*6)+$H+1] == 3)
			echo "<img src=2l.gif>\n";
                        elseif ($board[(($V-1)*6)+$H] == 2 || $board[(($V-1)*6)+$H] == 3)
                        echo "<img src=2d.gif>\n";
                        elseif ($board[(($V+1)*6)+$H] == 2 || $board[(($V+1)*6)+$H] == 3 )
                        echo "<img src=2u.gif>\n";
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
echo "</tr>";


?>
</body></html>
