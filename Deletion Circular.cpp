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
    
    void remove(int nilai)
	{
    elemen *data = pokok;
    while ((data->berikut)->isi != nilai)
        data = data->berikut;
    elemen *hapus = data->berikut;
    data->berikut = hapus->berikut;
    delete hapus;

    return;
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
  
  cout << "Menghapus 2: ";
  l.remove(2);
  l.display();
}
