#include<iostream>
#include<string>
using namespace std;
#ifndef _NODE_1_H_
#define _NODE_1_H_

class Node
{
  public:
    Node();
    Node(string newNama, string newUmur, string newAlamat);
    
    Node* getLeftNode();
    Node* getRightNode();
    string getNama();
    string getUmur();
    string getAlamat();
    
    void setLeftNode( Node* newNode );
    void setRightNode( Node* newNode );
    void setNama( string newNama );
    void setUmur( string newUmur );
    void setAlamat( string newAlamat );
    void traversal();
    void printNode();

    ~Node();
  
  private:
    Node* left;
    Node* right;
    Node* prev;
    string nama;
    string umur;
    string alamat;
};
#endif
