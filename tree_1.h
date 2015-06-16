#include<iostream>
#include<string>
#include"node_1.h"
using namespace std;
#ifndef _TREE_H_
#define _TREE_H_

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
