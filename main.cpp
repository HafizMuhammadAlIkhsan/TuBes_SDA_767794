#include "header.h"

int main()
{
    Gudang gudang, etalase;
    addrBar hasil, beliBar;
    addrBel awal = NULL, akhir = NULL, curr;
    int opsi, i = 1, returnValue, jumBar, harga;
    char lanjut, beli[100], nama[100];

    createTree(&gudang);
    createTree(&etalase);

    /*Paling atas*/
    insertBarang(&gudang, NULL, "Gudang", 0, 0);
    insertBarang(&etalase, NULL, "Etalase", 0, 0);

    hasil = searchGudang(gudang.root, "Gudang");

    /*Kategori*/
    insertBarang(&gudang, hasil, "Makanan", 0, 0);
    insertBarang(&gudang, hasil, "Minuman", 0, 0);
    insertBarang(&gudang, hasil, "Kosmetik", 0, 0);

    /*Sub Kategori*/
    hasil = searchGudang(gudang.root, "Makanan");
    insertBarang(&gudang, hasil, "Snack", 0, 0);
    insertBarang(&gudang, hasil, "Makanan beku", 0, 0);

    /*Barang*/
    hasil = searchGudang(gudang.root, "Snack");
    insertBarang(&gudang, hasil, "Chitato", 11000, 0);
    tambahstock(gudang.root, "Chitato", 4);
    insertBarang(&gudang, hasil, "Taro", 8000, 0);
    tambahstock(gudang.root, "Taro", 120);
    insertBarang(&gudang, hasil, "Lays", 11000, 0);
    tambahstock(gudang.root, "Lays", 120);
    insertBarang(&gudang, hasil, "Pota Bee", 10000, 0);
    tambahstock(gudang.root, "Pota Bee", 120);

    /*barang*/
    hasil = searchGudang(gudang.root, "Makanan Beku");
    insertBarang(&gudang, hasil, "So Good", 21000, 0);
    tambahstock(gudang.root, "So Good", 120);
    insertBarang(&gudang, hasil, "Fiesta", 19000, 0);
    tambahstock(gudang.root, "Fiesta", 120);

    /*Sub kategori*/
    hasil = searchGudang(gudang.root, "Minuman");
    insertBarang(&gudang, hasil, "Minuman bersoda", 0, 0);
    insertBarang(&gudang, hasil, "Minuman berakohol", 0, 0);

    /*Barang*/
    hasil = searchGudang(gudang.root, "Minuman bersoda");
    insertBarang(&gudang, hasil, "Coca Cola", 7000, 0);
    tambahstock(gudang.root, "Coca Cola", 120);
    insertBarang(&gudang, hasil, "Sprite", 7000, 0);
    tambahstock(gudang.root, "Sprite", 120);
    insertBarang(&gudang, hasil, "Fanta", 7000, 0);
    tambahstock(gudang.root, "Fanta", 120);
    insertBarang(&gudang, hasil, "Pepsi", 8000, 0);
    tambahstock(gudang.root, "Pepsi", 120);

    /*Barang*/
    hasil = searchGudang(gudang.root, "Minuman berakohol");
    insertBarang(&gudang, hasil, "HAARAAMM", 1000000000, 0);
    tambahstock(gudang.root, "HAARAAMM", 120);

    /*Sub Kategori*/
    hasil = searchGudang(gudang.root, "Kosmetik");
    insertBarang(&gudang, hasil, "Sabun Cuci Muka", 0, 0);
    insertBarang(&gudang, hasil, "Pemutih", 0, 0);

    /*Barang*/
    hasil = searchGudang(gudang.root, "Sabun Cuci Muka");
    insertBarang(&gudang, hasil, "Mens Biore", 21000, 0);
     tambahstock(gudang.root, "Mens Biore", 120);
    insertBarang(&gudang, hasil, "Garnier Men", 19000, 0);
    tambahstock(gudang.root, "Garnier Men", 120);
    system("cls");

    puts("masuk insert etalase");
    hasil = searchGudang(etalase.root, "Etalase");

    /*Kategori*/
    insertBarang(&etalase, hasil, "Makanan", 0, 0);
    insertBarang(&etalase, hasil, "Minuman", 0, 0);
    insertBarang(&etalase, hasil, "Kosmetik", 0, 0);

    /*Sub Kategori*/
    hasil = searchGudang(etalase.root, "Makanan");
    insertBarang(&etalase, hasil, "Snack", 0, 0);
    insertBarang(&etalase, hasil, "Makanan beku", 0, 0);

    /*Barang*/
    hasil = searchGudang(etalase.root, "Snack");
    insertBarang(&etalase, hasil, "Chitato", 11000, 0);
    insertBarang(&etalase, hasil, "Taro", 8000, 0);
    insertBarang(&etalase, hasil, "Lays", 11000, 0);
    insertBarang(&etalase, hasil, "Pota Bee", 10000, 0);

    /*barang*/
    hasil = searchGudang(etalase.root, "Makanan Beku");
    insertBarang(&etalase, hasil, "So Good", 21000, 0);
    insertBarang(&etalase, hasil, "Fiesta", 19000, 0);

    /*Sub kategori*/
    hasil = searchGudang(etalase.root, "Minuman");
    insertBarang(&etalase, hasil, "Minuman bersoda", 0, 0);
    insertBarang(&etalase, hasil, "Minuman berakohol", 0, 0);

    /*Barang*/
    hasil = searchGudang(etalase.root, "Minuman bersoda");
    insertBarang(&etalase, hasil, "Coca Cola", 7000, 0);
    insertBarang(&etalase, hasil, "Sprite", 7000, 0);
    insertBarang(&etalase, hasil, "Fanta", 7000, 0);
    insertBarang(&etalase, hasil, "Pepsi", 8000, 0);

    /*Barang*/
    hasil = searchGudang(etalase.root, "Minuman berakohol");
    insertBarang(&etalase, hasil, "HAARAAMM", 1000000000, 0);

    /*Sub Kategori*/
    hasil = searchGudang(etalase.root, "Kosmetik");
    insertBarang(&etalase, hasil, "Sabun Cuci Muka", 0, 0);
    insertBarang(&etalase, hasil, "Pemutih", 0, 0);

    /*Barang*/
    hasil = searchGudang(etalase.root, "Sabun Cuci Muka");
    insertBarang(&etalase, hasil, "Mens Biore", 21000, 0);
    insertBarang(&etalase, hasil, "Garnier Men", 19000, 0);
    system("cls");

    // puts("Barang yang ditambahkan pada etalase");
    // tambahStockEtalase(etalase.root, gudang.root, 3);
    // system("pause");

    // puts("");
    // tampilkanGudang(etalase.root, 0);
    // system("pause");

    do
    {
        system("cls");
        puts("(1) Menu Kasir");
        puts("(2) Menu Gudang");
        puts("(0) Keluar program");

        printf("Pilih opsi: ");
        scanf("%d", &opsi);
        switch (opsi)
        {
        case 1:
            do
            {
                awal = NULL;
                akhir = NULL;
                system("cls");
                puts("Menu Kasir");
                puts("1. Lihat Kategori");
                puts("2. Lihat Sub Kategori");
                puts("3. Lihat Barang");
                puts("4. Belanja");
                puts("0. Pergi");

                printf("Pilih opsi: ");
                scanf("%d", &opsi);
                puts("");
                switch (opsi)
                {
                case 1:
                    puts("List kategori");
                    tampilSubKategori(gudang.root, 1, 1);
                    system("pause");
                    break;
                case 2:
                    puts("List Sub Kategori");
                    tampilSubKategori(gudang.root, 2, 1);
                    system("pause");
                    break;
                case 3:
                    puts("List Barang");
                    tampilSubKategori(gudang.root, 3, 1);
                    system("pause");
                    break;
                case 4:
                    do
                    {
                        printf("Beli: ");
                        scanf(" %[^\n]s", &beli);
                        printf("Jumlah: ");
                        scanf("%d", &jumBar);

                        beliBar = searchGudang(gudang.root, beli);
                        if (beliBar != NULL)
                        {
                            insertBarBel(gudang, beliBar, &awal, &akhir, jumBar);
                        }
                        else
                        {
                            puts("Barang tidak ada");
                            break;
                        }
                        printf("Ada lagi yang dibeli? (y/n): ");
                        scanf(" %c", &lanjut);

                    } while (lanjut == 'y' || lanjut == 'Y');
                    kurangistock(gudang, awal);
                    system("cls");
                    puts("Struk Hafiz Market");
                    tampilBarBel(awal, akhir);
                    curr = awal;
                    while (curr->nextBar != NULL)
                    {
                        curr = curr->nextBar;
                        deleteBarBel(&awal, akhir);
                    }
                    system("pause");
                    break;
                default:
                    break;
                }
            } while (opsi != 0);
            opsi = 99;
            break;
        case 2:
            do
            {
                system("cls");
                puts("Menu Gudang");
                puts("(1) Tambah Kategori");
                puts("(2) Tambah barang baru");
                puts("(3) Tambah stok barang");
                puts("(4) Tampilkan stok barang");
                puts("(5) Tampilkan etalase");
                puts("(0) Kembali");

                printf("Pilih opsi: ");
                scanf("%d", &opsi);

                switch (opsi)
                {
                case 1:
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
                            scanf(" %[^\n]s", &nama);
                            while (cekKategori(gudang.root, 1, nama))
                            {
                                system("cls");
                                puts("Tambah Kategori");
                                printf("%sKategori %s sudah terdaftar!%s\n", red, nama, normal);
                                printf("Nama kategori baru: ");
                                scanf(" %[^\n]s", &nama);
                            }
                            puts("masuk insert");
                            hasil = insertBarang(&gudang, gudang.root, nama, 0, 0);
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
                            printf("Kategori: ");
                            scanf(" %[^\n]s", &nama);
                            while (!cekKategori(gudang.root, 1, nama))
                            {
                                system("cls");
                                printf("%sKategori %s belum terdaftar!%s\n", red, nama, normal);
                                printf("Kategori: ");
                                scanf(" %[^\n]s", &nama);
                            }
                            hasil = searchGudang(gudang.root, nama);
                            printf("Nama Sub-kategori baru: ");
                            scanf(" %[^\n]s", &nama);

                            while (cekKategori(gudang.root, 2, nama))
                            {
                                system("cls");
                                printf("%sSub-kategori %s sudah terdaftar!%s\n", red, nama, normal);
                                printf("Nama Sub-kategori baru: ");
                                scanf(" %[^\n]s", &nama);
                            }
                            hasil = insertBarang(&gudang, hasil, nama, 0, 0);
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
                    opsi = 99;
                    break;

                case 2:
                    system("cls");
                    printf("Kategori: ");
                    scanf(" %[^\n]s", &nama);
                    while (!cekKategori(gudang.root, 1, nama))
                    {
                        system("cls");
                        printf("%sKategori %s belum terdaftar!%s\n", red, nama, normal);
                        printf("Kategori: ");
                        scanf(" %[^\n]s", &nama);
                    }
                    hasil = searchGudang(gudang.root, nama);
                    printf("Sub-kategori: ");
                    scanf(" %[^\n]s", &nama);

                    while (!cekKategori(gudang.root, 2, nama))
                    {
                        system("cls");
                        printf("%sSub-kategori %s belum terdaftar!%s\n", red, nama, normal);
                        printf("Sub-kategori: ");
                        scanf(" %[^\n]s", &nama);
                    }
                    hasil = searchGudang(gudang.root, nama);

                    printf("Nama barang baru: ");
                    scanf(" %[^\n]s", &nama);
                    while (cekKategori(gudang.root, 3, nama))
                    {
                        system("cls");
                        printf("%sBarang %ssudah terdaftar!%s\n", red, nama, normal);
                        printf("Nama barang baru: ");
                        scanf(" %[^\n]s", &nama);
                    }
                    printf("Harga barang: ");
                    scanf("%d", &harga);
                    hasil = insertBarang(&gudang, hasil, nama, harga, 0);

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
                    break;
                case 3:
                    system("cls");
                    printf("Tambah Stock\n");
                    printf("Masukan Nama Barang: ");
                    scanf(" %[^\n]s", &beli);
                    while (!cekKategori(gudang.root, 3, beli))
                    {
                        system("cls");
                        printf(" %sBarang %s belum terdaftar! %s\n", red, beli, normal);
                        printf("Masukan Nama Barang: ");
                        scanf(" %[^\n]s", &beli);
                    }
                    printf("Masukan Jumlah Barang: ");
                    scanf(" %d", &jumBar);
                    tambahstock(gudang.root, beli, jumBar);
                    system("cls");
                    printf(" %sBerhasil menambahkan stock %s sejumlah %d %s\n", green, beli, jumBar, normal);
                    system("pause");
                    break;
                case 4:
                    system("cls");
                    tampilkanGudang(gudang.root, 0);
                    system("pause");
                    break;
                case 5:
                    system("cls");
                    puts("List barang yang stock nya kosong");
                    Cek_Stock_Etalase(gudang.root, 3, 1);       // KARENA Insert ETALASE BELUM ADA CEK NYA DI GUDANG
                    system("pause");
                    break;
                case 0:
                    puts("Kembali ke menu sebelumnya...");
                    break;
                default:
                    printf("Inputkan salah satu opsi di atas!\n");
                    puts("===============================================================");
                    break;
                }
            } while (opsi != 0);
            opsi = 99;
            break;
        case 0:
            puts("Keluar ke program...");
            break;
        default:
            printf("Inputkan salah satu opsi di atas!\n");
            puts("===============================================================");
            break;
        }
    } while (opsi != 0);
}