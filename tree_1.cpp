#include "tree_1.h"

void Tree::insert(string newNama,string newUmur,string newAlamat){
  Node* currentNode=root;
  Node* prevNode;
  bool goLeft;
  while(currentNode!=NULL){
    prevNode=currentNode;
    comparedNama=currentNode.getNama();
    if(newNama<comparedNama){
      currentNode=currentNode.getLeftNode();
      goLeft=true;
    } else if(comparedNama<newNama){
      currentNode=currentNode.getRightNode();
      goLeft=false;
    } else{
    }
    if(goLeft){
      prevNode.setLeftNode(newNama,newUmur,newAlamat);
    } else{
      prevNode.setRightNode(newNama,newUmur,newAlamat);
    }
  }
}

void Tree::delete(string data,string type){
  Node *tbd=search(data,type,root);
  Node *replacement=tbd.getRightNode();
  while(replacement.getLeftNode()!=NULL){
    replacement=replacement.getLeftNode();
  }
  tbd.getPrevNode().getRightNode(replacement);
  tbd.setLeftNode(tbd.getLeftNode());
  //destruction
}

void Tree::search(string data,string type,Node* currentNode){
  if(currentNode==NULL){
    return;
  }
  search(currentNode.getLeftNode());
  if(type=="nama"&&currentNode.getNama()==data){
    return currentNode;
  }
  if(type=="umur"&&currentNode.getNama()==data){
    return currentNode;
  }
  if(type=="alamat"&&currentNode.getNama()==data){
    return currentNode;
  }
  search(currentNode.getRightNode());
  return;
}