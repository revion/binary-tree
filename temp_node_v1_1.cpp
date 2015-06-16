#include <iostream>
#include <string>

class Node
{
  public:
    Node();
    Node(string newNama, string newUmur, string newAlamat);
    
    Node* getLeftNode() { return left; }
    Node* getRightNode() { return right; }
    string getNama() { return nama; }
    string getUmur() { return umur; }
    string getAlamat() { return alamat; }
    
    void setLeftNode( Node* newNode );
    void setRightNode( Node* newNode );
    //void setNama( string newNama );
    void setUmur( string newUmur );
    void setAlamat( string newAlamat );
    void traversal();
    void printNode();
  
  private:
    Node* left;
    Node* right;
    Node* prev;
    string nama;
    string umur;
    string alamat;
};

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
  cout << nama << "\t" << umur << "\t" << alamat << endl;
}
