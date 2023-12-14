#include <stdio.h>
#include <string.h>
#include "dataPenjual.h"

// membersihkan enter
void clearNewline() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// struktur 
struct dataPenjual
{
    char nama [100];
    char alamat [400];
    char nomor [30];
    char email [70];
    char password [48];
};

// daftar sebagai penjual
void daftarPenjual(struct dataPenjual * dataPenjual, char * data){
    clearNewline(); // Clear newline buffer

    printf("Daftar\n");
    
    printf("Masukan Nama: ");
    fgets(dataPenjual[*data].nama, sizeof(dataPenjual[*data].nama), stdin);
    
    printf("Masukan No Handphone: ");
    fgets(dataPenjual[*data].nomor, sizeof(dataPenjual[*data].nomor), stdin);

    printf("Masukan Alamat: ");
    fgets(dataPenjual[*data].alamat, sizeof(dataPenjual[*data].alamat), stdin);

    printf("Masukan Email: ");
    fgets(dataPenjual[*data].email, sizeof(dataPenjual[*data].email), stdin);

    printf("Masukan Password: ");
    fgets(dataPenjual[*data].password, sizeof(dataPenjual[*data].password), stdin);


}

// login sebagai Penjaul jika sudah mempunyai akun
void loginPenjual(){
    

}