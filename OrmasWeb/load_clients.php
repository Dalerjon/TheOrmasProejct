<?php
	session_start();
	require_once 'logsql.php';
?>
<?php
	$query_client = "SELECT user_id_2 FROM \"OrmasSchema\".relations_view WHERE user_id_1=".$_SESSION['id'];			
	$result_clinet = pg_query($query_client);
	$client_options = "";
	while ($row_user = pg_fetch_array($result_clinet)) {
		$query = "SELECT user_id, user_name, user_surname, user_phone, city_name, user_address, firm	 FROM \"OrmasSchema\".clients_view WHERE user_id=".$row_user[0];			
		$result = pg_query($query);
		while ($row = pg_fetch_array($result)) {
			$client_options .= "<option value='".$row[0]."'>".$row[1].", ".$row[2].", ".$row[3].", ".$row[6]."</option>";
		}
	}
	echo $client_options;
?>