#include <iostream>
#include <Windows.h>
#include<map>
#include<list>
#include<conio.h>
#include<string>
#include<fstream>
#include"Crime.h"
using namespace std;

#define tab "\t"

void print(const std::map<std::string, std::list <Crime>>& base);
void add(std::map<std::string, std::list<Crime>>& base);
void save(const std::map<std::string, std::list <Crime>>& base, const std::string& file_name);
void load(std::map<std::string, std::list <Crime>>& base, const std::string& file_name);
std::ofstream& operator<<(std::ofstream& ofs, const Crime& obj);


int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::map<std::string, std::list<Crime>> base =
	{
		{"a123tm",{Crime(1,"Ленина"),Crime(2,"Победы")}},
		{"s456rt",{Crime(5,"Мира"),Crime(6,"Октябрьская")}},
		{"o987cb",{Crime(3,"Пушкина"),Crime(4,"Маяковского")}}
	};
	load(base, "base.txt");
	print(base);
	char key;
	do
	{
		system("CLS");
		cout << "\t\t\t\tБаза данных ГАИ" << endl;
		cout << "\t\t\t\t   Меню:" << endl;
		cout << "\t1. Добавление элемента в базу." << endl;
		cout << "\t2. Сохранение базы в файл." << endl;
		cout << "\t3. Полная распечатка базы." << endl;
		cout << "\t4. Распечатка данных по диапазону номеров." << endl;
		cout << "\t5. Чтение базы из файла." << endl;
		cout << "\t0. Выход." << endl;
		key = _getch();
		switch (key)
		{
		case '1':
		{
			add(base);
			break;
		}
		case '2':
		{
			save(base, "Base");
			break;
		}
		case '3':
		{
			print(base);
			key = _getch();
			break;
		}
		case '4':
		{
			
			break;
		}
		case '5':
		{
			load(base, "Base");
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
	} while (key != '0');





















	/*save(base, "base.txt");*/
	//add(base);

	//print(base);
	
	return 0;
}

void print(const std::map<std::string, std::list <Crime>>& base)
{
	for (std::map<std::string,std::list<Crime>>::const_iterator it = base.begin(); it!= base.end(); ++it)
	{
		cout << it->first + ":"<<endl;
		int i = 1;
		for (std::list<Crime>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
		{
			cout << i << tab;
			i++;
			cout << *jt<<endl;
		}
		cout <<"---------------------------------------------------------------" << endl;
	}
}
void add(std::map<std::string, std::list<Crime>>& base)
{
	std::string licence_plate;
	int id;
	std::string plase;	
	cout << "Введите номер авто "; std::getline(cin, licence_plate);	
	cout << "Введите номер строки "; cin >> id;	
	cout << "Введите адрес "; 
	cin.ignore();
	cin.clear();
	std::getline(cin, plase);
	base[licence_plate].push_back(Crime(id, plase));
}
void save(const std::map<std::string, std::list <Crime>>& base, const std::string& file_name)
{
	std::ofstream fout(file_name);
	for (std::pair< std::string, std::list<Crime>> i: base)
	{
		fout << i.first << ":\t";
		for (Crime j :i.second)
		{
			fout << j << ", ";
		}
		fout.seekp(-2, std::ios::cur);//сдвигаем курсор на две позиции влево
		fout << ";\n";
	}
	fout.close();
	std::string comand = std::string("start notepad ") + file_name;//строка для командной строки	
	system(comand.c_str());
}
void load(std::map<std::string, std::list <Crime>>& base, const std::string& file_name)
{
	std::ifstream fin(file_name);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			std::string licence_plate;
			int id;
			std::string plase;
			std::string crimes;
			std::getline(fin, licence_plate, ':');
			std::getline(fin, crimes);
			if (crimes.empty())continue;
			if (crimes.find(',') != std::string::npos)
			{
				for (int start = 0, end = crimes.find(','); end != std::string::npos; start = end)
				{
					end = crimes.find(',', start + 1);
					plase = crimes.substr(start+1, end);
					plase.erase(0, plase.find_first_not_of(' '));
					id = std::stoi(plase.substr(0, plase.find_first_of(' ')));
					plase.erase(0, plase.find_first_of(' ') + 1);
					base[licence_plate].push_back(Crime(id, plase));
				} 
			}
			else
			{
				id = std::stoi(crimes.substr(0, crimes.find_first_of(' ')));
				crimes.erase(0, crimes.find_first_of(' ') + 1);
				base[licence_plate].push_back(Crime(id, crimes));
			}
			

		}
		fin.close();
	}
	else
	{
		std::cerr << "Erorr: file not found" << endl;
	}
}
std::ofstream& operator<<(std::ofstream& ofs, const Crime& obj)
{
	ofs << obj.get_id() << " " << obj.get_plase();
	return ofs;
}