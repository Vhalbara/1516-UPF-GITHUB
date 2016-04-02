//montrer les flèches si on est sur la photo
$(document).ready(function(){
  $(".main").mouseover(function(){
	$(".arrow").css("visibility","visible");
  });
});
//cacher les flèches si on est pas sur la photo
$(document).ready(function(){
  $(".main").mouseout(function(){
	$(".arrow").css("visibility","hidden");
  });
});

//gestion de la transparence des points en bas
indice=0; // indice de la photo affichée, au départ c'est la photo0


//lorsque l'on clique sur la fleche de gauche
$(document).ready(function(){
  $("#left").click(function(){
	if (indice==0) indice=4;
	else indice-=1;
	affiche(indice);
  });
});

//lorsque l'on clique sur la fleche de droite
$(document).ready(function(){
  $("#right").click(function(){
	indice=(indice+1)%5;
	affiche(indice);
  });
});


function affiche(N){  
	$("#dot0,#dot1,#dot2,#dot3,#dot4").css("opacity","0.5"); // on estompe tous les points
	$("#dot"+N).css("opacity","1");
	
	//animate sur les images du milieu
	$("#photo"+N).animate({left:'0px'});
	$("#photo"+((N+1)%5)).animate({left:'600px'});
	$("#photo"+((N+4)%5)).animate({left:'-600px'});
	//mais pas sur les extrêmes
	$("#photo"+((N+2)%5)).css("left","1200px");
	$("#photo"+((N+3)%5)).css("left","-1200px");	
}

//lorsque l'on clique sur un des points en bas
$(document).ready(function(){
  $("#dot0").click(function(){
	indice=0;
	affiche(indice);
  });
});

$(document).ready(function(){
  $("#dot1").click(function(){
	indice=1;
	affiche(indice);
  });
});
$(document).ready(function(){
  $("#dot2").click(function(){
	indice=2;
	affiche(indice);
  });
});
$(document).ready(function(){
  $("#dot3").click(function(){
	indice=3;
	affiche(indice);
  });
});
$(document).ready(function(){
  $("#dot4").click(function(){
	indice=4;
	affiche(indice);
  });
});









