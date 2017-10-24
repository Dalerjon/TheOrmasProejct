<?php
	if(empty($_SESSION['login']) or empty($_SESSION['password']) or empty($_SESSION['role']) or $_SESSION['role'] != "CLIENT")
	{
		header("location:error.php");
	}
	else
	{
		$role_result = pg_query("SELECT * FROM \"OrmasSchema\".roles_view WHERE role_name='CLIENT'");
		$role_row = pg_fetch_array($role_result, null, PGSQL_BOTH);
		if(!empty($role_row[0]))
		{
			$role_id = $role_row['role_id'];
		}
		else
		{
			$role_id =0;
		}
		$PageTitle="Ormas";
		function customPageHeader()
		{
			echo ("<meta http-equiv='Content-Type' content='text/html; charset=utf-8' />");
			echo ("<meta name='keywords' content='Ormas, oreder mamagement system, order' />");
			echo ("<meta name='description' content='Oreder mamagement system' />");
			echo ("<meta name='author' content='Main technology Comp.' />");
			echo ("<meta name='robots' content='all' />");
			echo ("<LINK rel='stylesheet' media='screen' type='text/css' title='Style' href='css/menu.css'>");
			echo ("<script type='text/javascript' src='js/jquery-3.2.1.min.js'></script>");
			echo ("<script type='text/javascript' src='js/main.js'></script>");
		}	
		require_once ('header.php');	
	}
?>
<div id="main-content">
		<div id="menu">
			<div id="items">
				<div class = "pannel-block">
					<div class="pannel" id="create-order">
						<div id="order-img"></div>
						<label class= "for-pannel">Создать заказ</label>
					</div>
					<div class="pannel" id="create-return">
						<div id="return-img"></div>
						<label class= "for-pannel">Создать возврат</label>
					
					</div>
				</div>
				<div class = "pannel-block">
					<div class="pannel" id="show-list">
						<div id="list-img"></div>
						<label class= "for-pannel">Список</label>
					</div>
					<div class="pannel" id="search-element">
						<div id="find-img"></div>
						<label class= "for-pannel">Поиск по ID</label>
					
					</div>
				</div>
				<div class = "pannel-block">
					<div class="pannel" id="balance">
						<div id="balance-img"></div>
						<label class= "for-pannel">Мой баланс</label>
					
					</div>
					<div class="pannel" id="expeditor">
						<div id="expeditor-img"></div>
						<label class= "for-pannel">Экспедитор</label>
					
					</div>
				</div>
				<div class = "pannel-block">
					<div class="pannel" id="price">
						<div id="price-img"></div>
						<label class= "for-pannel">Цены</label>
					
					</div>
				</div>
				<!--<div class = "pannel-block">
					<div class="pannel" id="delete-order">
						<div id="del-order-img"></div>
						<label class= "for-pannel">Удалить заказ</label>
					
					</div>
					<div class="pannel" id="delete-return">
						<div id="del-return-img"></div>
						<label class= "for-pannel">Удалить возврат</label>
					
					</div>
				</div>-->
			</div>
		</div>
		<div id="content-body">
			<div id="ajax-content">
			</div>
		</div>
	</div>
<?php
	require_once('footter.php')
?>