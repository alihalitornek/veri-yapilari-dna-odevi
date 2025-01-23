/**       
* @file Daireselliste.hpp
* @description Dairesel bağlı liste veri yapısını kullanarak kromozomlardan oluşan bir dna’da çeşitli manipülasyonlar gerçekleştirmek
* @course  1. öğretim A gurubu
* @assignment  1. ödev
* @date  03.11.2024
* @author  ali halit örnek halit.ornek@ogr.sakarya.edu.tr
*/
#ifndef DAISELLISTE_HPP
#define DAISELLISTE_HPP

#include "Dugum.hpp"

class Daireselliste {
public:
    Daireselliste();
    ~Daireselliste();
    void temizle();
    void ekle(char veri);
    Dugum* dugumGetir(int sira);
    void listeyiYazdir();
    static Daireselliste caprazlaIlkKisim(Daireselliste& liste1, Daireselliste& liste2);
    static Daireselliste caprazlaIkinciKisim(Daireselliste& liste1, Daireselliste& liste2);
    static void mutasyon(Daireselliste liste, int sira);
    Dugum* getilk() const;
    int getDugumSayisi() const;


private:
    Dugum* ilk;
    int dugumSayisi;
};

#endif
