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
    char grade;
};

char mutu(int na){
    mahasiswa mhs;
    if (na > 80)
    {
        return 'A';
    }else if (na > 70 && na <=85){
        return 'B';
    }
    else if (na > 55 && na <=70)
    {
        return 'C';
    }
    else if (na > 40 && na <=55)
    {
        return 'D';
    }else if (na <= 40 )
    {
        return 'E';
    }
    return 0;
}
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
    cout << endl << endl;
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
        mhs[i].grade = mutu(mhs[i].nilai.nilaiAkhir);
        cout << "Grade          : "<< mhs[i].grade<<endl<<endl;
    }
    
}