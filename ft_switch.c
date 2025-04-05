#include <stdio.h>

// Exemple de fonctions
int *f(char *c, int *d, char *g) {
  *c = '\0';
  *d = 4;
  *g = 'z';
  static int result_f = 1; // Valeur statique pour retourner un pointeur valide
  return &result_f;
}

int *t(char *c, int *d, char *g) {
  *c = 'a';
  *d = 8;
  *g = 'y';
  static int result_t = 2;
  return &result_t;
}

int *w(char *c, int *d, char *g) {
  *c = 'b';
  *d = 12;
  *g = 'x';
  static int result_w = 3;
  return &result_w;
}

// Fonction "switch" utilisant un tableau de pointeurs de fonction
void truc(int type, char *c, int *d, char *g, int *(*pointeur[])(char*, int*, char*)) {
  if (type >= 0 && type < 3) { // Vérifie que le type est valide
    int *result = pointeur[type](c, d, g);
    printf("Résultat de la fonction : %d\n", *result);
  } else {
    printf("Type invalide\n");
  }
}

void mafunctionSwapK1(int *(*pointeur[])(char*, int*, char*)) {
  // Exemple d'utilisation
  char pileA = 'A';
  int pileB = 0;
  char pileC = 'C';

  pointeur[0](&pileA, &pileB, &pileC); // Appelle pointeur[0] (f)
  pointeur[1](&pileA, &pileB, &pileC); // Appelle pointeur[1] (t)
}

int main() {
  char c;
  int d;
  char e;

  // Tableau de pointeurs de fonction
  int *(*pointeur[3])(char*, int*, char*) = {&f, &t, &w};

  // Appel de la fonction "switch"
  truc(0, &c, &d, &e, pointeur); // Appelle f
  truc(1, &c, &d, &e, pointeur); // Appelle t
  truc(2, &c, &d, &e, pointeur); // Appelle w
  truc(3, &c, &d, &e, pointeur); // Type invalide

  // Appel de mafunctionSwapK1
  mafunctionSwapK1(pointeur);

  return 0;
}

