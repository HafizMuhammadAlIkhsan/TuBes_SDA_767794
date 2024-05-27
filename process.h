#ifndef process_h
#define process_h

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

typedef char *infotype;

/* untuk barang dan kategori (struktur data tree) */
typedef struct barang *addrBar;
typedef struct barang
{
    infotype nama;
    int harga;
    int jumlah;
    addrBar fs, nb, pr;
} barang;

struct Gudang
{
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



#endif
