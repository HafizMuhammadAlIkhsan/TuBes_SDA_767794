#include "header.h"

int main()
{
    Gudang gudang, etalase;
    addrBar hasil, beliBar;
    bool kasir;
    int opsi, i, returnValue, jumBar, harga;
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
        printf("%s", cyan);
        puts("======================================================================================================");                                                                                                
        puts("  _     _   _____   ______  _______  _______      __   __    _____   _____   _    _  ______  _______  ");
        puts(" (_)   (_) (_____) (______)(_______)(_______)    (__)_(__)  (_____) (_____) (_)  (_)(______)(__ _ __) ");
        puts(" (_)___(_)(_)___(_)(_)__      (_)       _(_)    (_) (_) (_)(_)___(_)(_)__(_)(_)_(_) (_)__      (_)    ");
        puts(" (_______)(_______)(____)     (_)     _(_)      (_) (_) (_)(_______)(_____) (____)  (____)     (_)    ");
        puts(" (_)   (_)(_)   (_)(_)      __(_)__  (_)____    (_)     (_)(_)   (_)( ) ( ) (_) (_) (_)____    (_)    ");
        puts(" (_)   (_)(_)   (_)(_)     (_______)(_______)   (_)     (_)(_)   (_)(_)  (_)(_)  (_)(______)   (_)    ");                                                                                                                                                                                        
        puts("                                                                                                      ");
        puts("======================================================================================================");
        printf("%s", normal);

        puts("(1) Menu Kasir");
        puts("(2) Menu Gudang");
        puts("(0) Keluar program");

        printf("Inputan berupa angka!\n");
        printf("Pilih opsi: ");
        scanf("%d", &opsi);
        switch (opsi)
        {
        case 1:
            do
            {
                system("cls");

                printf("%s", cyan);
                puts("============================================");                                            
                puts("  _    _   _____    _____  _______  _____   ");
                puts(" (_)  (_) (_____)  (_____)(_______)(_____)  ");
                puts(" (_)_(_) (_)___(_)(_)___     (_)   (_)__(_) ");
                puts(" (____)  (_______)  (___)_   (_)   (_____)  ");
                puts(" (_) (_) (_)   (_)  ____(_)__(_)__ ( ) ( )  ");
                puts(" (_)  (_)(_)   (_) (_____)(_______)(_)  (_) ");
                puts("                                            ");
                puts("============================================"); 
                printf("%s", normal); 

                puts("Menu Kasir");
                puts("1. Lihat Kategori");
                puts("2. Lihat Sub Kategori");
                puts("3. Lihat Barang");
                puts("4. Belanja");
                puts("0. Pergi");

                printf("Inputan berupa angka!\n");
                printf("Pilih opsi: ");
                scanf("%d", &opsi);
                puts("");
                switch (opsi)
                {
                case 1:
                    lihatKategori(gudang);
                    break;
                case 2:
                    lihatSubKategori(gudang);
                    break;
                case 3:
                    lihatBarang(gudang);
                    break;
                case 4:
                    do
                    {
                        kasir = belanja(gudang);
                    } while (kasir == false);
                    break;
                default:
                    printf("Inputkan salah satu opsi di atas!\n");
                    puts("===============================================================");
                    break;
                }
            } while (opsi != 0);
            opsi = 99;
            break;
        case 2:
            do
            {
                system("cls");
                printf("%s", cyan);
                puts("=======================================================");                           
                puts("   _____   _     _  _____    _____   _     _   _____   ");
                puts("  (_____) (_)   (_)(_____)  (_____) (_)   (_) (_____)  ");
                puts(" (_)  ___ (_)   (_)(_)  (_)(_)___(_)(__)_ (_)(_)  ___  ");
                puts(" (_) (___)(_)   (_)(_)  (_)(_______)(_)(_)(_)(_) (___) ");
                puts(" (_)___(_)(_)___(_)(_)__(_)(_)   (_)(_)  (__)(_)___(_) ");
                puts("  (_____)  (_____) (_____) (_)   (_)(_)   (_) (_____)  ");
                puts("                                                       ");
                puts("=======================================================");  
                printf("%s", normal);                               
                                                     
                puts("(1) Tambah Kategori");
                puts("(2) Tambah barang baru");
                puts("(3) Tambah stok barang");
                puts("(4) Tampilkan stok barang");
                puts("(0) Kembali");

                printf("Inputan berupa angka!\n");
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