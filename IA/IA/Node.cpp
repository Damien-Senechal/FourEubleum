//IA QUE J'AVAIS CODER POUR LE PROJET MAIS JE N'AI PAS EU LE TEMPS DE L'IMPLEMENTER

#include "Node.h"

Node::Node(const Location& loc, int g, int f)
{
	this->rPos = loc.row;
	this->cPos = loc.col;
	this->GValue = g;
	this->FValue = f;
}

Location Node::getLocation() const
{
	return Location(rPos, cPos);
}

int Node::getGValue() const
{
	return this->GValue;
}

int Node::getFValue() const
{
	return this->FValue;
}

void Node::calculateFValue(const Location& locDest)
{
	this->FValue = GValue + getHValue(locDest) * 10;
}

void Node::updateGValue(const int& i)
{
	GValue += 10;
}

const int& Node::getHValue(const Location& locDest) const
{
	static int rd, cd, d;
	rd = locDest.row - rPos;
	cd = locDest.col - cPos;

	d = abs(rd) + abs(cd);

	return d;
}

bool operator<(const Node& a, const Node& b)
{
	return a.getFValue() > b.getFValue();
}


