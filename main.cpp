#include <iostream>

using namespace std;



void DodawanieMacierzy(int tablica1[], int tablica2[], int wyniki[]) {

	for (int i = 0; i < 7; i++) {
		wyniki[i] = (tablica1[i] + tablica2[i]) % 2;
	}
}

void DodawanieMacierzy2(int tablica1[], int tablica2[], int wyniki[]) {

	for (int i = 0; i < 16; i++) {
		wyniki[i] = (tablica1[i] + tablica2[i]) % 2;
	}
}

void MnozenieMacierzy(int tablica1[], int tablica2[], int wyniki[], int lewa, int prawa) {

	int mnozenie[4][8];



	for (int i = 0; i < 4; i++) {

		for (int j = 0; j < 7; j++) {
			mnozenie[i][j] = 0;
		}
	}

	for (int j = 0; j < 4; j++) {

		if (tablica2[j + prawa] == 1) {

			for (int i = 0; i < 4; i++) {
				mnozenie[j][i + j] = tablica1[i + lewa];
			}
		}

	}

	for (int i = 0; i < 7; i++) {

		wyniki[i] = (((mnozenie[0][i] + mnozenie[1][i]) % 2 + mnozenie[2][i]) % 2 + mnozenie[3][i]) % 2;

	}
}

void Dzielenie(int tablica_przed[], int tablica_po[]) {

	int dzielnik[5] = { 1, 0, 0, 1, 1 };

	for (int y = 0; y < 3; y++) {

		if (tablica_przed[y] == 1) {

			for (int i = 0; i < 5; i++) {
				tablica_przed[y + i] ^= dzielnik[i];

			}
		}
	}

	for (int i = 0; i < 4; i++) {
		tablica_po[i] = tablica_przed[i + 3];
	}


}

void SboxE(int lancuszek[], int SboxE[], int op) {

	int suma = 10000 + lancuszek[0 + op] * 1000 + lancuszek[1 + op] * 100 + lancuszek[2 + op] * 10 + lancuszek[3 + op];

	switch (suma) {

	case 10000: {SboxE[0] = 1; SboxE[1] = 1; SboxE[2] = 1; SboxE[3] = 0; } break;
	case 10001: {SboxE[0] = 0; SboxE[1] = 1; SboxE[2] = 0; SboxE[3] = 0; } break;
	case 10010: {SboxE[0] = 1; SboxE[1] = 1; SboxE[2] = 0; SboxE[3] = 1; } break;
	case 10011: {SboxE[0] = 0; SboxE[1] = 0; SboxE[2] = 0; SboxE[3] = 1; } break;
	case 10100: {SboxE[0] = 0; SboxE[1] = 0; SboxE[2] = 1; SboxE[3] = 0; } break;
	case 10101: {SboxE[0] = 1; SboxE[1] = 1; SboxE[2] = 1; SboxE[3] = 1; } break;
	case 10110: {SboxE[0] = 1; SboxE[1] = 0; SboxE[2] = 1; SboxE[3] = 1; } break;
	case 10111: {SboxE[0] = 1; SboxE[1] = 0; SboxE[2] = 0; SboxE[3] = 0; } break;
	case 11000: {SboxE[0] = 0; SboxE[1] = 0; SboxE[2] = 1; SboxE[3] = 1; } break;
	case 11001: {SboxE[0] = 1; SboxE[1] = 0; SboxE[2] = 1; SboxE[3] = 0; } break;
	case 11010: {SboxE[0] = 0; SboxE[1] = 1; SboxE[2] = 1; SboxE[3] = 0; } break;
	case 11011: {SboxE[0] = 1; SboxE[1] = 1; SboxE[2] = 0; SboxE[3] = 0; } break;
	case 11100: {SboxE[0] = 0; SboxE[1] = 1; SboxE[2] = 0; SboxE[3] = 1; } break;
	case 11101: {SboxE[0] = 1; SboxE[1] = 0; SboxE[2] = 0; SboxE[3] = 1; } break;
	case 11110: {SboxE[0] = 0; SboxE[1] = 0; SboxE[2] = 0; SboxE[3] = 0; } break;
	case 11111: {SboxE[0] = 0; SboxE[1] = 1; SboxE[2] = 1; SboxE[3] = 1; } break;

	}

}

void SboxD(int lancuszek[], int SboxE[], int op) {

	int suma = 10000 + lancuszek[0 + op] * 1000 + lancuszek[1 + op] * 100 + lancuszek[2 + op] * 10 + lancuszek[3 + op];

	switch (suma) {

	case 10000: {SboxE[0] = 1; SboxE[1] = 1; SboxE[2] = 1; SboxE[3] = 0; } break;
	case 10001: {SboxE[0] = 0; SboxE[1] = 0; SboxE[2] = 1; SboxE[3] = 1; } break;
	case 10010: {SboxE[0] = 0; SboxE[1] = 1; SboxE[2] = 0; SboxE[3] = 0; } break;
	case 10011: {SboxE[0] = 1; SboxE[1] = 0; SboxE[2] = 0; SboxE[3] = 0; } break;
	case 10100: {SboxE[0] = 0; SboxE[1] = 0; SboxE[2] = 0; SboxE[3] = 1; } break;
	case 10101: {SboxE[0] = 1; SboxE[1] = 1; SboxE[2] = 0; SboxE[3] = 0; } break;
	case 10110: {SboxE[0] = 1; SboxE[1] = 0; SboxE[2] = 1; SboxE[3] = 0; } break;
	case 10111: {SboxE[0] = 1; SboxE[1] = 1; SboxE[2] = 1; SboxE[3] = 1; } break;
	case 11000: {SboxE[0] = 0; SboxE[1] = 1; SboxE[2] = 1; SboxE[3] = 1; } break;
	case 11001: {SboxE[0] = 1; SboxE[1] = 1; SboxE[2] = 0; SboxE[3] = 1; } break;
	case 11010: {SboxE[0] = 1; SboxE[1] = 0; SboxE[2] = 0; SboxE[3] = 1; } break;
	case 11011: {SboxE[0] = 0; SboxE[1] = 1; SboxE[2] = 1; SboxE[3] = 0; } break;
	case 11100: {SboxE[0] = 1; SboxE[1] = 0; SboxE[2] = 1; SboxE[3] = 1; } break;
	case 11101: {SboxE[0] = 0; SboxE[1] = 0; SboxE[2] = 1; SboxE[3] = 0; } break;
	case 11110: {SboxE[0] = 0; SboxE[1] = 0; SboxE[2] = 0; SboxE[3] = 0; } break;
	case 11111: {SboxE[0] = 0; SboxE[1] = 1; SboxE[2] = 0; SboxE[3] = 1; } break;
	}
}

void ZK(int przed_ZK[], int po_ZK[]) {

	for (int i = 0; i < 8; i++) {
		po_ZK[i] = przed_ZK[i];
	}
	for (int i = 0; i < 4; i++) {
		po_ZK[8 + i] = przed_ZK[12 + i];
	}
	for (int i = 0; i < 4; i++) {
		po_ZK[12 + i] = przed_ZK[8 + i];
	}
}

void MM(int macierz[], int wynik[], int m[]) {

	int wynik_mnozenia1[7], wynik_mnozenia2[7], wynik_mnozenia3[7], wynik_mnozenia4[7], wynik_mnozenia5[7], wynik_mnozenia6[7], wynik_mnozenia7[7], wynik_mnozenia8[7];
	int wynik_dodawania1[7], wynik_dodawania2[7], wynik_dodawania3[7], wynik_dodawania4[7], wynik_dodawania5[7], wynik_dodawania6[7], wynik_dodawania7[7], wynik_dodawania8[7];
	int reszta_z_dzielenia1[4], reszta_z_dzielenia2[4], reszta_z_dzielenia3[4], reszta_z_dzielenia4[4];



	MnozenieMacierzy(m, macierz, wynik_mnozenia1, 0, 0);
	MnozenieMacierzy(m, macierz, wynik_mnozenia2, 4, 8);
	MnozenieMacierzy(m, macierz, wynik_mnozenia3, 0, 4);
	MnozenieMacierzy(m, macierz, wynik_mnozenia4, 4, 12);
	MnozenieMacierzy(m, macierz, wynik_mnozenia5, 8, 0);
	MnozenieMacierzy(m, macierz, wynik_mnozenia6, 12, 8);
	MnozenieMacierzy(m, macierz, wynik_mnozenia7, 8, 4);
	MnozenieMacierzy(m, macierz, wynik_mnozenia8, 12, 12);

	DodawanieMacierzy(wynik_mnozenia1, wynik_mnozenia2, wynik_dodawania1);
	DodawanieMacierzy(wynik_mnozenia3, wynik_mnozenia4, wynik_dodawania2);
	DodawanieMacierzy(wynik_mnozenia5, wynik_mnozenia6, wynik_dodawania3);
	DodawanieMacierzy(wynik_mnozenia7, wynik_mnozenia8, wynik_dodawania4);

	Dzielenie(wynik_dodawania1, reszta_z_dzielenia1);
	Dzielenie(wynik_dodawania2, reszta_z_dzielenia2);
	Dzielenie(wynik_dodawania3, reszta_z_dzielenia3);
	Dzielenie(wynik_dodawania4, reszta_z_dzielenia4);

	for (int i = 0; i < 4; i++) {

		wynik[i] = reszta_z_dzielenia1[i];
		wynik[4 + i] = reszta_z_dzielenia2[i];
		wynik[8 + i] = reszta_z_dzielenia3[i];
		wynik[12 + i] = reszta_z_dzielenia4[i];
	}
}

void Fsbox(int macierz[], int wynik[]) {

	int cz1[4], cz2[4], cz3[4], cz4[4];
	SboxE(macierz, cz1, 0);
	SboxE(macierz, cz2, 4);
	SboxE(macierz, cz3, 8);
	SboxE(macierz, cz4, 12);

	for (int i = 0; i < 4; i++) {

		wynik[i] = cz1[i];
		wynik[4 + i] = cz2[i];
		wynik[8 + i] = cz3[i];
		wynik[12 + i] = cz4[i];
	}
}

void Fsbox2(int macierz[], int wynik[]) {

	int cz1[4], cz2[4], cz3[4], cz4[4];
	SboxD(macierz, cz1, 0);
	SboxD(macierz, cz2, 4);
	SboxD(macierz, cz3, 8);
	SboxD(macierz, cz4, 12);

	for (int i = 0; i < 4; i++) {

		wynik[i] = cz1[i];
		wynik[4 + i] = cz2[i];
		wynik[8 + i] = cz3[i];
		wynik[12 + i] = cz4[i];
	}
}



int main() {

	
	int klucz_1[16], klucz_2[16], sboxe[4], fsbox_wynik[16], zk_wynik[16], mm_wynik[16], dodanie_klucza_1[16], zk_wynik2[16], fsbox_wynik2[16], dodanie_klucza_2[16];
	int stala[4] = { 0, 0, 0, 1 };
	int stala2[4] = { 0, 0, 1, 0 };
	int a[16];
	int tekst[16];
	int m[16];


	int klucz_poczatkowy[16];
	cout << "Podaj klucz poczatkowy: ";
	for (int i = 0; i < 16; i++) {
		cin >> klucz_poczatkowy[i];
	}

	int A, B, C, D = 0;
	


	cout << "\n\nPodaj tekst: ";
	for (int i = 0; i < 16; i++) {
		cin >> tekst[i];
	}
	
	
	cout << "\n\nPodaj m: ";
	for (int i = 0; i < 16; i++) {
		cin >> m[i];
	}
	char znak = 0;
	while (znak != 'n') {
		cout << "\nPodaj A: " << endl;
		cin >> A;
		klucz_poczatkowy[0] = A;
		cout << "\nPodaj B: " << endl;
		cin >> B;
		klucz_poczatkowy[5] = B;
		cout << "Podaj C: " << endl;
		cin >> C;
		klucz_poczatkowy[11] = C;
		cout << "Podaj D: " << endl;
		cin >> D;
		klucz_poczatkowy[12] = D;
		
	DodawanieMacierzy2(tekst, klucz_poczatkowy, a);

	cout << "\n\nTekst: ";

	for (int i : tekst) {
		cout << i;
	}
	
	
		cout << "\nPo dodaniu klucza rundy 0: ";

		for (int i : a) {
			cout << i;
		}

		cout << "\n";
		SboxE(klucz_poczatkowy, sboxe, 12);

		//KLUCZ 1 RUNDY
		for (int i = 0; i < 4; i++) {
			klucz_1[i] = ((klucz_poczatkowy[i] + sboxe[i]) % 2 + stala[i]) % 2;
		}
		for (int i = 0; i < 4; i++) {
			klucz_1[8 + i] = (klucz_poczatkowy[8 + i] + klucz_1[i]) % 2;
		}
		for (int i = 0; i < 4; i++) {
			klucz_1[4 + i] = (klucz_poczatkowy[4 + i] + klucz_1[8 + i]) % 2;
		}
		for (int i = 0; i < 4; i++) {
			klucz_1[12 + i] = (klucz_poczatkowy[12 + i] + klucz_1[4 + i]) % 2;
		}


		SboxE(klucz_1, sboxe, 12);

		//KLUCZ 2 RUNDY
		for (int i = 0; i < 4; i++) {
			klucz_2[i] = ((klucz_1[i] + sboxe[i]) % 2 + stala2[i]) % 2;
		}
		for (int i = 0; i < 4; i++) {
			klucz_2[8 + i] = (klucz_2[i] + klucz_1[8 + i]) % 2;
		}
		for (int i = 0; i < 4; i++) {
			klucz_2[4 + i] = (klucz_2[8 + i] + klucz_1[4 + i]) % 2;
		}
		for (int i = 0; i < 4; i++) {
			klucz_2[12 + i] = (klucz_2[4 + i] + klucz_1[12 + i]) % 2;
		}


		cout << "Klucz rundy 1: ";

		for (int i : klucz_1) {
			cout << i;
		}
		cout << "\nKlucz rundy 2: ";

		for (int i : klucz_2) {
			cout << i;
		}


		//SZYFROWANIE

		Fsbox(a, fsbox_wynik);
		ZK(fsbox_wynik, zk_wynik);
		MM(zk_wynik, mm_wynik, m);
		DodawanieMacierzy2(mm_wynik, klucz_1, dodanie_klucza_1);
		Fsbox(dodanie_klucza_1, fsbox_wynik2);
		ZK(fsbox_wynik2, zk_wynik2);
		DodawanieMacierzy2(zk_wynik2, klucz_2, dodanie_klucza_2);


		cout << "\nPo Fsbox(a,e): ";

		for (int i : fsbox_wynik) {
			cout << i;
		}

		cout << "\nPo ZK: ";

		for (int i : zk_wynik) {
			cout << i;
		}

		cout << "\nMM: ";

		for (int i : mm_wynik) {
			cout << i;
		}

		cout << "\nPo dodaniu klucza 1 rundy: ";

		for (int i : dodanie_klucza_1) {
			cout << i;
		}

		cout << "\nFsbox(a,e) nr 2: ";

		for (int i : fsbox_wynik2) {
			cout << i;
		}

		cout << endl;

		cout << "Po ZK(a) nr 2: ";

		for (int i : zk_wynik2) {
			cout << i;
		}
		cout << endl;


		cout << "Po dodaniu klucza 2 rundy: ";

		for (int i : dodanie_klucza_2) {
			cout << i;
		}
		cout << "\n\n\n";

		cout << "\nCzy chcesz kontynuowac? \n";
		cin >> znak;

		
	}
	system("pause");
	return 0;

}