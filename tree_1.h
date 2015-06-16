#include<iostream>
#include<string>
#include"node_1.h"
using namespace std;
#ifndef _Tree_H
#define _Tree_H

class Tree::Node{
public:
  Tree();
  Tree(string filename);
  ~Tree();
  
  Node* root;
  
  void insert(string newNama,string newUmur,string newAlamat);
  void search(string data,string type,Node *currentNode);
  void delete(string data,string type);
};

#endif
