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
void loginPembeli(struct dataPembeli *dataPembeli, int data){

    char inputEmail[70];
    char inputPassword[48];

    clearNewline();

    printf("Masukan Email: ");
    fgets(inputEmail, sizeof(inputEmail), stdin);

    for (int i = 0; i < data; i++)
    {
        if (strcmp(inputEmail, dataPembeli[i].email) == 0)
        {
            printf("Masukan Password: ");
            fgets(inputPassword, sizeof(inputPassword), stdin);

            if (strcmp(inputPassword, dataPembeli[i].password) == 0)
            {
                printf("Login berhasil!\n");
                return 1; // Login successful
            }
            else
            {
                printf("Password salah!\n");
                return 0; // Password incorrect
            }
        }
    }

    printf("Email tidak ditemukan!\n");
    return -1; // Email not found
}

// Function to recover password
void lupaPassword(struct dataPembeli *dataPembeli, int data)
{
    char inputEmail[70];

    clearNewline();

    printf("Masukan Email: ");
    fgets(inputEmail, sizeof(inputEmail), stdin);

    for (int i = 0; i < data; i++)
    {
        if (strcmp(inputEmail, dataPembeli[i].email) == 0)
        {
            // Simulate sending a recovery email
            printf("Email pemulihan password telah dikirim ke %s\n", inputEmail);
            return;
        }
    }

    printf("Email tidak ditemukan!\n");
}
