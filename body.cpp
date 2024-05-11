#include "header.h"

void buatGudang(gudang *root)
{
    (*root).root = NULL;
}

addrBar alokBarang(infotype nama, int harga)
{
    addrBar p;
    // Alokasi memori untuk struct barang
    p = (addrBar)malloc(sizeof(barang));
    if (p == NULL)
    {
        printf("Memori sudah penuh\n");
    }
    else
    {
        p->nama = (infotype)malloc(strlen(nama) + 1);
        if (p->nama == NULL)
        {
            printf("Memori sudah penuh\n");
        }

        // Salin nama barang
        strcpy(p->nama, nama);

        p->harga = harga;
        p->jumlah = 0;
        p->fs = NULL;
        p->nb = NULL;
        p->pr = NULL;
    }
    return p;
}

addrBar insertBarang(gudang *root, addrBar pr, infotype nama, int harga)
{
    addrBar p, q;

    p = alokBarang(nama, harga);
    if (p != NULL)
    {
        if (pr == NULL)
        {
            root->root = p;
        }
        else
        {
            if (pr->fs == NULL)
            {
                pr->fs = p;
                p->pr = pr;
            }
            else
            {
                q = pr->fs;
                while (q->nb != NULL)
                {
                    q = q->nb;
                }

                q->nb = p;
                p->pr = pr;
            }
        }
    }
}

void tampilkanGudang(addrBar node, int i)
{
    int j = 0;
    j = i;
    j++;
    //printf("%d\n", i);
    if (node != NULL)
    {
        if (i == 0)
        {
            printf("%s\n", node->nama);
        }
        else if (i == 1)
        {

            printf("Kategori: %s\n", node->nama);
        }
        else if (i == 2)
        {

            printf(" Sub Kategori: %s\n", node->nama);
        }
        else
        {

            printf("  -%s: Rp.%d\n", node->nama, node->harga);
        }
        tampilkanGudang(node->fs, j);
        tampilkanGudang(node->nb, i);
    }
}