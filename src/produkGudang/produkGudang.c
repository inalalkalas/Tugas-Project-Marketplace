#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/produkGudang/produkGudang.h"

void clearBufferPK() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


// Fungsi untuk menukar dua elemen
void swap(PROduct *a, PROduct *b) {
    PROduct temp = *a;
    *a = *b;
    *b = temp;
}

// Fungsi untuk membagi array dan mengembalikan indeks pivot
int partition(PROduct arr[], int low, int high, int (*compare)(float, float)) {
    float pivot = arr[high].price;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (compare(arr[j].price, pivot)) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Fungsi untuk melakukan quicksort pada array
void quickSort(PROduct arr[], int low, int high, int (*compare)(float, float)) {
    if (low < high) {
        int pi = partition(arr, low, high, compare);

        quickSort(arr, low, pi - 1, compare);
        quickSort(arr, pi + 1, high, compare);
    }
}

// Fungsi untuk membandingkan dua harga (untuk ascending dan descending)
int compareAscending(float a, float b) {
    return a < b;
}

int compareDescending(float a, float b) {
    return a > b;
}

void getCurrentDate(char *date) {
    time_t t;
    struct tm *current_time;

    // Mendapatkan waktu saat ini
    time(&t);
    current_time = localtime(&t);

    // Format tanggal sebagai DD-MM-YYYY
    strftime(date, 15, "%d-%m-%Y", current_time);
}

void estimateRestockDate(char *restockDate) {
    time_t t;
    struct tm *current_time;

    // Get the current time
    time(&t);
    current_time = localtime(&t);

    // Add 30 days to the current date for the restock date
    current_time->tm_mon += 2;
    mktime(current_time);

    // Format the restock date as DD-MM-YYYY
    strftime(restockDate, 15, "%d-%m-%Y", current_time);
}

void calculateExpirationDate(const char *restockDate, char *expirationDate) {
    struct tm expiration_time;

    // Convert the restock date to a tm structure
    sscanf(restockDate, "%d-%d-%d", &expiration_time.tm_mday, &expiration_time.tm_mon, &expiration_time.tm_year);
    expiration_time.tm_mon -= 1; // Adjust month (0-11)

    // Add 10 days to the restock date for the expiration date
    expiration_time.tm_year += 30;
    mktime(&expiration_time);

    // Format the expiration date as DD-MM-YYYY
    strftime(expirationDate, 15, "%d-%m-%Y", &expiration_time);
}

// tambha produk sebagai penjual
void addProduct(FILE *file) {
    clearBufferPK();
    PROduct product;

    printf("Masukkan nama produk: ");
    fgets(product.name, sizeof(product.name), stdin);
    product.name[strcspn(product.name, "\n")] = '\0'; // Remove trailing newline
    printf("Masukkan harga produk: ");
    scanf("%f", &product.price);

    // Get the current date for restock
    getCurrentDate(product.restock_date);

    // Estimate restock date (30 days from the current date)
    estimateRestockDate(product.restock_date);

    // Calculate expiration date (250 days from the restock date)
    calculateExpirationDate(product.restock_date, product.expiry_date);

    // Write product data to the file
    fprintf(file, "%s %.2f %s %s\n", product.name, product.price, product.restock_date, product.expiry_date);
    printf("Produk berhasil ditambahkan.\n");
    getchar();
}

// mengedit produk untuk penjual
void editProduct(FILE *file, const char *productName) 
{
    clearBufferPK();
    PROduct product, temp;
    int found = 0;

    // Membaca data produk dari file
    rewind(file);
    while (fscanf(file, "%s %f %s %s", product.name, &product.price, product.restock_date, product.expiry_date) != EOF) {
        if (strcmp(product.name, productName) == 0) {
            printf("Masukkan informasi produk yang baru:\n");
            printf("Harga baru: ");
            scanf("%f", &temp.price);
            getchar();

            // Mendapatkan tanggal restock saat ini
            getCurrentDate(temp.restock_date);

            // Menetapkan tanggal kedaluwarsa misalnya 30 hari dari tanggal restock
            time_t t = time(NULL);
            struct tm *expiry_time = localtime(&t);
            expiry_time->tm_mday += 30; // Tambah 30 hari
            mktime(expiry_time);

            // Format tanggal kedaluwarsa sebagai DD-MM-YYYY
            strftime(temp.expiry_date, 15, "%d-%m-%Y", expiry_time);

            // Menulis data produk yang telah diubah ke dalam file
            fprintf(file, "%s %.2f %s %s\n", product.name, temp.price, temp.restock_date, temp.expiry_date);
            printf("Informasi produk berhasil diubah.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Produk tidak ditemukan.\n");
    }
}

// Fungsi untuk mencari produk berdasarkan nama
void searchProduct(FILE *file, const char *productName) {
    PROduct product;
    int found = 0;

    // Membaca data produk dari file
    rewind(file);
    while (fscanf(file, "%s %f %s %s", product.name, &product.price, product.restock_date, product.expiry_date) != EOF) {
        if (strcmp(product.name, productName) == 0) {
            printf("Produk ditemukan:\n");
            printf("Nama: %s\n", product.name);
            printf("Harga: %.2f\n", product.price);
            printf("Tanggal Restock: %s\n", product.restock_date);
            printf("Tanggal Expired: %s\n", product.expiry_date);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Produk tidak ditemukan.\n");
    }
}

// Fungsi untuk menghapus produk berdasarkan nama
void deleteProduct(FILE *file, const char *productName) {
    clearBufferPK();

    PROduct product;
    FILE *tempFile;

    // Membuka file temporary untuk menulis sementara
    tempFile = fopen(DATABASE_FILE_PRODUK, "w");
    if (tempFile == NULL) {
        printf("Error creating temporary file.\n");
        return;
    }

    int found = 0;

    // Membaca data produk dari file
    rewind(file);
    while (fscanf(file, "%s %f %s %s", product.name, &product.price, product.restock_date, product.expiry_date) != EOF) {
        // Jika produk ditemukan, skip penulisan ke temporary file (menghapus produk)
        if (strcmp(product.name, productName) == 0) {
            found = 1;
            continue;
        }

        // Menulis data produk yang tidak dihapus ke dalam temporary file
        fprintf(tempFile, "%s %.2f %s %s\n", product.name, product.price, product.restock_date, product.expiry_date);
    }

    // Menutup file temporary
    fclose(tempFile);

    // Menghapus file awal
    remove("products.txt");

    // Mengganti nama temporary file menjadi nama file asli
    if (rename("temp.txt", "products.txt") != 0) {
        printf("Error renaming temporary file.\n");
        return;
    }

    if (found) {
        printf("Produk berhasil dihapus.\n");
    } else {
        printf("Produk tidak ditemukan.\n");
    }
}

// untuk menampilkan isi produk dari penjual yang sudah ditambahkan ataupun belum
void viewProducts(FILE *file) {
    PROduct product;
    
    rewind(file);
    
    printf("Product List:\n");
    printf("%-20s%-10s%-15s%-15s\n", "Name", "Price", "Restock Date", "Expiry Date");
    printf("--------------------------------------------------------\n");

    while (fscanf(file, "%s %f %s %s", product.name, &product.price, product.restock_date, product.expiry_date) != EOF) {
        printf("%-20s%-10.2f%-15s%-15s\n", product.name, product.price, product.restock_date, product.expiry_date);
    }

    printf("--------------------------------------------------------\n");
}

// untuk menambah item pada keranjang
void tambahItem(PROduct *keranjang, int *jumlahProduk, const PROduct *allProducts, int jumlahAllProducts) {
    clearBufferPK();

    if (*jumlahProduk == MAX_PRODUCTS) {
        printf("Keranjang penuh. Tidak dapat menambah item lebih banyak.\n");
        return;
    }

    char productName[50];
    printf("Masukkan nama produk yang ingin ditambahkan ke keranjang: ");
    fgets(productName, sizeof(productName), stdin);
    productName[strcspn(productName, "\n")] = '\0'; // Remove trailing newline

    // Search for the product in the available products
    int found = 0;
    for (int i = 0; i < jumlahAllProducts; i++) {
        if (strcmp(allProducts[i].name, productName) == 0) {
            // Add the product to the cart
            keranjang[*jumlahProduk] = allProducts[i];
            (*jumlahProduk)++;
            printf("Produk berhasil ditambahkan ke keranjang.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Produk tidak ditemukan.\n");
    }
}

// mengurangi produk pada keranjang
void removeItem(PROduct *keranjang, int *jumlahProduk) 
{
    clearBufferPK();

    if (*jumlahProduk == 0) {
        printf("Keranjang kosong. Tidak dapat menghapus item.\n");
        return;
    }

    char productName[50];
    printf("Masukkan nama produk yang ingin dihapus dari keranjang: ");
    fgets(productName, sizeof(productName), stdin);
    productName[strcspn(productName, "\n")] = '\0'; // Remove trailing newline
    getchar();

    int found = 0;
    for (int i = 0; i < *jumlahProduk; i++) {
        if (strcmp(keranjang[i].name, productName) == 0) {
            // Remove the product from the cart
            for (int j = i; j < (*jumlahProduk - 1); j++) {
                keranjang[j] = keranjang[j + 1];
            }
            (*jumlahProduk)--;
            printf("Produk berhasil dihapus dari keranjang.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Produk tidak ditemukan dalam keranjang.\n");
    }
}

// untuk menghapus produk pada keranjang
void deleteProduk(FILE *file, PROduct *keranjang, int *jumlahProduk, const char *productName) 
{
    clearBufferPK();

    if (*jumlahProduk == 0) {
        printf("Keranjang kosong. Tidak dapat menghapus produk.\n");
        return;
    }

    int found = 0;

    // Remove the product from the cart
    for (int i = 0; i < *jumlahProduk; i++) {
        if (strcmp(keranjang[i].name, productName) == 0) {
            // Remove the product from the cart
            for (int j = i; j < (*jumlahProduk - 1); j++) {
                keranjang[j] = keranjang[j + 1];
            }
            (*jumlahProduk)--;
            printf("Produk berhasil dihapus dari keranjang.\n");
            found = 1;
            break;
        }
    }

    // Remove the product from the database file
    FILE *tempFile = fopen(DATABASE_FILE_PRODUK, "w");
    if (tempFile == NULL) {
        printf("Error creating temporary file.\n");
        return;
    }

    rewind(file);
    PROduct product;

    while (fscanf(file, "%s %f %s %s", product.name, &product.price, product.restock_date, product.expiry_date) != EOF) {
        if (strcmp(product.name, productName) == 0) {
            // Skip writing the product to the temporary file (delete from database)
            found = 1;
            continue;
        }

        // Write non-deleted products to the temporary file
        fprintf(tempFile, "%s %.2f %s %s\n", product.name, product.price, product.restock_date, product.expiry_date);
    }

    fclose(tempFile);
    fclose(file);

    // Remove the original database file
    remove(DATABASE_FILE_PRODUK);

    // Rename the temporary file to the original database file
    if (rename("temp.txt", DATABASE_FILE_PRODUK) != 0) {
        printf("Error renaming temporary file.\n");
        return;
    }

    if (!found) {
        printf("Produk tidak ditemukan dalam keranjang atau database.\n");
    }
}

// menampilkan produk pada keranjang
void tampilanKeranjang(const PROduct *keranjang, int jumlahProduk) {
    printf("\n----- Keranjang Belanja -----\n");

    if (jumlahProduk == 0) {
        printf("Keranjang kosong.\n");
    } else {
        printf("%-20s %-10s\n", "Nama Produk", "Harga");
        printf("-----------------------------------\n");

        for (int i = 0; i < jumlahProduk; i++) {
            printf("%-20s %-10.2f\n", keranjang[i].name, keranjang[i].price);
        }
    }

    printf("-----------------------------------\n");
}
