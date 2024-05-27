#ifndef HEADER_H
#define HEADER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cstring>
#include <ctype.h>

using namespace std;

#define nama(P) (P)->nama
#define harga(P) (P)->harga
#define jumlah(P) (P)->jumlah
#define pr(P) (P)->pr
#define fs(P) (P)->fs
#define nb(P) (P)->nb
#define root(P) (P)->root
#define namBar(P) (P)->namBar
#define nextBar(P) (P)->nextBar
#define barBel(P) (P)->barBel

#define MAX_JUMLAH 10

// ? define warna untuk teks di cli
#define normal "\033[0m"
#define red "\033[31m"
#define green "\033[32m"
#define yellow "\033[33m"
#define blue "\033[34m"
#define magenta "\033[35m"
#define cyan "\033[36m"
#define barBel(P) (P)->barBel

typedef char* infotype;

/* untuk barang dan kategori (struktur data tree) */
typedef struct barang *addrBar;
typedef struct barang
{
    infotype nama;
    int harga;
    int jumlah;
    addrBar fs, nb, pr;
} barang;

struct Gudang {
    addrBar root;
};

/* barang yang dipesan oleh pembeli */
typedef struct dibeli *addrBel;
typedef struct dibeli
{
    addrBar namBar;
    int jumlah;
    addrBel nextBar;
} dibeli;

/* Membuat nama dari Toko */
void createTree(Gudang *x);

/* Modul untuk alokasi */
addrBar alokBarang(infotype nama, int harga);

/* Modul untuk menyisipkan node pada struktur tree */
addrBar insertBarang(Gudang *root, addrBar pr, infotype nama, int harga);

/* Modul untuk menampilkan keseluruhan list yang ada pada struktur tree */
void tampilkanGudang(addrBar node, int i);

/* Mencari semua barang yang ada di gudang toko, sudah termasuk kategori dan subkategori */
addrBar searchGudang(addrBar root, char cariGudang[]);
// variabel cariGudang ini maksudnya untuk mencari kategori, subkategori, dan barang

bool cekKategori(addrBar node,int level, infotype search);

/*Menmabahkan stock yang ada di gudang*/
void tambahstock(addrBar root, char carigudang[], int jumlahbarang);

/*Mengurangi stock yang ada di gudang*/
void kurangistock(Gudang root, infotype nama, addrBel *awal, int jumlahbarang);

/*Menmabahkan stock yang ada di gudang*/
void tambahstock(addrBar root, char carigudang[], int jumlahbarang);

string standarisasi(infotype nama);

/* Menampilkan list dari subkatergori barang yang ada di gudang toko */
void tampilSubKategori(addrBar nama, int level, int i);

/* Modul untuk alokasi barang yang dibeli pembeli */
addrBel alokBarBel(Gudang root, addrBar beli, int harga);

/* Modul untuk menyisipkan barang yang dibeli pembeli pada sebuah node linked list */
void insertBarBel(Gudang root, addrBar beli, addrBel *awal, addrBel *akhir, int jumlah);

/* Mencari semua barang yang ada di gudang toko, sudah termasuk kategori dan subkategori */
addrBar searchGudang(addrBar root, char cariGudang[]);

/*Mengurangi stock yang ada di gudang*/
void kurangistock(Gudang root, addrBel awal);

void tampilBarBel(addrBel first, addrBel last);

/*Mengurangi stock yang ada di gudang*/
void kurangistock(Gudang root, infotype nama, addrBel *awal, int jumlahbarang);

void tampilBarBel(addrBel first, addrBel last);

addrBel deleteBarBel(addrBel *awal, addrBel akhir);

void Cek_Stock_Etalase(addrBar node, int level, int i);

#endif