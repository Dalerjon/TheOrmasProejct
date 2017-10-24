<?php
	session_start();
	require_once 'logsql.php';
?>
<?php
	$query = "SELECT balance_id, user_name, balance_value, currency_short_name FROM \"OrmasSchema\".balances_view WHERE user_id=".$_SESSION['id'];			
	$result = pg_query($query);
	$string_out = "<table class='table_common'><caption>Мои баланс</cation><tr><th>Номер счета</th><th>Имя</th><th>Сумма счета</th><th>Валюта</th></tr>";
	while ($row = pg_fetch_array($result)) {
        $string_out =$string_out."<tr>";
		$string_out =$string_out."<td>$row[0]</td>";
		$string_out =$string_out."<td>$row[1]</td>";
		$string_out =$string_out."<td>$row[2]</td>";
		$string_out =$string_out."</tr>";
    }
	$string_out = $string_out."</table>";
	echo $string_out;
?>