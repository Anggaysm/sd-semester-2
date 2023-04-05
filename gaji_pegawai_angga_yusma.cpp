#include <iostream>
using namespace std;

int main(){
    int gajiPerJam = 6000;
    int bonus = gajiPerJam*3;
    int jam;
    cout << "Lama Kerja Perminggu(jam) : ";
    cin >> jam;
    int total = 0 ;
    int gajiPerminggu;
    string hari[7] = {"senin", "selasa", "rabu", "kamis", "jumat", "sabtu", "minggu"};
    
    if (jam >= 40)      
    {
        int lemburan = jam-40;
        int gajiLembur = lemburan * bonus;
        gajiPerminggu = gajiPerJam*jam;
        total = gajiLembur + gajiPerminggu - (lemburan*gajiPerJam) ;
    }else{
        total += gajiPerminggu;
    }
    int harian = total / 7;
    for (int i = 0; i < 7; i++)
    {
        cout << "gaji "<< hari[i] << " adalah : Rp"<< harian << endl;
    }
    
}