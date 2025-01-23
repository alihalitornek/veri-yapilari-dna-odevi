/**       
* @file Dna.hpp
* @description Dairesel bağlı liste veri yapısını kullanarak kromozomlardan oluşan bir dna’da çeşitli manipülasyonlar gerçekleştirmek
* @course  1. öğretim A gurubu
* @assignment  1. ödev
* @date  03.11.2024
* @author  ali halit örnek halit.ornek@ogr.sakarya.edu.tr
*/
#ifndef DNA_HPP
#define DNA_HPP

#include "Daireselliste.hpp"
#include "SatirDugum.hpp"

class Dna {
public:
    Dna();
    ~Dna();
    void dosyaOku(const string& dosyaAdi);
    void satirEkle(Daireselliste& liste);
    Daireselliste* satirGetir(int sira);
    void kromozomGuncelle(int indeks, Daireselliste& yeniListe);
    void otomatikIslemler(Dna& dna);
    void ekranaYaz();

private:
    SatirDugum* ilkSatir;
    int satirSayisi;
};

#endif
