#include "node_1.h"

Node::Node()
{
  left = NULL;
  right = NULL;
}

Node::Node(string newNama, string newUmur, string newAlamat)
{
  left = NULL;
  right = NULL;
  nama = newNama;
  umur = newUmur;
  alamat = newAlamat;
}

void Node::traversal( Node* root )
{
  if ( root == NULL ) { return; }
  traversal( getLeftNode() );
  printNode();
  traversal( getRightNode() );
}


void Node::printNode()
{
  std::cout << nama << "\t" << umur << "\t" << alamat << std::endl;
}
