#include <iostream>
#include <string>

class Node
{
  public:
    Node();
    Node(Data newData);
  
    Node* left;
    Node* right;
    Node* prev;
    //Data* data;
    
    //void getLeftNode() { return Node::left; }
    //void getRightNode() { return Node::right; }
    //void traversal;
};

void Node::traversal()
{
  if ( data::getnama() == NULL ) { return; }
  traversal( getLeftNode() );
  //get the data of the node here and put it somewhere
  traversal( getRightNode() );
}
