<?php
	session_start();
	require_once 'logsql.php';
?>
<?php
	$query_exp = "SELECT relation_id, relation_type, user_id_1, user_id_2, FROM \"OrmasSchema\".relations_view WHERE user_2=".$_SESSION['id'];
	$result_exp = pg_query($query_exp);
	$row_exp = pg_fetch_array($result_exp);
	$query = "SELECT * FROM \"OrmasSchema\".users_view WHERE user_id=".$row_exp['2'];
	$result = pg_query($query_exp);
	$row = pg_fetch_array($result_exp);
	if(empty($row['0'])
	{
		echo "<div id= 'error-div'> У Вас пока нет экспедитора, ждите скоро он будет назначан.</div>"
	}
	else
	{
		
	}
	echo $string_out;
?>