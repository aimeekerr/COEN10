<html>
	<body style="background-color:yellow">
		<h1 style="color:pink"> And the numbers were... </h1>
		<?php
			$counter=0;
			$ar1=array ($_POST["num1"], $_POST["num2"], $_POST["num3"], $_POST["num4"], $_POST["num5"]);
			$ar2=array (0,0,0,0,0);
 			for($i=0;$i<5;$i++){
	 			$ar2[$i] = rand(0,20);
	 			echo $ar2[$i],"        ";
//This loop generates and echos the random numbers  
			}
		?>
		<h1 style="color:pink"> Your numbers were... </h1>
		<?php
			 for($i=0;$i<5;$i++)
				 echo $ar1[$i],"			";
//this loops echos the numbers that the user input 
		?>
		<?php
  			for($i=0;$i<5;$i++){
	  			for($j=0;$j<5;$j++){
					if($ar1[$i]==$ar2[$j]){
						$counter++;
//This loop tests if there are any values in the 2 arrays that match
					}
	  			}
  			}
			echo "...";
			echo "You have" . " "  .  $counter . " "  .  "matches!";
		?>
		<form method="POST" action="akerrlab4.html">
			<input type="submit" value="Try again?" />
		</form>
	</body>
</html>
