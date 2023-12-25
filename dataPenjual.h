#ifndef DATAPENJUAL_H
#define DATAPENJUAL_H

#define MAX_NAMA    100
#define MAX_ALAMAT  400
#define MAX_NOMOR   30
#define MAX_EMAIL   70
#define MAX_PASSWORD 48
#define MAX_PEMBELI 100

#define DATABASE_FILE "seller_data.txt"

typedef struct{

    char nama_penjual[MAX_NAMA];
    char alamat_penjual[MAX_ALAMAT];
    char nomor_penjual[MAX_NOMOR];
    char email_penjual[MAX_EMAIL];
    char password_penjual[MAX_PASSWORD];

} DataPenjual;


// daftar sebagai penjual
void daftarPenjual();

// login sebagai Penjaul jika sudah mempunyai akun
int loginPenjual(char *email_penjual, char *password_penjual);

void fogPassword();

extern DataPenjual dataPenjual [MAX_PEMBELI];

#endif
