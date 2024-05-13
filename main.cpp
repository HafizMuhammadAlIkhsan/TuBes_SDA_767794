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
    puts("Sub Kategori");
    tampilSubKategori(root.root, level, i);
}