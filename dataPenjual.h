#ifndef DATAPENJUAL_H
#define DATAPENJUAL_H
#define MAX_NAMA    100
#define MAX_ALAMAT  400
#define MAX_NOMOR   30
#define MAX_EMAIL   70
#define MAX_PASSWORD 48
#define MAX_PEMBELI 100

// struktur 
typedef struct{

    char nama[MAX_NAMA];
    char alamat[MAX_ALAMAT];
    char nomor[MAX_NOMOR];
    char email[MAX_EMAIL];
    char password[MAX_PASSWORD];

} DataPenjual;

void clearNewline(void);

// daftar sebagai penjual
void daftarPenjual(DataPenjual *dataPenjual, int *data_DafPJ, int *numRegistrations);

// login sebagai Penjaul jika sudah mempunyai akun
int loginPenjual(DataPenjual *dataPenjual, int data_LogPJ, int numRegistrations);

void fogPassword(DataPenjual *dataPenjual, int data_FogPJ, int numRegistrations);

extern DataPenjual dataPenjual [MAX_PEMBELI];
extern int data_DafPJ[MAX_PEMBELI];
extern int data_LogPJ[MAX_PEMBELI];
extern int data_FogPJ[MAX_PEMBELI];
#endif
