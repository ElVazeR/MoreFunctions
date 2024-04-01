#include <iostream>
#include <algorithm>
int NUM; // Глобальная переменная
const double PI = 3.1416; // Глобальная константа
int ARR[3]; // Глобальный массив

void func() {
	static int a = 0; 
	a++;
	std::cout << a << std::endl;

}
 /*Области применения статических элементов:
 1. Сохранение данных внутри функции для следующего её вызова;
 2. Щадящее отношение к памяти и быстродействию программы;
 3. Создание общей памяти для всех элементов, принадлежащих одному множеству (классу или структуре).

 */



int power(int left, int right = 2) {
	int result = 1;
	for (int i = 1; i <= right; i++)
		result *= left;
	return result;

}


inline int sum(int num1, int num2) {
	return (num1 + num2);

}

inline int sum_arr(int arr[], const int length) {
	int result = 0;
	for (int i = 0; i < length; i++)
		result += arr[i];
	return result;
}

// Перегруженные функции

int max(int num1, int num2) {
	std::cout << "TWO INTS\n";
	return num1 > num2 ? num1 : num2;
}
double max(double num1, double num2) {
	std::cout << "TWO DOUBLES\n";
	return num1 > num2 ? num1 : num2;
}
char max(char sym1, char sym2){
	std::cout << "TWO CHARES\n";
	return sym1 > sym2 ? sym1 : sym2;
}
int max(int num1, int num2, int num3) {
	std::cout << "THREE INTS\n";
	return max(max(num1, num2), num3);
}
// Шаблонная функция
template <typename T>
void print_arr(T arr[], const int length) { // Идеальный вариант вывода массива
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }\n";
}





int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;
	// Области видимости данных.
	NUM = 7;
	std::cout <<"Num = "<< NUM << std::endl;
	std::cout << "PI = " << PI << std::endl;

	func();
	func();
	func();

	// Параметры по умолчанию.

	std::cout << "7^2  = " << power(7) << std::endl;
	std::cout << "4^3  = " << power(4, 3) << std::endl;
	std::cout << "5^2  = " << power(5) << std::endl;
	std::cout << "10^5 = " << power(10, 5) << std::endl;

	// Встраиваемая функция
	std::cout << "Введите два числа -> ";
	std::cin >> n >> m;
	std::cout << n << " + " << m << " = " << sum(n, m) << std::endl;

	// Перегруженные функции

	std::cout << max(7, 15) << std::endl; // 15
	std::cout << max(5.4, 5.04) << std::endl; // 5.4
	std::cout << max('Z','0') << std::endl;
	std::cout << max(7, 42, 15) << std::endl;
	

	// Все экземпляры перегруженной функции должны отличаться между собой по наборам параметров, а именно по их типам или их количество.

	// Шаблонная функция
	const int size = 5;
	int arr[size]{ 7, 15, 42, 105, -77 };
	std::cout << "Массив:\n";
	print_arr(arr, size);
	
	return 0;
}