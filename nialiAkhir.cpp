#include <iostream>
using namespace std;

struct nilai_mahasiswa
{
    float nilaiAkhir;
    float tugas;
    float kuis;
    float uts;
    float uas;
};


struct mahasiswa{
    string nim;
    string name;
    string prodi;
    nilai_mahasiswa nilai;
};

int main (){
    int jumlahMahasiswa;
    cout << "Data mahasiswa yang ingin dimasukan : ";
    cin >> jumlahMahasiswa;
    
    mahasiswa mhs[jumlahMahasiswa];
    cout << "Data mahasiswa"<< endl;
    cout << "=============="<< endl;
    float nilaiTugas;
    for (int i = 0; i < jumlahMahasiswa; i++)
    {
        cout << "Data Mahasiswa ke-"<< i+1<<endl;
        cout << "Nim            :";cin>>mhs[i].nim;
        cout << "Nama           :";getline(cin>>ws, mhs[i].name);
        cout << "Nilai tugas    : ";cin>>mhs[i].nilai.tugas;
        cout << "Nilai Quis     : ";cin>>mhs[i].nilai.kuis;
        cout << "Nilai UTS      : ";cin>>mhs[i].nilai.uts;
        cout << "Nilai UAS      : ";cin>>mhs[i].nilai.uas;
    }
    for (int i = 0; i < jumlahMahasiswa; i++)
    {
        cout << "Data Mahasiswa ke-"<< i+1<<endl;
        cout << "Nim            :"<<mhs[i].nim<<endl;
        cout << "Nama           :"<<mhs[i].name<<endl;
        cout << "Nilai tugas    : "<<mhs[i].nilai.tugas<<endl;
        cout << "Nilai Quis     : "<<mhs[i].nilai.kuis<<endl;
        cout << "Nilai UTS      : "<<mhs[i].nilai.uts<<endl;
        cout << "Nilai UAS      : "<<mhs[i].nilai.uas<<endl;
        mhs[i].nilai.nilaiAkhir = (mhs[i].nilai.tugas * 30/100)+(mhs[i].nilai.kuis * 10/100)+(mhs[i].nilai.uts * 30/100)+(mhs[i].nilai.uas * 30/100);
        cout << "Nilai Akhir    : "<<mhs[i].nilai.nilaiAkhir<<endl;
        if (mhs[i].nilai.nilaiAkhir > 80){
            cout<< "Grade          : A"       <<endl<<endl;
        }else if (mhs[i].nilai.nilaiAkhir > 70 && mhs[i].nilai.nilaiAkhir <=85){
            cout<< "Grade          : B"       <<endl<<endl;
        }
        else if (mhs[i].nilai.nilaiAkhir > 55 && mhs[i].nilai.nilaiAkhir <=70)
        {
            cout<< "Grade          : C"       <<endl<<endl;
        }
        else if (mhs[i].nilai.nilaiAkhir > 40 && mhs[i].nilai.nilaiAkhir <=55)
        {
            cout<< "Grade          : D"       <<endl<<endl;
        }else if (mhs[i].nilai.nilaiAkhir <= 40 )
        {
            cout<< "Grade          : E"       <<endl<<endl;
        }
        
    }
    
}