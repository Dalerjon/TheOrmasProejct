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
		var html = "<div class='addable'> \
						<div class='close-bar'> \
							<div class='close-img'> \
							</div> \
						</div> \
						<div class='row'>\
							<div class='float-left'>\
								<label class='float-left form-label'>Виберите продукт:</label>\
								<select class='form-prod' name='product[]'>\
								</select>\
							</div>\
							<div >\
								<label class='float-left form-label'>Количество:</label>\
								<input class ='form-count' type='text' name='count[]'/>\
							</div>\
						</div>\
					</div>";
		$('#form-content').append(html);
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
	
	//delete-order
	$('#balance').on('click',function(){
		$('div').removeClass('current');
		$('#delete-order').addClass('current');
		$('#ajax-content').empty();
		//ajax call
		$.ajax({
			type: 'POST',
			url: '/balance.php',
			success: function(data){
				$('#ajax-content').html(data);
			}
		});
	});
	
	//delete return
	$('#expeditor').on('click',function(){
		$('div').removeClass('current');
		$('#delete-return').addClass('current');
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
	
});

