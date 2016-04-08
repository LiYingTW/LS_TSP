#include "Node.h"

Node::Node()
{
	this->_x = 0.0;
	this->_y = 0.0;
}

Node::~Node(){return;}

double Node::x(){ return this->_x; }
double Node::y(){ return this->_y; }

void Node::setNode(double const x, double const y)
{
	this->_x = x;
	this->_y = t;
}
