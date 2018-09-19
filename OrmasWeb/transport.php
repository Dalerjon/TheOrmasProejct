<?php
	session_start();
	require_once 'logsql.php';
?>
<?php
	$query_transport = "SELECT transport_id FROM \"OrmasSchema\".transports_view WHERE employee_id=".$_SESSION['id'];			
	$result_transport = pg_query($query_transport);
	$row_transport = pg_fetch_array($result_transport);
	$string_out = "<table id='transport-table'><caption>Товары в таранспорте</cation><thead><tr><th>Наименование продукта</th><th>Количество</th><th>Сумма</th><th>Валюта</th></tr></thead><tbody>";
	if(!empty($row_transport))
	{
		$query = "SELECT product_name, count, sum, sum_currency_name FROM \"OrmasSchema\".transport_list_view WHERE transport_id=".$row_transport[0];			
		$result = pg_query($query);
		while ($row = pg_fetch_array($result)) {
			$string_out =$string_out."<tr>";
			$string_out =$string_out."<td>$row[0]</td>";
			$string_out =$string_out."<td>$row[1]</td>";
			$string_out =$string_out."<td>$row[2]</td>";
			$string_out =$string_out."<td>$row[3]</td>";
			$string_out =$string_out."</tr>";
		}
	}
	$string_out = $string_out."</tbody></table>";
	$string_out .= "<script>
			$(document).ready( function () {
				$('#transport-table').DataTable();
			});
	</script>";
	echo $string_out;
?>