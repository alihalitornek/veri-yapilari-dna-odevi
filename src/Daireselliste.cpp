/**       
* @file Daireselliste.cpp
* @description Dairesel bağlı liste veri yapısını kullanarak kromozomlardan oluşan bir dna’da çeşitli manipülasyonlar gerçekleştirmek
* @course  1. öğretim A gurubu
* @assignment  1. ödev
* @date  03.11.2024
* @author  ali halit örnek halit.ornek@ogr.sakarya.edu.tr
*/
#include "Daireselliste.hpp"
#include <iostream>

Daireselliste::Daireselliste()
{
	ilk = 0;
	dugumSayisi = 0;
}

Daireselliste::~Daireselliste() {

}

void Daireselliste::temizle() {
	Dugum* gec = ilk;

	for (int i = 0;i < dugumSayisi;i++)
	{
		Dugum* silinecek = gec;
		gec = gec->sonraki;
		delete silinecek;
	}
}

Dugum* Daireselliste::getilk() const {
    return ilk;
}

void Daireselliste::ekle(char veri) {
    Dugum* yeni = new Dugum(veri);

    if (ilk == nullptr) {
        ilk = yeni;
        ilk->onceki = ilk;
        ilk->sonraki = ilk;
    } else {
        Dugum* gec = dugumGetir(dugumSayisi - 1);
        gec->sonraki = yeni;
        yeni->onceki = gec;
        yeni->sonraki = ilk;
        ilk->onceki = yeni;
    }
    dugumSayisi++;
}

Dugum* Daireselliste::dugumGetir(int sira) {
    if (sira < 0 || sira >= dugumSayisi)
        return nullptr;
    Dugum* gec = ilk;
    for (int i = 0; i < sira; i++) {
        gec = gec->sonraki;
    }
    return gec;
}

void Daireselliste::listeyiYazdir() {
    if (dugumSayisi == 0) {
        cout << "Liste bos" << endl;
        return;
    }

    Dugum* gec = ilk;
    for (int i = 0; i < dugumSayisi; i++) {
        cout << gec->veri << " ";
        gec = gec->sonraki;
    }
    cout << endl;
}
Daireselliste Daireselliste::caprazlaIlkKisim(Daireselliste& liste1, Daireselliste& liste2)
{
	Daireselliste yeniListe1;
	float ikincidugumsayisi = liste2.dugumSayisi;
	int orta1 = liste1.dugumSayisi / 2;
	int orta2 = ikincidugumsayisi / 2 + 0.5;

	//yeni kromozomu oluştur. liste1in sol yarısı + liste2nin sağ yarısı
	Dugum* gec1 = liste1.ilk;
	for (int i = 0; i < orta1; i++)  //liste1in sol yarısını ekle
	{
		yeniListe1.ekle(gec1->veri);
		gec1 = gec1->sonraki;
	}
	Dugum* gec2 = liste2.dugumGetir(orta2);
	for (int i = orta2; i < liste2.dugumSayisi; i++)  //liste2nin sağ yarısını ekle
	{
		yeniListe1.ekle(gec2->veri);
		gec2 = gec2->sonraki;
	}

	return yeniListe1;
}
Daireselliste Daireselliste::caprazlaIkinciKisim(Daireselliste& liste1, Daireselliste& liste2)
{
	Daireselliste yeniListe2;
	float birincidugumsayisi = liste1.dugumSayisi / 2;
	if (liste1.dugumSayisi % 2 == 1)
		birincidugumsayisi++;
	int orta1 = birincidugumsayisi;
	int orta2 = liste2.dugumSayisi / 2;
	Dugum* gec1 = liste2.dugumGetir(orta2);
	Dugum* gec2 = liste1.ilk;

	for (int i = 0; i < orta2; i++)
	{
		yeniListe2.ekle(gec1->veri);
		gec1 = gec1->sonraki;
	}
	for (int i = orta1; i < liste1.dugumSayisi; i++)
	{
		yeniListe2.ekle(gec2->veri);
		gec2 = gec2->sonraki;
	}


	return yeniListe2;
}
void Daireselliste::mutasyon(Daireselliste liste, int sira)
{
	Dugum* gec = liste.ilk;
	for (int i = 0;i < sira;i++)
	{
		gec = gec->sonraki;
	}
	gec->veri = 'X';
}
int Daireselliste::getDugumSayisi() const {
    return dugumSayisi;
}
