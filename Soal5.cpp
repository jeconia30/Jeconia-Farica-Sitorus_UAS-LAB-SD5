#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int interpolationSearch(vector<int> arr, int x) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high && x >= arr[low] && x <= arr[high]) {
        int pos = low + ((x - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if (arr[pos] == x)
            return pos;

        if (arr[pos] < x)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}

int main() {
    int n, cari;

    cin >> n;
    vector<int> kursi(n);

    for (int i = 0; i < n; i++) {
        cin >> kursi[i];
    }

    cin >> cari;

    int hasil = interpolationSearch(kursi, cari);

    if (hasil != -1) {
        cout << "Nomor kursi: " << cari << endl;
        cout << "Status: TERSEDIA" << endl;
        cout << "Posisi index: " << hasil << endl;
    } else {
        cout << "Nomor kursi: " << cari << endl;
        cout << "Status: TIDAK TERSEDIA" << endl;

        int closest = -1;
        int selisihMin = 999;

        for (int i = 0; i < n; i++) {
            int selisih = abs(kursi[i] - cari);
            if (selisih < selisihMin) {
                selisihMin = selisih;
                closest = kursi[i];
            }
        }

        cout << "Kursi terdekat yang tersedia adalah No: " << closest << endl;
    }

    return 0;
}
