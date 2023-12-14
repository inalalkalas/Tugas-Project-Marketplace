#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <libpq-fe.h>

// struct pada data
struct All [2][2] {
    {char namaBarangPenjual [50], char namaBarangPembeli [50]}
    {int hargaBarangJual, int hargaBarangBeli}
} 

// membersihkan enter
void clearNewline() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// menampilkan data pada pilihan pertama
void tampilanData (){
    printf("Login Sebagai:\n");
    printf("1. Penjual\n");
    printf("2. Pembeli\n");
    printf("E. Exit\n");
    printf("Pilihan Anda: ");    
} 

// menampilkan data pada penjual
void tampilSbgPenjual () {
    printf("1. Tambahkan Item\n");
    printf("2. ");
    printf("");
    printf("");
    printf("");
    printf("");
    printf("");
    printf("");
    printf("");

}

// menampilkan data pada pembeli
void tampilSbgPembeli() {
    printf("");
    printf("");
    printf("");
    printf("");
    printf("");
    printf("");
    printf("");

}

// mengurutkan harga dari yang terendah
void hargaTertinggi(struct Produk *produk, int jumlahProduk, int ascending){

}

// mengurutkan harga dari yang terbesar
void hargaTerendah(struct Produk *produk, int jumlahProduk, int descending){

}

void tampilanKeranjang(){

}

void tampilanProfilePenjual(){

}

void tampilSearchBarang(){

}

void tampilBarangPembeli(){

}

void 

