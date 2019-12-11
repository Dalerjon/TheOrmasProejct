<?php
	$db_hostname= '109.68.236.201';
	$db_database = 'FarhundaTest';
	$db_username = 'postgres';
	$db_password = 'postgres2018';
	$db_port = '5432';
	
	$connStr = "host=".$db_hostname." port=".$db_port." dbname=".$db_database." user=".$db_username." password=".$db_password." options='--client_encoding=UTF8'";
	$dbconn = pg_connect($connStr);
	if (!$dbconn) die ("Database error :".pg_last_error());
?>