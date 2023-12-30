#ifndef PRODUKGUDANG_H
#define PRODUKGUDANG_H
#define DATABASE_FILE_PRODUK "data_produk.txt"
#define MAX_PRODUCTS 100

typedef struct {

    char name[50];
    float price;
    char restock_date[15];
    char expiry_date[15];

} PROduct;

// clear NewLine
void clearBufferPK();

void swap(PROduct *a, PROduct *b);
int partition(PROduct arr[], int low, int high, int (*compare)(float, float));

void quickSort(PROduct arr[], int low, int high, int (*compare)(float, float));

int compareAscending(float a, float b);
int compareDescending(float a, float b);

void getCurrentDate(char *date);
void estimateRestockDate(char *restockDate);
void calculateExpirationDate(const char *restockDate, char *expirationDate);

void addProduct(FILE *file);

void searchProduct(FILE *file, const char *productName);

void editProduct(FILE *file, const char *productName);
void deleteProduct(FILE *file, const char *productName);
void viewProducts(FILE *file);

void tambahItem(PROduct *keranjang, int *jumlahProduk, const PROduct *allProducts, int jumlahAllProducts);
void removeItem(PROduct *keranjang, int *jumlahProduk);
void deleteProduk(FILE *file, PROduct *keranjang, int *jumlahProduk, const char *productName);

void tampilanKeranjang(const PROduct *keranjang, int jumlahProduk);

extern PROduct product[100];

#endif