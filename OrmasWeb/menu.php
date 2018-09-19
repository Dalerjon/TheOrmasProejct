<?php
	session_start();
	if(empty($_SESSION['name']) or empty($_SESSION['surname']) or empty($_SESSION['id']) or empty($_SESSION['role_id']))
	{
		header("location:error.php");
	}
	else
	{
		$PageTitle="Ormas";
		function customPageHeader()
		{
			echo ("<meta http-equiv='Content-Type' content='text/html; charset=utf-8' />");
			echo ("<meta name='keywords' content='Ormas, oreder mamagement system, order' />");
			echo ("<meta name='description' content='Oreder mamagement system' />");
			echo ("<meta name='author' content='Main technology Comp.' />");
			echo ("<meta name='robots' content='all' />");
			echo ("<LINK rel='stylesheet' media='screen' type='text/css' title='Style' href='css/menu.css'>");
			echo ("<LINK rel='stylesheet' media='screen' type='text/css' title='Style' href='css/select2.min.css'>");
			echo ("<LINK rel='stylesheet' media='screen' type='text/css' href='css/datatables.min.css'/>");
			echo ("<script type='text/javascript' src='js/jquery-3.2.1.min.js'></script>");
			echo ("<script type='text/javascript' src='js/main.js'></script>");
			echo ("<script type='text/javascript' src='js/select2.min.js'></script>");
			echo ("<script type='text/javascript' src='js/datatables.min.js'></script>");
		}	
		require_once ('header.php');	
	}
?>
<?php
	function GetParentHeadAccID($accID)
	{
		$acc_result = pg_query("SELECT * FROM \"OrmasSchema\".accounts_view WHERE account_id = ".$accID);
		$acc_array = pg_fetch_array($acc_result, null, PGSQL_BOTH);
		if(empty($acc_array))
		{
			return 0;
		}
		$number = 0;
		$headtreechar =0;
		$number = $acc_array['account_number'];
		$headtreechar= substr($number,0,3);
		$headtreechar .= "00";
		$headacc_result = pg_query("SELECT * FROM \"OrmasSchema\".accounts_view WHERE account_number = '".$headtreechar."';");
		$headacc_array = pg_fetch_array($headacc_result, null, PGSQL_BOTH);
		if(empty($headacc_array))
		{
			return 0;
		}
		return $headacc_array['account_id'];
	}
	function GetParentAccID($accID)
	{
		$subacc_result = pg_query("SELECT * FROM \"OrmasSchema\".subaccounts_view WHERE subaccount_id = ".$accID);
		$subacc_array = pg_fetch_array($subacc_result, null, PGSQL_BOTH);
		if(empty($subacc_array))
		{
			return 0;
		}
		return $subacc_array['account_id'];
	}
	function DebitAccount($accID, $value)
	{
		$acc_result = pg_query("SELECT * FROM \"OrmasSchema\".accounts_view WHERE account_id = ".$accID);
		$acc_array = pg_fetch_array($acc_result, null, PGSQL_BOTH);
		if(empty($acc_array))
		{
			return false;
		}
		$sum = $acc_array['current_balance'] + $value;
		$update_acc =  pg_query("UPDATE \"OrmasSchema\".accounts SET current_balance = $sum  WHERE account_id = ".$accID);
		if(!$update_acc)
			return false;
		return true;
	}
	function CreditAccount($accID, $value)
	{
		$acc_result = pg_query("SELECT * FROM \"OrmasSchema\".accounts_view WHERE account_id = ".$accID);
		$acc_array = pg_fetch_array($acc_result, null, PGSQL_BOTH);
		if(empty($acc_array))
		{
			return false;
		}
		$sum = $acc_array['current_balance'] - $value;
		$update_acc =  pg_query("UPDATE \"OrmasSchema\".accounts SET current_balance = $sum  WHERE account_id = ".$accID);
		if(!$update_acc)
			return false;
		return true;
	}
	function DebitSubaccount($accID, $value)
	{
		$acc_result = pg_query("SELECT * FROM \"OrmasSchema\".subaccounts_view WHERE subaccount_id = ".$accID);
		$acc_array = pg_fetch_array($acc_result, null, PGSQL_BOTH);
		if(empty($acc_array))
		{
			return false;
		}
		$sum = $acc_array['current_balance'] + $value;
		$update_acc =  pg_query("UPDATE \"OrmasSchema\".subaccounts SET current_balance = $sum  WHERE subaccount_id = ".$accID);
		if(!$update_acc)
			return false;
		return true;
	}
	function CreditSubaccount($accID, $value)
	{
		$acc_result = pg_query("SELECT * FROM \"OrmasSchema\".subaccounts_view WHERE subaccount_id = ".$accID);
		$acc_array = pg_fetch_array($acc_result, null, PGSQL_BOTH);
		if(empty($acc_array))
		{
			return false;
		}
		$sum = $acc_array['current_balance'] - $value;
		$update_acc =  pg_query("UPDATE \"OrmasSchema\".subaccounts SET current_balance = $sum  WHERE subaccount_id = ".$accID);
		if(!$update_acc)
			return false;
		return true;
	}
	function RecalculateParentDebAcc($debAccID, $value)
	{
		$parentAcc = GetParentHeadAccID($debAccID);
		if ($parentAcc ==0)
			return false;
		$acc_result = pg_query("SELECT * FROM \"OrmasSchema\".accounts_view WHERE account_id = ".$parentAcc);
		$acc_array = pg_fetch_array($acc_result, null, PGSQL_BOTH);
		if(empty($acc_array))
		{
			return false;
		}
		$sum = $acc_array['current_balance'] + $value;
		$row = "UPDATE \"OrmasSchema\".accounts SET current_balance = $sum  WHERE account_id = ".$parentAcc;
		$update_acc =  pg_query("UPDATE \"OrmasSchema\".accounts SET current_balance = $sum  WHERE account_id = ".$parentAcc);
		if(!$update_acc)
			return false;
		return true;
	}
	function RecalculateParentCredAcc($credAccID, $value)
	{
		
		$parentAcc = GetParentHeadAccID($credAccID);
		if ($parentAcc ==0)
			return false;
		$acc_result = pg_query("SELECT * FROM \"OrmasSchema\".accounts_view WHERE account_id = ".$parentAcc);
		$acc_array = pg_fetch_array($acc_result, null, PGSQL_BOTH);
		if(empty($acc_array))
		{
			return false;
		}
		$sum = $acc_array['current_balance'] - $value;
		$update_acc =  pg_query("UPDATE \"OrmasSchema\".accounts SET current_balance = $sum  WHERE account_id = ".$parentAcc);
		if(!$update_acc)
			return false;
		return true;
	}
	function CreateEntryAccountRelationForOrder($entryID,$debAccID)
	{
		$entry_acc_id ="";
		$id_result = pg_query("SELECT nextval('\"OrmasSchema\".id_seq')");
		$id_row = pg_fetch_array($id_result, null, PGSQL_BOTH);
		if(empty($id_row))
		{
			return false;
		}
		$entry_acc_id = $id_row[0];
		$create_entry = pg_query("INSERT INTO \"OrmasSchema\".entry_subaccount(entry_subaccount_id, entry_id, subaccount_id)
				VALUES ($entry_acc_id, $entryID, $debAccID);");
		if(!$create_entry)
			return false;
		return true;
	}
	function CreateEntryAccountRelationForReturn($entryID,$credAccID)
	{
		$entry_acc_id ="";
		$id_result = pg_query("SELECT nextval('\"OrmasSchema\".id_seq')");
		$id_row = pg_fetch_array($id_result, null, PGSQL_BOTH);
		if(empty($id_row))
		{
			return false;
		}
		$entry_acc_id = $id_row[0];
		$create_entry = pg_query("INSERT INTO \"OrmasSchema\".entry_subaccount(entry_subaccount_id, entry_id, subaccount_id)
				VALUES ($entry_acc_id, $entryID, $credAccID);");
		if(!$create_entry)
			return false;
		return true;
	}
	
	function UpdateTransport($orderID)
	{
		$netcost_sum = 0.0;
		$transport_result =  pg_query("SELECT * FROM \"OrmasSchema\".transports_view where employee_id =".$_SESSION['id']);
		$transport_row = pg_fetch_all($transport_result);
		if(empty($transport_row))
		{
			return false;
		}
		$order_list_result = pg_query("SELECT * FROM \"OrmasSchema\".order_list_view where order_id = ".$orderID);
		while ($order_list_row = pg_fetch_array($order_list_result)) {
			if(empty($order_list_row))
			{
				return false;
			}
			$transport_list_result = pg_query("SELECT * FROM \"OrmasSchema\".transport_list_view where transport_id = ".$transport_row[0]['transport_id']." AND product_id=".$order_list_row['product_id']);
			while ($transport_list_row = pg_fetch_array($transport_list_result)) {
				if(empty($transport_list_row))
					{
					return false;
				}
				$net_cost_result = pg_query("SELECT * FROM \"OrmasSchema\".net_cost_view where product_id = ".$order_list_row['product_id']);
				$net_cost_row = pg_fetch_array($net_cost_result);
				if(empty($net_cost_row))
				{
					return false;
				}
				$netcost_sum += $order_list_row['count'] * $net_cost_row['net_cost_value'];
				$update_list_order =  pg_query("UPDATE \"OrmasSchema\".transport_list SET count = ($transport_list_row[count] - $order_list_row[count]), sum = ($transport_list_row[sum] - ($order_list_row[count] * $net_cost_row[net_cost_value]))  WHERE transport_list_id = ".$transport_list_row['transport_list_id']);
				if(!$update_list_order)
				{
					return false;
				}
			}
		}
		if($netcost_sum == 0)
			return false;
		$order_result = pg_query("SELECT * FROM \"OrmasSchema\".orders_view where order_id = ".$orderID);
		$order_row = pg_fetch_all($order_result);
		if(!empty($order_row))
		{
				$acc_10742 = 0;
				$acc_55010 =0;
				//print_r($order_row);
				$acc_result_10742 = pg_query("SELECT * FROM \"OrmasSchema\".accounts_view where account_number = '10742'");
				$acc_row_10742 = pg_fetch_all($acc_result_10742);
				if($acc_row_10742[0]['account_id'])
				{
					$acc_10742 = $acc_row_10742[0]['account_id'];
				}
				$acc_result_55010 = pg_query("SELECT * FROM \"OrmasSchema\".accounts_view where account_number = '55010'");
				$acc_row_55010 = pg_fetch_all($acc_result_55010);
				if($acc_row_55010[0]['account_id'])
				{
					$acc_55010 = $acc_row_55010[0]['account_id'];
				}
				if($acc_10742 != 0 && $acc_55010 != 0)
				{
					if(CreateEntry($acc_55010, $netcost_sum, $acc_10742, 0))
					{
						return true;
					}
				}
		}
		return false;
	}
	
	function UpdateOrder($orderID)
	{
		$order_result = pg_query("SELECT * FROM \"OrmasSchema\".orders_view where order_id = ".$orderID);
		$order_row = pg_fetch_all($order_result);
		if(empty($order_row))
		{
			return false;
		}
		$status_result =  pg_query("SELECT * FROM \"OrmasSchema\".status_view where status_name = 'EXECUTED'");
		$status_row = pg_fetch_all($status_result);
		if(empty($status_row))
		{
			return false;
		}
		
		$current_date_result = pg_query("SELECT \"OrmasSchema\".getcurrentdate()");
		$current_date = pg_fetch_array($current_date_result, null, PGSQL_BOTH);
		if(empty($current_date))
		{
			return false;
		}
		
		$status_id = $status_row[0]['status_id'];
		$date = $current_date[0];
			
		$update_order =  pg_query("UPDATE \"OrmasSchema\".orders SET status_id = $status_id, execution_date = '$date'  WHERE order_id = ".$orderID);
		if(!$update_order)
			return false;
		return true;
	}
	
	function UpdateReturn($returnID)
	{
		$return_result = pg_query("SELECT * FROM \"OrmasSchema\".returns_view where return_id = ".$returnID);
		$return_row = pg_fetch_all($return_result);
		if(empty($return_row))
		{
			return false;
		}
		$status_result =  pg_query("SELECT * FROM \"OrmasSchema\".status_view where status_name = 'EXECUTED'");
		$status_row = pg_fetch_all($status_result);
		if(empty($status_row))
		{
			return false;
		}
		
		$current_date_result = pg_query("SELECT \"OrmasSchema\".getcurrentdate()");
		$current_date = pg_fetch_array($current_date_result, null, PGSQL_BOTH);
		if(empty($current_date))
		{
			return false;
		}
		
		$status_id = $status_row[0]['status_id'];
		$date = $current_date[0];
			
		$update_return =  pg_query("UPDATE \"OrmasSchema\".returns SET status_id = $status_id, execution_date = '$date'  WHERE return_id = ".$returnID);
		if(!$update_return)
		{
			return false;
		}
		return true;
	}
	
	function CreateEntry($debAccID, $sum, $credAccID, $userID)
	{
		$current_date_result = pg_query("SELECT \"OrmasSchema\".getcurrentdate()");
		$current_date = pg_fetch_array($current_date_result, null, PGSQL_BOTH);
		if(empty($current_date))
		{
			return false;
		}
		$date ="";
		$entry_id ="";
		$parentDebAccID =0;
		$parentCredAccID=0;
		if($userID > 0)
		{
			if(GetParentAccID($debAccID) != 0)
			{
				$description= "Товар продан и отгружен клиенту с ID = ".$userID;
			}
			if(GetParentAccID($credAccID) != 0)
			{
				$description= "Возврат товара от клиента с ID = ".$userID;
			}
		}
		else
		{
			$description= "Списание товаров по себестоимости";
		}
		$date = $current_date[0];
		$id_result = pg_query("SELECT nextval('\"OrmasSchema\".id_seq')");
		$id_row = pg_fetch_array($id_result, null, PGSQL_BOTH);
		if(empty($id_row))
		{
			return false;
		}
		$entry_id = $id_row[0];
		$parentDebAccID = GetParentAccID($debAccID);
		$parentCredAccID = GetParentAccID($credAccID);
		if($parentDebAccID == 0)
			$parentDebAccID=$debAccID;
		if($parentCredAccID == 0)
			$parentCredAccID=$credAccID;
		
		if($parentDebAccID == 0 || $parentCredAccID == 0)
			return false;
		
		$create_entry = pg_query("INSERT INTO \"OrmasSchema\".entries(entry_id, entry_date, debiting_account_id, value, crediting_account_id, description)
				VALUES ($entry_id, '$date', $parentDebAccID, $sum, $parentCredAccID, '$description');");
		if(!$create_entry)
			return false;
		if(!DebitAccount($parentDebAccID, $sum) || !CreditAccount($parentCredAccID, $sum))
			return false;
		if(!RecalculateParentDebAcc($parentDebAccID, $sum) || !RecalculateParentCredAcc($parentCredAccID, $sum))
			return false;
		if(GetParentAccID($debAccID) != 0)
		{
			if(!DebitSubaccount($debAccID, $sum))
				return false;
			if(!CreateEntryAccountRelationForOrder($entry_id, $debAccID))
				return false;
		}
		if(GetParentAccID($credAccID) != 0)
		{
			if(!CreditSubaccount($credAccID, $sum))
				return false;
			if(!CreateEntryAccountRelationForReturn($entry_id, $credAccID))
				return false;
		}
		return true;
	}

	$productPrice = Array();
	$product_type_result = pg_query("SELECT product_type_id FROM \"OrmasSchema\".product_types_view where product_type_code = 'PRODUCT'");
    $product_type_row = pg_fetch_array($product_type_result);
	$product_result = pg_query("SELECT * FROM \"OrmasSchema\".products_view where product_type_id = ".$product_type_row[0]);
	$product_row = pg_fetch_all($product_result);
	$product_list ="";
	if(!empty($product_row[0]))
	{
		$row_count = pg_num_rows($product_result);
		for($i=0;$i<$row_count;$i++)
		{
			$product_list .= "<option value='".$product_row[$i]['product_id']."'>".$product_row[$i]['product_name']."</option>";
			$productPrice[$i] = array("id" => $product_row[$i]['product_id'], "price" => $product_row[$i]['price']);
		}
	}
// Logic section
	if(isset($_POST['execute']))
	{
		$start_transaction = pg_query("BEGIN");
		if($start_transaction)
		{
			$order_result = pg_query("SELECT * FROM \"OrmasSchema\".orders_view where order_id = ".$_POST['execute']);
			$order_row = pg_fetch_all($order_result);
			if(!empty($order_row))
			{
				$clinet_acc_id = 0;
				$acc_44010 =0;
				//print_r($order_row);
				$balance_result = pg_query("SELECT * FROM \"OrmasSchema\".balances_view where user_id = ".$order_row[0]['user_id']);
				$balance_row = pg_fetch_all($balance_result);
				if($balance_row[0]['subaccount_id'])
				{
					$clinet_acc_id = $balance_row[0]['subaccount_id'];
				}
				$acc_result = pg_query("SELECT * FROM \"OrmasSchema\".accounts_view where account_number = '44010'");
				$acc_row = pg_fetch_all($acc_result);
				if($acc_row[0]['account_id'])
				{
					$acc_44010 = $acc_row[0]['account_id'];
				}
				if($clinet_acc_id != 0 && $acc_44010 != 0)
				{
					if(CreateEntry($clinet_acc_id, $order_row[0]['sum'], $acc_44010, $order_row[0]['user_id']))
					{
						if(UpdateOrder($order_row[0]['order_id']))
						{
							if(UpdateTransport($order_row[0]['order_id']))
							{
								$commit_transaction = pg_query("COMMIT;");
							}
							else
							{
								echo "<script>alert('У Вас нет некоторых товаров в транспорте или их мало.')</script>";
							}
						}
						else
						{
							echo "<script>alert('Не возможно изменить статус заказа.')</script>";
						}
					}
					else
					{
						echo "<script>alert('Ошибка при создании проводки.')</script>";
					}
				}
				else
				{
					echo "<script>alert('Ошибка счета не найдены.')</script>";
				}
			}
		}
		$rollback_transaction = pg_query("ROLLBACK;");
	}
	
	if(isset($_POST['execute_return']))
	{
		$start_transaction = pg_query("BEGIN");
		if($start_transaction)
		{
			$return_result = pg_query("SELECT * FROM \"OrmasSchema\".returns_view where return_id = ".$_POST['execute_return']);
			$return_row = pg_fetch_all($return_result);
			if(!empty($return_row))
			{
				$clinet_acc_id = 0;
				$acc_10740 =0;
				$balance_result = pg_query("SELECT * FROM \"OrmasSchema\".balances_view where user_id = ".$return_row[0]['user_id']);
				$balance_row = pg_fetch_all($balance_result);
				if($balance_row[0]['subaccount_id'])
				{
					$clinet_acc_id = $balance_row[0]['subaccount_id'];
				}
				$acc_result = pg_query("SELECT * FROM \"OrmasSchema\".accounts_view where account_number = '10740'");
				$acc_row = pg_fetch_all($acc_result);
				if($acc_row[0]['account_id'])
				{
					$acc_10740 = $acc_row[0]['account_id'];
				}
				if($clinet_acc_id != 0 && $acc_10740 != 0)
				{
					if(CreateEntry($acc_10740, $return_row[0]['sum'], $clinet_acc_id, $return_row[0]['user_id']))
					{
						if(UpdateReturn($return_row[0]['return_id']))
						{
							$commit_transaction = pg_query("COMMIT;");
						}
						else
						{
							echo "<script>alert('Не возможно изменить статус возврата.')</script>";
						}
					}
					else
					{
						echo "<script>alert('Ошибка при создании проводки.')</script>";
					}
				}
				else
				{
					echo "<script>alert('Ошибка счета не найдены.')</script>";
				}
			}
		}
		$rollback_transaction = pg_query("ROLLBACK;");
	}

	if($_SESSION['role_id_client'] == $_SESSION['role_id'])
	{
		if(isset($_POST['product']) && isset($_POST['count']))
		{
			
		}
	}
	if($_SESSION['role_id_expeditor'] == $_SESSION['role_id'])
	{
		if(isset($_POST['value']) && $_POST['value'] > 0 && isset($_POST['status']) && isset($_POST['selected_clinet']) &&
		isset($_POST['currency']))
		{
			$id_result = pg_query("SELECT nextval('\"OrmasSchema\".id_seq')");
			$id_row = pg_fetch_array($id_result, null, PGSQL_BOTH);
			if(!empty($id_row[0]))
			{
				$payment_id = $id_row[0];
				$current_date_result = pg_query("SELECT \"OrmasSchema\".getcurrentdate()");
				$current_date = pg_fetch_array($current_date_result, null, PGSQL_BOTH);
				$start_transaction = pg_query("BEGIN");
				if($start_transaction)
				{
					$insert_payment_result =  pg_query("INSERT INTO \"OrmasSchema\".payments(payment_id, payment_date, payment_value,
								user_id, currency_id, status_id) VALUES($payment_id, '$current_date[0]',
								$_POST[value], $_POST[selected_clinet], $_POST[currency], $_POST[status])");
					if($insert_payment_result)
					{
						$insert_payment_employee_result = pg_query("INSERT INTO \"OrmasSchema\".payment_employee(payment_employee_id,
								payment_id, employee_id) VALUES((SELECT nextval('\"OrmasSchema\".id_seq')), $payment_id,
								$_SESSION[id])");
						if($insert_payment_employee_result)
						{
							echo ("<script>alert(\"Оплата прошла успешно!\")</script>");
							$commit_transaction = pg_query("COMMIT;");
						}
						else
						{
							echo ("<script>alert(\"Ошибка оплаты!\")</script>");
							$rollback_transaction = pg_query("ROLLBACK;");
						}
					}
					else
					{
						echo ("<script>alert(\"Оплата прошла успешно!\")</script>");
						$rollback_transaction = pg_query("ROLLBACK;");
					}						
				}
			}
		}
		
		if(isset($_POST['product']) && isset($_POST['count']) && isset($_POST['selected_clinet']))
		{
			$id_result = pg_query("SELECT nextval('\"OrmasSchema\".id_seq')");
			$id_row = pg_fetch_array($id_result, null, PGSQL_BOTH);
			if(!empty($id_row[0]))
			{
				$start_transaction = pg_query("BEGIN");
				if($start_transaction)
				{
					if($_POST['form_type'] == "order")
					{
						$order_id = $id_row[0];
						if(count($_POST['product']) == count($_POST['count']))
						{
							for($i =0; $i<count($_POST['product']); $i++)
							{
								$key = array_search($_POST['product'][$i], array_column($productPrice, 'id'));
								$needed_array = $productPrice[$key];
								$sum = $needed_array['price'] * $_POST['count'][$i];
								$product_current_id = $_POST['product'][$i];
								$count_current = $_POST['count'][$i];
								$insert_order_list_result = pg_query("INSERT INTO \"OrmasSchema\".order_list(order_list_id, order_id, product_id, count,
								sum, status_id, currency_id) VALUES((SELECT nextval('\"OrmasSchema\".id_seq')), $order_id, 
								$product_current_id, $count_current , $sum, $_POST[status], $_POST[currency])
								");
								if(!$insert_order_list_result)
								{
									$rollback_transaction = pg_query("ROLLBACK;");
									break;
								}
							}
							$current_date_result = pg_query("SELECT \"OrmasSchema\".getcurrentdate()");
							$current_date = pg_fetch_array($current_date_result, null, PGSQL_BOTH);
							$insert_order_result = pg_query("INSERT INTO \"OrmasSchema\".orders(order_id,user_id, order_date, execution_date, employee_id,
									 count, sum, status_id, currency_id) VALUES($order_id, $_POST[selected_clinet],'$current_date[0]',
									 NULL, $_POST[employee], $_POST[ordercount], $_POST[sum] ,$_POST[status], $_POST[currency])");
							if(!$insert_order_result)
							{
								$rollback_transaction = pg_query("ROLLBACK;");
							}
							$commit_transaction = pg_query("COMMIT;");
						}
					}
					else if($_POST['form_type'] == "return")
					{
						$return_id = $id_row[0];
						if(count($_POST['product']) == count($_POST['count']))
						{
							for($i =0; $i<count($_POST['product']); $i++)
							{
								$key = array_search($_POST['product'][$i], array_column($productPrice, 'id'));
								$needed_array = $productPrice[$key];
								$sum = $needed_array['price'] * $_POST['count'][$i];
								$product_current_id = $_POST['product'][$i];
								$count_current = $_POST['count'][$i];
								$insert_return_list_result = pg_query("INSERT INTO \"OrmasSchema\".return_list(return_list_id, return_id, product_id, count,
								sum, status_id, currency_id) VALUES((SELECT nextval('\"OrmasSchema\".id_seq')), $return_id, 
								$product_current_id, $count_current , $sum, $_POST[status], $_POST[currency])
								");
								if(!$insert_return_list_result)
								{
									$rollback_transaction = pg_query("ROLLBACK;");
								}
							}
							$current_date_result = pg_query("SELECT \"OrmasSchema\".getcurrentdate()");
							$current_date = pg_fetch_array($current_date_result, null, PGSQL_BOTH);
							$insert_return_result = pg_query("INSERT INTO \"OrmasSchema\".returns(return_id,user_id, return_date, execution_date, employee_id,
									 count, sum, status_id, currency_id) VALUES($return_id, $_POST[selected_clinet],'$current_date[0]',
									 NULL, $_POST[employee], $_POST[returncount], $_POST[sum] ,$_POST[status], $_POST[currency])");
							if(!$insert_return_result)
							{
								$rollback_transaction = pg_query("ROLLBACK;");
							}
							$commit_transaction = pg_query("COMMIT;");
						}
					}
				}
			}
		}
	}
?>
<div id="main-content">
		<div id="menu">
		<?php
			if($_SESSION['role_id'] == $_SESSION['role_id_client'])
			{
				require_once ('client.php');
			}
			if($_SESSION['role_id'] == $_SESSION['role_id_expeditor'])
			{
				require_once ('expeditor.php');
			}
		?>
		</div>
		<div id="content-body">
			<div id="ajax-content">
			</div>
		</div>
	</div>

<?php
	require_once('footter.php')
?>