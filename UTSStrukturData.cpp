#include <iostream>
using namespace std;

// Struktur untuk menyimpan informasi kamar
struct Kamar {
    int noKamar;
    string namaPenyewa;
    bool sudahDipesan;
};

// Fungsi untuk menampilkan menu pilihan
void tampilanMenu() {
    cout << "\nSELAMAT DATANG DI HOTEL ANGKASAPUTRA" << endl;
    cout << "------------------------------------" << endl;
    cout << "KENYAMANAN ANDA IALAH PRIORITAS KAMI" << endl;
    cout << "\n           PILIHAN MENU           " << endl;
    cout << "\n1. RESERVASI KAMAR" << endl;
    cout << "2. DAFTAR KAMAR" << endl;
    cout << "3. KELUAR" << endl;
}

int main() {
    const int nomorKamar = 100; // Jumlah kamar
    Kamar infoHotel[nomorKamar]; // Array 2 dimensi untuk menyimpan informasi kamar

    // Inisialisasi data awal
    for (int i = 0; i < nomorKamar; ++i) {
        infoHotel[i].noKamar = i + 1;
        infoHotel[i].namaPenyewa = "";
        infoHotel[i].sudahDipesan = false;
    }

    int pilihMenu;
    do {
        tampilanMenu();
        cout << "\nPILIH MENU : ";
        cin >> pilihMenu;

        switch (pilihMenu) {
            case 1: // Reservasi Kamar
                int kamarHotel;
                cout << "\nSILAHKAN PILIH NOMOR RUANGAN YANG INGIN ANDA PESAN (1-100) : ";
                cin >> kamarHotel;

                if (kamarHotel >= 1 && kamarHotel <= nomorKamar) {
                    if (!infoHotel[kamarHotel - 1].sudahDipesan) {
                        cout << "NAMA TAMU ( ANDA ) : ";
                        cin.ignore(); // Membersihkan buffer
                        getline(cin, infoHotel[kamarHotel - 1].namaPenyewa);
                        infoHotel[kamarHotel - 1].sudahDipesan = true;
                        cout << "\nKAMAR BERHASIL DIPESAN!" << endl;
                    } else {
                        cout << "KAMAR SUDAH DIPESAN :(" << endl;
                    }
                } else {
                    cout << "NOMOR KAMAR TIDAK VALID!" << endl;
                }
                break;

            case 2: // Lihat Daftar Kamar
                cout << "\nDAFTAR KAMAR : " << endl;
                for (int i = 0; i < nomorKamar; ++i) {
                    cout << "KAMAR " << infoHotel[i].noKamar << ": ";
                    if (infoHotel[i].sudahDipesan) {
                        cout << "TELAH DIPESAN OLEH : " << infoHotel[i].namaPenyewa;
                    } else {
                        cout << "TERSEDIA";
                    }
                    cout << endl;
                }
                break;

            case 3: // Keluar
                cout << "\nTERIMA KASIH!!, SEMOGA ANDA MERASA NYAMAN DISINI" << endl;
                break;

            default:
                cout << "PILIHAN ANDA TIDAK VALID! MOHON UNTUK COBA LAGI" << endl;
        }
    } while (pilihMenu != 3);

    return 0;
}
