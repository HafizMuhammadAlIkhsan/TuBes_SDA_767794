#include "header.h"

int main()
{
    gudang root;
    addrBar hasil;
    int opsi, level = 2, i = 1;
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
    insertBarang(&root, hasil, "Snack", 0);
    insertBarang(&root, hasil, "Makanan beku", 0);
    hasil = searchGudang(root.root, "Snack");
    insertBarang(&root, hasil, "Chitato", 11000);
    insertBarang(&root, hasil, "Taro", 8000);
    insertBarang(&root, hasil, "Lays", 11000);
    insertBarang(&root, hasil, "Pota Bee", 10000);
    hasil = searchGudang(root.root, "Makanan Beku");
    insertBarang(&root, hasil, "So Good", 21000);
    insertBarang(&root, hasil, "Fiesta", 19000);
    puts("cari minuman");
    hasil = searchGudang(root.root, "Minuman");
    puts("selesai cari minuman");
    insertBarang(&root, hasil, "Minuman bersoda", 0);
    insertBarang(&root, hasil, "Minuman berakohol", 0);
    hasil = searchGudang(root.root, "Minuman bersoda");
    insertBarang(&root, hasil, "Coca Cola", 7000);
    insertBarang(&root, hasil, "Sprite", 7000);
    insertBarang(&root, hasil, "Fanta", 7000);
    insertBarang(&root, hasil, "Pepsi", 8000);
    hasil = searchGudang(root.root, "Minuman berakohol");
    insertBarang(&root, hasil, "HAARAAMM", 1000000000);
    puts("cari kosmetik");
    hasil = searchGudang(root.root, "Kosmetik");
    puts("selesai cari minuman");
    insertBarang(&root, hasil, "Sabun Cuci Muka", 0);
    insertBarang(&root, hasil, "Pemutih", 0);
    hasil = searchGudang(root.root, "Sabun Cuci Muka");
    insertBarang(&root, hasil, "Mens Biore", 21000);
    insertBarang(&root, hasil, "Garnier Men", 19000);
    system("cls");
    puts("Sub Kategori");
    tampilSubKategori(root.root, level, i);
    puts("");
    tampilkanGudang(root.root, 0);

    int nilai, posisi, opsi, returnValue;
    char* nama;
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
            /* Menu Kasir */
            break;
        case 2:
            do
            {
                system("cls");
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
                            break;
                        }
                    } while (opsi != 0);
                    opsi = 99;
                    break;

                case 2:

                    break;

                case 3:

                    break;
                case 4:
                    puts("Sub Kategori");
                    tampilSubKategori(root.root, level, i);
                    tampilkanGudang(root.root, 0);
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