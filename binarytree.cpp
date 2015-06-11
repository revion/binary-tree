//binary tree are consist of key, left, right, and element
//insert -> left is smallest, right is largest, root is filled in the beginning of input

#include<iostream>
#include<string>
using namespace std;

class Data{
  string n,u,a; //nama,umur,alamat
public:
  //Constractor
  Data(){};

  //setter
  void setnama(string na){n=na;}
  void setumur(string um){u=um;}
  void setalamat(string al){a=al;}

  //getter
  string getnama()const{return n;}
  string getumur()const{return u;}
  string getalamat()const{return a;}

  //method
  void input(string na,string um,string al);
  void print(string na,string um,string al);
};

void Data::input(string na,string um,string al){
  cin>>na;
  setnama(na);
  cin>>um;
  setumur(um);
  cin>>al;
  setalamat(al);
}

void Data::print(string na,string um,string al){
  cout<<"Nama: "<<getnama()<<endl;
  cout<<"Umur: "<<getumur()<<endl;
  cout<<"Alamat: "<<getalamat()<<endl;
}

/*
class Node{
};
*/

/*
class binarytree::Node{
  Node l,r,p;
public:
  void create();
};
*/

main(){
  Data data1;
  string na,um,al;
  data1.input(na,um,al);
  /*cin>>na;
  data1.setnama(na);
  cin>>um;
  data1.setumur(um);
  cin>>al;
  data1.setalamat(al);*/
  data1.print(na,um,al);
}
