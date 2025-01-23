/**       
* @file Dugum.cpp
* @description Dairesel bağlı liste veri yapısını kullanarak kromozomlardan oluşan bir dna’da çeşitli manipülasyonlar gerçekleştirmek
* @course  1. öğretim A gurubu
* @assignment  1. ödev
* @date  03.11.2024
* @author  ali halit örnek halit.ornek@ogr.sakarya.edu.tr
*/
#include "Dugum.hpp"

Dugum::Dugum(char veri) {
    this->veri = veri;
    onceki = nullptr;
    sonraki = nullptr;
}
