//IA QUE J'AVAIS CODER POUR LE PROJET MAIS JE N'AI PAS EU LE TEMPS DE L'IMPLEMENTER

#pragma once
#include"Lib.h"

class Node
{
protected:
	int rPos;
	int cPos;

	int GValue;

	int FValue;

public:
	Node(const Location& loc, int g, int f);

	Location getLocation() const;

	int getGValue() const;

	int getFValue() const;

	void calculateFValue(const Location& locDest);

	void updateGValue(const int& i);

	const int& getHValue(const Location& locDest) const;

	friend bool operator<(const Node& a, const Node& b);
};

