<?php
	session_start();
	require_once 'logsql.php';
?>
<?php
	if($_SESSION['role_id_client'] == $_SESSION['role_id'])
	{
		$query_order = "SELECT order_id, status_name, count, sum, currency_name FROM \"OrmasSchema\".orders_view WHERE user_id=".$_SESSION['id']." AND status_name != 'EXECUTED' LIMIT 15";	
		$query_return = "SELECT return_id, status_name, count, sum, currency_name FROM \"OrmasSchema\".returns_view WHERE user_id=".$_SESSION['id']." AND status_name != 'EXECUTED' LIMIT 15";			
		$result_order = pg_query($query_order);
		$string_out = "<table id='order-table'><caption>Мои заказы</cation><thead><tr><th>ID заказа</th><th>Дата заказа</th><th>Клиент</th><th>Статус</th><th>Количество</th><th>Сумма</th><th>Валюта</th><th>Действие</th></tr></thead><tbody>";
		while ($row = pg_fetch_array($result_order)) {
			$string_out =$string_out."<tr>";
			$string_out =$string_out."<td>$row[0]</td>";
			$string_out =$string_out."<td>$row[1]</td>";
			$string_out =$string_out."<td>$row[2] $row[3] $row[4]</td>";
			$string_out =$string_out."<td>$row[5]</td>";
			$string_out =$string_out."<td>$row[6]</td>";
			$string_out =$string_out."<td>$row[7]</td>";
			$string_out =$string_out."<td>$row[8]</td>";
			$string_out =$string_out."<td><form method='post'><button class='list-submit' id='execute' name='execute' value='$row[0]' type='submit'>Выполнить</button></form></td>";
			$string_out =$string_out."</tr>";
		}
		$string_out = $string_out."</tbody></table><br/><br/><br/>";
		$result_return = pg_query($query_return);
		$string_out = $string_out."<table id='return-table'><caption>Мои возвраты</cation><thead><tr><th>ID возврата</th><th>Дата возврата</th><th>Клиент</th><th>Статус</th><th>Количество</th><th>Сумма</th><th>Валюта</th><th>Действие</th></tr></thead><tbody>";
		while ($row = pg_fetch_array($result_return)) {
			$string_out =$string_out."<tr>";
			$string_out =$string_out."<td>$row[0]</td>";
			$string_out =$string_out."<td>$row[1]</td>";
			$string_out =$string_out."<td>$row[2] $row[3] $row[4]</td>";
			$string_out =$string_out."<td>$row[5]</td>";
			$string_out =$string_out."<td>$row[6]</td>";
			$string_out =$string_out."<td>$row[7]</td>";
			$string_out =$string_out."<td>$row[8]</td>";
			$string_out =$string_out."<td><form method='post'><button class='list-submit' id='execute_return' name='execute_return' value='$row[0]' type='submit'>Выполнить</button></form></td>";
			$string_out =$string_out."</tr>";
		}
		$string_out = $string_out."</tbody></table>";
		$string_out .= "<script>
			$(document).ready( function () {
				$('#order-table').DataTable();
			});
			$(document).ready( function () {
				$('#return-table').DataTable();
			});
		</script>";
		echo $string_out;
	}
	if($_SESSION['role_id_expeditor'] == $_SESSION['role_id'])
	{
		$query_order = "SELECT order_id, order_date, client_name, client_surname, client_phone, status_name, count, sum, currency_name FROM \"OrmasSchema\".orders_view WHERE employee_id=".$_SESSION['id']." AND status_name != 'EXECUTED' ORDER BY order_id DESC";	
		$query_return = "SELECT return_id, return_date, client_name, client_surname, client_phone, status_name, count, sum, currency_name FROM \"OrmasSchema\".returns_view WHERE employee_id=".$_SESSION['id']." AND status_name != 'EXECUTED' ORDER BY return_id DESC";			
		$result_order = pg_query($query_order);
		$string_out = "<table id='order-table'><caption>Мои заказы</cation><thead><tr><th>ID заказа</th><th>Дата заказа</th><th>Клиент</th><th>Статус</th><th>Количество</th><th>Сумма</th><th>Валюта</th><th>Действие</th></tr></thead><tbody>";
		while ($row = pg_fetch_array($result_order)) {
			$string_out =$string_out."<tr>";
			$string_out =$string_out."<td>$row[0]</td>";
			$string_out =$string_out."<td>$row[1]</td>";
			$string_out =$string_out."<td>$row[2] $row[3] $row[4]</td>";
			$string_out =$string_out."<td>$row[5]</td>";
			$string_out =$string_out."<td>$row[6]</td>";
			$string_out =$string_out."<td>$row[7]</td>";
			$string_out =$string_out."<td>$row[8]</td>";
			$string_out =$string_out."<td><form method='post'><button class='list-submit' id='execute' name='execute' value='$row[0]' type='submit'>Выполнить</button></form></td>";
			$string_out =$string_out."</tr>";
		}
		$string_out = $string_out."</tbody></table><br/><br/><br/>";
		$result_return = pg_query($query_return);
		$string_out = $string_out."<table id='return-table'><caption>Мои возвраты</cation><thead><tr><th>ID возврата</th><th>Дата возврата</th><th>Клиент</th><th>Статус</th><th>Количество</th><th>Сумма</th><th>Валюта</th><th>Действие</th></tr></thead><tbody>";
		while ($row = pg_fetch_array($result_return)) {
			$string_out =$string_out."<tr>";
			$string_out =$string_out."<td>$row[0]</td>";
			$string_out =$string_out."<td>$row[1]</td>";
			$string_out =$string_out."<td>$row[2] $row[3] $row[4]</td>";
			$string_out =$string_out."<td>$row[5]</td>";
			$string_out =$string_out."<td>$row[6]</td>";
			$string_out =$string_out."<td>$row[7]</td>";
			$string_out =$string_out."<td>$row[8]</td>";
			$string_out =$string_out."<td><form method='post'><button class='list-submit' id='execute_return' name='execute_return' value='$row[0]' type='submit'>Выполнить</button></form></td>";
			$string_out =$string_out."</tr>";
		}
		$string_out = $string_out."</tbody></table>";
		$string_out .= "<script>
			$(document).ready( function () {
				$('#order-table').DataTable();
			});
			$(document).ready( function () {
				$('#return-table').DataTable();
			});
		</script>";
		echo $string_out;
	}
	if($_SESSION['role_id_stock_inspector'] == $_SESSION['role_id'])
	{
		$query_stock = "SELECT stock_id, product_name, count, sum, currency_name, warehouse_name FROM \"OrmasSchema\".stock_view ORDER BY product_name";	
		$result_stock = pg_query($query_stock);
		$string_out = "<table id='stock-table'><caption>Склад</cation><thead><tr><th>ID склада</th><th>Наименование продукта</th><th>Количество</th><th>Сумма</th><th>Валюта</th><th>Название склада</th></tr></thead><tbody>";
		while ($row = pg_fetch_array($result_stock)) {
			$string_out =$string_out."<tr>";
			$string_out =$string_out."<td>$row[0]</td>";
			$string_out =$string_out."<td>$row[1]</td>";
			$string_out =$string_out."<td>$row[2]</td>";
			$string_out =$string_out."<td>$row[3]</td>";
			$string_out =$string_out."<td>$row[4]</td>";
			$string_out =$string_out."<td>$row[5]</td>";
			$string_out =$string_out."</tr>";
		}
		$string_out = $string_out."</tbody></table><br/><br/><br/>";
		$string_out .= "<script>
			$(document).ready( function () {
				$('#stock-table').DataTable();
			});
		</script>";
		echo $string_out;						
	}
?>