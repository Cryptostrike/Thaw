<?php
$MyUsername = "username";  // enter username for mysql
$MyPassword = "password";  // enter password for mysql
$MyHostname = "localhost"; // usually "localhost" unless your database resides on a different server

$dbh = mysql_pconnect($MyHostname , $MyUsername, $MyPassword);
$selected = mysql_select_db("thaw",$dbh);
?>
