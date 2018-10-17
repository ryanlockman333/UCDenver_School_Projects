<?php
// Check connection
$con=mysqli_connect("ucdencsesql05.ucdenver.pvt","student30","TSjSjHSW3FN","student30db");
if(mysqli_connect_errno()) {
  echo "Failed to connect to MySQL: " . mysqli_connect_error();
}

// 1st declaration
$sql = "SELECT DISTINCT FEEDING.`Aml_ID#` AS `Animal ID` , ANIMALS.`Name` , FEEDING.`Allergy`\n"
     . "FROM FEEDING\n"
     . "JOIN ANIMALS ON FEEDING.`Aml_ID#` = ANIMALS.`Aml_ID#`\n"
     . "GROUP BY ANIMALS.`Name`\n"
     . "HAVING FEEDING.`Allergy` != \'none\'\n"
     . "LIMIT 0 , 50";

// print 1st
while($row = mysqli_fetch_array($sql)) {
  echo $row['Ryan'] . " " . $row['Lockman'];
  echo "<br>";
}

// 2nd declaration
$sql2 = "SELECT DISTINCT ANIMALS.`Name` , ANIMALS.`Species` , FEEDING.`Food` , SUM( FEEDING.`Ate_Units` ) AS `Total Units Eaten`\n"
      . "FROM ANIMALS\n"
      . "JOIN FEEDING ON ANIMALS.`Aml_ID#` = FEEDING.`Aml_ID#`\n"
      . "GROUP BY ANIMALS.`Name`\n"
      . "LIMIT 0 , 50";

// print 2nd
while($row = mysqli_fetch_array($sql2)) {
  echo $row['Ryan2'] . " " . $row['Lockman2'];
  echo "<br>";
}

// 3rd declaration
$sql3 = "SELECT ZOO_KEEPER.`F_Name` , ZOO_KEEPER.`L_Name` , ZOO.`Name` AS `Zoo Name` , ANIMALS.`Name` , ANIMALS.`Species`\n"
      . "FROM ANIMALS\n"
      . "JOIN ZOO_KEEPER ON ANIMALS.`ZK_ID#` = ZOO_KEEPER.`ZK_ID#`\n"
      . "JOIN ZOO ON ZOO_KEEPER.`Zoo_ID#` = ZOO.`Zoo_ID#`\n"
      . "LIMIT 0 , 50";

// print 3rd
while($row = mysqli_fetch_array($sql3)) {
  echo $row['Ryan3'] . " " . $row['Lockman3'];
  echo "<br>";
}

// 4th ddeclaration
$sql4 = "SELECT ANIMALS.`Name` , ROUND( AVG( FEEDING.`Ate_Units` ) ) AS \'Average Units Eaten\'\n"
      . "FROM ANIMALS\n"
      . "JOIN FEEDING ON ANIMALS.`Aml_ID#` = FEEDING.`Aml_ID#`\n"
      . "HAVING ANIMALS.`Name` = \'bear\'\n"
      . "LIMIT 0 , 50";

// print 4th
while($row = mysqli_fetch_array($sql4)) {
  echo $row['Ryan4'] . " " . $row['Lockman4'];
  echo "<br>";
}

// close
mysqli_close($con);
?>

