/* 
 * File:   Programa.h
 * Author: Bruno Villas Boas, Wagner Takeshi, Guilherme A. Monteiro, Henriete
 *
 * Created on 10 de Junho de 2010, 13:36
 */

#ifndef _PROGRAMA_H
#define	_PROGRAMA_H
#include <sstream>
#include <string>
#include <iostream>
#include <fstream.h>
#include "Ponto.h"
#include <math.h>
class Programa {
public:
    Programa();
    Programa(const Programa& orig);
    virtual ~Programa();
    void run();
private:
    int calculaIsosceles(Ponto p1, Ponto p2, Ponto p3);
    void lerArquivo();
    double calculaDistancia(Ponto p1, Ponto p2);
    int Programa::quantidadeIsosceles(Ponto p1, Ponto *p, int tam);
};

#endif	/* _PROGRAMA_H */

