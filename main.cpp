#include "header.h"

int main()
{
    gudang root;
    addrBar hasil, beliBar, temp;
    addrBel awal = NULL, akhir = NULL;
    char* nama;
    int opsi, opsi2, opsi3, opsi4, level = 2, i = 1, nilai, posisi, returnValue, jumBar;
    char lanjut, beli[100], barang[100];

    puts("masuk");
    createTree(&root);
    /*Paling atas*/
    insertBarang(&root, NULL, "King Jonats", 0);
    puts("masuk tampil");
    hasil = searchGudang(root.root, "King Jonats");
    puts("selesai cari root");

    /*Kategori*/
    insertBarang(&root, hasil, "Makanan", 0); 
    insertBarang(&root, hasil, "Minuman", 0);
    insertBarang(&root, hasil, "Kosmetik", 0);
    puts("cari makanan");

    /*Sub Kategori*/
    hasil = searchGudang(root.root, "Makanan");
    puts("selesai cari makanan");
    insertBarang(&root, hasil, "Snack", 0);
    insertBarang(&root, hasil, "Makanan beku", 0);

    /*Barang*/
    hasil = searchGudang(root.root, "Snack");
    insertBarang(&root, hasil, "Chitato", 11000);
    insertBarang(&root, hasil, "Taro", 8000);
    insertBarang(&root, hasil, "Lays", 11000);
    insertBarang(&root, hasil, "Pota Bee", 10000);

    /*barang*/
    hasil = searchGudang(root.root, "Makanan Beku");
    insertBarang(&root, hasil, "So Good", 21000);
    insertBarang(&root, hasil, "Fiesta", 19000);
    puts("cari minuman");

    /*Sub kategori*/
    hasil = searchGudang(root.root, "Minuman");
    puts("selesai cari minuman");
    insertBarang(&root, hasil, "Minuman bersoda", 0);
    insertBarang(&root, hasil, "Minuman berakohol", 0);

    /*Barang*/
    hasil = searchGudang(root.root, "Minuman bersoda");
    insertBarang(&root, hasil, "Coca Cola", 7000);
    insertBarang(&root, hasil, "Sprite", 7000);
    insertBarang(&root, hasil, "Fanta", 7000);
    insertBarang(&root, hasil, "Pepsi", 8000);

    /*Barang*/
    hasil = searchGudang(root.root, "Minuman berakohol");
    insertBarang(&root, hasil, "HAARAAMM", 1000000000);
    puts("cari kosmetik");

    /*Sub Kategori*/
    hasil = searchGudang(root.root, "Kosmetik");
    puts("selesai cari minuman");
    insertBarang(&root, hasil, "Sabun Cuci Muka", 0);
    insertBarang(&root, hasil, "Pemutih", 0);
    
    /*Barang*/
    hasil = searchGudang(root.root, "Sabun Cuci Muka");
    insertBarang(&root, hasil, "Mens Biore", 21000);
    insertBarang(&root, hasil, "Garnier Men", 19000);
    system("cls");
    // puts("Sub Kategori");
    // tampilSubKategori(root.root, level, i);
    // puts("");
    // tampilkanGudang(root.root, 0);

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
                system("cls");
                puts("Menu Kasir");
                puts("1. Lihat Kategori");
                puts("2. Lihat Sub Kategori");
                puts("3. Lihat Barang");
                puts("4. Belanja");
                puts("0. Pergi");

                printf("Pilih opsi: ");
                scanf("%d", &opsi2);
                puts("");
                switch (opsi2)
                {
                case 1:
                    puts("List kategori");
                    tampilSubKategori(root.root, 1, 1);
                    system("pause");
                    break;
                case 2:
                    puts("List Sub Kategori");
                    tampilSubKategori(root.root, 2, 1);
                    system("pause");
                    break;
                case 3:
                    puts("List Barang");
                    tampilSubKategori(root.root, 3, 1);
                    system("pause");
                    break;
                case 4:
                    do
                    {
                        printf("Beli: ");
                        scanf("%s", &beli);
                        printf("Jumlah: ");
                        scanf("%d", &jumBar);
                        
                        beliBar = searchGudang(root.root, beli);
                        if (beliBar != NULL)
                        {
                            insertBarBel(root, beli, &awal, &akhir, jumBar);
                            kurangistock(root, beli, &awal, jumBar);
                        }
                        else
                        {
                            puts("Barang tidak ada");
                            break;
                        }
                        printf("Ingin beli barang lain? (y/n): ");
                        scanf(" %c", &lanjut);

                    } while (lanjut == 'y' || lanjut == 'Y');
                    tampilBarBel(awal, akhir);
                    system("pause");
                    break;
                default:
                    break;
                }
            } while (opsi2 != 0);
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
                scanf("%d", &opsi3);

                switch (opsi3)
                {
                case 1:
                    do
                    {
                        system("cls");
                        puts("(1) Tambah Kategori");
                        puts("(2) Tambah Sub Kategori");
                        puts("(0) Kembali");
                        
                        printf("Pilih opsi: ");
                        scanf("%d", &opsi4);
                        switch (opsi4)
                        {
                        case 1:
                            printf("Nama kategori baru: ");
                            scanf(" %s", &nama);
                            break;
                        case 2:
                            /* code */
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
                    } while (opsi4 != 0);
                    break;

                case 2:

                    break;

                case 3:
                    printf("Tambah Stock\n");
                    printf("Masukan Nama Barang = ");
                    scanf("%s", &beli);
                    printf("Masukan Jumlah Barang = ");
                    scanf("%d", &jumBar);
                    puts("Masukan input");
                    tambahstock(root.root, beli, jumBar);
                    break;
                case 4:
                    tampilkanGudang(root.root, 0);
                    system("pause");
                    break;
                case 0:
                    puts("Kembali ke menu sebelumnya...");
                    system("pause");
                    break;
                default:
                    printf("Inputkan salah satu opsi di atas!\n");
                    puts("===============================================================");
                    break;
                }
            } while (opsi3 != 0);
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