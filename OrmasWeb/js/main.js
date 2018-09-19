$(document).ready(function(){              
    //init load
	$.ajax({
	type: 'POST',
	url: '/list.php',
	success: function(data){
		$('#ajax-content').html(data);
	}
    });
	
	$('#show-list').addClass('current');
	
	//add additional html
	$('#ajax-content').on('click','#form-button-content',function(){
		function collback(options){
			var html = "<div class='addable'> \
						<div class='close-bar'> \
							<div class='close-img'> \
							</div> \
						</div> \
						<div class='row'>\
							<div class='float-left'>\
								<label class='float-left form-label'>Виберите продукт:</label>\
								<select class='form-prod' name='product[]'>";
							html = html	+ options;
							html = html +	"</select>\
							</div>\
							<div >\
								<label class='float-left form-label'>Количество:</label>\
								<input class ='form-count' type='number' name='count[]'/>\
							</div>\
						</div>\
					</div>";
			$('#form-content').append(html);
			$('#form-content .form-prod').each(function(i, obj) {
				$( this ).select2({
				placeholder: '',
				allowClear: false
				});
				//console.log(i);
			});
		}
		$.ajax({type: 'POST',	url: '/product_list.php', success: function(data){ collback(data);}});
	});
	
	//delete additional html
	$('#ajax-content').on('click','.close-img',function(){
		$(this).parent().parent().empty();
	});
	//chage by click 
	
	//create order
	$('#create-order').on('click',function(){
		$('div').removeClass('current');
		$('#create-order').addClass('current');
		$('#ajax-content').empty();
		//ajax call
		$.ajax({
			type: 'POST',
			url: '/order.php',
			success: function(data){
				$('#ajax-content').html(data);
			}
		});
		//ajax call
		$.ajax({
			type: 'POST',
			url: '/load_clients.php',
			success: function(data){
				$('#select-clinets').html(data);
			}
		});
	});
	
	//create return
	$('#create-return').on('click',function(){
		$('div').removeClass('current');
		$('#create-return').addClass('current');
		$('#ajax-content').empty();
		//ajax call
		$.ajax({
			type: 'POST',
			url: '/return.php',
			success: function(data){
				$('#ajax-content').html(data);
			}
		});
	});
	
	//show list
	$('#show-list').on('click',function(){
		$('div').removeClass('current');
		$('#show-list').addClass('current');
		$('#ajax-content').empty();
		//ajax call
		$.ajax({
			type: 'POST',
			url: '/list.php',
			success: function(data){
				$('#ajax-content').html(data);
			}
		});
	});
	
	//search element
	$('#search-element').on('click',function(){
		$('div').removeClass('current');
		$('#search-element').addClass('current');
		$('#ajax-content').empty();
		//ajax call
		$.ajax({
			type: 'POST',
			url: '/find.php',
			success: function(data){
				$('#ajax-content').html(data);
			}
		});
	});
	
	//transport element
	$('#transport').on('click',function(){
		$('div').removeClass('current');
		$('#transport').addClass('current');
		$('#ajax-content').empty();
		//ajax call
		$.ajax({
			type: 'POST',
			url: '/transport.php',
			success: function(data){
				$('#ajax-content').html(data);
			}
		});
	});
	
	//my balance
	$('#balance').on('click',function(){
		$('div').removeClass('current');
		$('#balance').addClass('current');
		$('#ajax-content').empty();
		//ajax call
		$.ajax({
			type: 'POST',
			url: '/my_balance.php',
			success: function(data){
				$('#ajax-content').html(data);
			}
		});
	});
	
	//clients balances
	$('#clients-balance').on('click',function(){
		$('div').removeClass('current');
		$('#clients-balance').addClass('current');
		$('#ajax-content').empty();
		//ajax call
		$.ajax({
			type: 'POST',
			url: '/clients_balance.php',
			success: function(data){
				$('#ajax-content').html(data);
			}
		});
	});
	
	//my expeditor
	$('#expeditor').on('click',function(){
		$('div').removeClass('current');
		$('#expeditor').addClass('current');
		$('#ajax-content').empty();
		//ajax call
		$.ajax({
			type: 'POST',
			url: '/my_expeditor.php',
			success: function(data){
				$('#ajax-content').html(data);
			}
		});
	});
	
	//my clients
	$('#clients').on('click',function(){
		$('div').removeClass('current');
		$('#clients').addClass('current');
		$('#ajax-content').empty();
		//ajax call
		$.ajax({
			type: 'POST',
			url: '/my_clients.php',
			success: function(data){
				$('#ajax-content').html(data);
			}
		});
	});
	
	//payment
	$('#payment').on('click',function(){
		$('div').removeClass('current');
		$('#payment').addClass('current');
		$('#ajax-content').empty();
		//ajax call
		$.ajax({
			type: 'POST',
			url: '/payment.php',
			success: function(data){
				$('#ajax-content').html(data);
			}
		});
	});
	
});

function Calculate(type)
{
	var jsonObject = JSON.parse(document.getElementsByName('prices')[0].value);
	var productObjects = document.getElementsByClassName('form-prod');
	var countObjects = document.getElementsByClassName('form-count');
	var totalCount;
	var totalSum;
	if(productObjects.length == countObjects.length)
	{
		totalCount = Number(0);
		totalSum = Number(0.0);
		for(i=0; i < productObjects.length; i++)
		{
			totalCount += Number(countObjects[i].value);
			jsonObject.forEach(function(item, j, jsonObject) {
				if(item.id == productObjects[i].value)
				{
					totalSum += Number(Number(item.price)*Number(countObjects[i].value));
				}
			});
		}
	}
	document.getElementById('sum').value = Math.round(totalSum * 100)/100;
	if(type == "Order")
	{
		document.getElementById('ordercount').value = Math.round(totalCount* 100)/100;
	}
	if(type == "Return")
	{
		document.getElementById('returncount').value = Math.round(totalCount* 100)/100;
	}
}

//submit form
function SubmitOrderForm()
{
	Calculate("Order");
	var exitStatus = false;
	if($("#selected-clinet").val() == null)
	{
		alert("Поле 'Клиент' не может быть пустым!");
		exitStatus = true;
	}
	$('#form-content .form-count').each(function(i, obj) {
				if($( this ).val().length == 0 || $( this ).val() == 0)
				{
					alert("Поле 'Количество' не может быть пустым или равно быть нулью!");
					exitStatus = true;
				}
			});
	if(exitStatus)
		return false;
	$("#ajax-content").hide();
	
	html = "<div id='accept-form'>\
	<div id='form-title'>\
		<label>Ваш заказ</label>\
	</div>";
	
	var count = new Array();
	var prod = new Array();
	$('#form-content .form-prod').each(function(i, obj) {
				prod.push($(obj[i]).text());
			});
	$('#form-content .form-count').each(function(i, obj) {
				count.push($( this ).val());
			});
	
	var divForAdd = ""
	if(prod.length == count.length)
	{
		var i;
		for(i = 0; i < prod.length; i++)
		{
			divForAdd += "<div class='row'>";
			divForAdd += "<label class='float-left approve-label'>"+prod[i]+"</label>";
			divForAdd += "<label class='approve-label'>"+count[i]+"</label>";
			divForAdd += "</div>";
		}
	}
	
	html += divForAdd;
	html +="<div class= 'row'>\
				<label class='float-left form-label'>На сумму:</label>\
				<label id='sum-lb' class='float-left approve-price'>";
	html += $("#sum").val() == null ? 0 : $("#sum").val();
	html +="</label> <label class='float-left form-label'>Сомони</label>\
		</div>\
		<div class= 'row'>\
		</div>\
		<div class= 'row'>\
			<input class='accept-submit float-left' type='button' value='Назад' onclick='CancelForm()' id='can-button' />\
			<input class='accept-submit' type='submit' value='Подтвердить' onclick='ApproveOrderForm()' id='app-button' />\
		</div>\
	</div>";
	$("#content-body").append(html);
}

function SubmitReturnForm()
{
	Calculate("Return");
	var exitStatus = false;
	if($("#selected-clinet").val() == null)
	{
		alert("Поле 'Клиент' не может быть пустым!");
		exitStatus = true;
	}
	$('#form-content .form-count').each(function(i, obj) {
				if($( this ).val().length == 0 || $( this ).val() == 0)
				{
					alert("Поле 'Количество' не может быть пустым или равно быть нулью!");
					exitStatus = true;
				}
			});
	if(exitStatus)
		return false;
	$("#ajax-content").hide();
	
	html = "<div id='accept-form'>\
	<div id='form-title'>\
		<label>Список возврата</label>\
	</div>";
	
	var count = new Array();
	var prod = new Array();
	$('#form-content .form-prod').each(function(i, obj) {
				prod.push($(obj[i]).text());
			});
	$('#form-content .form-count').each(function(i, obj) {
				count.push($( this ).val());
			});
	
	var divForAdd = ""
	if(prod.length == count.length)
	{
		var i;
		for(i = 0; i < prod.length; i++)
		{
			divForAdd += "<div class='row'>";
			divForAdd += "<label class='float-left approve-label'>"+prod[i]+"</label>";
			divForAdd += "<label class='approve-label'>"+count[i]+"</label>";
			divForAdd += "</div>";
		}
	}
	
	html += divForAdd;
	html +="<div class= 'row'>\
				<label class='float-left form-label'>На сумму:</label>\
				<label id='sum-lb' class='float-left approve-price'>";
	html += $("#sum").val() == null ? 0 : $("#sum").val();
	html +="</label> <label class='float-left form-label'>Сомони</label>\
		</div>\
		<div class= 'row'>\
		</div>\
		<div class= 'row'>\
			<input class='accept-submit float-left' type='button' value='Назад' onclick='CancelForm()' id='can-button' />\
			<input class='accept-submit' type='submit' value='Подтвердить' onclick='ApproveReturnForm()' id='app-button' />\
		</div>\
	</div>";
	$("#content-body").append(html);
}

function CancelForm()
{
	$("#accept-form").remove();
	$("#ajax-content").show();
}

function ApproveOrderForm()
{
	document.getElementById("order-form").submit();
}

function ApproveReturnForm()
{
	document.getElementById("return-form").submit();
}

