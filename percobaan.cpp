#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

addrBar alokBarang(infotype nama, int harga)
{
    addrBar p;
    p = (addrBar)malloc(sizeof(barang));
    if (p == NULL)
    {
        printf("Memori sudah penuh\n");
    }
    else
    {
        nama(p) = (infotype)malloc(strlen(nama) + 1);
        if (nama(p) == NULL)
        {
            printf("Memori sudah penuh\n");
        }

        strcpy(nama(p), nama);

        harga(p) = harga;
        jumlah(p) = 0;
        fs(p) = NULL;
        nb(p) = NULL;
        pr(p) = NULL;
    }
    return p;
}

addrBar insertBarang(Gudang *root, addrBar pr, infotype nama, int harga)
{
    addrBar p, q;
    p = alokBarang(nama, harga);
    if (p != NULL)
    {
        if (pr == NULL)
        {
            root(root) = p;
        }
        else
        {
            if (fs(pr) == NULL)
            {
                fs(pr) = p;
                pr(p) = pr;
            }
            else
            {
                q = fs(pr);
                while (nb(q) != NULL)
                {
                    q = nb(q);
                }
                nb(q) = p;
                pr(p) = pr;
            }
        }
    }
    return p;
}

void createTree(Gudang *x)
{
    (*x).root = NULL;
}

addrBar searchGudang(addrBar root, char* cariGudang)
{
    addrBar p = root;
    bool resmi = true;
    if (strcasecmp(nama(p), cariGudang) == 0)
    {
        return p;
    }
    do
    {
        if (fs(p) != NULL && resmi)
        {
            p = fs(p);
            if (strcasecmp(nama(p), cariGudang) == 0)
            {
                return p;
            }
        }
        else if (nb(p) != NULL)
        {
            p = nb(p);
            if (strcasecmp(nama(p), cariGudang) == 0)
            {
                return p;
            }
            resmi = true;
        }
        else
        {
            p = pr(p);
            resmi = false;
        }
    } while (pr(p) != NULL);
    return NULL;
}

void cetakGudang(addrBar node)
{
    if (node != NULL)
    {
        printf("Nama: %s, Harga: %d Jumlah: %d\n", nama(node), harga(node), jumlah(node));

        if (fs(node) != NULL)
        {
            cetakGudang(fs(node));
        }

        if (nb(node) != NULL)
        {
            cetakGudang(nb(node));
        }
    }
}

void tampilkanGudang(addrBar node, int i)
{
    int j = 0;
    j = i;
    j++;
    if (node != NULL)
    {
        if (i == 0)
        {
            printf("%s\n", node->nama);
        }
        else if (i == 1)
        {

            printf("Kategori: %s [Jumlah: %d]\n", node->nama, node->jumlah);
        }
        else if (i == 2)
        {

            printf(" Sub Kategori: %s [Jumlah: %d]\n", node->nama, node->jumlah);
        }
        else
        {

            printf("  -%s : Rp.%d [Jumlah: %d]\n", node->nama, node->harga, node->jumlah);
        }
        tampilkanGudang(node->fs, j);
        tampilkanGudang(node->nb, i);
    }
}

void bacaFile(Gudang gudang, char namaFile[])
{
    FILE *file;
    file = fopen(namaFile, "r");
    if (file == NULL)
    {
        printf("File tidak dapat dibuka.\n");
        exit(1);
    }

    char wadah[500];
    while (fgets(wadah, sizeof(wadah), file) != NULL)
    {
        char *jumlah, *fs, *nb, *pr;
        char *token = strtok(wadah, ",");
        infotype nama = token;
        token = strtok(NULL, ",");
        int harga = atoi(token);
        token = strtok(NULL, ",");
        int jumlah = atoi(token);
        jumlah = token;
        token = strtok(NULL, ",");
        fs = token;
        token = strtok(NULL, ",");
        nb = token;
        token = strtok(NULL, ",");
        pr = token;
        printf("cek: %s,%d,%s,%s,%s,%s\n", nama, harga, jumlah, fs, nb, pr);
        addrBar hasil = searchGudang(gudang.root, pr);
        if (hasil != NULL)
        {
            insertBarang(&gudang, hasil, nama, harga);
        }
        else
        {
            printf("Kategori %s tidak ditemukan. Data tidak dimasukkan.\n", nama);
        }
    }

    fclose(file);
}

int main()
{
    struct Gudang gudang;

    createTree(&gudang);
    insertBarang(&gudang, NULL, "Gudang", 0);

    bacaFile(gudang, "gudang.txt");

    printf("Isi Gudang:\n");
    tampilkanGudang(gudang.root, 0);

    return 0;
}
