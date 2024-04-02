#include <iostream>
#include <stdexcept>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    string peminatan;

    struct biodata {
        char kelas;
        string no_hp;
        string email;
    } biodata;
};

const int jumlah_mahasiswa = 130;

void main_menu() {
    cout << "-----------------------Menu-----------------------\n";
    cout << "1. Lihat daftar\n";
    cout << "2. Tambah data\n";
    cout << "3. Ubah data\n";
    cout << "4. Hapus data\n";
    cout << "0. Keluar\n";
    cout << "Pilihan : ";
}

bool signup(string& username, string& password) {
    cout << "--Sign Up--" << endl;
    cout << "Masukkan username anda : ";
    getline(cin, username);
    cout << "Masukkan password anda : ";
    getline(cin, password);
    cout << "Sign Up berhasil" << endl;
    return true;
}

bool login(const string& username, const string& password) {
    string input_username, input_password;
    int i = 0;
    while (i < 3) {
        cout << "--Log In--" << endl;
        cout << "Masukkan username: ";
        getline(cin, input_username);
        cout << "Masukkan password: ";
        getline(cin, input_password);
        if (input_username == username && input_password == password || input_username == "putri jasmine h" && input_password == "2309106051") {
            cout << "Berhasil Log In" << endl;
            return true;
        } else {
            cout << "Log In Gagal. Coba lagi.\n";
            cout << "Percobaan Login ke-" << i + 1 << endl;
            i++;
        }
    }
    cout << "Anda telah gagal Log In sebanyak 3 kali. Program berhenti." << endl;
    return false;
}

void tampilkandata(Mahasiswa* data, int jumlah_data) {
    if (jumlah_data != 0) {
        cout << "-----Data Mahasiswa-----" << endl;
        for (int i = 0; i < jumlah_data; i++) {
            cout << "No." << i + 1 << endl;
            cout << "Nama : " << data[i].nama << endl;
            cout << "NIM : " << data[i].nim << endl;
            cout << "Kelas : " << data[i].biodata.kelas << endl;
            cout << "Peminatan : " << data[i].peminatan << endl;
            cout << "No.Hp : " << data[i].biodata.no_hp << endl;
            cout << "Email : " << data[i].biodata.email << endl;
        }
    } else {
        cout << "Daftar Kosong." << endl;
    }
}

bool tambahdata(Mahasiswa* data, int& jumlah_data, char& ulang) {
    if (jumlah_data < jumlah_mahasiswa) {
        do {
            cout << "Masukkan nama lengkap anda : ";
            cin.ignore();
            getline(cin, data[jumlah_data].nama);
            cout << "Masukkan NIM anda : ";
            getline(cin, data[jumlah_data].nim);
            cout << "Masukkan kelas anda : ";
            cin >> data[jumlah_data].biodata.kelas;
            cin.ignore();
            cout << "Peminatan anda : ";
            getline(cin, data[jumlah_data].peminatan);
            cin.ignore();
            cout << "Masukkan No.Hp anda : ";
            getline(cin, data[jumlah_data].biodata.no_hp);
            cin.ignore();
            cout << "Masukkan email anda : ";
            getline(cin, data[jumlah_data].biodata.email);
            cin.ignore();
            cout << "Data berhasil ditambahkan." << endl;
            jumlah_data++;
            cout << "Apakah ingin menambahkan data yang lain? (y/n) : ";
            cin >> ulang;
            cin.ignore();
        } while (ulang == 'y' || ulang == 'Y');
        if (ulang == 'y' || ulang == 'Y') {
            cin.ignore(); 
            tambahdata(data, jumlah_data, ulang);
            return true;
        } else {
            cin.ignore(); 
            return false;
        }
    } else {
        cout << "Jumlah data telah mencapai batas maksimum." << endl;
        return false;
    }
}


bool ubahdata(Mahasiswa* data, int& jumlah_data, char& yakin, int& pilihan) {
    if (jumlah_data > 0) {
        tampilkandata(data, jumlah_data);
        cout << "Masukkan nomor data yang ingin diubah: ";
        cin >> pilihan;
        cin.ignore();
        if (pilihan > 0 && pilihan <= jumlah_data) {
            pilihan--;
            Mahasiswa datasebelum = data[pilihan];
            cout << "Nama : ";
            getline(cin, data[pilihan].nama);
            cout << "NIM : ";
            getline(cin, data[pilihan].nim);
            cout << "Kelas : ";
            cin >> data[pilihan].biodata.kelas;
            cout << "Peminatan baru: ";
            cin.ignore();
            getline(cin, data[pilihan].peminatan);
            cout << "No.Hp : ";
            getline(cin,data[pilihan].biodata.no_hp);
            cout << "Email : ";
            getline(cin, data[pilihan].biodata.email);
            cout << "Yakin ingin mengubah (y/n)? : ";
            cin >> yakin;
            if (yakin == 'y' || yakin == 'Y') {
                cout << "Data berhasil diubah." << endl;
                return true;
            } else if (yakin == 'n' || yakin == 'N') {
                data[pilihan] = datasebelum;
                cout << "Pengubahan data dibatalkan." << endl;
                return false;
            } else {
                cout << "Input tidak valid. Pengubahan data dibatalkan." << endl;
                return false;
            }
        } else {
            cout << "Nomor data tidak valid." << endl;
            return false;
        }
    } else {
        cout << "Tidak ada data yang bisa diubah." << endl;
        return false;
    }
}

bool hapusdata(Mahasiswa* data, int& jumlah_data, int pilihan, char& yakin) {
    tampilkandata(data, jumlah_data);
    if (jumlah_data != 0) {
        cout << "Masukkan no data yang ingin dihapus : ";
        cin >> pilihan;
        if (pilihan >= 0 && pilihan < jumlah_mahasiswa) {
            cout << "Apakah anda yakin ingin menghapus data?(y/n)";
            cin >> yakin;
            if (yakin == 'y' || yakin == 'Y') {
                for (int i = pilihan; i < jumlah_mahasiswa - 1; i++) {
                    data[i] = data[i + 1];
                }
                jumlah_data--;
                cout << "Data berhasil dihapus." << endl;
                return true;
            }
            else if(yakin == 'n' || yakin == 'N'){
                cout << "Hapus Data dibatalkan" << endl;
                return false;
            }
            else {
                cout << "Hapus data dibatalkan" << endl;
                return false;
            }
        } else {
            cout << "Pilihan tidak valid";
            return false;
        }
    } else {
        return false;
    }
}

int main() {
    try {
        string username, password;
        Mahasiswa data[jumlah_mahasiswa];
        int jumlah_data = 0;
        char ulang, yakin;
        int pilihan;
        int pilihann;
        bool logged_in = false;
        bool signed_up = false;

        do {
            cout << "-----------------------Menu Awal-----------------------\n";
            cout << "1. Log In\n";
            cout << "2. Sign Up\n";
            cout << "0. Keluar\n";
            cout << "Pilihan : ";
            cin >> pilihan;
            cin.ignore(); 
            switch (pilihan) {
                case 1:
                    if (!logged_in) {
                        if (login(username, password)) {
                            logged_in = true;
                            cout << "Berhasil login." << endl;
                        }
                        else {
                            return 0; 
                        }
                    }
                    break;
                case 2: 
                    if (!signed_up) {
                        if (signup(username, password)) {
                            signed_up = true;
                            cout << "Berhasil sign up." << endl;
                        }
                    }
                    break;
                case 0: 
                    cout << "Keluar dari program." << endl;
                    break;
                default:
                    cout << "Pilihan tidak valid!" << endl;
            }

            while (logged_in) {
                main_menu();
                cin >> pilihann;
                cin.ignore(); 

                switch (pilihann) {
                    case 1: 
                        tampilkandata(data, jumlah_data);
                        break;
                    case 2:
                        tambahdata(data, jumlah_data, ulang);
                        break;
                    case 3:
                        ubahdata(data, jumlah_data, yakin, pilihan);
                        break;
                    case 4: 
                        hapusdata(data, jumlah_data, pilihan, yakin);
                        break;
                    case 0: 
                        cout << "Keluar." << endl;
                        logged_in = false;
                        break;
                    default:
                        cout << "Pilihan tidak valid!" << endl;
                }
            }
        } while (pilihann != 0);

    } catch (const exception& e) {
        cerr << "Kesalahan: " << e.what() << endl;
    }

    return 0;
}