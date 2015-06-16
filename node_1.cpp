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

Node* getLeftNode() { return left; }
Node* getRightNode() { return right; }
string getNama() { return nama; }
string getUmur() { return umur; }
string getAlamat() { return alamat; }

void setLeftNode( Node* newNode ) { left = newNode; }
void setRightNode( Node* newNode ) { right = newNode; }
void setNama( string newNama ) { nama = newName; }
void setUmur( string newUmur ) { umur = newUmur; }
void setAlamat( string newAlamat ) { alamat = newAlamat; }

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
