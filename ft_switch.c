

int *f(char *c, int *d, char *g) {
  *c = '\0';
  *d = 4;
 *g = 'z';
}

int *t(char *c, int *d, char *g) {
  *c = '\0';
  *d = 4;
 *g = 'z';
}

int *w(char *c, int *d, char *g) {
  *c = '\0';
  *d = 4;
 *g = 'z';
}

// void truc (char type, char *c, int *d, char *g)
// {
// 	pointeur(type, &c, &d, &g);
// }


void mafunctionSwapK1(int *(*pointeur[])(char*, int*, char*)) {
	// pointeur[RRA](&pileA, &pileB);
	// pointeur[RRA](&pileA, &pileB);
	// pointeur[SA](&pileA, &pileB);
}

void main() {
	char c;
	int d;
	char e;
 int *(*pointeur[2])(char*, int*, char*) = {&f, &t};
 
	// tableau dynamique de tablequ statique

	char (*str)[0];

  mafunctionSwapK1(pointeur);

}

