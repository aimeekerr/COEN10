<html>
<body style="background-color:#F6CEEC">
<h1 style="color:blue">
What do the two numbers multiplied together equal??
</h1>
<?php
$number1 = rand(0, 12);
$number2 = rand(0, 12);
echo "<p style=\"font-size:200%\">" . $number1 ." x ". $number2." = ". "</p>";
?>
<form action="akerrlab2pg2.php" method="POST">
 <input type= "hidden" name="number1" value="<?php echo $number1; ?>" />
 <input type= "hidden" name="number2" value="<?php echo $number2; ?>" />
 <input type= "number" name="number3" />
 <input type="submit" value="Answer!" />
</form>
</body>
<html>
