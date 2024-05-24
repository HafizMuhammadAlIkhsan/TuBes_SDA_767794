#include "header_gudang.h"

void createTree(Gudang *x)
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

void Cek_Stock_Etalase(addrBar node, int level, int i)
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
            if (current->jumlah == 0)
            {
                printf("%d. %s \t| [Jumlah: %d]\n", i, current->nama, current->jumlah);
            }
        }
        else
        {
            Cek_Stock_Etalase(current, level - 1, i);
            i++;
        }
        current = current->nb;
        i++;
    }
}


/*Membenarkan jumlah barang di kategori dan subkategori*/
void kalibrasi()
{
}
/*Agar tidak ada barang yang sama walau typo*/
string standarisasi(string nama)
{
    string text = nama;
    string hasil;
    for (int i = 0; i <= text.length(); i++)
    {
        if (i == 0)
        {
            hasil += toupper(text[i]);
        }
        else
        {
            if (text[i] == ' ')
            {
                text[i] = '_';
            }
            else
            {
                hasil += tolower(text[i]);
            }
        }
    }

    return hasil;
}

void tambahstock(addrBar root, char cariGudang[], int jumlahbarang)
{
    searchGudang(root, cariGudang);
    addrBar current;
    int jumlah = jumlahbarang = jumlahbarang;
    current = searchGudang(root, cariGudang);
    if (current != NULL)
    {
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

bool cekKategori(addrBar node, int level, infotype search)
{
    addrBar current;
    current = node->fs;
    if (node == NULL)
    {
        return false;
    }
    while (current != NULL)
    {
        if (level == 1)
        {
            if (strcmp(current->nama, search) == 0)
            {
                return true;
            }
        }
        else
        {
            return cekKategori(current, level - 1, search);
        }
        current = current->nb;
    }
    return false;
}
