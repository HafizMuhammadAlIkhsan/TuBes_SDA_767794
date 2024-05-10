#include "header.h"

void createTree(rootToko *x)
{
    (*x).root = NULL;
}

void tampilSubKategori (addrBar nama)
{

}

void beliBarang (addrPem pembeli, addrBel barang)
{

}

addrBar searchGudang (addrBar root, infotype cariGudang)
{
    addrBar p = root;
    bool resmi = true;
    if (nama(p) == cariGudang)
    {
        return p;
    }
    do
    {
        if (fs(p) != NULL && resmi)
        {
            p = fs(p);
            if (nama(p) == cariGudang)
            {
                return p;
            }
        }
        else if (nb(p) != NULL)
        {
            p = nb(p);
            if (nama(p) == cariGudang)
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