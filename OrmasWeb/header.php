<?php
	require_once 'logsql.php';
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
	<head>
		<title><?php echo($PageTitle)?></title>
		<?php 
			if (function_exists('customPageHeader'))
			{
				customPageHeader();
			}
		?>
	</head>
	<body>
		<div id="action-bar">
			<div id="logo">
				<a href="exit.php">ORMAS</a>
			</div>
			<div id="action-bar-wrap">
				<?php 
					if(!empty($_SESSION['name']) and !empty($_SESSION['surname']) and !empty($_SESSION['password']) and !empty($_SESSION['role_id']))
					{
						echo"<div id='user-img-div'></div>";
					}
				?>
				<div id="action-bar-content">
					<?php
						if(!empty($_SESSION['name']) and !empty($_SESSION['surname']) and !empty($_SESSION['password']) and !empty($_SESSION['role_id']))
						{	
							echo("<a href='exit.php'>".$_SESSION['name']." ".$_SESSION['surname']."</a>");
						}
						else
						{
							//if($PageTitle != "Регистрация")
								//echo("<a href='registration.php'>Регистрация</a>");
						}
					?>
				</div>
			</div>
		</div>
