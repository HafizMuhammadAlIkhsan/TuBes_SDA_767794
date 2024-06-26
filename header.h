#ifndef HEADER_H
#define HEADER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cstring>
#include <ctype.h>
#include <conio.h>

using namespace std;

#define nextBarang(P) (P)->nextBarang

#define MAX_JUMLAH 10

// ? define warna untuk teks di cli
#define normal "\033[0m"
#define red "\033[31m"
#define green "\033[32m"
#define yellow "\033[33m"
#define blue "\033[34m"
#define magenta "\033[35m"
#define cyan "\033[36m"

typedef struct data_barang
{
    char nama[50], fs[50], nb[50], pr[50];
    int harga, jumlah;
} data_barang;

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
typedef struct belanjaan *addrBel;
typedef struct belanjaan
{
    addrBar namaBarang;
    int jumlah;
    addrBel nextBarang;
} belanjaan;

/*==========================================================In use==========================================================*/
/* Membuat nama dari Toko */
void createTree(Gudang *x);

/* Modul untuk alokasi */
addrBar alokBarang(infotype nama, int harga, int jumlah);

/* Modul untuk menyisipkan node pada struktur tree */
addrBar insertBarang(Gudang *root, addrBar pr, infotype nama, int harga, int jumlah);

/* Modul untuk menampilkan keseluruhan list yang ada pada struktur tree */
void tampilkanGudang(addrBar node, int i);

/* Mencari semua barang yang ada di gudang toko, sudah termasuk kategori dan subkategori */
addrBar searchGudang(addrBar root, char cariGudang[]);
// variabel cariGudang ini maksudnya untuk mencari kategori, subkategori, dan barang

/* Mengecek apakah Kategori sudah terdaftar pada gudang atau belum */
bool cekKategori(addrBar node, infotype search);

/* Mengurangi\Menmabahkan stock yang ada di gudang */
void tambahstock(addrBar root, char carigudang[], int jumlahbarang);
void kurangistock(Gudang root, addrBel awal);

/* Menampilkan list dari subkatergori barang yang ada di gudang toko */
void tampilKategori(addrBar node, int level, int i);
void tampilSubKategori(addrBar nama, int level, int *i);
void tampilBarang(addrBar node, int level);

/* Modul untuk menyisipkan barang yang dibeli pembeli pada sebuah node linked list */
addrBel alokBelanja(Gudang root, addrBar beli, int harga);
void insertbelanja(Gudang root, addrBar beli, addrBel *awal, addrBel *akhir, int jumlah);

/* Menampilkan barang yang dibeli */
int tampilkanBelanja(addrBel first);

/* Menghapus list barang yang sudah dibeli */
addrBel deleteBelanja(addrBel *awal, addrBel akhir);

/* Baca dan update file pada data gudang */
void bacaFile(Gudang gudang, char namaFile[]);
void updateData(addrBar root);

/* Modul Katalog */
bool katalog(addrBar root);
void tampilkan_katalog(addrBar root, int arah, int arahsub);
int previous(addrBar current, int current_page);

/* Modul untuk memasukkan jumlah yang harus dibayarkan saat ingin membeli barang */
void transaksi(int Total, Gudang root, addrBel awal);

// ? ======================================================= Menu pada kasir =========================================================

void lihatKategori(Gudang gudang);

void lihatSubKategori(Gudang gudang);

void lihatBarang(Gudang gudang);

void belanja(Gudang gudang);

// ? ====================================================== Menu pada gudang =========================================================

void tambahKategori(Gudang gudang);

void tambahBarangBaru(Gudang gudang);

void tambahStokBarang(Gudang gudang);

void tampilkanStokBarang(Gudang gudang);

// !========================================================== Currently not In use ==========================================================

void tambahStockEtalase(addrBar etalase, addrBar gudang, int level);

string standarisasi(infotype nama);

void Cek_Stock_Etalase(addrBar node, int level, int i);

#endif