#include "header.h"

void createTree(gudang *x)
{
    (*x).root = NULL;
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
        nama(p) = (infotype)malloc(strlen(nama) + 1);
        if (nama(p) == NULL)
        {
            printf("Memori sudah penuh\n");
        }

        // Salin nama barang
        strcpy(nama(p), nama);

        harga(p) = harga;
        jumlah(p) = 0;
        fs(p) = NULL;
        nb(p) = NULL;
        pr(p) = NULL;
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

void tampilkanKategori(addrBar node,int level,int i) 
{
    addrBar current;
    current = node->fs;
    if (node == NULL)
    {
        return;
    }
    while (current != NULL)
    {
        if (level == 1)
        {
            printf("%d. %s\n",i,current->nama);
        }
        else
        {
            tampilkanKategori(current, level - 1, i);
            i++;
        }
        current = current->nb;
        i++;
    }   
    
    
}

void tampilSubKategori(addrBar node, int level, int i)
{
    addrBar current = fs(node);
    if (node == NULL)
    {
        return;
    }
    while (current != NULL)
    {
        if (level == 1)
        {
            printf("%d. %s \n", i, nama(current));
        }
        else
        {
            tampilSubKategori(current, level - 1, i);
            i++;
        }
        current = nb(current);
        i++;
    }
}

/*Membenarkan jumlah barang di kategori dan subkategori*/
void kalibrasi()
{

}

void tambahstock(addrBar root, char carigudang[])
{
    searchGudang(root, carigudang);
    addrBar current;
    int jumlah;
    current = searchGudang(root, carigudang);
    if (current != NULL)
    {
        printf("Masukan Jumlah Barang = ");
        scanf("%d", &jumlah);
        puts("Masukan input");
        current->jumlah = current->jumlah + jumlah;
        puts("output");

        return;
    }
    else
    {
        printf("Barang Tidak ada\n");
        return;
    }
}

void kurangistock(addrBar root, char carigudang[])
{
    addrBar current;
    int jumlah;
    current = searchGudang(root, carigudang);
    // jumlah = beliBarang()
    if (current != NULL)
    {

    }
    else
    {
        return;
    }

    
}
void beliBarang(addrPem pembeli, addrBel barang)
{
    
}

addrBar searchGudang(addrBar root, char cariGudang[])
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