#pragma once
#include<iostream>
#include<string>
#include<map>

const std::map<size_t, std::string> crimes =
{
	{1,"������ �� �������"},
	{2,"���������� ��������"},
	{3,"���� �� ��������� ������"},
	{4,"����� �� �����������"},
	{5,"�������� � ����������� �����"},
	{6,"����������� �������"},
	{7,"�� ���������� ������ ������������"}
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
	
