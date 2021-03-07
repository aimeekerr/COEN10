<html>
<body style="background-color:blue">
<?php
$nu=array (0,0,0,0,0);
for ($i = 0; $i < 5; $i++){
	$nu[$i] = rand(0, 20);
}
$number = $_POST["number"];
?>
<h1 style="color:purple"> And your answer <?php echo  $number ?> is... </h1>
<?php
$x = 0;
for ($i = 0; $i < 5; $i++){
	if ($nu[$i]==$number){
		$x=1;
	}
}	
	if ($x==1)
		echo "Correct!";
    else {
		echo "Incorrect :(";
	}
?>
<h1 style="color:purple"> The numbers were... </h1>
<?php
echo "<p style=\"font-size:200%\">" .  $nu[0]  . " | "  . $nu[1] . " | "  . $nu[2] . " | "  . $nu[3] . " | "  . $nu[4] .  "</p>";
?>
<form method="POST" action="akerrlab3.html">
	<input type="submit" value="Try again?" />
</form>
</body>
</html>
