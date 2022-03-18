#pragma once
#include<iostream>
#include<string>
#include<map>

const std::map<size_t, std::string> crimes =
{
	{1,"Проезд на красный"},
	{2,"Привышение скорости"},
	{3,"Езда по встречной полосе"},
	{4,"Дрифт на перекрестке"},
	{5,"Парковка в неположеном месте"},
	{6,"Оскорбление офицера"},
	{7,"Не пристегнут ремень безопасности"}
};

class Crime
{
	size_t id;
	std::string plase;
public:
	size_t get_id()const
	{
		return id;
	}
	const std::string& get_plase()const
	{
		return plase;
	}
	Crime(size_t id, const std::string& plase) :id(id), plase(plase) {}

	~Crime(){}
	bool operator == (const Crime& other)const
	{
		return this->id == other.get_id() && this->plase == other.get_plase();
	}
	bool operator != (const Crime& other)const
	{
		return this->id != other.get_id() && this->plase != other.get_plase();
	}
};

std::ostream& operator << (std::ostream& os, const Crime& obj);
	
