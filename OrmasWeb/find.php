<?php
$form_string= "
<div id='form-body'>
	<form method='post'>
		<div id='form-title'>
			<label>Найти по ID</label>
		</div>
		<input type='hidden' name='form_type' value='order'/>
		<div id='form-content'>
			<div class='addable'>
				<div class='close-bar'>
					<!--<div class='close-img'>
					</div>-->
				</div>
				<div class='row'>
					<div class='centering'>
						<label class='float-left form-label'>Введите ID:</label>
						<input class ='form-id' type='text' name='id'/>
					</div>
				</div>
			</div>
		</div>
		<div id='from-submit'>
			<input class='form-submit' type='submit' value='Найти'/>
		<div>
	</form>
</div>";
echo ($form_string);
?>
