#ifndef header
#define header

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

/* barang yang dipesam oleh pembeli */
typedef struct dibeli *addrBel;
typedef struct dibeli
{
    addrBar namBar;
    int jumlah;
    addrBel nextBar;
};

/* pembeli yang memesan barang */
typedef struct pembeli *addrPem;
typedef struct pembeli           
{
    infotype nama;
    addrBel barBel;
    addrPem next;
} pembeli;

void buatGudang(gudang *root);
addrBar alokBarang(infotype nama, int harga);
addrBar insertBarang(gudang *root, addrBar pr, infotype nama, int harga);
void tampilkanGudang(addrBar node, int i);

#endif