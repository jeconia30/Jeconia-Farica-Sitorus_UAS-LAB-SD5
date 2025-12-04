#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Pelanggan {
    string nama;
    int berat;
    string layanan; 
    int urutan;     
    int waktu;      
};

int main() {
    int n;
    cout << "Masukkan jumlah pelanggan: ";
    cin >> n;

    vector<Pelanggan> daftar(n);

    for (int i = 0; i < n; i++) {
        cin >> daftar[i].nama >> daftar[i].berat >> daftar[i].layanan;
        daftar[i].urutan = i; 
        
        if (daftar[i].layanan == "express") {
            daftar[i].waktu = daftar[i].berat * 5;
        } else {
            daftar[i].waktu = daftar[i].berat * 10;
        }
    }

    sort(daftar.begin(), daftar.end(), [](Pelanggan a, Pelanggan b) {
        if (a.layanan == b.layanan) {
            return a.urutan < b.urutan; 
        }
        return a.layanan == "express"; 
    });

    cout << "\nUrutan Pemrosesan:\n";
    int total_waktu = 0;
    for (auto &p : daftar) {
        cout << p.nama << endl;
        total_waktu += p.waktu;
    }

    cout << "\nTotal waktu yang dibutuhkan: " << total_waktu << " menit\n";

    return 0;
}
