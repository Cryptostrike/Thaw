<?php
    // Connect to MySQL
    include("dbconnect.php");
    
    $counter=1;
    while ( isset( $_GET["serial".$counter] ) )
    {
        // Prepare the SQL statement
        $SQL = "INSERT INTO thaw.temperature (sensor ,celsius) VALUES ('".$_GET["serial"]."', '".$_GET["temperature"]."')";     

        // Execute SQL statement
         mysql_query($SQL);
        
        // Increase counter
        $counter++;
    }
    
    // Go to the review_data.php (optional)
    header("Location: review_data.php");
?>
