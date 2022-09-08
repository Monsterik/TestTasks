#include <iostream>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	string Str;
	string StrOut;
	bool CharWas = false;
	char CurrentChar;

	while (true) { // Повторение программы
		cout << "Введите строку:\n";

		getline(cin, Str); // Получаем строку пользователя

		StrOut = Str; // Делаем строку для вывода

		for (int i = 0; i < Str.size(); i++) { // Приводим к одному регистру (Не работает для кириллицы)
			Str[i] = toupper(Str[i]);
		}

		for (int i = 0; i < Str.size(); i++) { // Проходим по всем символам
			CurrentChar = Str[i];
			for (int j = 0; j < Str.size(); j++) { // Если символ встречается больше одного раза запоминаем это
				if (i != j) {
					if (Str[i] == Str[j]) {
						CharWas = true;
						break;
					}
				}
			}

			if (CharWas == true) // Если встречался больше одного раза меняем все такие символы в строке вывода на на ")"
			{
				for (int i = 0; i < Str.size(); i++) {
					if (Str[i] == CurrentChar)
					{
						StrOut[i] = ')';
					}
				}
			}
			else { // Если не встречался больше, то меняем один этот символ в сроке вывода  на "("
				StrOut[i] = '(';
			}

			CharWas = false;
		}

		cout << "Результат:\n" << StrOut << "\n";
	}

}
