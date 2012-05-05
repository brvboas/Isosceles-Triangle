/* 
 * File:   Programa.cpp
 * Author: Bruno Villas Boas, Wagner Takeshi, Guilherme A. Monteiro, Henriete
 * 
 * Created on 10 de Junho de 2010, 13:36
 */

#include "Programa.h"

using namespace std;

Programa::Programa() {
}

Programa::Programa(const Programa& orig) {
}

Programa::~Programa() {
}

void Programa::run() {
    lerArquivo();
}

/* calculaDistancia: calcula a distancia entre dois pontos localizados
 * no plano XY.
 */
double Programa::calculaDistancia(Ponto p1, Ponto p2) {
    double x = (p1.getX()-p2.getX());
    double y = (p1.getY()-p2.getY());
    double n = pow(x,2)+pow(y,2);// (double) (((p1.getX() - p2.getX())^2)+((p1.getY() - p2.getY())^2));
    return  sqrt(n);
}

/* calculaIsoceles: calcula se tres pontos sao isosceles. Se sim, retorna 1,
 * caso contrario retorna 0.
 */
int Programa::calculaIsosceles(Ponto p1, Ponto p2, Ponto p3) {
    double d1 = 0, d2 = 0, d3 = 0;
    d1 = calculaDistancia(p1, p2);
    d2 = calculaDistancia(p1, p3);
    d3 = calculaDistancia(p2, p3);
    if ((d1 == d2 && d1 != d3) || (d1 == d3 && d1 != d2) || (d2 == d3 && d2 != d1)) {
        return 1;
    }
//    cout << "p1: ";
//    p1.show();
//    cout << "| p2: ";
//    p2.show();
//    cout << "| p3: ";
//    p3.show();
//    cout << endl;
//    cout << "--------------------------------" << endl;
    return 0;
}

/*quantidadeIsosceles: recebe a quantidade de pontos e os pontos em um vetor
 * e, se existirem 3 pontos, apenas verifica se eles formam triangulo isosceles.
 * Se formarem retorna 1 para a saida, caso contrario retorna zero.
 * Caso exista mais de tres pontos, o programa calcula a quantidade de isosceles
 * que se pode formar com um ponto do vetor (variando entre os outros) e chama,
 * recursivamente, a si mesma passando omo parametro um vetor sem o ponto ja
 * calculado e um novo tamanho (tam-1).
 * Ao chegar ao seu retorno, o programa retornará a quantidade de isosceles formados
 * com os pontos dados.
 */
int Programa::quantidadeIsosceles(Ponto p1, Ponto *p, int tam) {
    //se tam = 2, significa que existem apenas 3 pontos, ou seja, um triangulo.
    if (tam == 2) {
        return calculaIsosceles(p1, p[0], p[1]);
    }

    int qtdIsosceles = 0;
    //calcula a quantidade de triangulos isosceles, levando em conta que
    //p1 e p[0] fazem parte deste triangulo.
    int vezes = tam;
    for (int i = 0; i < (tam); i++) {
        for (int j=1;j<vezes;j++){
            qtdIsosceles += calculaIsosceles(p1, p[i], p[i+j]);
        }
        vezes--;
    }
    Ponto *p2 = new Ponto[tam - 1];
    for (int i = 0; i < tam - 1; i++) {
        p2[i] = p[i + 1];
    }
    qtdIsosceles += quantidadeIsosceles(p[0],p2, tam - 1);
    return qtdIsosceles;
}

/*lerArquivo: le o arquivo de entrada, chama a funcao quantidadeIsosceles e salva
 * seu resultado em um arquivo de saída. 
 */
void Programa::lerArquivo() {
    //acessa os arquivos de entrada e saida
    stringstream localEntrada;
    localEntrada << "H:/TrianguloIsosceles/dist/Debug/MinGW-Windows";
    localEntrada << "/entrada1.txt";
    string arquivo = localEntrada.str();
    ifstream fin(arquivo.c_str());
    stringstream localSaida;
    localSaida << "H:/TrianguloIsosceles/dist/Debug/MinGW-Windows";
    localSaida << "/saida.txt";
    arquivo = localSaida.str();
    ofstream fout(arquivo.c_str());
    if (fin.fail() || fout.fail()) { // se nao abrir fecha prog
        cout << "Nao abriu o arquivo de disco, o programa foi fechado." << endl;
        exit(0);
    }

    int tamanho = 0, x = 0, y = 0, saida = 0;
    Ponto *p; //cria um ponteiro de pontos.
    Ponto p1;
    while (!fin.eof()) {
        fin >> tamanho;
        cout << "tamanho: " << tamanho << endl;
        if (tamanho != 0) {
            p = new Ponto[tamanho - 1];
            //popula o novo 'ponto' criado.
            for (int i = 0; i < tamanho; i++) {
                if (i == 0) {
                    fin.ignore(255, '\n');
                    fin >> x;
                    p1.setX(x);
                    fin.ignore(255, ' ');
                    fin >> y;
                    p1.setY(y);
                } else {
                    fin.ignore(255, '\n');
                    fin >> x;
                    p[i - 1].setX(x);
                    fin.ignore(255, ' ');
                    fin >> y;
                    p[i - 1].setY(y);
                }
            }
            //chama a funcao que retorna a quantidade de triangulos isosceles.
            saida = quantidadeIsosceles(p1, p, tamanho - 1);
            fout << saida;
            fout.put('\n');
        } else break;

    }
    //fecha os arquivos
    fout.close();
    fin.close();


}
