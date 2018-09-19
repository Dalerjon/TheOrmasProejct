<?php
	session_start();
	require_once 'logsql.php';
?>
<?php
	$product_type_result = pg_query("SELECT product_type_id FROM \"OrmasSchema\".product_types_view where product_type_code = 'PRODUCT'");
	$product_type_row = pg_fetch_array($product_type_result);
	$product_result = pg_query("SELECT * FROM \"OrmasSchema\".products_view where product_type_id = ".$product_type_row[0]);
	$product_row = pg_fetch_all($product_result);
	$string_out ="";
	if(!empty($product_row[0]))
	{
	$row_count = pg_num_rows($product_result);
	for($i=0;$i<$row_count;$i++)
	{
		$string_out .= "<option value='".$product_row[$i]['product_id']."'>".$product_row[$i]['product_name']."</option>";
	}
	echo $string_out;
}
?>