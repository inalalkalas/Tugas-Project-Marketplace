#ifndef DATAPEMBELI_H
#define DATAPEMBELI_H
#define MAX_NAMA    100
#define MAX_ALAMAT  400
#define MAX_NOMOR   30
#define MAX_EMAIL   70
#define MAX_PASSWORD 48
#define MAX_PEMBELI 100
#define DATABASE_FILE "buyyer_data.txt"

// strukturI
typedef struct
{
    char nama_pembeli[MAX_NAMA];
    char alamat_pembeli[MAX_ALAMAT];
    char nomor_pembeli[MAX_NOMOR];
    char email[MAX_EMAIL];
    char password_pembeli[MAX_PASSWORD];

} DataPembeli;

// membersihkan enter
// Add this function prototype

void encryptPassword(char *password);

// daftar sebagai pembeli 
void daftarPembeli();


// login sebagai pembeli
int loginUser(char *email, char *password_pembeli);


// lupa password
void forgotPassword();

void display_name(char *nama_pembeli);
void display_alamat(char *alamat_pembeli);
void display_nomor(char *nomor_pembeli);

extern DataPembeli dataPembeli [MAX_PEMBELI];

#endif