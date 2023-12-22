#ifndef DATAPEMBELI_H
#define DATAPEMBELI_H
#define MAX_NAMA    100
#define MAX_ALAMAT  400
#define MAX_NOMOR   30
#define MAX_EMAIL   70
#define MAX_PASSWORD 48
#define MAX_PEMBELI 100

// struktur
typedef struct
{
    char nama [MAX_NAMA];
    char alamat [MAX_ALAMAT];
    char nomor [MAX_NOMOR];
    char email [MAX_EMAIL];
    char password [MAX_PASSWORD];

} DataPembeli;

// membersihkan enter

// daftar sebagai pembeli 
void daftarPembeli(DataPembeli *dataPembeli, int *dataDaf, int *numRegistrations);

// login sebagai pembeli
int loginPembeli(DataPembeli *dataPembeli, int data_Log, int numRegistrations);

// lupa password
void lupaPassword(DataPembeli *dataPembeli, int data_Fog, int numRegistrations);

extern DataPembeli dataPembeli [MAX_PEMBELI];
extern int dataDaf[MAX_PEMBELI];
extern int data_Log[MAX_PEMBELI];
extern int data_Fog[MAX_PEMBELI];

#endif