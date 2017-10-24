<?php
require_once ('header.php');
?>
		<div id= "content">
			<div id="menu">
				<div id="menu-tab">
					<div id="menu-header"><h1>Заказы</h1></div>
					<div id="h-separator-slim"></div>
					<div id="menu-item"><a href="client.php">Мои последние заказы</a></div>
					<div id="menu-item"><a href="client.php">Создать заказ</a></div>
					<div id="menu-item"><a href="client.php">Удалить заказ по ID</a></div>
					<div id="menu-item"><a href="client.php">Обновить заказ по ID</a></div>
				</div>
				<div id="menu-tab">
					<div id="menu-header"><h1>Возвраты</h1></div>
					<div id="h-separator-slim"></div>
					<div id="menu-item"><a href="client.php">Посмотреть все возвраты</a></div>
					<div id="menu-item"><a href="client.php">Создать возврат</a></div>
					<div id="menu-item"><a href="client.php">Удалить возврат</a></div>
					<div id="menu-item"><a href="client.php">Обновить возврат по ID</a></div>
				</div>
			</div>
			<div id="work-panel">
				<?php
					if(empty($_GET) || $_GET['action'] == "all_orders")
					{
						echo("<div id=\"view\">
						<table id =\"main-table\">
							<>
						</table>
						</div>
						<div id=\"commands\">
						</div>");
					}
				?>
			</div>
		</div>
<?php
	require_once('footter.php')
?>