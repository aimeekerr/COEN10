<html>
<body style="background-color:#F6CEEC">
<h1 style="color:blue"> and your answer </h1>
<?php
$number1 = $_POST["number1"];
$number2 = $_POST["number2"];
$number3 = $_POST["number3"];
echo "<p style=\"font-size:200%\">" . $number1 ." x ". $number2." = ". $number3."</p>";
?>
<h2 style="color:blue"> is... </h2>
<?php
if ($number1 * $number2 == $number3)
 echo "<p style=\"font-size:200%\">". "Correct!";
else
 echo "<p style=\"font-size:200%\">". "Incorrect :( The correct answer is" ." ". ($number1 * $number2);
?>
<form method="POST" action="akerrlab2.php">
 <input type="submit" value="Want another one?" />
</form>
</body>
</html>
