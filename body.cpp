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

void tampilkanKategori(addrBar root,int level,int i) 
{
    addrBar current;
    current = root->fs;
    if (root == NULL)
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

void tampilSubKategori(addrBar root, int level, int i)
{
    addrBar current = fs(root);
    if (root == NULL)
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

int main()
{
    gudang root;
    addrBar hasil;
    int opsi, level = 1, i = 1;
    puts("masuk");
    createTree(&root);
    insertBarang(&root, NULL, "King Jonats", 0);
    puts("masuk tampil");
    hasil = searchGudang(root.root, "King Jonats");
    puts("selesai cari root");
    insertBarang(&root, hasil, "Makanan", 0);
    insertBarang(&root, hasil, "Minuman", 0);
    insertBarang(&root, hasil, "Kosmetik", 0);
    puts("cari makanan");
    hasil = searchGudang(root.root, "Makanan");
    puts("selesai cari makanan");
    insertBarang(&root, hasil, "Makanan ringan", 0);
    insertBarang(&root, hasil, "Makanan berat", 0);
    puts("cari minuman");
    hasil = searchGudang(root.root, "Minuman");
    puts("selesai cari minuman");
    insertBarang(&root, hasil, "Minuman bersoda", 0);
    insertBarang(&root, hasil, "Minuman berakohol", 0);
    puts("cari kosmetik");
    hasil = searchGudang(root.root, "Kosmetik");
    puts("selesai cari minuman");
    insertBarang(&root, hasil, "Pelembap", 0);
    insertBarang(&root, hasil, "Pemutih (deniggafy)", 0);
    system("cls");
    puts("Kategori");
    tampilkanKategori(root.root,level,i);
    tampilSubKategori(root.root, level, i);
    tampilkanGudang(root.root, 0);

    puts("Menu kasir");
    puts("1. Lihat Kategori");
    puts("2. Lihat Subkategori");
    puts("3. Lihat Barang");
    puts("4. Beli Barang");
    puts("5. Lihat Barang");
}