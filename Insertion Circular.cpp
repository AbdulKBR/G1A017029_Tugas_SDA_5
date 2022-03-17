#include <iostream>
using namespace std;

struct elemen { 
  int isi; 
  elemen *berikut; 
};

class CircularLinkedList
{
  elemen* pokok;

  public:

    void insert(int nilai)
    {
      elemen* data = new elemen;
      data->isi = nilai;
      data->berikut = NULL;

      if (nilai == 1)
        pokok = data;
      else
      {
        data->berikut = pokok;
        pokok = data;
      }
    }


    void display()
    {
      elemen* sementara = pokok;
      while(sementara != NULL)
      {
        cout << sementara->isi << " ";
        sementara = sementara->berikut;
      }
      cout << endl;
    }
};

int main() {
  
  CircularLinkedList l;
  l.insert(2);
  l.insert(3);
  l.insert(4);
  cout << "Elemen CSLL: ";
  l.display();
}
