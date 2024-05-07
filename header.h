#ifndef header
#define header

#include <stdlib.h>
#include <stdio.h>

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

/* kasir berupa array yang memiliki pointer menunjuk ke record pembeli */
typedef struct kasir *addrKas;
typedef struct kasir           
{
    infotype nama = "0"; 
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

#endif