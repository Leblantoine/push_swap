##push_swap

Tri d'une pile avec un nombre limité d'instructions.

###Description

- 2 piles : 'a' et 'b'
- 'b' est vide et 'a' contient un certain nombre de nombres positifs ou négatifs sans doublons
- Le but du jeu est de faire en sorte que 'a' contienne les mêmes nombres mais dans l’ordre croissant.

###Instructions

- sa : swap a - intervertit les 2 premiers éléments au sommet de la pile a. (ne fait rien s’il n’y en a qu’un ou aucun).
- sb : swap b - intervertit les 2 premiers éléments au sommet de la pile b. (ne fait rien s’il n’y en a qu’un ou aucun).
- ss : sa et sb en même temps.
- pa : push a - prend le premier élément au sommet de b et le met sur a. (ne fait rien si b est vide).
- pb : push b - prend le premier élément au sommet de a et le met sur b. (ne fait rien si a est vide).
- ra : rotate a - décale d’une position tous les élements de la pile a. (vers le haut, le premier élément devient le dernier).
- rb : rotate b - décale d’une position tous les élements de la pile b. (vers le haut, le premier élément devient le dernier).
- rr : ra et rb en meme temps.
- rra : reverse rotate a (vers le bas, le dernier élément devient le premier).
- rrb : reverse rotate b (vers le bas, le dernier élément devient le premier).
- rrr : rra et rrb en même temps.

###Résultats

Eléments dans la pile | nombre d'opération
--- | ---
100 | ~ 1 900
500 | ~ 14 000
1 000 | ~ 34 000
10 000 | ~ 490 000
15 000 | ~ 750 000
