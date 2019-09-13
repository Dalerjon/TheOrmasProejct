<?php
	$db_hostname= 'localhost';
	$db_database = 'FarhundaDB';
	$db_username = 'postgres';
	$db_password = 'postgres';
	$db_port = '5432';
	
	$connStr = "host=".$db_hostname." port=".$db_port." dbname=".$db_database." user=".$db_username." password=".$db_password." options='--client_encoding=UTF8'";
	$dbconn = pg_connect($connStr);
	if (!$dbconn) die ("Database error :".pg_last_error());
?>