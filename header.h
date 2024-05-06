#ifndef header

#include<stdlib.h>
#include <stdio.h>

using namespace std;

typedef address *address;

/*untuk barang dan kategori*/
typedef struct barang
{
    char name;
    int harga;
    int jumlah;
    address fs, nb, pr;
};

/*transaksi saat barang keluar*/
typedef struct transaksi
{
    char name;
    int harga;
    int jumlah;
    address next,prev;
};


void create_barang();
void kasir();
void barang_masuk();
void mencari_barang();
void Edit_info();
void tampilkan_barang();
void menghitung_Barang();

#endif