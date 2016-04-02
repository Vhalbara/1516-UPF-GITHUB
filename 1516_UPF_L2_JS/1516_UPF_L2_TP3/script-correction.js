function init() //onload de la page html
	{
	joueur="x";	//flag du joueur qui doit jouer
	fini=false;		//flag pour savoir si le jeu est fini
	coups=0;		//compteur
	
	$("img").attr("src","img/gris.gif");	//on affiche gris
	$("img").attr("name","vide");		//on met le name  qui correspond
	$("#affichage").text("Joueur "+joueur+", à vous de jouer..."); //on affiche qui doit jouer
	}

$(document).ready(function(){
  $("img").click(function(){ //à chaque clic sur une image
	if(fini) 
		{
		if(confirm("Le jeu est fini, Voulez vous recommencer!!!")) init();
		}
	else
		{
			if($(this).attr("name")=="vide")
				{
					$(this).attr("src","img/"+joueur+".gif");
					$(this).attr("name",joueur);
					coups++;
		
					if (
						(($("#case00").attr("name")==joueur)&&($("#case01").attr("name")==joueur)&&($("#case02").attr("name")==joueur))||
						(($("#case10").attr("name")==joueur)&&($("#case11").attr("name")==joueur)&&($("#case12").attr("name")==joueur))||
						(($("#case20").attr("name")==joueur)&&($("#case21").attr("name")==joueur)&&($("#case22").attr("name")==joueur))||
						(($("#case00").attr("name")==joueur)&&($("#case10").attr("name")==joueur)&&($("#case20").attr("name")==joueur))||
						(($("#case01").attr("name")==joueur)&&($("#case11").attr("name")==joueur)&&($("#case21").attr("name")==joueur))||
						(($("#case02").attr("name")==joueur)&&($("#case12").attr("name")==joueur)&&($("#case22").attr("name")==joueur))||
						(($("#case00").attr("name")==joueur)&&($("#case11").attr("name")==joueur)&&($("#case22").attr("name")==joueur))||
						(($("#case02").attr("name")==joueur)&&($("#case11").attr("name")==joueur)&&($("#case20").attr("name")==joueur))
						) 	if (confirm("BRAVO, Le Joueur "+joueur+" a gagne... Voulez vous recommencer??")) init();
							else fini=true;
					else //sinon change le joueur
						if (coups==9) 
							{
							if (confirm("Plus de cases de libres, Le jeu est fini, Voulez vous recommencer!!!")) init();
							else fini=true;
							}
						else
							{
							if (joueur=="x") joueur="o"; else joueur="x"; //change le joueur
							$("#affichage").text("Joueur "+joueur+", à vous de jouer...");  //nouvel affichage
							}
				}
				else alert("Case deja jouee: joueur "+joueur+ " recommencez..."); 
		}
	});
});


