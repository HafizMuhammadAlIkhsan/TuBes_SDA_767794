#ifndef header
#define header

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cstring>
#include <ctype.h>
#include <conio.h>

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

/* kasir berupa array yang memiliki pointer menunjuk ke record pembeli */
typedef struct kasir *addrKas;
typedef struct kasir           
{
    infotype nama; 
    addrKas next = NULL;
    addrKas akhir = NULL;  
} kasir;

/* barang yang dipesan oleh pembeli */
typedef struct dibeli *addrBel;
typedef struct dibeli
{
    addrBar namBar;
    int jumlah;
    addrBel nextBar;
} dibeli;

/* pembeli yang memesan barang */
typedef struct pembeli *addrPem;
typedef struct pembeli           
{
    infotype nama;
    addrBel barBel;
    addrPem next;
} pembeli;

typedef struct
{
    char nama[50], fs[50], nb[50], pr[50];
    char harga[100000000];
    char jumlah[100000000];
} data_barang;

/* Membuat nama dari Toko */
void createTree(Gudang *x);

/* Modul untuk alokasi */
addrBar alokBarang(infotype nama, int harga);

/* Modul untuk menyisipkan node pada struktur tree */
addrBar insertBarang(Gudang *root, addrBar pr, infotype nama, int harga);

/* Modul untuk menampilkan keseluruhan list yang ada pada struktur tree */
void tampilkanGudang(addrBar node, int i);

/* Menampilkan list dari subkatergori barang yang ada di gudang toko */
void tampilSubKategori(addrBar nama, int level, int i);

/* Modul untuk alokasi barang yang dibeli pembeli */
addrBel alokBarBel(Gudang root, infotype nama, int harga);

/* Modul untuk menyisipkan barang yang dibeli pembeli pada sebuah node linked list */
void insertBarBel(Gudang root, infotype nama, addrBel *awal, addrBel *akhir, int jumlah);

/* Mencari semua barang yang ada di gudang toko, sudah termasuk kategori dan subkategori */
addrBar searchGudang(addrBar root, char cariGudang[]);
// variabel cariGudang ini maksudnya untuk mencari kategori, subkategori, dan barang

bool cekKategori(addrBar node,int level, infotype search);

/*Mengurangi stock yang ada di gudang*/
void kurangistock(Gudang root, infotype nama, addrBel *awal, int jumlahbarang);

/*Menmabahkan stock yang ada di gudang*/
void tambahstock(addrBar root, char carigudang[], int jumlahbarang);

void tampilBarBel(addrBel first, addrBel last);

/*Mengurangi stock yang ada di gudang*/
void kurangistock(Gudang root, infotype nama, addrBel *awal, int jumlahbarang);

/*Menmabahkan stock yang ada di gudang*/
void tambahstock(addrBar root, char carigudang[], int jumlahbarang);

void tampilBarBel(addrBel first, addrBel last);

addrBel deleteBarBel(addrBel awal, addrBel akhir);

string standarisasi(infotype nama);

void Tampil_file();

void Entry_file();

#endif