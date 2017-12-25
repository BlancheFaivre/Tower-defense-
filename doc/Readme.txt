************************************************ Pour lancer le projet ******************************************************

- Lancer la solution du projet "Projet_C.sln"
- Exécuter le programme


****************************************************** Pour jouer ***********************************************************

INITIALISATION : 

- Vous possédez, à l'initialisation du jeu, 20 pièces vous permettant d'acheter 2 vaisseaux "LowV" représentés en vert. 
- Vous pouvez choisir la difficulté que vous voulez - entre 0 et 5 - grâce au menu déroulant "Difficulté".

- Vous devez alors sélectionner le type de vaisseau que vous voulez poser. S'il vous reste assez de vaisseaux à poser de ce type, vous pouvez les poser sur le damier.
Sinon, un message "Vous n'avez plus ce type de vaisseau, veuillez en acheter" apparait. Il vous suffit de cliquer sur l'écran pour que le message disparaisse.

- Lorsque vos vaisseaux sont placés comme vous le désirez, vous pouvez lancer la partie grâce au bouton "Lancer la partie" situé en haut à droite de l'écran de jeu.
Sinon, vous pouvez enlever les vaisseaux du damier en cliquant dessus, et les replacer.

- La partie s'arrête dans 3 cas différents : 1 asteroide a touché l'un de vos vaisseaux / 1 asteroide est arrivé à la fin du damier / tous les asteroides de la vague ont été détruits.
Dans les deux premiers cas vous perdez. Dans le 3e, vous gagnez. En fonction du niveau gagné, vous remportez un certain nombre de pièces qui vous permetteront d'acheter
de nouveaux vaisseaux et de remporter plus facilement les niveaux suivants.


 -----------------------------------------------------------------------------------------------------
 - CONSEIL : Il est nécessaire de faire au minimum 2 fois chaque niveau avant de passer au suivant,  -
 - cela permet de gagner plus de vaisseaux, et de réussir plus facilement les autres niveaux.        -
 -----------------------------------------------------------------------------------------------------



********************************************** Détail des composantes du jeu ***************************************************

Difficulte :

               * DIFFICULTE 0 : Damier d'une ligne, et une vague de 3 astéroides (3 LowAsteroides)
               * DIFFICULTE 1 : Damier de 2 lignes, une vague de 4 astéroides (3 LowAsteroides, 1 StrongAsteroide)
               * DIFFICULTE 2 : Damier de 3 lignes, une vague de 5 astéroides (2 LowAsteroides, 2 StrongAsteroides, 1 FatAsteroide)
               * DIFFICULTE 3 : Damier de 4 lignes, une vague de 7 asteroides (3 LowAsteroides, 2 StrongAsteroides, 2 FastAsteroides)
               * DIFFICULTE 4 : Damier de 5 lignes, une vague de 15 asteroides (6 LowAsteroides, 6 StrongAsteroides, 3 FastAsteroides)

Vaisseaux et Missiles : 

	       3 types : 
	       - LowV (Fréquence : 5, Puissance : 1, Vitesse : 8)
	       - MediumV (Fréquence : 5, Puissance : 2, Vitesse : 10)
	       - SpeedV (Fréquence : 5, Puissance : 4, Vitesse : 12)

	       > Chaque vaisseau tire des missiles d'une certaine puissance et vitesse, avec une certaine fréquence.
	       > Plus la vitesse est augmentée, plus le missile se déplace loin à chaque tour de tick().
	       > Plus la puissance est augmentée, plus le missile enlève un grand nombre de vies à un astéroide.


Asteroides : 

	       3 types : 
	       - LowAsteroide (Vies : 10, Vitesse : 2)
	       - StrongAsteroide (Vies : 15, Vitesse : 2)
	       - FastAsteroide (Vies : 9, Vitesse : 3)

	       > Chaque asteroide est cree de façon aléatoire sur une des lignes du damier (-> Nombre de ligne qui varie en fonction de la difficulte)
	       > Comme pour les missiles : A chaque fois qu'un missile touche un asteroide il perd un certain nombre de vies.


Argent : 
	       Le joueur possède 20 pièces à l'intialisation. A la fin du niveau 0, il gagne 10 pièces.
	       A la fin du niveau 1, 15 pièces. Niveau 2 : 20 pièces. Niveau 3 : 25 pièces. Niveau 4 : 30 pièces.



Score : 
	        Lorsqu'un vaisseau touche un asteroide, le score augmente de 10. Le score maximal est donc de 150, puisque la plus grande vague est de 15 asteroides.
		Si le joueur dépasse le meilleur score au cours du jeu, le meilleur score est modifié.







