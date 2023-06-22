#include <iostream>

#define MAX_STACK 10 //deklarasi stack dapat menampung max 10 data

using namespace std;

struct STACK //deklarasi struct untuk stack
{ int top; //var untuk menentukan posisi atas stack
  string data[10]; //var untuk data yang akan disimpan dalam stack
  };
  
STACK tumpuk; //deklarasi variabel stack

void inisialisasi() //fungsi persiapan
{ tumpuk.top= -1;} // mendefinisikan stack kosong, maka top bernilai -1

int IsFull() //fungsi untuk memeriksa apakah stack penuh
{
   if(tumpuk.top== MAX_STACK-1) //jika top = max_stack -1
       return 1;// maka fungsi mengembalikan nilai 1, artinya stack dalam keeadaan penuh
   else //jika tidak
       return 0; //maka fungsi mengembalikan nilai 0, artinya stack belum penuh
}

int IsEmpty() //fungsi untuk memeriksa apakah stack kosong
{
	if(tumpuk.top == -1) //jika top = -1,
		return 1; //maka fungsi mengembalikan nilai 1, artinya stack dalam keadaan kosong
	else // jika tidak
		return 0; //maka fungsi mengembalikan nilai 0, artiniya stack sudah berisi data
}

void Push(string d) // fungsi untuk memasukkan data ke dalam stack
{ tumpuk.top++; // setiap ada data masuk, maka posisi top akan bertambah 1
  tumpuk.data[tumpuk.top]=d; //menyimpan data dalam stack
}

void pop() //fungsi untuk menghapus data dalam stack
{ cout<<"Elemen terakhir stack sudah dihapus, yaitu : "<<tumpuk.data[tumpuk.top]<<endl;
		// menghapus data pada posisi atas
  tumpuk.top--; } // posisi atas berkurang 1, karena 1 data telah terhapus
  
void Clear() // fungsi untuk menghapus semua data dalam stack (meriset stack)  }
{ tumpuk.top=-1; } // posisi top dijadikan -1, maka stack akan kosong

void TampilStack() //fungsi untuk menampilkan data yang ada dalam stack
{
	for(int i=tumpuk.top;1>=0;i--) //Looping dari posisi atas sampai posisi paling bawah
	{ cout<<"Data : "<<tumpuk.data[i]<<endl; } //T Tampilkan data yang ada dalam stack
}

int main() // program utama
{
	int pil; // var untuk pilihan menu
	inisialisasi(); //memanggil fungsi inisialisasi
	string dt; // var untuk data yang akan dimasukkan ke stack
	
do{
	cout<<endl;
	cout<<"PILIHAN PROSES\n"; //pilihan menu proses
	cout<<"[1] Masukkan Data\n";
	cout<<"[2] Hapus Data\n";
	cout<<"[3] Tampil Isi Stack\n";
	cout<<"[4] Mereset Stack\n";
	cout<<"[5] Keluar\n";
	cout<<"Masukkan kode pilihan (1 ... 5) : ";
	cin>>pil;
	cout<<endl;
	
	switch(pil)
	{
	   case 1: if(IsFull() != 1) // jika stack tidak penuh
	   { cout<<"Masukkan Data : "; // masukan data ke stack
	   cin>>dt;
	   Push(dt); // memanggil fungsi push
	   cout<<endl;}
	   else
	    cout<<"\n Sudah penuh, push gagal!\n"; // jika stack penuh tampil pesan
	   break;
	   
	   case 2: if(IsEmpty() != 1) // jika stack tidak kosong
	    pop();//memanggil fungsi pop untuk menghapus stack
	   else
	    cout<<"\nMasih kosong!\n"; // jika stack kosong ma atampil pesan
	   break;
	   
	   case 3: if(IsEmpty() != 1)// jika stack tidak kosong
	    TampilStack();// maka tampilan data stack
	   else
	    cout<< "\n Stack kosong!\n"; // jika stack kosong tampilkan pesan
	   break;
	   
	   case 4: Clear(); //memanggil fungsi clear untuk menghapus semua data
	    cout<<"\n Stack sudah di hapus!\n";
	   break;
	}
  }while(pil!= 5);
 return 0;
}
		
	
