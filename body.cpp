#include "header.h"

void createTree(Gudang *x)
{
    (*x).root = NULL;
}

addrBar alokBarang(infotype nama, int harga, int jumlah)
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
        p->jumlah = jumlah;
        p->fs = NULL;
        p->nb = NULL;
        p->pr = NULL;
    }
    return p;
}

addrBar insertBarang(Gudang *root, addrBar pr, infotype nama, int harga, int jumlah)
{
    addrBar p, q;
    p = alokBarang(nama, harga, jumlah);
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

            printf("  -%s : Rp %d [Jumlah: %d]\n", node->nama, node->harga, node->jumlah);
        }
        tampilkanGudang(node->fs, j);
        tampilkanGudang(node->nb, i);
    }
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
        current->pr->jumlah = current->pr->jumlah + jumlah;
        current->pr->pr->jumlah = current->pr->pr->jumlah + jumlah;
        puts("output");

        return;
    }
    else
    {
        printf("Barang Tidak ada\n");
        return;
    }
}

void tambahStockEtalase(addrBar etalase, addrBar gudang, int level)
{
    int jumlahStok;
    addrBar barangEtalase, barangGudang;
    barangEtalase = etalase->fs;
    if (etalase == NULL)
    {
        puts("Tree etalase belum dibuat");
    }

    while (barangEtalase != NULL)
    {
        if (level == 1)
        {
            if (barangEtalase->jumlah < MAX_JUMLAH)
            {
                // ? Mencari barang tersebut di gudang
                barangGudang = searchGudang(gudang, barangEtalase->nama);

                if (barangGudang->jumlah < MAX_JUMLAH - barangEtalase->jumlah)
                {
                    jumlahStok = barangGudang->jumlah;
                }
                else
                {
                    jumlahStok = MAX_JUMLAH - barangEtalase->jumlah;
                }

                // ? Mengurangi stok barang dan juga parentnya (etalase)
                barangGudang->jumlah = barangGudang->jumlah - jumlahStok;
                barangGudang->pr->jumlah = barangGudang->pr->jumlah - jumlahStok;
                barangGudang->pr->pr->jumlah = barangGudang->pr->pr->jumlah - jumlahStok;

                // ? Mengurangi stok barang dan juga parentnya (etalase)
                barangEtalase->jumlah = barangEtalase->jumlah + jumlahStok;
                barangEtalase->pr->jumlah = barangEtalase->pr->jumlah + jumlahStok;
                barangEtalase->pr->pr->jumlah = barangEtalase->pr->pr->jumlah + jumlahStok;

                printf("-%s ditambahkan %s%d%s, sisa %s%d%s di gudang\n", barangEtalase->nama, blue, jumlahStok, normal, blue, barangGudang->jumlah, normal);
            }
        }
        else
        {
            tambahStockEtalase(barangEtalase, gudang, level - 1);
        }
        barangEtalase = barangEtalase->nb;
    }
}

bool cekKategori(addrBar node, infotype search)
{
    addrBar p = node;
    bool resmi = true;
    if (strcasecmp(p->nama, search) == 0)
    {
        return true;
    }
    do
    {
        if (p->fs != NULL && resmi)
        {
            p = p->fs;
            if (strcasecmp(p->nama, search) == 0)
            {
                return true;
            }
        }
        else if (p->nb != NULL)
        {
            p = p->nb;
            if (strcasecmp(p->nama, search) == 0)
            {
                return true;
            }
            resmi = true;
        }
        else
        {
            p = p->pr;
            resmi = false;
        }
    } while (p->pr != NULL);
    return false;
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
        p->nama = (infotype)malloc(strlen(nama) + 1);
        if (p->nama == NULL)
        {
            printf("Memori sudah penuh\n");
        }

        // Salin nama barang
        strcpy(p->nama, nama);

        p->harga = harga;
        if (p->jumlah < MAX_JUMLAH)
        {
            p->jumlah = 0;
        }
        else
        {
            return NULL;
        }
        p->fs = NULL;
        p->nb = NULL;
        p->pr = NULL;
    }
    return p;
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

void tampilKategori(addrBar node, int level, int i)
{
    addrBar current = node->fs;
    if (node == NULL)
    {
        printf("Tidak ada Ketegori yang bisa ditampilkan.");
        exit(1);
    }
    while (current != NULL)
    {
        if (level == 1)
        {
            printf("%d. %s \n", i, current->nama);
        }
        else
        {
            tampilKategori(current, level - 1, i);
            i++;
        }
        current = current->nb;
        i++;
    }
}

void tampilSubKategori(addrBar node, int level, int *i)
{
    addrBar current = node->fs;
    if (node == NULL)
    {
        printf("Tidak ada Sub Ketegori yang bisa ditampilkan.");
        exit(1);
    }
    while (current != NULL)
    {
        if (level == 1)
        {
            printf("%d. %s \n", (*i)++, current->nama);
        }
        else
        {
            tampilSubKategori(current, level - 1, i);
        }
        current = current->nb;
    }
}

void tampilBarang(addrBar node, int level)
{
    addrBar current = node->fs;
    static int tempNumber = 1;
    static int resetTempNumber = 0;     //digunakan untuk mereset tempNumber kembali menjadi 1 saat dipanggil kembali pada main

    if (node == NULL)
    {
        printf("Tidak ada Barang yang bisa ditampilkan.");
        exit(1);
    }
    resetTempNumber++;
    if (level == 0)
    {
        if (tempNumber >= 10)
        {
            if (node->jumlah == 0)
            {
                printf("%-2d. %-20s Jumlah stok: %s%d%s\n", tempNumber, node->nama, red, node->jumlah, normal);
            }
            else  
            {
                printf("%-2d. %-20s Jumlah stok: %s%d%s\n", tempNumber, node->nama, green, node->jumlah, normal);
            }
        }
        else
        {
            if (node->jumlah == 0)
            {
                printf("%d. %-21s Jumlah stok: %s%d%s\n", tempNumber, node->nama, red, node->jumlah, normal);
            }
            else  
            {
                printf("%d. %-21s Jumlah stok: %s%d%s\n", tempNumber, node->nama, green, node->jumlah, normal);
            }
        }
        tempNumber++;
    }
    else
    {
        while (current != NULL)
        {
            tampilBarang(current, level - 1);
            current = current->nb;
        }
    }
    resetTempNumber--;
    if (resetTempNumber == 0)
    {
        tempNumber = 1;
    }
}

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

void kurangistock(Gudang root, addrBel awal)
{
    addrBar current;
    addrBel temp;
    temp = awal;
    while (temp != NULL)
    {

        if (temp->namaBarang != NULL)
        {
            if (temp->namaBarang->jumlah > temp->jumlah)
            {
                temp->namaBarang->jumlah = temp->namaBarang->jumlah - temp->jumlah;
                temp->namaBarang->pr->jumlah = temp->namaBarang->pr->jumlah - temp->jumlah;
                temp->namaBarang->pr->pr->jumlah = temp->namaBarang->pr->pr->jumlah - temp->jumlah;
            }
            else
            {
                puts("Stok barang tidak mencukupi");
                break;
            }
        }
        else
        {
            printf("Tidak ada barang nya");
        }
        temp = temp->nextBarang;
    }
}

addrBel alokBelanja(Gudang root, addrBar beli, int jumlah)
{
    addrBel p;
    p = (addrBel)malloc(sizeof(belanjaan));
    if (p == NULL)
    {
        printf("Memori sudah penuh\n");
        printf("Cek1\n");
    }
    else
    {
        p->namaBarang = beli;
        p->jumlah = jumlah;
        p->nextBarang = NULL;
    }
    return p;
}

void insertbelanja(Gudang root, addrBar beli, addrBel *awal, addrBel *akhir, int jumlah)
{
    addrBel p;
    addrBel current = *awal;
    while (current != NULL)
    {
        if (strcasecmp(current->namaBarang->nama, beli->nama) == 0)
        {
            current->jumlah = current->jumlah + jumlah;
            return;
        }
        current = current->nextBarang;
    }
    p = alokBelanja(root, beli, jumlah);

    if (*awal == NULL && *akhir == NULL)
    {
        *awal = p;
    }
    else
    {
        nextBarang(*akhir)= p;
    }
    *akhir = p;
}

addrBel deleteBelanja(addrBel *awal, addrBel akhir)
{
    addrBel p = (*awal), temp;

    if ((*awal) == NULL && akhir == NULL)
    {
        printf("List kosong\n");
    }
    else if ((*awal) == akhir)
    {
        (*awal) = NULL;
        akhir = NULL;
    }
    else
    {
        (*awal) = p->nextBarang;
    }

    p->nextBarang = NULL;
    free(p);

    return p;
}

addrBar searchGudang(addrBar root, char cariGudang[])
{
    addrBar p = root;
    bool resmi = true;
    if (strcasecmp(p->nama, cariGudang) == 0)
    {        
        return p;
    }
    do
    {
        if (p->fs != NULL && resmi)
        {
            p = p->fs;
            if (strcasecmp(p->nama, cariGudang) == 0)
            {
                return p;
            }
        }
        else if (p->nb != NULL)
        {
            p = p->nb;
            if (strcasecmp(p->nama, cariGudang) == 0)
            {
                return p;
            }
            resmi = true;
        }
        else
        {
            p = p->pr;
            resmi = false;
        }
    } while (p->pr != NULL);
    return NULL;
}

int tampilkanBelanja(addrBel first)
{
    int totalHarga = 0;
    addrBel p = first;
    int i = 1;
    while (p != NULL)
    {
        printf("%d. %s jumlah %d x %d: %d\n", i, p->namaBarang->nama, p->jumlah, p->namaBarang->harga, p->jumlah * p->namaBarang->harga);
        totalHarga = totalHarga + (p->jumlah * p->namaBarang->harga);
        p = p->nextBarang;
        i++;
    }
    printf("Total harga: %d\n", totalHarga);
    return totalHarga;
}

void bacaFile(Gudang gudang, char namaFile[])
{
    addrBar hasil;
    infotype nama;
    int harga, jumlah;

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
        char *pr;
        char *token = strtok(wadah, ",");
        nama = token;
        token = strtok(NULL, ",");
        harga = atoi(token);
        token = strtok(NULL, ",");
        jumlah = atoi(token);
        token = strtok(NULL, ",");
        pr = token;

        hasil = searchGudang(gudang.root, pr);
        if (hasil != NULL)
        {
            insertBarang(&gudang, hasil, nama, harga, jumlah);
        }
        else
        {
            printf("Kategori %s tidak ditemukan. Data tidak dimasukkan.\n", nama);
        }
    }

    fclose(file);
}

void tampilkan_katalog(addrBar root, int arah, int arahsub)
{
    addrBar current = root->fs; // ke kategori
    addrBar temp;
    addrBar barang;
    int id;
    id = 1;
    system("cls");
    for (int i = 0; i < arah && current != NULL; i++) // pindah kategori
    {
        current = current->nb;
    }

    if (current->fs != NULL)
    {
        temp = current->fs;
        for (int i = 0; i < arahsub && temp != NULL; i++)
        {
            temp = temp->nb;
        }
    }
    else
    {
        temp = NULL;
    }

    puts("========================================");
    if (current != NULL)
    {
        printf("%s \n", current->nama); // Kategori
    }
    else
    {
        printf("tidak ada kategori\n");
    }

    puts("----------------------------------------");
    if (temp != NULL)
    {
        current = temp;
        printf("%s \n", current->nama);
    }
    else
    {
        printf("tidak ada sub kategori\n");
    }
    puts("========================================");

    /*disini temp ada di subkategori*/
    if (current != NULL)
    {
        barang = current->fs; // ke barang
        if (barang != NULL)
        {
            while (barang != NULL)
            {
                if (strlen(barang->nama) < 5)
                {
                    printf("%d.%s \t\t\t[stock %d]\n", id, barang->nama, barang->jumlah);
                }
                else if (strlen(barang->nama) < 13)
                {
                    printf("%d.%s \t\t[stock %d]\n", id, barang->nama, barang->jumlah);
                }
                else
                {
                    printf("%d.%s \t[stock %d]\n", id, barang->nama, barang->jumlah);
                }

                id += 1;
                barang = barang->nb;
            }
        }
        else
        {
            printf("Tidak ada Barang\n");
        }
    }
    else
    {
        printf("Tidak ada Sub kategori\n");
    }

    puts("========================================");
    puts("press left or right arrow key to flip the page");
    puts("Press B to open buy menu");
    puts("Press Q to go back");
    puts("========================================");
}

int previous(addrBar current, int current_page)
{
    int hasil;
    int i;
    i = 0;
    addrBar temp = current; // root
    temp = temp->fs;        // kategori
    for (int i = 0; i < current_page - 1; i++)
    {
        temp = temp->nb;
    }

    temp = temp->fs;

    while (temp != NULL)
    {
        hasil += 1;
        temp = temp->nb;
        cout << i++;
    }

    return hasil - 1;
}

bool katalog(addrBar root)
{
    /**/
    int current_page = 0;
    int current_page_sub = 0;
    int ch;
    int max = 0;
    int max_sub = 0;
    addrBar current;
    addrBar temp;

    bool quit = false;
    bool cek = false;

    current = root->fs; // di kategori
    temp = current;

    if (current != NULL)
    {
        while (temp != NULL) // kategori max kategori
        {
            max += 1;
            temp = temp->nb;
        }
    }

    tampilkan_katalog(root, current_page, current_page_sub);

    while (!quit)
    {
        current = root->fs; // di kategori
        for (int i = 0; i < current_page; i++)
        {
            current = current->nb;
        }

        if (current->fs != NULL && !cek)
        {
            temp = current->fs; // di awal sub kategori
            while (temp != NULL)
            {
                max_sub += 1;
                temp = temp->nb;
            }
            cek = true;
        }

        ch = _getch();
        if (ch == 0 || ch == 224) // default is variabel ch
        {
            switch (_getch())
            {
            case 77:                                // right
                if (current_page_sub < max_sub - 1) // pindah page sub
                {
                    current_page_sub++;
                }
                else if (current_page < max - 1) // pindah page kategori
                {
                    current_page++;
                    current_page_sub = 0;
                    max_sub = 0;
                    cek = false;
                }

                break;
            case 75: // left
                if (current_page_sub > 0)
                {
                    current_page_sub--;
                }
                else if (current_page > 0)
                {

                    current_page_sub = previous(root, current_page);
                    current_page--;
                    max_sub = 0;
                    cek = false;
                }
                break;

            default:
                break;
            }
            tampilkan_katalog(root, current_page, current_page_sub);
        }
        else if (ch == 'q' || ch == 'Q')
        {
            quit = true;
            return false;
        }
        else if (ch == 'B' || ch == 'b')
        {
            quit = true;
            return true;
        }
    }
}

void updateData(addrBar root)
{
    FILE *f_gudang;
    if ((f_gudang = fopen("DATA/gudang.txt", "wt+")) == NULL)
    {
        printf("File tidak dapat dibuka\n");
        exit(1);
    }

    infotype pr;
    addrBar Pcur = root; // Posisi node aktif
    bool resmi = true;   // Kunjungan resmi
    do
    {
        if (Pcur->fs != NULL && resmi)
        {
            Pcur = Pcur->fs;
            if (Pcur->pr == NULL)
            {
                pr = "NULL";
            }
            else
            {
                pr = Pcur->pr->nama;
            }

            fprintf(f_gudang, "%s,%d,%d,%s,\n", Pcur->nama, Pcur->harga, Pcur->jumlah, pr);
        }
        else if (Pcur->nb != NULL)
        {
            Pcur = Pcur->nb;
            if (Pcur->pr == NULL)
            {
                pr = "NULL";
            }
            else
            {
                pr = Pcur->pr->nama;
            }
            fprintf(f_gudang, "%s,%d,%d,%s,\n", Pcur->nama, Pcur->harga, Pcur->jumlah, pr);
            resmi = true;
        }
        else
        {
            Pcur = Pcur->pr;
            resmi = false; // Numpang lewat
        }
    } while (Pcur->pr != NULL);
    fclose(f_gudang);
}

void transaksi(int Total, Gudang root, addrBel awal)
{
    int temp;
    system("cls");
    printf("Total harga          : Rp %d\n", Total);
    printf("Masukkan jumlah uang : Rp ");
    scanf(" %d", &temp);
    if (Total <= temp)
    {
        printf("Kembalian            : Rp %d\n", temp - Total);
        puts("Terima kasih sudah belanja!");
        kurangistock(root, awal);
        updateData(root.root);
    }
    else
    {
        printf("Uang Tidak cukup\n");
    }
}

// ? =================================================== Modul untuk menu kasir ==============================================================

void lihatKategori(Gudang gudang)
{
    puts("List kategori");
    tampilKategori(gudang.root, 1, 1);
    system("pause");
}

void lihatSubKategori(Gudang gudang)
{
    int i = 1;
    puts("List Sub Kategori");
    tampilSubKategori(gudang.root, 2, &i);
    system("pause");
}

void lihatBarang(Gudang gudang)
{
    puts("List Barang");
    tampilBarang(gudang.root, 3);
    system("pause");
}

void belanja(Gudang gudang)
{
    char beli[256], lanjut;
    int jumlahBarang, returnValue, harga;
    addrBar beliBar;
    addrBel awal = NULL, akhir = NULL, curr;
    if(katalog(gudang.root))
    {
        do
        {
            printf("Beli: ");
            scanf(" %[^\n]s", &beli);
            printf("Jumlah: ");
            scanf("%d", &jumlahBarang);

            while (!cekKategori(gudang.root, beli))
            {
                printf("%s tidak ada\n", beli);
                printf("Beli: ");
                scanf(" %[^\n]s", &beli);
                printf("Jumlah: ");
                scanf("%d", &jumlahBarang);
            }
        
        beliBar = searchGudang(gudang.root, beli);
        if (beliBar != NULL)
        {
            insertbelanja(gudang, beliBar, &awal, &akhir, jumlahBarang);
        }
        else
        {
            puts("Barang tidak ada");
            break;
        }
        printf("Ada lagi yang dibeli? (y/n): ");
        scanf(" %c", &lanjut);

        } while (lanjut == 'y' || lanjut == 'Y');
        system("cls");
        puts("Struk Hafiz Market");
        returnValue = tampilkanBelanja(awal);
        system("pause");
        system("cls");
        transaksi(returnValue, gudang, awal);
        system("pause");
        // ? Proses delete pembelian
        curr = awal;
        while (curr->nextBarang != NULL)
        {
            curr = curr->nextBarang;
            deleteBelanja(&awal, akhir);
        }
    }
    
}

// ? ================================================== Modul untuk menu gudang ==============================================================

void tambahKategori(Gudang gudang)
{
    char kategori[256], subkategori[256];
    addrBar hasil;
    int opsi;
    do
    {
        system("cls");
        puts("(1) Tambah Kategori");
        puts("(2) Tambah Sub Kategori");
        puts("(0) Kembali");

        printf("Pilih opsi: ");
        scanf("%d", &opsi);
        switch (opsi)
        {
        case 1:
            system("cls");
            puts("Tambah Kategori");
            printf("Nama kategori baru: ");
            scanf(" %[^\n]s", &kategori);
            while (cekKategori(gudang.root, kategori))
            {
                system("cls");
                printf("%sKategori %s sudah terdaftar!%s\n", red, kategori, normal);
                puts("Tambah Kategori");
                printf("Nama kategori baru: ");
                scanf(" %[^\n]s", &kategori);
            }
            hasil = insertBarang(&gudang, gudang.root, kategori, 0, 0);
            system("cls");
            if (hasil != NULL)
            {
                printf("%sKategori %s berhasil didaftarkan!%s\n", green, hasil->nama, normal);
            }
            else
            {
                puts("Gagal mendaftarkan kategori");
            }
            system("pause");
            opsi = 0;
            break;
        case 2:
            system("cls");
            puts("Tambah Sub-Kategori");
            printf("Kategori              : ");
            scanf(" %[^\n]s", &kategori);
            while (!cekKategori(gudang.root, kategori))
            {
                system("cls");
                printf("%sKategori %s belum terdaftar!%s\n", red, kategori, normal);
                puts("Tambah Sub-Kategori");
                printf("Kategori              : ");
                scanf(" %[^\n]s", &kategori);
            }
            hasil = searchGudang(gudang.root, kategori);
            printf("Nama Sub-kategori baru: ");
            scanf(" %[^\n]s", &subkategori);

            while (cekKategori(gudang.root, subkategori))
            {
                system("cls");
                printf("%sSub-kategori %s sudah terdaftar!%s\n", red, subkategori, normal);
                puts("Tambah Sub-Kategori");
                printf("Kategori              : %s\n", kategori);
                printf("Nama Sub-kategori baru: ");
                scanf(" %[^\n]s", &subkategori);
            }
            hasil = insertBarang(&gudang, hasil, subkategori, 0, 0);
            system("cls");
            if (hasil != NULL)
            {
                printf("%sSub-kategori %s berhasil didaftarkan!%s\n", green, hasil->nama, normal);
            }
            else
            {
                puts("Gagal mendaftarkan sub-kategori");
            }
            system("pause");
            opsi = 0;
            break;
        case 0:
            puts("Kembali ke menu sebelumnya...");
            break;
        default:
            printf("Inputkan salah satu opsi di atas!\n");
            puts("===============================================================");
            system("pause");
            break;
        }
    } while (opsi != 0);
}

void tambahBarangBaru(Gudang gudang)
{
    char kategori[256], subkategori[256], barang[256];
    addrBar hasil;
    int harga;

    system("cls");
    puts("Tambah Barang Baru");
    printf("Kategori        : ");
    scanf(" %[^\n]s", &kategori);
    while (!cekKategori(gudang.root, kategori))
    {
        system("cls");
        printf("%sKategori %s belum terdaftar!%s\n", red, kategori, normal);
        puts("Tambah Barang Baru");
        printf("Kategori        : ");
        scanf(" %[^\n]s", &kategori);
    }
    hasil = searchGudang(gudang.root, kategori);
    printf("Sub-kategori    : ");
    scanf(" %[^\n]s", &subkategori);

    while (!cekKategori(gudang.root, subkategori))
    {
        system("cls");
        printf("%sSub-kategori %s belum terdaftar!%s\n", red, subkategori, normal);
        puts("Tambah Barang Baru");
        printf("Kategori        : %s\n", kategori);
        printf("Sub-kategori    : ");
        scanf(" %[^\n]s", &subkategori);
    }
    hasil = searchGudang(gudang.root, subkategori);

    printf("Nama barang baru: ");
    scanf(" %[^\n]s", &barang);
    while (cekKategori(gudang.root, barang))
    {
        system("cls");
        printf("%sBarang %s sudah terdaftar!%s\n", red, barang, normal);
        puts("Tambah Barang Baru");
        printf("Kategori        : %s\n", kategori);
        printf("Sub-kategori    : %s\n", subkategori);
        printf("Nama barang baru: ");
        scanf(" %[^\n]s", &barang);
    }
    printf("Harga barang    : ");
    scanf("%d", &harga);
    hasil = insertBarang(&gudang, hasil, barang, harga, 0);

    system("cls");
    if (hasil != NULL)
    {
        printf("%sBarang %s berhasil didaftarkan!%s\n", green, hasil->nama, normal);
    }
    else
    {
        puts("Gagal mendaftarkan barang");
    }
    system("pause");
}

void tambahStokBarang(Gudang gudang)
{
    char beli[256];
    int jumlah;
    system("cls");
    printf("Tambah Stok\n");
    printf("Masukan Nama Barang  : ");
    scanf(" %[^\n]s", &beli);
    while (!cekKategori(gudang.root, beli))
    {
        system("cls");
        printf("%sBarang %s belum terdaftar! %s\n", red, beli, normal);
        printf("Tambah Stok\n");
        printf("Masukan Nama Barang  : ");
        scanf(" %[^\n]s", &beli);
    }
    printf("Masukan Jumlah Barang: ");
    scanf(" %d", &jumlah);
    tambahstock(gudang.root, beli, jumlah);
    system("cls");
    printf(" %sBerhasil menambahkan stok %s sejumlah %d. %s\n", green, beli, jumlah, normal);
    system("pause");
}

void tampilkanStokBarang(Gudang gudang)
{
    system("cls");
    tampilkanGudang(gudang.root, 0);
    system("pause");
}