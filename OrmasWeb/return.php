<?php
$form_string= "
<div id='form-body'>
	<form method='post'>
		<div id='form-title'>
			<label>Создать возврат</label>
		</div>
		<input type='hidden' name='form_type' value='return'/>
		<input type='hidden' name='client' value=''/>
		<input type='hidden' name='date' value=''/>
		<input type='hidden' name='worker' value=''/>
		<input type='hidden' name='status' value=''/>
		<input type='hidden' name='returncount' value=''/>
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
?>