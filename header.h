#ifndef header
#define header

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define nama(P) (P)->nama
#define harga(P) (P)->harga
#define jumlah(P) (P)->jumlah
#define pr(P) (P)->pr
#define fs(P) (P)->fs
#define nb(P) (P)->nb
#define root(P) (P)->root
#define namBar(P) (P)->namBar
#define nextBar(P) (P)->nextBar

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

struct gudang {
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

/* Membuat nama dari Toko */
void createTree(gudang *x);

/* Modul untuk alokasi */
addrBar alokBarang(infotype nama, int harga);

/* Modul untuk menyisipkan node pada struktur tree */
addrBar insertBarang(gudang *root, addrBar pr, infotype nama, int harga);

/* Modul untuk menampilkan keseluruhan list yang ada pada struktur tree */
void tampilkanGudang(addrBar node, int i);

/* Menampilkan list dari subkatergori barang yang ada di gudang toko */
void tampilSubKategori(addrBar nama, int level, int i);

/* Modul untuk alokasi barang yang dibeli pembeli */
addrBel alokBarBel(gudang root, infotype nama, int harga);

/* Modul untuk menyisipkan barang yang dibeli pembeli pada sebuah node linked list */
addrBel insertBarBel(gudang root, infotype nama, int usia, addrBel *awal, addrBel *akhir, int jumlah);

/* Modul yang digunakan untuk membuat LL berupa barang yang dibeli oleh pembeli */
void beliBarang(addrPem pembeli, addrBel barang);

/* Mencari semua barang yang ada di gudang toko, sudah termasuk kategori dan subkategori */
addrBar searchGudang(addrBar root, char cariGudang[]);
// variabel cariGudang ini maksudnya untuk mencari kategori, subkategori, dan barang

#endif