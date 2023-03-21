#include<iostream>
#include<cstdlib>
#include<ctime>

void three_max(int&x, int&y, int&z) {
	int max = x;
	max = max > (y > z ? y : z) ? max : (y > z ? y : z);
	y = max; z = max; x = max;
}
template<typename T>
void riemp(T bloc[], const int eterno) {
	srand(time(NULL));
	for (int i = 0; i < eterno; i++)
		bloc[i] = rand() % 40 - 21;
}
template<typename T>
void aff(T bloc[], const int eterno) {
	std::cout << '[';
	for (int i = 0; i < eterno; i++)
		std::cout << bloc[i] << ", ";
	std::cout << "\b\b ]";
}
int negatif(int bloc[], const int eterno) {
	int& neg = bloc[0];
	for (int i = 0; i < eterno; i++)
		if (bloc[i] < 0) {
			neg = bloc[i];
			return neg;
		}
	return neg;
}
void zero(int bloc1[], const int eterno1, int bloc2[], const int eterno2) {
	for (int i = 0; i < eterno1; i++) {
		for (int j = 0; j < eterno2; j++) {
			if (*(bloc1 + i) == *(bloc2 + j))
				*(bloc2 + j) = 0;
		}
	}
}
int main() {
	setlocale(LC_ALL, "Russian");

	// Задача 1.
	std::cout << "Задача 1.\nВведите три числа : ";
	int A, B, C;
	std::cin >> A >> B >> C;
	three_max(A, B, C);
	std::cout << A << ' ' << B << ' ' << C << "\n\n";

	// Задача 2.
	std::cout << "Задача 2.\n";
	const int onze = 11;
	int mass[onze];
	riemp(mass, onze);
	aff(mass, onze);
	std::cout <<'\n'<< negatif(mass, onze)<<"\n\n";

	// Задача 3.
	const int douze = 12, seize = 16;
	int ter1[douze]{-3,2,13,-16,-5,4,-19,18,-10,0,7,-21}, ter2[seize];
	riemp(ter2, seize);
	std::cout << "Первый массив : \n";
	aff(ter1, douze);
	std::cout << "\nВторой массив : \n";
	aff(ter2, seize);
	std::cout << "\nВторой массив после вызова функции : \n";
	zero(ter1, douze, ter2, seize);
	aff(ter2, seize);
	std::cout << "\n\n";

	return 0;
}