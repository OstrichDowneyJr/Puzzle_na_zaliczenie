// Autor: Jan Burbicki
// Test dla dev
#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

// funkcjie do zamiany elemnetow

void moveRight(int tab[3][3], int index_i, int index_j);
void moveLeft(int tab[3][3], int index_i, int index_j);
void moveUp(int tab[3][3], int index_i, int index_j);
void moveDown(int tab[3][3], int index_i, int index_j);

// funkcje techniczne
int best_step(int tab[4], int steps);
void printTab(int tab[3][3]);
void shuffle(int tab[3][3]);
int displacment(int tab[3][3], int tab_org[3][3]);
void solver(int tab[3][3]);
void info();

int  Puzzle_Org[3][3] = { 1,2,3,4,5,6,7,8 }; // tablica referencyjna
int Puzzle[3][3] = { 1,2,3,4,5,6,7,8 }; // tablica do wykonywania krokow

int kroki[4]; // tablica do przechowywania wyników displacemnetu z każdego możliwego kroku

int main() {


	srand((unsigned)time(0));

	info();
	printTab(Puzzle);
	printf("Tablica Poczatkowa\n");

	shuffle(Puzzle);
	printTab(Puzzle);
	printf(" Przesuniecie wynosi: %d\n", displacment(Puzzle, Puzzle_Org));

	solver(Puzzle);

	return 0;
}

void solver(int tab[3][3]) {
	for (int k = 0; k < 20; k++) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (tab[i][j] == 0) {
					if (i == 0 && j == 0) {
						// pusty klocek jest w lewym gornym rogu 
						moveLeft(Puzzle, 0, 0);
						kroki[0] = displacment(Puzzle, Puzzle_Org);
						moveRight(Puzzle, 0, 1);
						// -----------------
						moveUp(Puzzle, 0, 0);
						kroki[1] = displacment(Puzzle, Puzzle_Org);
						moveDown(Puzzle, 1, 0);
						// -----------------
						int step = best_step(kroki, 2);
						switch (step) {
						case 0:
							moveLeft(Puzzle, 0, 0);
							printf("Krok w lewo\n");
							break;
						case 1:
							moveUp(Puzzle, 0, 0);
							printf("Krok w gore\n");
							break;

						}
						printTab(Puzzle);
						printf(" Przesuniecie wynosi: %d\n", displacment(Puzzle, Puzzle_Org));
					}

					else if (i == 0 && j == 2) {
						// pusty klocek jest w prawym gorny rogu
						moveRight(Puzzle, 0, 2);
						kroki[0] = displacment(Puzzle, Puzzle_Org);
						moveLeft(Puzzle, 0, 1);
						// -----------------
						moveUp(Puzzle, 0, 2);
						kroki[1] = displacment(Puzzle, Puzzle_Org);
						moveDown(Puzzle, 1, 2);
						// -----------------
						int step = best_step(kroki, 2);
						switch (step) {
						case 0:
							moveRight(Puzzle, 0, 2);
							printf("Krok w prawo\n");
							break;
						case 1:
							moveUp(Puzzle, 0, 2);
							printf("Krok w gore\n");
							break;

						}
						printTab(Puzzle);
						printf(" Przesuniecie wynosi: %d\n", displacment(Puzzle, Puzzle_Org));
					}

					else if (i == 2 && j == 0) {
						// pusty klocek jest w lewym dolnym rogu
						moveLeft(Puzzle, 2, 0);
						kroki[0] = displacment(Puzzle, Puzzle_Org);
						moveRight(Puzzle, 2, 1);
						// -----------------
						moveDown(Puzzle, 2, 0);
						kroki[1] = displacment(Puzzle, Puzzle_Org);
						moveUp(Puzzle, 1, 0);
						// -----------------
						int step = best_step(kroki, 2);
						switch (step) {
						case 0:
							moveLeft(Puzzle, 2, 0);
							printf("Krok w prawo\n");
							break;
						case 1:
							moveDown(Puzzle, 2, 0);
							printf("Krok w gore\n");
							break;

						}
						printTab(Puzzle);
						printf(" Przesuniecie wynosi: %d\n", displacment(Puzzle, Puzzle_Org));
					}

					else if (i == 2 && j == 2) {
						// pusty klocek jest w prawy dolnym rogu
						moveRight(Puzzle, 2, 2);
						kroki[0] = displacment(Puzzle, Puzzle_Org);
						moveLeft(Puzzle, 2, 1);
						// -----------------
						moveDown(Puzzle, 2, 2);
						kroki[1] = displacment(Puzzle, Puzzle_Org);
						moveUp(Puzzle, 1, 2);
						// -----------------
						int step = best_step(kroki, 2);
						switch (step) {
						case 0:
							moveRight(Puzzle, 2, 2);
							printf("Krok w prawo\n");
							break;
						case 1:
							moveDown(Puzzle, 2, 2);
							printf("Krok w dol\n");
							break;

						}
						printTab(Puzzle);
						printf(" Przesuniecie wynosi: %d\n", displacment(Puzzle, Puzzle_Org));
					}

					else if (i == 0 && j == 1) {
						// pusty klocek jest na gornej krawedzi
						moveRight(Puzzle, 0, 1);
						kroki[0] = displacment(Puzzle, Puzzle_Org);
						moveLeft(Puzzle, 0, 0);
						// -----------------
						moveUp(Puzzle, 0, 1);
						kroki[1] = displacment(Puzzle, Puzzle_Org);
						moveDown(Puzzle, 1, 1);
						// -----------------
						moveLeft(Puzzle, 0, 1);
						kroki[2] = displacment(Puzzle, Puzzle_Org);
						moveRight(Puzzle, 0, 2);
						// -----------------
						int step = best_step(kroki, 3);
						switch (step) {
						case 0:
							moveRight(Puzzle, 0, 1);
							printf("Krok w prawo\n");
							break;
						case 1:
							moveUp(Puzzle, 0, 1);
							printf("Krok w gore\n");
							break;
						case 2:
							moveLeft(Puzzle, 0, 1);
							printf("Krok w lewo\n");
							break;
						}
						printTab(Puzzle);
						printf(" Przesuniecie wynosi: %d\n", displacment(Puzzle, Puzzle_Org));
					}

					else if (i == 1 && j == 2) {
						// pusty klocek jest na prawej krawedzi
						moveDown(Puzzle, 1, 2);
						kroki[0] = displacment(Puzzle, Puzzle_Org);
						moveUp(Puzzle, 0, 2);
						// -----------------
						moveRight(Puzzle, 1, 2);
						kroki[1] = displacment(Puzzle, Puzzle_Org);
						moveLeft(Puzzle, 1, 1);
						// -----------------
						moveUp(Puzzle, 1, 2);
						kroki[2] = displacment(Puzzle, Puzzle_Org);
						moveDown(Puzzle, 2, 2);
						// -----------------
						int step = best_step(kroki, 3);
						switch (step) {
						case 0:
							moveDown(Puzzle, 1, 2);
							printf("Krok w dol\n");
							break;
						case 1:
							moveRight(Puzzle, 1, 2);
							printf("Krok w prawo\n");
							break;
						case 2:
							moveUp(Puzzle, 1, 2);
							printf("Krok w gore\n");
							break;
						}
						printTab(Puzzle);
						printf(" Przesuniecie wynosi: %d\n", displacment(Puzzle, Puzzle_Org));
					}

					else if (i == 2 && j == 1) {
						// pusty klocek jest na dolnej krawedzi
						moveDown(Puzzle, 2, 1);
						kroki[0] = displacment(Puzzle, Puzzle_Org);
						moveUp(Puzzle, 1, 1);
						// -----------------
						moveRight(Puzzle, 2, 1);
						kroki[1] = displacment(Puzzle, Puzzle_Org);
						moveLeft(Puzzle, 2, 0);
						// -----------------
						moveLeft(Puzzle, 2, 1);
						kroki[2] = displacment(Puzzle, Puzzle_Org);
						moveRight(Puzzle, 2, 2);
						// -----------------
						int step = best_step(kroki, 3);
						switch (step) {
						case 0:
							moveDown(Puzzle, 2, 1);
							printf("Krok w dol\n");
							break;
						case 1:
							moveRight(Puzzle, 2, 1);
							printf("Krok w prawo\n");
							break;
						case 2:
							moveLeft(Puzzle, 2, 1);
							printf("Krok w lewo\n");
							break;
						}
						printTab(Puzzle);
						printf(" Przesuniecie wynosi: %d\n", displacment(Puzzle, Puzzle_Org));
					}

					else if (i == 1 && j == 0) {
						// pusty klocek jest na lewej krawedzi
						moveUp(Puzzle, 1, 0);
						kroki[0] = displacment(Puzzle, Puzzle_Org);
						moveDown(Puzzle, 2, 0);
						// -----------------
						moveLeft(Puzzle, 1, 0);
						kroki[1] = displacment(Puzzle, Puzzle_Org);
						moveRight(Puzzle, 1, 1);
						// -----------------
						moveDown(Puzzle, 1, 0);
						kroki[2] = displacment(Puzzle, Puzzle_Org);
						moveUp(Puzzle, 0, 0);
						// -----------------
						int step = best_step(kroki, 3);
						switch (step) {
						case 0:
							moveUp(Puzzle, 1, 0);
							printf("Krok w gore\n");
							break;
						case 1:
							moveLeft(Puzzle, 1, 0);
							printf("Krok w lewo\n");
							break;
						case 2:
							moveDown(Puzzle, 1, 0);
							printf("Krok w dol\n");
							break;
						}

						printTab(Puzzle);
						printf(" Przesuniecie wynosi: %d\n", displacment(Puzzle, Puzzle_Org));
					}
					else {
						// pusty klocek jest na srodku
						moveDown(Puzzle, 1, 1);
						kroki[0] = displacment(Puzzle, Puzzle_Org);
						moveUp(Puzzle, 0, 1);
						// -----------------
						moveLeft(Puzzle, 1, 1);
						kroki[1] = displacment(Puzzle, Puzzle_Org);
						moveRight(Puzzle, 1, 2);
						// -----------------
						moveUp(Puzzle, 1, 1);
						kroki[2] = displacment(Puzzle, Puzzle_Org);
						moveDown(Puzzle, 2, 1);
						// -----------------
						moveRight(Puzzle, 1, 1);
						kroki[3] = displacment(Puzzle, Puzzle_Org);
						moveLeft(Puzzle, 1, 0);
						// -----------------
						int step = best_step(kroki, 4);
						switch (step) {
						case 0:
							moveDown(Puzzle, 1, 1);
							printf("Krok w dol\n");
							break;
						case 1:
							moveLeft(Puzzle, 1, 1);
							printf("Krok w lewo\n");
							break;
						case 2:
							moveUp(Puzzle, 1, 1);
							printf("Krok w gore\n");
							break;
						case 3:
							moveRight(Puzzle, 1, 1);
							printf("Krok w prawo\n");
							break;
						}

						printTab(Puzzle);
						printf(" Przesuniecie wynosi: %d\n", displacment(Puzzle, Puzzle_Org));
					}

					// wykonaj krok > zmierz displacment > zapisz do korki[] > cofnij krok 
					// wykonaj wszystkie dostepne kroki (max 4.)
					// wybierz krok o najniższym displacmencie
					// wykonaj go
					// wypisz tablice Puzzle
				}

			}
		}
	}

}

int best_step(int tab[4], int steps) { // funckja do wybierania najbardziej optymalnego kroku 
	int best = tab[0];
	int best_index = 0;
	for (int i = 0; i < steps; i++)
	{
		if (tab[i] < best) {
			best = tab[i];
			best_index = i;

		}
	}
	return best_index;
}


// przesunięcia są względem pustego pola

void moveRight(int tab[3][3], int index_i, int index_j) {
	int box;
	box = tab[index_i][index_j];
	tab[index_i][index_j] = tab[index_i][index_j - 1];
	tab[index_i][index_j - 1] = box;
}

void moveLeft(int tab[3][3], int index_i, int index_j) {
	int box;
	box = tab[index_i][index_j];
	tab[index_i][index_j] = tab[index_i][index_j + 1];
	tab[index_i][index_j + 1] = box;
}

void moveUp(int tab[3][3], int index_i, int index_j) {
	int box;
	box = tab[index_i][index_j];
	tab[index_i][index_j] = tab[index_i + 1][index_j];
	tab[index_i + 1][index_j] = box;
}

void moveDown(int tab[3][3], int index_i, int index_j) {
	int box;
	box = tab[index_i][index_j];
	tab[index_i][index_j] = tab[index_i - 1][index_j];
	tab[index_i - 1][index_j] = box;
}



void info() {
	printf("Program do rozwiazywania 8th Puzzle ");
	printf("za pomoca algorytmu A*\n");
	printf("Autor: Jan Burbicki\n");
}

void printTab(int tab[3][3]) {
	printf("-----------\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 2 && i == 2) {
				if (tab[i][j] == 0) {
					printf("   |\n");
					printf("-----------\n\n");
				}
				else {
					printf(" %d |\n", tab[i][j]);
					printf("-----------\n\n");
				}
			}
			else if (j == 2) {
				if (tab[i][j] == 0) {
					printf("   |\n");
					printf("-----------\n");
				}
				else {
					printf(" %d |\n", tab[i][j]);
					printf("-----------\n");
				}
			}
			else {
				if (tab[i][j] == 0) {
					printf("   |");
				}
				else {
					printf(" %d |", tab[i][j]);
				}
			}
		}
	}
}

void shuffle(int tab[3][3]) {
	for (int i = 0; i < 3; i++)
	{

		for (int j = 0; j < 3; j++)
		{
			int r = rand() / (RAND_MAX / (3 - i) + 1);
			int t = rand() / (RAND_MAX / (3 - i) + 1);
			int temp = tab[i][j];
			tab[i][j] = tab[r][t];
			tab[r][t] = temp;
		}
	}
}

int displacment(int tab[3][3], int tab_org[3][3]) {
	int displaced = 0;
	for (int n = 0; n < 9; n++) {

		int i, j, p, q;


		for (i = 0; i < 3; i++) { // szukanie pierwszej tablicy
			for (j = 0; j < 3; j++) {

				if (tab_org[i][j] == n) { // jezeli znajdziesz element z pierwszej tablicy
					for (p = 0; p < 3; p++) { // szukanie 2 tablicy
						for (q = 0; q < 3; q++) {

							if (tab[p][q] == n) {
								displaced += abs(p - i) + abs(q - j); // metryka manhatańska 
							}
						}
					}
				}
			}
		}
	}

	return displaced;
}

