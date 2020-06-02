<!DOCTYPE HTML>
<html> 
<head>
<style> 
.error {
    color: #FF0000;
} 
</style> 
</head> 
<body> 
<h2>PHP Form Validation Example</h2>

<form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>">
User Name: <input type="text" name="username" value="<?php echo $username ; ?>"><BR>
Password: <input type="text" name="password" value="<?php echo $password; ?>"><BR>

<input type="submit" name="submit" value="Submit"> 
</form>

<?php 
$username=$_POST["username"]; 
$password=$_POST["password"]; 

function pg_connection_string_from_database_url() {
extract(parse_url($_ENV[ "DATABASE_URL"])); 
return "user=$user password=$pass host=$host dbname=" . substr($path, 1); # < you may want to add sslmode=require there too
}

$db = pg_connect(Pg_connection_string_from_database_url()); 

if(!$db) {
echo "Error : Unable to open database\n";
} else {
echo "Opened database successfully\n";
}
$sql="INSERT INTO MyAccounts (username, password) VALUES ('$username', '$password')";

print "<BR>$sql<BR>"; 

$ret = pg_query($db, $sql); 
if(!$ret){
echo pg_last_error($db); 
} else {
echo "Insert successfully\n";
}
Pg_close($db);
?>
<br>
<a href=index.php>HOME</a>
</body>
</html>