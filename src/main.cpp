/**       
* @file main.cpp
* @description Dairesel bağlı liste veri yapısını kullanarak kromozomlardan oluşan bir dna’da çeşitli manipülasyonlar gerçekleştirmek
* @course  1. öğretim A gurubu
* @assignment  1. ödev
* @date  03.11.2024
* @author  ali halit örnek halit.ornek@ogr.sakarya.edu.tr
*/
#include <iostream>
#include "Dna.hpp"

int main() {
    int secim, secim1, secim2;
    Dna dna;

    dna.dosyaOku("Dna.txt");

    do {
        cout << "\n--- MENU ---" << endl;
        cout << "1- Caprazlama" << endl;
        cout << "2- Mutasyon" << endl;
        cout << "3- Otomatik Islemler" << endl;
        cout << "4- Ekrana Yaz" << endl;
        cout << "5- Cikis" << endl;
        cout << "Seciminizi yapin: ";
        cin >> secim;

        switch (secim) {
		case 1: {
			cout << "Istediginiz ilk kromozomun indeksini girin: ";
			cin >> secim1;
			cout << "Istediginiz ikinci kromozomun indeksini girin: ";
			cin >> secim2;

			Daireselliste* k1 = dna.satirGetir(secim1);
			Daireselliste* k2 = dna.satirGetir(secim2);

			if (k1 && k2) {
				Daireselliste yeniKromozom1 = Daireselliste::caprazlaIlkKisim(*k1, *k2);
				Daireselliste yeniKromozom2 = Daireselliste::caprazlaIkinciKisim(*k2, *k1);

				//yeni kromozomları ekle
				dna.satirEkle(yeniKromozom1);
				dna.satirEkle(yeniKromozom2);

				cout << "Caprazlama Tamamlandi" << endl;
			}
			else {
				cout << "Gecersiz indeks. Kromozomlar bulunamadi" << endl;
			}
			break;
		}


		case 2:{
            Daireselliste* mutasyonKromozomu;
            cout << "Istediginiz satiri girin: ";
            cin >> secim1;
            cout << "Istediginiz sutunu girin: ";
            cin >> secim2;

            mutasyonKromozomu = dna.satirGetir(secim1);
            if (mutasyonKromozomu) {
                //girilen sutun indeksinin doğrulanması
                if (secim2 < 0 || secim2 >= mutasyonKromozomu->getDugumSayisi()) {
                    cout << "Sutun indeksi gecersiz. Lutfen gecerli bir indeks girin" << endl;
                } 
                else {
                    mutasyonKromozomu->mutasyon(*mutasyonKromozomu, secim2);  //mutasyon işlemini uygula
                    dna.kromozomGuncelle(secim1, *mutasyonKromozomu);         //güncellenmiş kromozomu kaydet
                    cout << "Mutasyona Ugramis Kromozom: ";
                    mutasyonKromozomu->listeyiYazdir();                      //kromozomu yazdır
                }
            } 
            else {
                cout << "Gecersiz indeks. Kromozom bulunamadi." << endl;
            }
            break;
                }

		case 3:
			dna.otomatikIslemler(dna);
			break;

		case 4:
			dna.ekranaYaz();
			break;

		case 5:
			cout << "Programdan cikiliyor" << endl;
			break;
		}
    } while (secim != 5);

    return 0;
}
