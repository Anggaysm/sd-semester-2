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
    tail = NULL;
	
}

int isEmpty() // fungsi untuk memeriksa apakah linked list masih kosong
{
	if(tail == NULL) return 1;
    else return 0;
}

void insertDepan(int databaru) // Fungsi menambah node di depan
{
	TNode *baru; // deklarasi var node baru (node yang ditambahkan)
	baru = new TNode; // membuat node baru
	baru->data = databaru; // mengisikan data dalam node baru
	baru->next = NULL; //node baru belum menunjuk ke node lain
	if(isEmpty()==1){ // jika linked list masih kosong
				head=baru; //maka node baru akan menjadi head (node awal)
								// dan tail (node akhir)
                tail=baru;
				head->next=head;
                tail->next=tail;                            

	}
	else {
		baru->next = head;
        head = baru;
        tail->next = head;
	}
	cout<<"Data masuk\n"; // keterangan bahwa data sudah masuk ke list
}

void insertBelakang (int databaru) //Fungsi menambah di belakang
{
	TNode *baru;
    baru = new TNode;
    baru->data = databaru;
    baru->next = baru;
        if(isEmpty()==1){
            head=baru;
            tail=baru;
            head->next=head;
            tail->next=tail;
        }else {
            tail->next = baru;
            tail = baru;
            tail->next = head;
        }
    cout<<"Data masuk\n";

}

void tampil(){ 		// fungsi untuk menampilkan data dalam linked list
	TNode *b;
    b = head;
    if(isEmpty()==0){
        do{
        printf("%d",b->data);
        b=b->next;
        }while(b!=tail->next);
        printf("\n");
    } else  printf("Masih kosong\n");		
}

void hapusDepan()	// Fungsi untuk menghapus Node di depan
{
	TNode *hapus;
    if (isEmpty()==0){
        int d;
        hapus = head;
        d = head->data;
    if(head != tail){
        hapus = head;
        head = head->next;
        tail->next = head;
        delete hapus;
    }else{
        head=NULL;
        tail=NULL;
    }
    printf("%d terhapus\n",d);
    } else printf("Masih kosong\n1");
}

void hapusBelakang() //Fungsi untuk menghapus node dibelakang
{
	TNode *hapus,*bantu;
    if (isEmpty()==0){
         int d;
    if(head == tail){
        d = tail->data;
        head = NULL;
        tail = NULL;
    }else{
        bantu = head;
            while(bantu->next != tail){
            bantu = bantu->next;
    }
        hapus = tail;
        tail = bantu;
        d = hapus->data;
        tail->next = head;
        delete hapus;
    }
    printf("%d terhapus\n",d);
    } else printf("Masih kosong\n");
}

void clear() //fungsi menghapus semua node
{
    TNode *bantu,*hapus;
    if(isEmpty() == 0){
        bantu = head;
        while(bantu->next!=head){
            hapus = bantu;
            bantu = bantu->next;
            delete hapus;
    }
    head = NULL;
    tail = NULL;
    }
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