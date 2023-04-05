#include <iostream>
#include <iomanip>
using namespace std;

struct mahasiswa{
    char nim[10] ;
    string nama;
    string prodi;
    float ipk;
};

main(){
    mahasiswa mhs [5];
    for(int i=0; i < 5; i++){

    cout << "Data Mahasiswa"<<endl;
    cout << "=============="<<endl;
    cout << endl;
    cout << "Masukan Nim    :"; cin >> mhs[i].nim;
    cout << "Masukan Nama   :"; getline(cin>>ws, mhs[i].nama);
    cout << "Masukan Prodi  :"; getline(cin>>ws, mhs[i].prodi) ;
    cout << "Masukan IPK    :"; cin >> mhs[i].ipk;
    }

    for(int i=0; i < 5; i++){

    cout << endl;
    cout << "=============="<<endl;
    cout << "NIm Anda   :"<<mhs[i].nim<<endl;
    cout << "Nama Anda  :"<<mhs[i].nama<<endl;
    cout << "prodi Anda :"<<mhs[i].prodi<<endl;
    cout << "IPK Anda   :"<<mhs[i].ipk<<endl;
    }
}