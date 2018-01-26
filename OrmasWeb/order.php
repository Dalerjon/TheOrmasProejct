<?php
session_start();
require_once 'logsql.php';

if($_SESSION['role_id_client'] == $_SESSION['role_id'])
{
$product_result = pg_query("SELECT * FROM \"OrmasSchema\".products_view");
$product_row = pg_fetch_all($product_result);
$product_list ="";
if(!empty($product_row[0]))
{
	$row_count = pg_num_rows($product_result);
	for($i=0;$i<$row_count;$i++)
	{
		$product_list .= "<option value='".$product_row[$i]['product_id']."'>".$product_row[$i]['product_name']."</option>";
	}
}

$form_string= "
<div id='form-body'>
	<form method='post'>
		<div id='form-title'>
			<label>Создать заказ</label>
		</div>
		<input type='hidden' name='form_type' value='order'/>
		<input type='hidden' name='client' value=''/>
		<input type='hidden' name='date' value=''/>
		<input type='hidden' name='employee' value=''/>
		<input type='hidden' name='status' value=''/>
		<input type='hidden' name='ordercount' value=''/>
		<input type='hidden' name='sum' value=''/>
		<input type='hidden' name='currency' value=''/>
		<div id='form-content'>
			<div class='addable'>
				<div class='close-bar'>
					<!--<div class='close-img'>
					</div>-->
				</div>
				<div class='row'>
					<div class='float-left'>
						<label class='float-left form-label'>Виберите продукт:</label>
						<select class='form-prod' name='product[]'>
						".$product_list."
						</select>
					</div>
					<div >
						<label class='float-left form-label'>Количество:</label>
						<input class ='form-count' type='text' name='count[]'/>
					</div>
				</div>
			</div>
		</div>
		<div id='form-button'>
			<div id='form-button-content'>
				<div id='form-button-img' class='float-left'>
				</div>
				<div id='form-buttom-text'>
					Добавить еще...
				</div>
			</div>
		</div>
		<div id='from-submit'>
			<input class='form-submit' type='submit' value='Создать'/>
		<div>
	</form>
</div>";
echo ($form_string);
}
if($_SESSION['role_id_expeditor'] == $_SESSION['role_id'])
{
$form_string= "
<div id='form-body'>
	<form method='post'>
		<div id='form-title'>
			<label>Создать заказ</label>
		</div>
		<input type='hidden' name='form_type' value='order'/>
		<input type='hidden' name='date' value=''/>
		<input type='hidden' name='employee' value=''/>
		<input type='hidden' name='status' value=''/>
		<input type='hidden' name='ordercount' value=''/>
		<input type='hidden' name='sum' value=''/>
		<input type='hidden' name='currency' value=''/>
		<div id='form-content'>
			<div class='addable'>
				<div class='close-bar'>
					<!--<div class='close-img'>
					</div>-->
				</div>
				<div class='row'>
					<div class='float-left'>
						<label class='float-left form-label'>Виберите клиента:</label>
						<select class='form-prod' name='client'>
						</select>
					</div>
				</div>
				<div class='row'>
					<div class='float-left'>
						<label class='float-left form-label'>Виберите продукт:</label>
						<select class='form-prod' name='product[]'>
						".$product_list."
						</select>
					</div>
					<div >
						<label class='float-left form-label'>Количество:</label>
						<input class ='form-count' type='text' name='count[]'/>
					</div>
				</div>
			</div>
		</div>
		<div id='form-button'>
			<div id='form-button-content'>
				<div id='form-button-img' class='float-left'>
				</div>
				<div id='form-buttom-text'>
					Добавить еще...
				</div>
			</div>
		</div>
		<div id='from-submit'>
			<input class='form-submit' type='submit' value='Создать'/>
		<div>
	</form>
</div>";
echo ($form_string);
}
?>