#pragma once
#include <iostream>
using namespace std;
#define COUNT 10
namespace family{
	
	struct node{
	string name;
	string type;
	node *mother;
	node *father;
	node *son;
};
class Tree
{
	node *root;
public:
	Tree(string root);
	~Tree();//delete the tree
	Tree& addFather(string son, string father);
	Tree& addMother(string son, string mother);
	void display();
	void remove(string name);
	string relation(string name);
	string find(string type);
private:
	node *findNode(node *n,string name);
	node *findNodeByType(node *n,string type);
	void print2DUtil(node *root, int space);
};
}