#include <iostream>
using namespace std;
#include "FamilyTree.hpp"
using namespace family;
///////////////////////////////////////////////////constructors /////////////////////////////////////////////////////////////////////////
Tree :: Tree(string name)
{
	node *p=new node;
    p->name=name;
	p->son=NULL;
	p->father=NULL;
	p->mother=NULL;
	p->type="me";
    root=p;
}
Tree :: ~Tree()
{
	
}
///////////////////////////////////////////////////////public methods ///////////////////////////////////////////////////////////////////////////
Tree& Tree :: addFather(string son, string father)
{	
	node *temp=findNode(root,son);
	if(temp==nullptr) throw std::out_of_range("The name not exists in the tree");
	if(temp->father!=nullptr)throw std::out_of_range("duplicate father");
	node *p=new node;
    p->name=father;
	p->son=temp;
	p->father=NULL;
	p->mother=NULL;
	if(temp->type == "me")
		p->type="father";
	else if(temp->type == "father" || temp->type == "mother")
		p->type="grandfather";
	else {
		p->type="great-"+temp->type;
	    int l=p->type.length();
	    p->type=p->type.substr(0,l-11);
	    p->type+="grandfather";
	}
    temp->father=p;
return *this;
}
Tree& Tree :: addMother(string son, string mother)
{
	node *temp=findNode(root,son);
	if(temp==nullptr) throw std::out_of_range("The name not exists in the text");
	if(temp->mother!=nullptr) throw std::out_of_range("duplicate mother");
	node *p=new node;
    p->name=mother;
	p->son=temp;
	p->father=NULL;
	p->mother=NULL;
	if(temp->type =="me")
		p->type="mother";
	else if(temp->type == "mother" || temp->type == "father" )
		p->type="grandmother";
		else {
		p->type="great-"+temp->type;
	    int l=p->type.length();
	    p->type=p->type.substr(0,l-11);
	    p->type+="grandmother";
	}
	temp->mother=p;
return *this;	
}
void Tree :: display()
{
	print2DUtil(root, 0);  
}
string Tree :: relation(string name)
{
	node *temp=findNode(root,name);
	if(temp==nullptr)
		return "unrelated";
	return temp->type;
}
string Tree :: find(string type)
{
	node *temp=findNodeByType(root,type);
	if(temp==nullptr) throw std::out_of_range("The tree cannot handle the 'uncle' relation");
	return temp->name;
}
void Tree :: remove(string name)
{
	node *temp=findNode(root,name);
	if(temp==nullptr) throw std::out_of_range("The name not exists in the tree");
	node *p=temp->son;
	if(p->mother == temp){
		p->mother=nullptr;
	}
	else
		p->father=nullptr;	
}
///////////////////////////////////////////////////////private methods ///////////////////////////////////////////////////////////////////////////
node *Tree :: findNode(node *n,string name)
{	
	if(n==nullptr)
		return nullptr;
	if(n->name==name)
		return n;
	node *found=findNode(n->father,name);
	if(found!=nullptr)
		return found;
	return findNode(n->mother,name);
} 
node *Tree :: findNodeByType(node *n,string type)
{	
	if(n==nullptr)
		return nullptr;
	if(n->type==type)
		return n;
	node *found=findNodeByType(n->father,type);
	if(found!=nullptr)
		return found;
	return findNodeByType(n->mother,type);
} 
void Tree :: print2DUtil(node *root, int space)  
{  
    // Base case  
    if (root == nullptr)  
        return;  
  
    // Increase distance between levels  
    space += COUNT;  
  
    // Process right child first  
    print2DUtil(root->mother, space);  
  
    // Print current node after space  
    // count  
    cout<<endl;  
    for (int i = COUNT; i < space; i++)  
        cout<<" ";  
    cout<<root->name<<"\n";  
  
    // Process left child  
    print2DUtil(root->father, space); 
}  
  
