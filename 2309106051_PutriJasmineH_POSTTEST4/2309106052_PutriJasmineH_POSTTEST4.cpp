// Nama : Putri Jasmine H
// NIM : 2309106051


#include <iostream>
#include <stdexcept>
using namespace std;



struct Mahasiswa {
    string nama;
    string nim;
    string peminatan;

    struct biodata{
        char kelas;
        string no_hp;
        string email;
    }biodata;
};

const int jumlah_mahasiswa = 130;


void menu(){
    cout << "1. lihat daftar\n";
    cout << "2. tambah data\n";
    cout << "3. ubah data\n";
    cout << "4. hapus data\n";
    cout << "0. Keluar\n";
    cout << "Pilih : ";
}




bool signup(string& username, string& password, char yakin){
    cout << "--Sign Up--" << endl;
    cout << "Apakah anda yakin ingin sign up?(y/n) : ";
    cin >> yakin;
    // cin.ignore();
    if (yakin == 'y' || yakin == 'Y'){
        cout << "Masukkan username anda : ";
        getline(cin, username);
        cin.ignore();
        cout << "Masukkan password anda : ";
        getline(cin, password);
        cin.ignore();
        cout << "Sign Up berhasil" << endl;
        return true;
    }
    else{
        cout << "Sign Up dibatalkan\n";
        return false;
    }
}


bool login(string& username, string& password, string& inputnama, string& inputnim) {
    int i = 0;
    while (i < 3) {
        cout << "--Log In--" << endl;
        cout << "Masukkan username: ";
        getline(cin, inputnama);
        // cin.ignore();
        cout << "Masukkan password: ";
        getline(cin, inputnim);
        // cin.ignore();

        if ((inputnama == username && inputnim == password) || (inputnama == "putri jasmine h" && inputnim == "2309106051")) {
            cout << "Berhasil Log In" << endl;
            return true;
        }
        else {
            cout << "Log In Gagal. Coba lagi." << endl;
            i++;
        }
    }
    cout << "Anda telah gagal Log In sebanyak 3 kali." << endl;
    return false;
}





void tampilkandata(Mahasiswa data[jumlah_mahasiswa], int& jumlah_data) {
    if (jumlah_data != 0) {
        cout << "-----Data Mahasiswa-----" << endl;
        for (int i = 0; i < jumlah_data; i++) { 
            cout << "No." << i + 1 << endl;
            cout << "Nama : " << data[i].nama << endl;
            cout << "NIM : " << data[i].nim << endl;
            cout << "Kelas : " << data[i].biodata.kelas;
            cout << "Peminatan : " << data[i].peminatan << endl;
            cout << "No.Hp : " << data[i].biodata.no_hp << endl;
            cout << "Email : " << data[i].biodata.email;
        }
    } 
    else {
        cout << "Daftar Kosong." << endl;
    }
}



bool tambahdata(Mahasiswa data[jumlah_mahasiswa], int& jumlah_data, char ulang){
    if (jumlah_data <= jumlah_mahasiswa){
        cout << "Masukkan nama lengkap anda : ";
        cin.ignore();
        getline(cin,data[jumlah_data].nama);
        cout << "Masukkan NIM anda : ";
        cin >> data[jumlah_data].nim;
        cin.ignore();
        cout << "Masukkan kelas anda : ";
        cin >> data[jumlah_data].biodata.kelas; 
        cin.ignore();
        cout << "Peminatan anda : ";
        getline(cin,data[jumlah_data].peminatan);
        cout << "Masukkan No.Hp anda : ";
        cin >> data[jumlah_data].biodata.no_hp;
        cin.ignore();
        cout << "Masukkan email anda : ";
        getline(cin,data[jumlah_data].biodata.email);
        cin.ignore();
        cout << "Data berhasil ditambahkan." << endl;
        jumlah_data++;
        cout << "Apakah ingin menambahkan data yang lain? (y/n) : ";
        cin >> ulang;
        if (ulang == 'y' || ulang == 'Y'){
            tambahdata(data, jumlah_data, ulang);
            return true;
        }
        else{
            return false;
        }
    
    }
    else{
        cout << "Jumlah dari data telah penuh";
        return false;
    }
}


bool ubahdata(Mahasiswa data[jumlah_mahasiswa], int& jumlah_data, char yakin, int pilihan) {
    if (jumlah_data > 0) {
        tampilkandata(data, jumlah_data); 
        cout << "Masukkan nomor data yang ingin diubah: ";
        cin >> pilihan;
        cin.ignore(); 
        if (pilihan > 0 && pilihan <= jumlah_data) {
            pilihan--; 
            cout << "Nama : ";
            getline(cin, data[pilihan].nama);
            cout << "NIM : ";
            getline(cin, data[pilihan].nim);
            cout << "Peminatan baru: ";
            getline(cin, data[pilihan].peminatan);
            cout << "Yakin ingin mengubah (y/n)? : ";
            cin >> yakin;
            if (yakin == 'y' || yakin == 'Y') {
                cout << "Data berhasil diubah." << endl;
                return true;
            } 
            else if (yakin == 'n' || yakin == 'N') {
                cout << "Pengubahan data dibatalkan." << endl;
                return false;
            } 
            else {
                cout << "Input tidak valid. Pengubahan data dibatalkan." << endl;
                return false;
            }
        } 
        else {
            cout << "Nomor data tidak valid." << endl;
            return false;
        }
    } 
    else {
        cout << "Tidak ada data yang bisa diubah." << endl;
        return false;
    }
}





bool hapusdata(Mahasiswa data[], int& jumlah_data,int pilihan, char yakin){
    tampilkandata(data,jumlah_data);
    if (jumlah_data !=0){
        cout << "Masukkan no data yang ingin dihapus : ";
        cin >> pilihan;
        if (pilihan >=0 && pilihan < jumlah_mahasiswa){
            cout << "Apakah anda yakin ingin menghapus data?(y/n)";
            cin >> yakin;
            if(yakin == 'y'){ 
                for (int i = pilihan; i < jumlah_mahasiswa -1; i++){
                    data[i] = data[i+1];
                }
                jumlah_data--;
                cout << "Data berhasil dihapus." << endl;
                return true;
            }
            else{
                cout << "Hapus data dibatalkan" << endl;
                return false;
            }
        }
        else{
            cout << "Pilihan tidak valid";
            return false;
        }
    }
    else{
        return false;
    }
}



int main(){
    try {
        int pilihan,pilihann;
        int jumlah_data = 0;
        string username, nim, inputnama, inputnim, password;
        char yakin, ulang;
        Mahasiswa data[jumlah_mahasiswa];

        cout << "--------------------------------------------------\n";
        cout << "---Daftar Peminatan Mahasiswa Informatika Unmul---\n";
        cout << "--------------------------------------------------\n";
        cout << "-----------------------Menu-----------------------\n";
        cout << "1. Log In\n";
        cout << "2. Sign Up\n";
        cout << "Pilihan : ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
                if (login(username, inputnama, inputnim, password)) {
                    do {
                        menu();
                        cin >> pilihann;
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
                                cout << "Berhasil keluar";
                                break;
                            default:
                                cout << "Pilihan tidak valid!" << endl;
                        }
                    } while (pilihann != 0);
                }
            }
        else if (pilihan == 2){
            signup(username,password,yakin);
            return main();
        }
        else{
            throw invalid_argument("Pilihan tidak valid");
        }
    }
    catch (const exception& e) {
        cerr << "Kesalahan: " << e.what() << endl;
    }

    return 0;
}