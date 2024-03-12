// Nama : Putri Jasmine H
// NIM : 2309106051


#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    string peminatan;
};
const int jumlah_mahasiswa = 130;


int menu(int pilihann){
    cout << "1. lihat daftar\n";
    cout << "2. tambah data\n";
    cout << "3. ubah data\n";
    cout << "4. hapus data\n";
    cout << "0. Keluar\n";
    cout << "Pilih : ";
    cin >> pilihann;
    return pilihann;
}



bool login(string& nama, string& inputnama, string& inputnim, string& password) {
    int i = 0;
    while (i < 3) {
        cout << "--Log In--" << endl;
        cout << "Masukkan nama: ";
        getline(cin, inputnama);
        cout << "Masukkan NIM: ";
        cin >> inputnim;
        cin.ignore();
        if ((inputnama == nama && inputnim == password) || (inputnama == "putri jasmine h" && inputnim == "2309106051")) {
            cout << "Berhasil Log In" << endl;
            return true;
        } else {
            cout << "Log In Gagal. Coba lagi." << endl;
            i++;
        }
    }
    cout << "Anda telah gagal Log In sebanyak 3 kali." << endl;
    return false;
}


bool signup(string& nama, string& password, char yakin){
    cout << "--Sign Up--" << endl;
    cout << "Apakah anda yakin ingin sign up?(y/n) : ";
    cin >> yakin;
    cin.ignore();
    if (yakin == 'y' || yakin == 'Y'){
        cout << "Masukkan nama anda : ";
        getline(cin,nama);
        cout << "Masukkan NIM anda sebagai password : ";
        cin >> password;
        cin.ignore();
        cout << "Sign Up berhasil" << endl;
        return true;
    }
    else{
        cout << "Sign Up dibatalkan\n";
        return false;
    }
}


bool tampilkandata(Mahasiswa data[jumlah_mahasiswa], int& jumlah_data) {
    if (jumlah_data != 0) {
        cout << "-----Data Mahasiswa-----" << endl;
        for (int i = 0; i < jumlah_data; i++) { 
            cout << "No." << i + 1 << endl;
            cout << "Nama : " << data[i].nama << endl;
            cout << "NIM : " << data[i].nim << endl;
            cout << "Peminatan : " << data[i].peminatan << endl;
        }
        return true;
    } else {
        cout << "Daftar Kosong." << endl;
        return false;
    }
}



bool tambahdata(Mahasiswa data[jumlah_mahasiswa], int& jumlah_data){
    if (jumlah_data <= jumlah_mahasiswa){
        cout << "Masukkan nama lengkap anda : ";
        cin.ignore();
        getline(cin,data[jumlah_data].nama);
        cout << "Masukkan NIM anda : ";
        cin >> data[jumlah_data].nim;
        cin.ignore();
        cout << "Peminatan anda : ";
        getline(cin,data[jumlah_data].peminatan);
        cout << "Data berhasil ditambahkan." << endl;
        jumlah_data++;
        return true;
    }
    else{
        cout << "Jumlah dari data telah penuh";
        return false;
    }
}


bool ubahdata(Mahasiswa data[jumlah_mahasiswa], int& jumlah_data, char yakin) {
    if (jumlah_data > 0) {
        tampilkandata(data, jumlah_data); 
        int pilihan;
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
            } else {
                cout << "Pengubahan data dibatalkan." << endl;
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



bool hapusdata(Mahasiswa data[], int& jumlah_data,int pilihan, char yakin){
    tampilkandata(data,jumlah_data);
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
    }
    return false;
}



int main(){
    int pilihan,pilihann;
    int jumlah_data = 0;
    string nama, nim, inputnama, inputnim, password;
    char yakin;
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
            if (login(nama, inputnama, inputnim, password)) {
                do {
                    pilihann = menu(pilihan);
                    switch (pilihann) {
                        case 1:
                            tampilkandata(data, jumlah_data);
                            break;
                        case 2:
                            tambahdata(data, jumlah_data);
                            break;
                        case 3:
                            ubahdata(data, jumlah_data, yakin);
                            break;
                        case 4:
                            hapusdata(data, jumlah_data, pilihan, yakin);
                            break;
                        case 0:
                            cout << "Berhasil keluar";
                            break;
                        default:
                            cout << "Pilihan tidak valid!";
                    }
                } while (pilihann != 0);
            }
        }
    else if (pilihan == 2){
        signup(nama,password,yakin);
        return main();
    }
    else{
        cout << "Pilihan tidak valid";
        return main();
    }

    return 0;
}