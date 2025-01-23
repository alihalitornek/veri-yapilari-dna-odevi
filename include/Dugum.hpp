/**       
* @file Dugum.hpp
* @description Dairesel bağlı liste veri yapısını kullanarak kromozomlardan oluşan bir dna’da çeşitli manipülasyonlar gerçekleştirmek
* @course  1. öğretim A gurubu
* @assignment  1. ödev
* @date  03.11.2024
* @author  ali halit örnek halit.ornek@ogr.sakarya.edu.tr
*/
#ifndef DUGUM_HPP
#define DUGUM_HPP
#include <string>
using namespace std;

class Dugum {
public:
    Dugum(char veri);
    char veri;
    Dugum* onceki;
    Dugum* sonraki;
};

#endif
