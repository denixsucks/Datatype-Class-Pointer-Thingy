#include<iostream>
using namespace std;

struct eleman{
  int veri;
  eleman* sonraki;
};

void olustur(eleman *ptr)
{
  // Elemanlari 100'den 1000'e 10 elemanli liste olustur.
  for (int i=1;i<=10;i++)
  {
    ptr->veri = i*100;
    ptr->sonraki = new eleman;
    ptr = ptr->sonraki;
  }
  ptr->sonraki = NULL;
}

void yazdir(eleman *ptr)
{
  while(ptr->sonraki!=NULL)
  {
    cout<<ptr->veri<<endl;
    ptr = ptr->sonraki;
  }
}
void sonaekle(eleman *ptr, int data)
{
  // eleman eklemek icin son elemani bul
  while(ptr->sonraki!=NULL)
  {
    cout<<ptr->veri<<endl;
    ptr = ptr->sonraki;
  }
  // elemani ekle
  ptr->sonraki = new eleman;
  ptr = ptr->sonraki;
  ptr->veri = data;
  ptr->sonraki = NULL;
}

int ara(eleman *ptr, int aranan)
{
  int sayac = 1; // Kacinci siradaki eleman?
  while(ptr->sonraki!=NULL)
  {
    if (ptr->veri == aranan)
    {
      return sayac;
      if (ptr->sonraki == NULL) return 0;// Aranan eleman listede yoksa
    }
    sayac++;
    ptr = ptr->sonraki;
  }
  return 0;
}

void arayaekle(eleman *ptr, int sira, int data)
{
  for(int i=1;i<sira;i++)
  {
    ptr = ptr->sonraki;
  }
  // Yeni eleman olustur
  eleman *yeni = new eleman;
  yeni->sonraki = ptr->sonraki;
  yeni->veri = data;
  ptr->sonraki = yeni;
}

void sil(eleman *ptr, int sira)
{
  for(int i=1;i<sira-1;i++) // 1 onceki elemanda dur
  {
    ptr = ptr->sonraki;
  }
  ptr->sonraki = ptr->sonraki->sonraki;
}



void yerdegistir(eleman *ptr, int sira1, int sira2)
{
  int temp;     //ilk secilen elemanin datasini saklaman icin temp integeri olusturma
  eleman *gosterici = new eleman;  //secilecek 2.eleman icin gosterici olusturma
  gosterici = ptr;   //gostericiyi root`a baglama
  
  for(int i=1;i<sira1;i++)
  {
    ptr = ptr->sonraki;         
  }
   for(int k=1;k<sira2;k++)
  {
    gosterici = ptr->sonraki;
  }

  //Swap-Takas Yontemi
  temp = ptr->veri;   // sira1 deki elemani tempte saklama
  ptr -> veri = gosterici -> veri;    //sira1 deki elemani sira2ye atama
  gosterici -> veri = temp;           //sira2deki elemani saklanan temp verisine atama
}

int main()
{
  // root pointer ile ilk elemani tanımla
  eleman* root = new eleman;
  // Liste olustur
  olustur(root);

  yerdegistir(root,4,5);

  // Listeyi yazdir
  yazdir(root);

  return 0;
}