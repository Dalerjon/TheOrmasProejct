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
			echo ("<script type='text/javascript' src='js/jquery-3.2.1.min.js'></script>");
			echo ("<script type='text/javascript' src='js/main.js'></script>");
		}	
		require_once ('header.php');	
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