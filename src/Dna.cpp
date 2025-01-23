/**       
* @file Dna.cpp
* @description Dairesel bağlı liste veri yapısını kullanarak kromozomlardan oluşan bir dna’da çeşitli manipülasyonlar gerçekleştirmek
* @course  1. öğretim A gurubu
* @assignment  1. ödev
* @date  03.11.2024
* @author  ali halit örnek halit.ornek@ogr.sakarya.edu.tr
*/
#include "Dna.hpp"
#include <iostream>
#include <fstream>
#include <sstream>



Dna::Dna() {
		ilkSatir = nullptr;
		satirSayisi = 0;
}

Dna::~Dna() {
    SatirDugum* gec = ilkSatir;
    while (gec) {
        gec->liste.temizle();  //listeyi temizle
        SatirDugum* silinecek = gec;
        gec = gec->sonraki;
        delete silinecek;
    }
}


void Dna::dosyaOku(const string& dosyaAdi) {
    ifstream dosya(dosyaAdi);
    if (!dosya.is_open()) {
        cout << "Dosya acilamadi" << endl;
        return;
    }

    string satir;
    while (getline(dosya, satir)) {
        Daireselliste yeniListe;
        istringstream iss(satir);
        char veri;
        while (iss >> veri) {
            yeniListe.ekle(veri);
        }
        satirEkle(yeniListe);
    }

    dosya.close();
}
void Dna::satirEkle(Daireselliste& liste) {
	SatirDugum* yeniDugum = new SatirDugum();
	yeniDugum->liste = liste;

	if (!ilkSatir) {
		ilkSatir = yeniDugum;
	}
	else {
		SatirDugum* gec = ilkSatir;
		while (gec->sonraki) {
			gec = gec->sonraki;
		}
		gec->sonraki = yeniDugum;
	}
	satirSayisi++;
}
Daireselliste* Dna::satirGetir(int sira) {
	if (sira < 0 || sira >= satirSayisi) return nullptr;

	SatirDugum* gec = ilkSatir;
	for (int i = 0; i < sira; i++) {
		gec = gec->sonraki;
	}
	return &gec->liste;
}
void Dna::kromozomGuncelle(int indeks, Daireselliste& yeniListe) {
	if (indeks < 0 || indeks >= satirSayisi) {
		cout << "Gecersiz indeks. Guncelleme basarisiz" << endl;
		return;
	}

	SatirDugum* gec = ilkSatir;
	for (int i = 0; i < indeks; i++) {
		gec = gec->sonraki;
	}
	gec->liste = yeniListe;  //kromozomu güncelle
}
void Dna::otomatikIslemler(Dna& dna)
{
	ifstream islemDosyasi("Islemler.txt");
	if (!islemDosyasi.is_open()) {
		cout << "Dosya acilamadi" << endl;
		return;
	}

	string komut;
	int secim1, secim2, dnasatirsayisi = 0;
	string islemsatir, dnasatir;
	Daireselliste kromozom1, kromozom2;

	while (getline(islemDosyasi, islemsatir))
	{
		istringstream iss(islemsatir);
		iss >> komut >> secim1 >> secim2;
		if (komut == "C")
		{
			Daireselliste* k1 = dna.satirGetir(secim1);
			Daireselliste* k2 = dna.satirGetir(secim2);

			if (k1 && k2) {
				Daireselliste yeniKromozom1 = Daireselliste::caprazlaIlkKisim(*k1, *k2);
				Daireselliste yeniKromozom2 = Daireselliste::caprazlaIkinciKisim(*k2, *k1);

				//yeni kromozomları ekle
				dna.satirEkle(yeniKromozom1);
				dna.satirEkle(yeniKromozom2);
			}
		}
		if (komut == "M")
		{
			Daireselliste* mutasyonKromozomu;
			mutasyonKromozomu = dna.satirGetir(secim1);
			if (mutasyonKromozomu) {
				mutasyonKromozomu->mutasyon(*mutasyonKromozomu,secim2);  //mutasyon işlemini uygula
				dna.kromozomGuncelle(secim1, *mutasyonKromozomu);  //güncellenmiş kromozomu kaydet
			}
		}

	}
	islemDosyasi.close();
    cout<<"Islemler tamamlandi";
}
void Dna::ekranaYaz()
{
    if (ilkSatir ==  nullptr)
    {
	    cout<<"Dna bos durumda";
	    return;
    }

	SatirDugum* gecsatir = ilkSatir;
	Daireselliste kromozom = gecsatir->liste;
	Dugum* gec = kromozom.getilk();
	cout << gec->veri;

	while (gecsatir->sonraki != 0)
	{
		gecsatir = gecsatir->sonraki;
		kromozom = gecsatir->liste;
		gec = kromozom.getilk();
		if (kromozom.getilk()->veri != 'A')
		{
			do {
				gec = gec->onceki;
				if (gec->veri == 'A') break;
			} while (gec->veri > kromozom.getilk()->veri || gec->veri == kromozom.getilk()->veri && gec != kromozom.getilk());
		}
		cout << gec->veri;
	}

}