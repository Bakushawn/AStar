/*
 * main.cpp
 *
 *  Created on: Mar 26, 2018
 *      Author: ShawnSargent
 */
#include "Node.h"
#include <vector>
#include <set>
#include <cmath>

#include <iostream>

int main(){
	std::vector<Node*> nodes;
	nodes.push_back(new Node(1,1));
	nodes.push_back(new Node(1,2));
	nodes.push_back(new Node(1,3));
	nodes.push_back(new Node(2,1));
	nodes.push_back(new Node(2,2));
	nodes.push_back(new Node(2,3));
	nodes.push_back(new Node(3,1));
	nodes.push_back(new Node(3,2));
	nodes.push_back(new Node(3,3));
	nodes[0]->connections.push_back(nodes[1]);
	nodes[0]->connections.push_back(nodes[3]);

	nodes[1]->connections.push_back(nodes[0]);
	nodes[1]->connections.push_back(nodes[4]);

	nodes[2]->connections.push_back(nodes[4]);

	nodes[3]->connections.push_back(nodes[0]);
	nodes[3]->connections.push_back(nodes[6]);

	nodes[4]->connections.push_back(nodes[1]);
	nodes[4]->connections.push_back(nodes[5]);

	nodes[5]->connections.push_back(nodes[4]);
	nodes[5]->connections.push_back(nodes[8]);

	nodes[6]->connections.push_back(nodes[3]);
	nodes[6]->connections.push_back(nodes[7]);

	nodes[7]->connections.push_back(nodes[6]);
	nodes[7]->connections.push_back(nodes[8]);

	nodes[8]->connections.push_back(nodes[5]);
	nodes[8]->connections.push_back(nodes[7]);

	int source = 0;
	int destination = 2;

	std::set<std::pair<double, Node*> > openList;
	std::vector<Node*> closedList;

	openList.insert(std::make_pair<double, Node*&>(0, nodes[source]));

	bool isDone = false;
	while(!isDone){
		 Node* current = openList.begin()->second;
		 closedList.push_back(current);
		 openList.erase(openList.begin());

		 std::cout << current->x << " " << current->y << std::endl;

		 for(auto connection : current->connections){
			double moveCost = sqrt( pow(current->x - connection->x,2) + pow(current->y - connection->y,2) );
			double destinationCost = sqrt( pow(nodes[destination]->x - connection->x,2) + pow(nodes[destination]->y - connection->y,2) );
			double cost = moveCost + destinationCost;
			openList.insert(std::make_pair<double&, Node*&>(cost, connection));

			connection->parent = current;
			if(connection == nodes[destination]){
				isDone = true;
			}
		 }
	}

	std::cout << "Path\n";

	Node* current = nodes[destination];
	while(current != nodes[source]){
		std::cout << current->x << " " << current->y << std::endl;
		current = current->parent;
	}
}



