//for the menu
#include <iostream>
#include <cstdlib>
using namespace std;

//made for reference of outline
//do not make the details of every sub-menu
void menu();

void tampil_data(){
  char choice;
  while(cin>>choice){
    switch(choice){
      case '1':
        cout<<"checked\n";
        break;
      case '2':
        cout<<"checked\n";
        break;
      case '3':
        cout<<"checked\n";
        break;
      case '4':
        menu();
        break;
      default:
        cerr<<choice<<endl;
        break;
    }
  }
}
void tambah_karakter(){cout<<"checked\n";}
void kurang_karakter(){cout<<"checked\n";}
void keluar(){cout<<"checked, then bye\n";exit(EXIT_SUCCESS);}

void menu(){
  char choice;
  while(cin>>choice){
    switch(choice){
      case '1':
        tampil_data();
        break;
      case '2':
        tambah_karakter();
        break;
      case '3':
        kurang_karakter();
        break;
      case '4':
        keluar();
        break;
      default:
        try{
          throw choice;
        }
        catch(char choice){
          cerr<<choice<<endl;
        }
    }
  }
}

main(){
  menu();
}
