#include <iostream>
#include <string>
#include<iostream>
#include<string>
#include <unordered_map>
#include <algorithm>
#include <fstream>
#include <filesystem>
#include <regex>

using namespace std;
string ABC = "abcdefghijklmnopqrstuvwxyz";


string filterWithoutSpace(string& text, string& ABC) { //метод фильтрации текста без пробелов

	string filterText = "";
	for (char c : text)
	{
		char v = tolower(c);

		if (ABC.find(v) != string::npos)  //проверяет, является ли данный символ алфавитом или нет
		{
			filterText += v;
		}
		else if (isspace(v)) {
			continue; //пропускаем пробелы 
		}
	}

	return filterText;
}





int keycode(char s) {//проверка на соответствие символа ключа алфавиту 
	for (int i = 0; i < ABC.length(); i++) {
		if (s == ABC[i]) return i;
	}
	return 0;
}

string Decode(string text, string key) { //метод разшифровки текста 
	string code;
	for (int i = 0; i < text.length(); i++) {//цикл проходит по всем елементам текста 
		code += ABC[(keycode(text[i]) - keycode(key[i % key.length()]) + ABC.length()) % ABC.length()];// по формуле выполняет значение текста - значение ключв
	}
	return code;
}


//void BLoc(string plaintext) { //метод для разбития текста на блоки для разшифровки с помошью UNIT
//
//	int block_size = 5;
//	string key = "unit";
//	for (int i = 0; i < plaintext.length(); i += block_size) {
//		string block = plaintext.substr(i, block_size);
//		cout << block << endl;
//		cout << Decode(block, key) << endl;
//	}
//}



int main() {
	setlocale(LC_ALL, "RU");
	string text = "pmta ulgc jmn srfr yleh";
	string F_text = filterWithoutSpace(text, ABC);
	//BLoc(F_text);
	cout << Decode(F_text, "keyword") << endl;// с помошью гугла нашли вероятный значение eywo из 7 букв 
	cout << F_text << endl;
	return 0;
}