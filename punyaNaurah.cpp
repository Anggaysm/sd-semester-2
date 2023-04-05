#include <iostream>
using namespace std;

const int jumlah_pegawai = 3;
const int jam_normal = 40;
const int gaji_per_jam = 6000;

// fungsi untuk menghitung gaji perminggu
int hitungGaji(int jam_kerja) {
    int gaji_harian = 0;
    if (jam_kerja > jam_normal) {
        int jam_lembur = jam_kerja - jam_normal;
        gaji_harian = (jam_normal * gaji_per_jam) + (jam_lembur * gaji_per_jam * 3);
    } else {
        gaji_harian = jam_kerja * gaji_per_jam;
    }
    return gaji_harian;
}

int main() {
    int jam_kerja[jumlah_pegawai];

    // input jumlah jam kerja per minggu untuk setiap pegawai
    for (int i = 0; i < jumlah_pegawai; i++) {
        cout << "Masukkan jumlah jam kerja pegawai ke-" << i+1 << ": ";
        cin >> jam_kerja[i];
    }

    // hitung dan tampilkan gaji harian untuk setiap pegawai
    cout << "Gaji harian pegawai:" << endl;
    for (int i = 0; i < jumlah_pegawai; i++) {
        int gaji_harian = hitungGaji(jam_kerja[i]);
        cout << "Pegawai ke-" << i+1 << ": " << gaji_harian << endl;
    }

    return 0;
}