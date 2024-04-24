#include <iostream>
#include <stdexcept>
using namespace std;

// metode sorting : mergesort, quicksort, insertionsort
// metode seraching : sequentialserach & binarysearch

struct Mahasiswa {
    string nama;
    int nim;
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
    cout << "5. Cari data\n";
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

void merge(int high, int low, int mid, Mahasiswa* data){
    Mahasiswa temp[high-low+1]; 
    int i = low;
    int j = mid + 1;
    int k = 0;
    
    while(i <= mid && j <= high){
        if (data[i].nama <= data[j].nama){
            temp[k] = data[i];
            k++;
            i++;
        }else{
            temp[k] = data[j];
            k++;
            j++;
        }
    }

    while(i <= mid){
        temp[k] = data[i];
        k++;
        i++;
    }

    while(j <= high){
        temp[k] = data[j];
        k++;
        j++;
    }

    for(i = low; i <= high; i++){
        data[i] = temp[i-low];
    }
}

 // mergesort mengurutkan data mahasiswa berdasarkan huruf dari nama mahasiswa secara ascending
void mergesort(Mahasiswa* data, int high, int low){
    if(low < high){
        int mid = (low+high)/2;
        mergesort(data,low,mid);
        mergesort(data,mid+1,high);
        merge(high,low,mid,data);
    }
}


void swap(Mahasiswa& a, Mahasiswa& b){
    Mahasiswa temp = a;
    a = b;
    b = temp;
}


int bagi(Mahasiswa* data, int kiri, int kanan) {
    Mahasiswa pivot = data[(kiri + kanan) / 2]; 
    int  pivotNIM = pivot.nim; 

    int i = kiri - 1;
    int j = kanan + 1;

    while (true) {
        do {
            i++;
        } while (data[i].nim > pivotNIM); 

        do {
            j--;
        } while (data[j].nim < pivotNIM); 

        if (i >= j) {
            return j;
        }

        swap(data[i], data[j]);
    }
}


//quicksort mengurutkan data mahasiswa berdasarkan nim mahasiswa secara descending
void quicksort(Mahasiswa* data, int kiri, int kanan) {
    if (kiri < kanan) {
        int pi = bagi(data, kiri, kanan);

        quicksort(data, kiri, pi);
        quicksort(data, pi + 1, kanan);
    }
}


// insertionsort untuk mengurutkan data berdasarkan nama secara ascending
void insertionsort(Mahasiswa* data, int n){
    int i, j;
    Mahasiswa key;
    for (i = 1; i < n; i++){
        key = data[i];
        j = i - 1;

        while (j >= 0 && data[j].nama > key.nama){
            data[j + 1] = data[j];
            j = j - 1;
        }
        data[j + 1] = key;
    }
}


// sequential serach untuk mencari data dengan nama
bool sequentialsearch(Mahasiswa* data, int jumlah_data, const string& nama_cari) {
    for (int i = 0; i < jumlah_data; i++) {
        if (data[i].nama == nama_cari) {
            cout << "Data ditemukan:" << endl;
            cout << "Nama : " << data[i].nama << endl;
            cout << "NIM : " << data[i].nim << endl;
            cout << "Kelas : " << data[i].biodata.kelas << endl;
            cout << "Peminatan : " << data[i].peminatan << endl;
            cout << "No.Hp : " << data[i].biodata.no_hp << endl;
            cout << "Email : " << data[i].biodata.email << endl;
            return true;
        }
    }
    cout << "Data tidak ditemukan!" << endl;
    return false;
}


// Binary search for finding data sorted in descending order using NIM
bool binarySearchDesc(Mahasiswa* data, int left, int right, const int& nim_cari) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (data[mid].nim == nim_cari) {
            cout << "Data ditemukan:" << endl;
            cout << "Nama : " << data[mid].nama << endl;
            cout << "NIM : " << data[mid].nim << endl;
            cout << "Kelas : " << data[mid].biodata.kelas << endl;
            cout << "Peminatan : " << data[mid].peminatan << endl;
            cout << "No.Hp : " << data[mid].biodata.no_hp << endl;
            cout << "Email : " << data[mid].biodata.email << endl;
            return true;
        }
        if (data[mid].nim > nim_cari)
            left = mid + 1;
        else
            right = mid - 1;
    }

    cout << "Data tidak ditemukan!" << endl;
    return false;
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
            cout << " " << endl;
        }
    } else {
        cout << "Daftar Kosong." << endl;
    }
}


void tampilkandatacari(Mahasiswa* data, int jumlah_data){
    if (jumlah_data != 0){
        cout << "-----Data Mahasiswa-----" << endl;
        for (int i = 0; i < jumlah_data; i++){
            cout << "No." << i + 1 << endl;
            cout << "Nama : " << data[i].nama << endl;
            cout << "NIM : " << data[i].nim << endl;
        } 
    }else {
       cout << "Daftar Kosong." << endl; 
    }
}


bool tambahdata(Mahasiswa* data, int& jumlah_data, char& ulang) {
    if (jumlah_data < jumlah_mahasiswa) {
        while (true) { 
            cout << "Masukkan nama lengkap anda : ";
            getline(cin, data[jumlah_data].nama);
            // cin.ignore();
            cout << "Masukkan NIM anda : ";
            cin >> data[jumlah_data].nim;
            cin.ignore();
            cout << "Masukkan kelas anda(a/b/c) : ";
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
            if (ulang == 'y' || ulang == 'Y') {
                tambahdata(data, jumlah_data, ulang);
                return true;
            }
            else if ( ulang == 'n' || ulang == 'N'){
                cout << "Kembali ke menu utama" << endl;
                return false;
            }
            else {
                cout << "Pilihan tidak valid. Kembali ke menu utama." << endl;
                return false; 
            }
        }
        return true; 
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
            cin >> data[pilihan].nim;
            cout << "Kelas(a/b/c) : ";
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
        int pilih_lihat;
        int pilih_cari;
        int nim_cari;
        string nama_cari;
        bool logged_in = false;
        bool signed_up = false;
        int high,low;
        int left, right;

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
                        cout << "1. Lihat daftar (A-Z)\n";
                        cout << "2. Lihat daftar berdasarkan nim (besar-kecil)" << endl; 
                        cout << "Pilihan: ";
                        cin >> pilih_lihat;
                        switch (pilih_lihat){
                            case 1:
                                mergesort(data, jumlah_data - 1, 0);
                                tampilkandata(data, jumlah_data);
                                break;
                            case 2:
                                quicksort(data, 0, jumlah_data -1);
                                tampilkandata(data, jumlah_data);
                                break;
                            default:
                                cout << "Pilihan tidak valid!" << endl;
                        }
                        break;
                    case 2:
                        if (!tambahdata(data, jumlah_data, ulang)) {
                            break; 
                        }
                        break;
                    case 3:
                        ubahdata(data, jumlah_data, yakin, pilihan);
                        break;
                    case 4: 
                        hapusdata(data, jumlah_data, pilihan, yakin);
                        break;
                    case 5:
                        cout << "Cari Data" << endl;
                        cout << "1. Cari berdasarkan nama\n";
                        cout << "2. Cari berdasarkan NIM\n";
                        cout << "Pilihan: ";
                        cin >> pilih_cari;
                        switch (pilih_cari) {
                            case 1:
                                if (jumlah_data != 0){
                                    insertionsort(data, jumlah_data);
                                    tampilkandatacari(data, jumlah_data);
                                    cout << "Masukkan nama yang ingin dicari datanya: ";
                                    cin.ignore();
                                    getline(cin, nama_cari);
                                    sequentialsearch(data, jumlah_data, nama_cari);
                                }
                                else {
                                    cout << "Daftar kosong!" << endl;
                                }
                                break;
                            case 2:
                                if (jumlah_data != 0){
                                    mergesort(data, high, low);
                                    tampilkandatacari(data, jumlah_data);
                                    cout << "Masukkan Nim: ";
                                    cin.ignore();
                                    cin >> nim_cari;
                                    binarySearchDesc(data, 0, jumlah_data - 1, nim_cari);
                                }
                                break;
                            default:
                                cout << "Pilihan tidak valid!" << endl;
                        }
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