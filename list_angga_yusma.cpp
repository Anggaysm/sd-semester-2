#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct TNode{		// Mendeklarasikan Struct Node yang terdiri dari
	int data;		// Data	: data yang ada dalam linked list
	TNode *next;	// next	: merupakan pointer untuk menunjuk ke node berikutnya
};

TNode *head, *tail; // deklarasi Var pointer untuk menunjuk node
					// head : menunjuk node awal
					// tail : menunjuk node akhir

void init() // fungsi inisialisasi yang menyatakan linked list masih kosong
{
	head = NULL; // sehingga head masih kosong
	tail = NULL; // dan tail juga masih kosong
}

int isEmpty() // fungsi untuk memeriksa apakah linked list masih kosong
{
	if(tail == NULL) // jika tail = null maka list masih kosong
		return 1; // mengembalikan nilai 1 jika list kosong
	else return 0; // mengembalikan nilai 0 jika list sudah berisi
}

void insertDepan(int databaru) // Fungsi menambah node di depan
{
	TNode *baru; // deklarasi var node baru (node yang ditambahkan)
	baru = new TNode; // membuat node baru
	baru->data = databaru; // mengisikan data dalam node baru
	baru->next = NULL; //node baru belum menunjuk ke node lain
	if(isEmpty()==1){ // jika linked list masih kosong
				head=tail=baru; //maka node baru akan menjadi head (node awal)
								// dan tail (node akhir)
				tail->next=NULL; // tail belum menunjuk ke node yang lain
								 // (artinya hanya satu node dalam list)							
	}
	else {
			baru->next = head; // Jika dalam linked list sudahh ada node maka
							   // pointer node baru akan menunjuk head
							   // (node awal dalam linked list)
			head = baru; // maka node yang baru masuk akan menjadi head
	}
	cout<<"Data masuk\n"; // keterangan bahwa data sudah masuk ke list
}

void insertBelakang (int databaru) //Fungsi menambah di belakang
{
	TNode  *baru;
	baru  = new TNode;
	baru->data = databaru;
	baru->next = NULL;
	if (isEmpty()==1){
	head=baru;
	tail=baru;
	tail->next = NULL;
	}
	else {
		tail->next = baru; // Jika dalam linked list sudah ada node, maka node akhir
		 				   // (tail) akan menunjuk ke node baru
	tail=baru; // dan node yang  baru masuk akan menjadi tail		 				   
	}
	cout<<"Data masuk\n"; //keterangan bahwa data sudah masuk ke list
}

void tampil(){ 		// fungsi untuk menampilkan data dalam linked list
	TNode *bantu;	// Deklarasi var pointer bantu untuk menunjuk node-node
					// yang akan dibaca
	bantu = head;	// awalnya pointer bantu akan menunjuk ke head (node awal)				
		if(isEmpty()==0){ // Jika list tidak kosong
			while(bantu!=NULL){ // dan selama pointer bantu tidak menunjuk null
			cout<<bantu->data<<" "; // maka tampilan data
			bantu=bantu->next;	// pointer bantu akan bergerak ke node berikutnya
			}
		} else cout<<"Masih kosong\n"; //Jika list masih kosong				
	}

void hapusDepan()	// Fungsi untuk menghapus Node di depan
{
	TNode *hapus;	// Deklarasi pointer hapus untuk menunjuk node yang akan dihapus
	int d; // variabel sementara untuk menampung data yang akan dihapus
	if (isEmpty()==0){	// Jika list tidak kosong
		if(head!=tail){ // dan jika head tidak sama dengan Tail
						// artinya list berisi lebih dari satu node
			hapus = head; // maka pointer hapus untuk menunjuk node yang akan dihapus
			d = hapus->data; // pindahkan data yang dihapus ke var d.
			head = head->next; // pointer head akan menunjuk ke node berikutnya
			delete hapus;  // delete node yang dihapus
			}
			else {		// Jika head = tail artinya hanya satu node dalam list
			 d = tail->data; // maka langsung hapus tail
			 head=tail=NULL; // Linked list menjadi kosong
			}
	 cout<<d<<"terhapus"; //keterangan data terhapus
	 }
	 else cout<<"Masih kosong\n"; // Keterangan jika list masih kosong
}

void hapusBelakang() //Fungsi untuk menghapus node dibelakang
{
	TNode *bantu,*hapus; //Deklarasi pointer bantu untuk mencari
						//node yang akan dihapus
	int d;
	if (isEmpty()==0){
		 bantu = head; //awalnya pointer bantu akan menunjuk ke head
	 	   if(head!=tail){ //jika head tidak sama dengan tail
	 	   	while(bantu->next!=tail) // selama pointer bantu tidak menunjuk ke tail
	 		{   
	 			bantu = bantu->next; // maka pointer bantu akan bergerak sampai
	 								 // sebelum tail
			}
			 hapus = tail; //hapus tail (node paling belakang)
			 tail=bantu; //node yang ditunjuk oleh pointer bantu menjadi Tail
			 d = hapus->data;
			 delete hapus;
			 tail->next = NULL; //Pointer tail akan menujuk null
			 				
			}
            else{
                d = tail -> data;
                head = tail = NULL;
            }
            cout<<d<<" Terhapus\n";
	}else cout << "Masih Kosong\n";
}

void clear() //fungsi menghapus semua node
{
    TNode *bantu, *hapus;//menggunakan pointer bantu dan hapus
    bantu = head; // awalnya pointer bantu menunjuk ke head
    while (bantu!=NULL)
    {
        hapus = bantu; //pointer hapus akan menunjuk
                       //node yang ditunjuk oleh pointer baru
        bantu = bantu -> next; // Pointer bantu menunjuk ke node berikutnya
        delete hapus; // mendelete node yang ditunjuk oleh pointer hapus
    }
    head = NULL; //linked list kosong;
    printf("CLEAR"); //keterangan linked List sudah kosong
}

int main()
{
    int pil, databaru;

    do
    {
        system("cls");
        cout << endl<< endl;
        cout << "   ================================="<<endl;
        cout << "   =       PROGRAM LINKED LIST     ="<<endl;
        cout << "   ================================="<<endl;
        cout << "   = 1.Insert Depan                ="<<endl;
        cout << "   = 2.Insert Belakang             ="<<endl;
        cout << "   = 3.Delete Depan                ="<<endl;
        cout << "   = 4.Delete Belakang             ="<<endl;
        cout << "   = 5.Tampil Data                 ="<<endl;
        cout << "   = 6.Clear                       ="<<endl;
        cout << "   = 7.Exit                        ="<<endl;
        cout << "   ================================="<<endl;
        cout << "   Masukan Pilihan : ";cin>>pil;
        switch (pil)
        {
        case 1: system ("cls");{
            cout<<"Masukan Data = ";
            cin >> databaru;
            insertDepan(databaru);
            break;
        }
        case 2 : system ("cls");{
            cout << "Masukan Data = ";
            cin >> databaru;
            insertBelakang(databaru);
            break;
        }
        case 3 : system ("cls");{
            hapusDepan();
            break;
        }
        case 4 : system ("cls"); {
            hapusBelakang();
            break;
        }
        case 5 : system ("cls");{
            tampil();
            break;
        }
        case 6 : system ("cls");{
            clear();
            break;
        }
        case 7: {
            return 0;
            //break
        }
        default: system ("cls");{
            cout << "\n maaf, Pilihan yang anda pilih tidak tersedia!";
        }

        }
        system("pause");
    } while (pil!=7);
    
}