<?php
	$PageTitle="Ormas";
	function customPageHeader()
	{
		echo ("<meta http-equiv='Content-Type' content='text/html; charset=utf-8' />");
		echo ("<meta name='keywords' content='Ormas, oreder mamagement system, order' />");
		echo ("<meta name='description' content='Oreder mamagement system' />");
		echo ("<meta name='author' content='Main technology Comp.' />");
		echo ("<meta name='robots' content='all' />");
		echo ("<LINK rel='stylesheet' media='screen' type='text/css' title='Style' href='css/mainstyle.css'>");
	}	
	require_once ('header.php');	
?> 


<?php
if(!empty($_SESSION['phonmail']) and !empty($_SESSION['id']) and !empty($_SESSION['role']))
    {
        $login    = $_SESSION['phonmail'];
		$role = $_SESSION['role'];
		$id = $_SESSION['id'];
	}
	 $message="";
?>

<?php
	if (isset($_GET['id']))
	{
		if($_GET['id'] != 0)
		{
			$user_result = pg_query("SELECT * FROM \"OrmasSchema\".users_view WHERE user_id=$_GET[id]");
			$user_row = pg_fetch_array($user_result, null, PGSQL_BOTH);
			if(!empty($user_row[0]))
			{
				$message = "Вы успешно зарегистрированы! Ваш ID: $_GET[id], ждите активации.";
			}
		}
	}
?>
<?php
if (isset($_POST['phonmail']) && isset($_POST['password'])) 
{ 
	$login = $_POST['phonmail']; 
    $password=$_POST['password'];
   
	if ($login == '' && $password =='')
	{unset($login); unset($password); }
	if (empty($login) or empty($password))
    {    
		$message="Вы ввели не всю информацию!";
    }
    else
	{
		$login = stripslashes($login);
		$login = htmlspecialchars($login);
		$password = stripslashes($password);
		$password = htmlspecialchars($password);
		//удаляем лишние пробелы
		$login = trim($login);
		$password = trim($password);

		$query = "SELECT * FROM \"OrmasSchema\".users_view WHERE phone='$login' OR email='$login'";
		$result = pg_query($query); //извлекаем из базы все данные о пользователе с введенным логином
	
		$user_row = pg_fetch_array($result, null, PGSQL_BOTH);
	
		if (empty($user_row[1]))
		{  
			$message="Введённый Вами номер телефона, e-mail или пароль неверный.";
		}
		else 
		{
      		if ($user_row['password']==$password) 
			{
   		 		if($user_row['activated'] == 't')
				{
					$_SESSION['login']=$user_row['user_name']; 
					$_SESSION['id']=$user_row['user_id'];
					$_SESSION['role']=$role_row['role_name'];
					header("location:menu.php");
				}
				else
				{
					$message = "Ваш акаунт не активирован, ждите активации.";	
				}
			}
 			else {
   				$message = "Извините, введённый Вами номер телефона, e-mail или пароль неверный!";
			}
		}	
	}
}
?>

<div id = "content">
	<div id="login">
		<div id="login-logo">
		</div>
		<div id="login-content">
			<form action="index.php" method="post">
				<p>
					<label>E-mail или номер тел.:<br></label>
					<input name="phonmail" type="text" placeholder="Например: 927771122"> 
				</p>
				<p>
					<label>Пароль:<br></label>
					<input name="password" type="password" >
				</p>
				<p>
				<input id="submit" type="submit" name="submit" value="Войти"/>
				<br>
			</form>
		</div>
		<div id="message">
			<span><?php echo $message?></span>
		</div>
	</div>
</div>
<?php
	require_once('footter.php')
?>