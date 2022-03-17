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

      if (nilai == 1)
        pokok = data;
      else
      {
        data->berikut = pokok;
        pokok = data;
      }
    }
    
	bool search(int nilai)
    {
      elemen* sementara = pokok;
      while(sementara != 0)
      {
        if (sementara->isi == nilai)
          return true;
        sementara = sementara->berikut;
      }
      return false;
    }

    void display()
    {
      elemen* sementara = pokok;
      while(sementara != 0)
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
  cout << "Mencari elemen 5: ";
  cout << l.search(5) << endl;
}
