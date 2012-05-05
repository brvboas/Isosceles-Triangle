/* 
 * File:   Ponto.cpp
 * Author: Bruno Villas Boas, Wagner Takeshi, Guilherme A. Monteiro, Henriete
 * 
 * Created on 10 de Junho de 2010, 13:26
 */

#include "Ponto.h"
using namespace std;
Ponto::Ponto() {
    x=0;
    y=0;
}

Ponto::Ponto(int x, int y) {
    this->x=x;
    this->y=y;
}


int Ponto::getX(){
    return x;
}

void Ponto::setX(int x){
    this->x=x;
}

int Ponto::getY(){
    return y;
}

void Ponto::setY(int y){
    this->y=y;
}

void Ponto::show(){
    cout << "(" ;
    cout << x;
    cout << ",";
    cout << y;
    cout <<")";
}