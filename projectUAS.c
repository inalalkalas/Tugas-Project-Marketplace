#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <libpq-fe.h>
#include ""

// struct pada data
struct All [2][2] {
    {char namaBarangPenjual [50], char namaBarangPembeli [50]}
    {int hargaBarangJual, int hargaBarangBeli}
}   

// perulangan untuk kembali ke menu utama
void tandaReturn(){
    if (... == 'r' || ... = 'R'){
        return 
    } else {
        return 1
    }
}

// perulangan untuk exit 
void tandaExit(){
    if (... == 'e' || ... = 'E'){
        return 1;
    }
}

// membersihkan enter
void clearNewline() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// mengurutkan harga dari yang terendah
void hargaTertinggi(struct Produk *produk, int jumlahProduk, int ascending){

}

// mengurutkan harga dari yang terbesar
void hargaTerendah(struct Produk *produk, int jumlahProduk, int descending){

}

// menampilkan data pada pilihan pertama
void tampilanData (){
    printf("Login Sebagai:\n");
    printf("1. Penjual\n");
    printf("2. Pembeli\n");
    printf("E. Exit\n");
    printf("Pilihan Anda: ");
    scanf("");

    if(n == 'e'|| n == 'E'){
        return 1;
    }
} 

// menampilkan data pada penjual
void tampilSbgPenjual () {
    printf("1. Tambahkan Item\n");
    printf("2. lihat data produk\n");
    printf("3. pesan\n");
    printf("4. notifikasi\n");
    printf("5. setting\n");
    printf("E. exit\n");
    scanf("");
   
    if (n)
}

// menambahkan item untuk penjual
void tambahItemPenjual(){

}

// menampilkan barang yang sudah ditambahkan
void tampilItem(){

}

// menampilkan pesan yang mengarah ke pembeli
void pesanPenjual(){

}

// menampilkan notifikasi apa yang terjadi
void notifPenjual(){

}

// menampilkan settingan untuk penjual melengkapi biodata
void settingPenjual(){

}


// menampilkan data pada pembeli
void tampilSbgPembeli() {
    printf("1. searching\n");
    printf("2. keranjang\n");
    printf("3. pesan\n");
    printf("4. notifikasi\n");
    printf("5. setting\n");
    printf("E. exit");
    scanf("");
}

// mencari barang untuk pembeli
void tampilSearchingPembeli(){
    printf("Search ");
    scanf("", );

    
}

// menampilkan isi pada keranjang 
void tampilanKeranjang(){


}

// menampilkan profil dan juga data tentang penjual
void tampilanProfilePenjual(){

}

// menampilkan baarang yang sudah di cari
void tampilSearchBarang(){

}

// menampilkan pesan yang mengarah ke pembeli
void pesanPembeli(){

}

// menampilkan notifikasi apa yang terjadi
void notifPembeli(){

}

// menampilkan settingan untuk penjual melengkapi biodata
void settingPembeli(){

}

