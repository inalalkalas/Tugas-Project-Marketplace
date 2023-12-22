#ifndef PRODUKGUDANG_H
#define PRODUKGUDANG_H

typedef struct {

    char name[50];
    float price;
    char restock_date[15];
    char expiry_date[15];

} PROduct;

void clearNewline(void);

void swap(PROduct *a, PROduct *b);
int partition(PROduct arr[], int low, int high, int (*compare)(float, float));

void quickSort(PROduct arr[], int low, int high, int (*compare)(float, float));

int compareAscending(float a, float b);
int compareDescending(float a, float b);

void getCurrentDate(char *date);

void addProduct(FILE *file);

void searchProduct(FILE *file, const char *productName);

void editProduct(FILE *file, const char *productName);
void deleteProduct(FILE *file, const char *productName);

extern PROduct product[100];

#endif