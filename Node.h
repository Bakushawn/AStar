/*
 * Nodes.h
 *
 *  Created on: Mar 26, 2018
 *      Author: ShawnSargent
 */

#ifndef NODE_H_
#define NODE_H_

#include <vector>

struct Node {
	Node(double _x, double _y) : x(_x), y(_y) {};
	double x;
	double y;
	Node* parent;
	std::vector<Node*> connections;
};

#endif /* NODE_H_ */
