#ifndef NODE_H
#define NODE_H

class Node
{
public:
	Node();
	~Node();

	double x();	//get _x
	double y();
	void setNode(double const x, double const y);
private:
	double _x;
	double _y;
};//end class Node

#endif
