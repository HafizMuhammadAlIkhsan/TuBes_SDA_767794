#ifndef header
#define header

#include <stdlib.h>
#include <stdio.h>

#define nama(P) (P)->nama 
#define pr(P) (P)->pr
#define fs(P) (P)->fs
#define nb(P) (P)->nb
#define root(P) (P)->root

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

/* pembeli yang memesan barang */
typedef struct pembeli *addrPem;
typedef struct pembeli           
{
    infotype nama;
    addrBel barBel;
    addrPem next;
} pembeli;

/* barang yang dipesam oleh pembeli */
typedef struct dibeli *addrBel;
typedef struct dibeli
{
    addrBar namBar;
    int jumlah;
    addrBel nextBar;
};

/* Membuat nama dari Toko */
void createTree(gudang *x);

/* Menampilkan list dari subkatergori barang yang ada di gudang toko */
void tampilSubKategori (addrBar nama);

/* Modul yang digunakan untuk membuat LL berupa barang yang dibeli oleh pembeli */
void beliBarang (addrPem pembeli, addrBel barang);

/* Mencari semua barang yang ada di gudang toko, sudah termasuk kategori dan subkategori */
addrBar searchGudang (addrBar root, infotype cariGudang);
// variabel cariGudang ini maksudnya untuk mencari kategori, subkategori, dan barang

#endif