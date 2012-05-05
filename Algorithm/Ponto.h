/* 
 * File:   Ponto.h
 * Author: Bruno Villas Boas, Wagner Takeshi, Guilherme A. Monteiro, Henriete
 *
 * Created on 10 de Junho de 2010, 13:26
 */

#ifndef _PONTO_H
#define	_PONTO_H
#include <iostream>
class Ponto {
public:
    Ponto();
    Ponto(int x, int y);

    int getX();
    void setX(int x);
    int getY();
    void setY(int y);
    void show();
private:
    int x;
    int y;
};

#endif	/* _PONTO_H */

