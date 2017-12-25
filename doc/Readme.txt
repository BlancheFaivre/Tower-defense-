************************************************ Pour lancer le projet ******************************************************

- Lancer la solution du projet "Projet_C.sln"
- Ex�cuter le programme


****************************************************** Pour jouer ***********************************************************

INITIALISATION : 

- Vous poss�dez, � l'initialisation du jeu, 20 pi�ces vous permettant d'acheter 2 vaisseaux "LowV" repr�sent�s en vert. 
- Vous pouvez choisir la difficult� que vous voulez - entre 0 et 5 - gr�ce au menu d�roulant "Difficult�".

- Vous devez alors s�lectionner le type de vaisseau que vous voulez poser. S'il vous reste assez de vaisseaux � poser de ce type, vous pouvez les poser sur le damier.
Sinon, un message "Vous n'avez plus ce type de vaisseau, veuillez en acheter" apparait. Il vous suffit de cliquer sur l'�cran pour que le message disparaisse.

- Lorsque vos vaisseaux sont plac�s comme vous le d�sirez, vous pouvez lancer la partie gr�ce au bouton "Lancer la partie" situ� en haut � droite de l'�cran de jeu.
Sinon, vous pouvez enlever les vaisseaux du damier en cliquant dessus, et les replacer.

- La partie s'arr�te dans 3 cas diff�rents : 1 asteroide a touch� l'un de vos vaisseaux / 1 asteroide est arriv� � la fin du damier / tous les asteroides de la vague ont �t� d�truits.
Dans les deux premiers cas vous perdez. Dans le 3e, vous gagnez. En fonction du niveau gagn�, vous remportez un certain nombre de pi�ces qui vous permetteront d'acheter
de nouveaux vaisseaux et de remporter plus facilement les niveaux suivants.


 -----------------------------------------------------------------------------------------------------
 - CONSEIL : Il est n�cessaire de faire au minimum 2 fois chaque niveau avant de passer au suivant,  -
 - cela permet de gagner plus de vaisseaux, et de r�ussir plus facilement les autres niveaux.        -
 -----------------------------------------------------------------------------------------------------



********************************************** D�tail des composantes du jeu ***************************************************

Difficulte :

               * DIFFICULTE 0 : Damier d'une ligne, et une vague de 3 ast�roides (3 LowAsteroides)
               * DIFFICULTE 1 : Damier de 2 lignes, une vague de 4 ast�roides (3 LowAsteroides, 1 StrongAsteroide)
               * DIFFICULTE 2 : Damier de 3 lignes, une vague de 5 ast�roides (2 LowAsteroides, 2 StrongAsteroides, 1 FatAsteroide)
               * DIFFICULTE 3 : Damier de 4 lignes, une vague de 7 asteroides (3 LowAsteroides, 2 StrongAsteroides, 2 FastAsteroides)
               * DIFFICULTE 4 : Damier de 5 lignes, une vague de 15 asteroides (6 LowAsteroides, 6 StrongAsteroides, 3 FastAsteroides)

Vaisseaux et Missiles : 

	       3 types : 
	       - LowV (Fr�quence : 5, Puissance : 1, Vitesse : 8)
	       - MediumV (Fr�quence : 5, Puissance : 2, Vitesse : 10)
	       - SpeedV (Fr�quence : 5, Puissance : 4, Vitesse : 12)

	       > Chaque vaisseau tire des missiles d'une certaine puissance et vitesse, avec une certaine fr�quence.
	       > Plus la vitesse est augment�e, plus le missile se d�place loin � chaque tour de tick().
	       > Plus la puissance est augment�e, plus le missile enl�ve un grand nombre de vies � un ast�roide.


Asteroides : 

	       3 types : 
	       - LowAsteroide (Vies : 10, Vitesse : 2)
	       - StrongAsteroide (Vies : 15, Vitesse : 2)
	       - FastAsteroide (Vies : 9, Vitesse : 3)

	       > Chaque asteroide est cree de fa�on al�atoire sur une des lignes du damier (-> Nombre de ligne qui varie en fonction de la difficulte)
	       > Comme pour les missiles : A chaque fois qu'un missile touche un asteroide il perd un certain nombre de vies.


Argent : 
	       Le joueur poss�de 20 pi�ces � l'intialisation. A la fin du niveau 0, il gagne 10 pi�ces.
	       A la fin du niveau 1, 15 pi�ces. Niveau 2 : 20 pi�ces. Niveau 3 : 25 pi�ces. Niveau 4 : 30 pi�ces.



Score : 
	        Lorsqu'un vaisseau touche un asteroide, le score augmente de 10. Le score maximal est donc de 150, puisque la plus grande vague est de 15 asteroides.
		Si le joueur d�passe le meilleur score au cours du jeu, le meilleur score est modifi�.







