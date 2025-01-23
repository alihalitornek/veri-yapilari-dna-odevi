/**       
* @file SatirDugum.hpp
* @description Dairesel bağlı liste veri yapısını kullanarak kromozomlardan oluşan bir dna’da çeşitli manipülasyonlar gerçekleştirmek
* @course  1. öğretim A gurubu
* @assignment  1. ödev
* @date  03.11.2024
* @author  ali halit örnek halit.ornek@ogr.sakarya.edu.tr
*/
#ifndef SATIR_DUGUM_HPP
#define SATIR_DUGUM_HPP

#include "Daireselliste.hpp"

class SatirDugum {
public:
    Daireselliste liste;
    SatirDugum* sonraki;

    SatirDugum();
};

#endif
