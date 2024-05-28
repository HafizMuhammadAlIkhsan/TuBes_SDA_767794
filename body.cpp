#include "header.h"

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
        } else {
            return NULL;
        }
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
            hasil += tolower(text[i]);
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

void kurangistock(Gudang root, infotype nama, addrBel *awal, int jumlahbarang)
{
    addrBar current;
    addrBel temp,temp2;
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
        namBar(p) = searchGudang(root.root,nama);
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

bool cekKategori(addrBar node,int level, infotype search) 
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

void Entry_file()
// Procedure untuk mengentrykan data ke file Mhs_jtk.dat
{
    data_barang dt;
    char lagi;
    FILE *f_mhs;
    if ((f_mhs = fopen("gudang.txt", "a")) == NULL)
    {
        printf("File tidak dapat dibuka\n");
        exit(1);
    }
    for (;;)
    {
        puts("masuk input");
        fflush(stdin);
        printf("Nama Barang : ");
        scanf("%s", &dt.nama);
        fflush(stdin);
        printf("Harga : ");
        scanf("%d", &dt.harga);
        fflush(stdin);
        printf("Jumlah Barang : ");
        scanf("%d", &dt.jumlah);
        printf("FS : ");
        scanf("%s", &dt.fs);
        printf("NB : ");
        scanf("%s", &dt.nb);
        printf("PR : ");
        scanf("%s", &dt.pr);
        // Sebelum nyimpan ke file, Hapus dulu isi penampung keyboard
        fflush(stdin);
        // Save to file
        fprintf(f_mhs, "%s,%d,%d,%s,%s,%s", dt.nama, dt.harga, dt.jumlah, dt.fs, dt.nb, dt.pr);
        printf("Entry data lagi ? (Y/T) ");
        lagi = getche();
        printf("\n");
        if (lagi == 't' || lagi == 'T')
            break;
    }
    fclose(f_mhs);
}
void Tampil_file()
// Procedure untuk Menampilkan isi file mahasiswa
{
    data_barang dt;
    FILE *f_mhs;
    if ((f_mhs = fopen("Mhs_jtk.dat", "rb")) == NULL)
    {
        printf("File tidak dapat dibuka\n");
        exit(1);
    }
    printf("\nISI FILE MHS_JTK.dat ADALAH : \n\n");
    printf("Kelas NIM JK IP \n");
    while (!feof(f_mhs))
    {
        fscanf(f_mhs, "%s", &dt.nama);
        strtok(dt.nama, ",");
        printf("%s\n", dt.nama);
        fscanf(f_mhs, "%s", &dt.harga);
        strtok(dt.harga, ",");
        printf("%s\n", dt.harga);
        fscanf(f_mhs, "%s", &dt.jumlah);
        strtok(dt.jumlah, ",");
        printf("%s\n", dt.jumlah);
        fscanf(f_mhs, "%s", &dt.fs);
        strtok(dt.fs, ",");
        printf("%s\n", dt.fs);
        fscanf(f_mhs, "%s", &dt.nb);
        strtok(dt.nb, ",");
        printf("%s\n", dt.nb);
        fscanf(f_mhs, "%s", &dt.pr);
        strtok(dt.pr, ",");
        printf("%s\n", dt.pr);
    }
    fclose(f_mhs);
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

    char wadah[256];
    while (fgets(wadah, sizeof(wadah), file) != NULL)
    {
        char *jumlah, *fs, *nb, *pr;
        char *token = strtok(wadah, ",");
        infotype nama = token;
        token = strtok(NULL, ",");
        int harga = atoi(token);
        token = strtok(NULL, ",");
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