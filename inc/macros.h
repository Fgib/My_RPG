/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** macros
*/

#define BANNER1 get_intrect(586 , 186, 185, 266)
#define BANNER2 get_intrect(336 , 0, 186, 394)
#define BARREL1 get_intrect(0 , 392, 231, 296)
#define BARREL2 get_intrect(0 , 623, 231, 296)
#define BARREL3 get_intrect(0 , 854, 231, 296)
#define CRATE get_intrect(336 , 186, 218, 250)
#define POT1 get_intrect(296 , 585, 181, 246)
#define POT2 get_intrect(296 , 404, 181, 245)
#define SKELETON1 get_intrect(0 , 165, 227, 187)
#define SKELETON2 get_intrect(187 , 165, 214, 149)
#define TORCH get_intrect(296 , 766, 28, 81)
#define WINDOW get_intrect(0 , 0, 165, 300)
#define CLEARFILE(X) fclose(fopen(X, "w"));
#define SVEC(X, Y) X.x = Y.x; \
X.y = Y.y;
#define ADD_VEC(A, X, Y) A.x += X; \
A.y += Y;
#define NVECTOR(V, X, Y) V.x = X; \
V.y = Y;

#define FREE_CONTINUE(X) free(X);\
continue;
#define FREE_RETURN(X, Y) free(X);\
return Y;
#define GVECTOR(V, X, Y) V.x = Y.x - X.x; \
V.y = Y.y - X.y;

#define RANGE(X, Y) sqrt(pow(X.x / 256 - Y.x / 256, 2) +\
pow(X.y / 256 - Y.y / 256, 2))
#define MCCASE(X) 710 + X % 9 * 56, 520 + X / 9 * 56 + (X / 9 == 3 ? 25 : 0)