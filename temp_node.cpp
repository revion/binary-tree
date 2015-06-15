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
  
  private:
    Node* left;
    Node* right;
    Node* prev;
    string nama;
    string umur;
    string alamat;
};

void Node::traversal( Node* root )
{
  if ( root == NULL ) { return; }
  traversal( getLeftNode() );
  //get the data of the node here and put it somewhere
  traversal( getRightNode() );
}
