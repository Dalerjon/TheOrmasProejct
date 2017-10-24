<?php
	session_start();
	require_once 'logsql.php';
?>
<?php
	$query_order = "SELECT order_id, status_name, count, sum, currency_name FROM \"OrmasSchema\".orders_view WHERE user_id=".$_SESSION['id']." LIMIT 15";	
	$query_return = "SELECT return_id, status_name, count, sum, currency_name FROM \"OrmasSchema\".returns_view WHERE user_id=".$_SESSION['id']." LIMIT 15";			
	$result_order = pg_query($query_order);
	$string_out = "<table class='table_common'><caption>Мои заказы</cation><tr><th>ID заказа</th><th>Статус</th><th>Количество</th><th>Сумма</th><th>Валюта</th><th>Подробно</th></tr>";
	while ($row = pg_fetch_array($result_order)) {
        $string_out =$string_out."<tr>";
		$string_out =$string_out."<td>$row[0]</td>";
		$string_out =$string_out."<td>$row[1]</td>";
		$string_out =$string_out."<td>$row[2]</td>";
		$string_out =$string_out."<td>$row[3]</td>";
		$string_out =$string_out."<td>$row[4]</td>";
		$string_out =$string_out."<td>...</td>";
		$string_out =$string_out."</tr>";
    }
	$string_out = $string_out."</table>";
	$result_return = pg_query($query_return);
	$string_out = $string_out."<table class='table_common'><caption>Мои возвраты</cation><tr><th>ID возврата</th><th>Статус</th><th>Количество</th><th>Сумма</th><th>Валюта</th><th>Подробно</th></tr>";
	while ($row = pg_fetch_array($result_return)) {
        $string_out =$string_out."<tr>";
		$string_out =$string_out."<td>$row[0]</td>";
		$string_out =$string_out."<td>$row[1]</td>";
		$string_out =$string_out."<td>$row[2]</td>";
		$string_out =$string_out."<td>$row[3]</td>";
		$string_out =$string_out."<td>$row[4]</td>";
		$string_out =$string_out."<td>...</td>";
		$string_out =$string_out."</tr>";
    }
	echo $string_out;
?>