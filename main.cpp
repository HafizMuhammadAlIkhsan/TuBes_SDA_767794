#include "header.h"

int main()
{
    Gudang gudang, etalase;
    addrBar hasil, beliBar;
    addrBel awal = NULL, akhir = NULL, curr;
    int opsi, i = 1, returnValue, jumBar, harga;
    char lanjut, beli[100], nama[100];
    int pil = 0;

    createTree(&gudang);
    createTree(&etalase);

    /*Paling atas*/
    insertBarang(&gudang, NULL, "Gudang", 0, 0);
    insertBarang(&etalase, NULL, "Etalase", 0, 0);
    bacaFile(gudang, "DATA/gudang.txt");

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
                           
                       while(!cekKategori(gudang.root, beli))
                       {
                            printf("%s tidak ada\n", beli);
                            printf("Beli: ");
                            scanf(" %[^\n]s", &beli);
                            printf("Jumlah: ");
                            scanf("%d", &jumBar);
                       }
                        
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
                    system("cls");
                    puts("Struk Hafiz Market");
                    returnValue = tampilBarBel(awal, akhir);
                    system("pause");
                    system("cls");
                    puts("Pembayaran");
                    printf("Total harga          : Rp %d\n", returnValue);
                    printf("Masukkan jumlah uang : Rp ");
                    scanf(" %d", &harga);
                    printf("Kembalian            : Rp %d\n", harga-returnValue);
                    puts("Terima kasih sudah belanja!");
                    kurangistock(gudang, awal);
                    system("pause");
                    curr = awal;
                    while (curr->nextBar != NULL)
                    {
                        curr = curr->nextBar;
                        deleteBarBel(&awal, akhir);
                    }
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
                puts("(0) Kembali");

                printf("Pilih opsi: ");
                scanf("%d", &opsi);

                switch (opsi)
                {
                case 1:
                    tambahKategori(gudang);
                    break;
                case 2:
                    tambahBarangBaru(gudang);
                    break;
                case 3:
                    tambahStokBarang(gudang);
                    break;
                case 4:
                    tampilkanStokBarang(gudang);
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
    updateData(gudang.root);
}