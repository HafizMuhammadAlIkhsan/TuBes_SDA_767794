#include "header_kasir.h"

void createTree(Gudang *x)
{
    (*x).root = NULL;
}

addrBar alokEtalase(infotype nama, int harga)
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
        if (jumlah(p) < MAX_JUMLAH)
        {
            jumlah(p) = 0;
        }
        else
        {
            return NULL;
        }
        fs(p) = NULL;
        nb(p) = NULL;
        pr(p) = NULL;
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

void tampilkanKategori(addrBar node, int level, int i)
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
            printf("%d. %s\n", i, current->nama);
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

void kurangistock(Gudang root, infotype nama, addrBel *awal, int jumlahbarang)
{
    addrBar current;
    addrBel temp, temp2;
    temp = *awal;
    while (temp != NULL)
    {
        current = searchGudang(root.root, temp->namBar->nama);

        if (current != NULL)
        {
            if (current->jumlah > jumlahbarang)
            {
                current->jumlah = current->jumlah - temp->jumlah;
            }
            else
            {
                printf("Stok barang tidak mencukupi");
                break;
            }
        }
        else
        {
            printf("Tidak ada barang nya");
        }
        temp2 = temp;
        temp = temp->nextBar;
    }
}

addrBel alokBarBel(Gudang root, infotype nama, int jumlah)
{
    addrBel p;
    p = (addrBel)malloc(sizeof(dibeli));
    if (p == NULL)
    {
        printf("Memori sudah penuh\n");
    }
    else
    {
        if (namBar(p) == NULL)
        {
            printf("Memori sudah penuh\n");
        }
        namBar(p) = searchGudang(root.root, nama);
        jumlah(p) = jumlah;
        nextBar(p) = NULL;
    }
    return p;
}

void insertBarBel(Gudang root, infotype nama, addrBel *awal, addrBel *akhir, int jumlah)
{
    addrBel p;
    p = alokBarBel(root, nama, jumlah);

    if (*awal == NULL && *akhir == NULL)
    {
        *awal = p;
    }
    else
    {
        nextBar(*akhir) = p;
    }
    *akhir = p;
}

addrBel deleteBarBel(addrBel awal, addrBel akhir)
{
    addrBel p = awal, temp;
    int nilai;

    if (awal == NULL && akhir == NULL)
    {
        printf("Linked list kosong\n");
    }
    else if (awal == akhir)
    {
        awal = NULL;
        akhir = NULL;
    }
    else
    {
        awal = p->nextBar;
    }

    p->nextBar = NULL;
    free(p);

    return p;
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

void tampilBarBel(addrBel first, addrBel last)
{
    addrBel p = first;
    int i = 1;
    while (p != NULL)
    {
        printf("%d. %s jumlah %d\n", i, p->namBar->nama, p->jumlah);
        p = nextBar(p);
        i++;
    }
}