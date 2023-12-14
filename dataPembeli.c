#include <stdio.h>
#include <string.h>
#include "dataPembeli.h"

// membersihkan enter
void clearNewline() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// struktur
struct dataPembeli
{
    char nama [100];
    char alamat [400];
    char nomor [30];
    char email [70];
    char password [48];
};

// daftar sebagai pembeli 
void daftarPembeli(struct dataPembeli * dataPembeli, char * data){
    clearNewline(); // Clear newline buffer

    printf("Daftar\n");
    
    printf("Masukan Nama: ");
    fgets(dataPembeli[*data].nama, sizeof(dataPembeli[*data].nama), stdin);
    
    printf("Masukan No Handphone: ");
    fgets(dataPembeli[*data].nomor, sizeof(dataPembeli[*data].nomor), stdin);

    printf("Masukan Alamat: ");
    fgets(dataPembeli[*data].alamat, sizeof(dataPembeli[*data].alamat), stdin);

    printf("Masukan Email: ");
    fgets(dataPembeli[*data].email, sizeof(dataPembeli[*data].email), stdin);

    printf("Masukan Password: ");
    fgets(dataPembeli[*data].password, sizeof(dataPembeli[*data].password), stdin);

}

// login sebagai pembeli
void loginPembeli(){
    
}
