<?php
	session_start();
	require_once 'logsql.php';
?>
<?php
	$query_client = "SELECT user_id_2 FROM \"OrmasSchema\".relations_view WHERE user_id_1=".$_SESSION['id'];			
	$result_clinet = pg_query($query_client);
	$string_out = "<table id='my-clients'><caption>Мои клиенты</cation><thead><tr><th>Имя</th><th>Фамилия</th><th>Телефон</th><th>Город</th><th>Адрес</th><th>Фирма</th></tr></thead><tbody>";
	while ($row_user = pg_fetch_array($result_clinet)) {
		$query = "SELECT user_id, user_name, user_surname, user_phone, city_name, user_address, firm FROM \"OrmasSchema\".clients_view WHERE user_id=".$row_user[0];			
		$result = pg_query($query);
		while ($row = pg_fetch_array($result)) {
			$string_out =$string_out."<tr>";
			$string_out =$string_out."<td>$row[1]</td>";
			$string_out =$string_out."<td>$row[2]</td>";
			$string_out =$string_out."<td>$row[3]</td>";
			$string_out =$string_out."<td>$row[4]</td>";
			$string_out =$string_out."<td>$row[5]</td>";
			$string_out =$string_out."<td>$row[6]</td>";
			$string_out =$string_out."</tr>";
		}
	}
	$string_out = $string_out."</tbody></table>";
	$string_out .= "<script>
			$(document).ready( function () {
				$('#my-clients').DataTable();
			});
	</script>";
	echo $string_out;
?>