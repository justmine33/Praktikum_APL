#include <iostream>
using namespace std;

int menu_konversi() {
    int pilihann;
    cout << "Menu Konversi" << endl;
    cout << "1.Konversi Kilometer/jam ke (Centimeter/detik, Meter/detik, Mil/jam)\n";
    cout << "2.Konversi Centimeter/detik ke (Kilometer/jam, Meter/detik, Mil/jam)\n";
    cout << "3.Konversi Meter/detik ke (Kilometer/jam, Meter/detik, Mil/jam)\n";
    cout << "4.Konversi Mil/jam ke (Kilometer/jam, Centimeter/detik, Meter/detik)\n";
    cout << "0. Keluar\n";
    cout << "Pilih : ";
    cin >> pilihann;
    return pilihann;
}

bool login() {
    int i = 0;
    string username, password;
    while (i < 3) {
        cout << "Masukkan nama: ";
        cin >> username;
        cout << endl;
        cout << "Masukkan password(NIM) : ";
        cin >> password;
        cout << endl;
        if (username == "Jasmine" && password == "2309106051") {
            cout << "Login berhasil!" << endl;
            return true;
        } else {
            cout << "Login gagal. Coba lagi." << endl;
            i++;
        }
    }
    cout << "Anda telah mencoba login sebanyak 3 kali. Program berhenti." << endl;
    return false;
}

void signin(string& username, char yakin, int nim) {
    cout << "=================Sign In=================\n";
    cout << "Masukkan username : ";
    cin >> username;
    cout << endl;
    cout << "Masukkan NIM anda sebagai Password : ";
    cin >> nim;
    cout << endl;
    cout << "yakin ingin membuat akun?(y/n)";
    cin >> yakin;
    if(yakin == 'y'){
        cout << "Akun berhasil dibuat";
    }
    else if (yakin == 'n'){
        cout << "Pembuatan akun dibatalkan";
    }
    else{
        cout << "Input Salah";
    }
}

double konversi1(double angka) {
    double hasil1, hasil2, hasil3;
    hasil1 = angka * 27.7778;
    hasil2 = angka * 0.277778;
    hasil3 = angka * 0.621371;
    cout << "Hasil Konversi :\n";
    cout << "Cm/detik = " << hasil1 << endl;
    cout << "m/detik = " << hasil2 << endl;
    cout << "mil/jam = " << hasil3 << endl;
    return hasil1; 
}

double konversi2(double angka){
    double hasil1, hasil2, hasil3;
    hasil1 = angka * 0.036;
    hasil2 = angka * 0.01;
    hasil3 = angka * 0.0224;
    cout << "Hasil Konversi :\n";
    cout << "km/jam = " << hasil1 << endl;
    cout << "m/detik = " << hasil2 << endl;
    cout << "mil/jam = " << hasil3 << endl;
    return hasil1; 
}

double konversi3(double angka){
    double hasil1, hasil2, hasil3;
    hasil1 = angka * 3.6;
    hasil2 = angka;
    hasil3 = angka * 2.237;
    cout << "Hasil Konversi :\n";
    cout << "km/jam = " << hasil1 << endl;
    cout << "m/detik = " << hasil2 << endl;
    cout << "mil/jam = " << hasil3 << endl;
    return hasil1;
}

double konversi4(double angka){
    double hasil1, hasil2, hasil3;
    hasil1 = angka * 1.609;
    hasil2 = angka * 44.704;
    hasil3 = angka * 0.447;
    cout << "Hasil Konversi :\n";
    cout << "km/jam = " << hasil1 << endl;
    cout << "cm/detik = " << hasil2 << endl;
    cout << "m/detik = " << hasil3 << endl;
    return hasil1; 
}

int main() {
    string username;
    int pilihan, nim, pilihann;
    char yakin;
    double angka;

    cout << "=========================================\n";
    cout << "=======Program Konversi Kecepatan========\n";
    cout << "=========================================\n";
    cout << "==================Menu===================\n";
    cout << "1. Log In\n";
    cout << "2. Sign In\n";
    cout << "pilihan : ";
    cin >> pilihan;
    if (pilihan == 1) {
        if (login()) {
            do {
                pilihann = menu_konversi();
                switch (pilihann) {
                    case 1:
                        cout << "Masukkan kecepatan dalam km/jam : ";
                        cin >> angka;
                        konversi1(angka);
                        break;
                    case 2:
                        cout << "Masukkan kecepatan dalam Cm/detik : ";
                        cin >> angka;
                        konversi2(angka);
                        break;
                    case 3:
                        cout << "Masukkan kecepatan dalam m/detik : ";
                        cin >> angka;
                        konversi3(angka);
                        break;
                    case 4:
                        cout << "Masukkan kecepatan dalam mil/jam : ";
                        cin >> angka;
                        konversi4(angka);
                        break;
                    case 5:
                        cout << "Berhasil Keluar";
                        break;
                    default:
                        cout << "Pilihan tidak valid!";
                }
            } while (pilihann != 0);
        }
    } else if (pilihan == 2) {
        signin(username, yakin, nim);
    } else {
        cout << "Pilihan tidak valid!";
    }

    return 0;
}
