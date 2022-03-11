#include <iostream>
#include <Windows.h>
#include<map>
#include<list>
#include<conio.h>
using namespace std;

#define tab "\t"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char key;
	
	std::map<std::string, std::list<std::string>>::iterator it1;
	std::map<std::string, std::list<std::string>>::iterator it2;
	std::map<std::string, std::list<std::string>> data_base
		
	{
		{"O123TM",{"Штраф за привышение скорости","Штраф за парковку в неположеном месте","Штраф за обгон"}},
		{"O145TM",{"Штраф за привышение скорости","Штраф за парковку в неположеном месте"}},
		{"O423TM",{"Штраф за привышение скорости"}}
	};
	std::pair < std::string, std::list<std::string>> add_elem;
	string tmp1;
	string tmp2;
	do
	{
		system("CLS");
		cout << "\t\t\t\tБаза данных ГАИ" << endl;
		cout << "\t\t\t\t   Меню:" << endl;
		cout << "\t1. Добавление элемента в базу." << endl;
		cout << "\t2. Удаление элемента из базы." << endl;
		cout << "\t3. Полная распечатка базы." << endl;
		cout << "\t4. Распечатка данных по диапазону номеров." << endl;
		cout << "\t0. Выход." << endl;
		key = _getch();
		switch (key)
		{
		case '1':
		{
			cout << "Введите номер машины : "; cin >> add_elem.first;
			cout << "Введите штраф : "; cin >> tmp1;
			add_elem.second.push_back(tmp1);
			it1 = data_base.find(add_elem.first);
			if (it1!=data_base.end())
			{
				it1->second.push_back(tmp1);
			}
			else 
			{
				data_base.insert(add_elem);
			}			
			break;
		}
		case '2':
		{
			cout << "Введите номер машины : "; cin >> add_elem.first;
			it1 = data_base.find(add_elem.first);
			if (it1 != data_base.end())
			{
				data_base.erase(it1);
			}
			else
			{
				cout<<"Номер не существует!!!";
			}
			break;
		}
		case '3':
		{
			for (std::pair< std::string, std::list<std::string>>i : data_base)
			{
				cout.width(10);
				cout << std::left;
				cout << i.first << " :\t";
				for (std::string j : i.second)cout << j << " , "; cout << "\b\b;\n";
			}
			key = _getch();
			break;
		}
		case '4':
		{
			cout << "Введите номер машины 1 : "; cin >> tmp1;
			it1 = data_base.find(tmp1);
			cout << "Введите номер машины 2 : "; cin >> tmp2;
			it2 = data_base.find(tmp2);
			++it2;
			for (std::map< std::string, std::list<std::string>>::iterator it = it1; it != it2; ++it)
			{
				cout.width(20);
				cout << std::left;
				cout << it->first << " :\t";
				for (std::string i : it->second)cout << i << " , "; cout << "\b\b;\n";
			}
			key = _getch();
			break;
		}
		case '0':
		{
			cout << "Досвидания." << endl;
			break;
		}
		default:
			
			break;
		}
	} while (key!='0');
	



	return 0;
}