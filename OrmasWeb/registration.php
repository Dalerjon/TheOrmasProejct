<?php
	$PageTitle="Регистрация";
	function customPageHeader()
	{
		echo ("<meta http-equiv='Content-Type' content='text/html; charset=utf-8' />");
		echo ("<meta name='keywords' content='Ormas, oreder mamagement system, order' />");
		echo ("<meta name='description' content='Oreder mamagement system registration' />");
		echo ("<meta name='author' content='Main technology Comp.' />");
		echo ("<meta name='robots' content='all' />");
		echo ("<LINK rel='stylesheet' media='screen' type='text/css' title='Style' href='css/registration.css'>");
		echo ("<script type='text/javascript' src='js/jquery-3.2.1.min.js'></script>");
		echo ("<script type='text/javascript' src='js/registration.js'></script>");
	}	
	require_once ('header.php');	
?> 

<?php
	$message_user="";
	$message_phone="";
	$message_address="";
	$message_firm="";
	$message_location="";
	$message_password="";
	if(isset($_POST['name']) && isset($_POST['surname']) && isset($_POST['email']) && isset($_POST['phone']) && isset($_POST['address']) && isset($_POST['firm']) && isset($_POST['password']))
	{
		if(($_POST['name'] == '') || ($_POST['surname'] == '') || ($_POST['email'] == '') || ($_POST['phone'] == '') || ($_POST['address']  == '') || ($_POST['firm'] == '') || ($_POST['password'] == ''))
		{
			unset($_POST['name']);
			unset($_POST['surname']);
			unset($_POST['email']);
			unset($_POST['phone']);
			unset($_POST['address']);
			unset($_POST['firm']);
			unset($_POST['password']);
		}
		else
		{
			//get id
			$id_result = pg_query("SELECT nextval('\"OrmasSchema\".id_seq')");
			$id_row = pg_fetch_array($id_result, null, PGSQL_BOTH);
			if(!empty($id_row[0]))
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
				$id = $id_row[0];
				$insert_result = pg_query("INSERT INTO \"OrmasSchema\".users(user_id, user_name, user_phone, user_address, firm, firm_number, role_id,
				location_id, password, activated) VALUES($id,'$_POST[name]','$_POST[phone]','$_POST[address]', '$_POST[firm]',
				'$_POST[number]', $role_id, $_POST[location], '$_POST[password]', 'f')");
				if($insert_result)
				{
					header("location:index.php?id=$id");
				}
				else
				{
					//error
				}
			}
			else
			{
				//show error
			}
		}
	}
?>

<div id = "content">
	<div id="regis-content">
		<form action="registration.php" method="post">
				<div class='close-bar'>
				</div>
				<div id="regis-main-label">Регистрация</div>
				<div id="regis-row">
					<label id="regis-label">Имя:</label>
					<input name="name" type="text"/>
					<div id="message"><label ></label></div>
				</div>
				<div id="regis-row">
					<label id="regis-label">Фамилия:</label>
					<input name="suurname" type="text"/>
					<div id="message"><label ></label></div>
				</div>
				<div id="regis-row">
					<label id="regis-label">E-mail:</label>
					<input name="email" type="email"/>
					<div id="message"><label ></label></div>
				</div>
				<div id="regis-row">
					<label id="regis-label">Номер телефона:</label>
					<input name="phone" type="text"/>
					<div id="message"><label ></label></div>
				</div>
				<div id="regis-row">
					<label id="regis-label">Адрес:</label>
					<input name="address"  type="text"/>
					<div id="message"><label ></label></div>
				</div id="regis-row">
				<div id="regis-row">
					<label id="regis-label">Название фирмы(магазина):</label>
					<input name="firm" id="firm" type="text"/>
					<div id="message"><label ></label></div>
				</div id="regis-row">
				<div id="regis-row">
					<label id="regis-label">Номер фирмы(магазина):</label>
					<input name="number"  type="text"/>
					<div id="message"><label ></label></div>
				</div id="regis-row">
				<div id="regis-row">
					<label id="regis-label">Регион:</label>
					<select name="location" id="location">
					<?php
						$location_result = pg_query("SELECT * FROM \"OrmasSchema\".locations_view");
						$location_row = pg_fetch_all($location_result);
						if(!empty($location_row[0]))
						{
							$row_count = pg_num_rows($location_result);
							for($i=0;$i<$row_count;$i++)
							{
								echo("<option value='".$location_row[$i]['location_id']."'>".$location_row[$i]['country_name'].", ".$location_row[$i]['region_name'].", ".$location_row[$i]['city_name']."</option>");
							}
						}
					?>
					</select>
					<div id="message"><label ></label></div>
				</div>
				<div id="regis-row">
					<label id="regis-label">Пароль:</label>
					<input name="password" type="password"/>
					<div id="message"><label ></label></div>
				</div>
				<div id="regis-row">
					<div id="button-position">
						<input id="regis-button" type="submit" name="submit" value="Зарегистрироватся"/>
					</div>
				</div>
		</form>
	</div>
</div>
<?php
	require_once('footter.php')
?>