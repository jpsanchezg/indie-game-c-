//hecho por juan pablo sanchez
#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#include <windows.h>
#define maxin 100
using namespace std;

void mapaJugadores(struct player jugadores [maxin],int numjug, struct mapa posiciontablero[maxin],int tam, struct tablero tab,int TP,int numeros[maxin][maxin], struct posi trampas[maxin]);
void jugarMapaJugadores(struct player jugadores [maxin],int numjug, struct mapa  posiciontablero[maxin],int tam, struct tablero tab,int TP,int numeros[maxin][maxin], struct posi trampas[maxin]);
void vistaTablero(struct player jugadores [maxin],int numjug, struct mapa posiciontablero[maxin],int tam, struct tablero tab,int TP,int numeros[maxin][maxin], struct posi trampas[maxin]);
void buscarposi(struct tablero tab,struct player jugadores [maxin],int tam,int numeros[maxin][maxin]);
struct player
{
    string nombre ;
    char genero;
    int edad;

    int posjug;
    string color;

    char codigo;


};
struct mapa
{
    int posinicial;
    string codigo;
    int posfinal;
    char pInicial;
};
struct jugadores
{
    string codigo;
    int dado;

};
struct tablero
{
    char inic[];
    int posx[],posy[];
    char jug1;
    char jug2;
    char jug3;
    char jug4;
};
struct posi
{
    char esca;
    char rodadero;
    int posiniesca, posfiniesca;
    int posiniresba,posfiniresba;
};


int main()
{

    int numjug=4,opc=0,tam=8,TP=17,TL=21;
    struct player jugadores[numjug] = { {"Hugo",'M',8,0,"Blanco"},{"Daisy",'F',7,0,"Rojo"},{"Paco",'M',8,0,"Verde"},{"Minie",'F',6,0,"Azul"} };
    struct mapa posiciontablero[TP]= { {4,"Escalera",20}, {5,"Escalera",10}, {7,"Escalera",23}, {22,"Escalera",39}, {18,"Escalera",35}, {5,"Escalera",10}, {27,"Escalera",37}, {41,"Escalera",58}, {42,"Escalera",53}, {49,"Escalera",62}, {34,"Rodadero",2}, {38,"Rodadero",3}, {43,"Rodadero",23}, {46,"Rodadero",33}, {57,"Rodadero",44}, {43,"Rodadero",23}, {59,"Rodadero",46} };
    string tablero[maxin][maxin];
    struct tablero tab ;
    struct posi trampas [TP];
    int numeros[maxin][maxin];
    srand(time(NULL));
    cout << "hola a este nuevo juego: " << endl;
    cout << "menu:" << endl;
    cout<<"1. jugar"<<endl;
    cout<<"2. salir"<<endl;
    cin>>opc;
    if(opc==1)
    {
        mapaJugadores(jugadores, numjug, posiciontablero, tam,tab, TP,numeros,trampas);

        //jugarMapaJugadores(jugadores,numjug,posiciontablero,tam,tab,TP,numeros,trampas);
    }
}
void mapaJugadores(struct player jugadores [maxin],int numjug, struct mapa posiciontablero[maxin],int tam, struct tablero tab,int TP,int numeros[maxin][maxin], struct posi trampas[maxin])
{
    cout<<"helo"<<endl;
    for(int i=0; i<4; i++)
    {
        if(jugadores[i].color == "Rojo")
        {
            jugadores[i].codigo = 'R';
        }
        if(jugadores[i].color == "Blanco")
        {
            jugadores[i].codigo = 'B';
        }
        if(jugadores[i].color == "Azul")
        {
            jugadores[i].codigo = 'A';
        }
        if(jugadores[i].color == "Verde")
        {
            jugadores[i].codigo = 'V';
        }
    }
    cout<<"heo"<<endl;
    for(int i=0; i<TP; i++)
    {
        if(posiciontablero[i].codigo == "Escalera")
        {
            posiciontablero[i].pInicial ='E';
        }
        if(posiciontablero[i].codigo == "Rodadero")
        {
            posiciontablero[i].pInicial ='R';
        }
    }
    int contador = 1;
    for (int i = 0; i < tam; i++)
    {

        if (i%2 == 0)   // Ascendente en pares
        {
            for (int j = 0; j < tam; j++)
            {
                numeros[i][j] = contador;
                contador ++;
            }

        }
        else     // Descendente en impares
        {
            for (int j = tam-1; j >= 0; j--)
            {
                numeros[i][j] = contador;
                contador ++;
            }
        }
    }
    for(int i=0; i<17; i++)
    {
        if(posiciontablero[i].codigo == "Escalera")
        {
            for(int x=0; x<tam; x++)
            {
                for(int j=0; j<tam; j++)
                {
                    if(posiciontablero[i].posinicial == numeros[x][j])
                    {
                        tab.inic[i]=posiciontablero[i].pInicial;
                        tab.posx[i]=x;
                        tab.posy[i]=j;
                    }

                }
            }
        }
        if(posiciontablero[i].codigo == "Rodadero")
        {
            for(int x=0; x<tam; x++)
            {
                for(int j=0; j<tam; j++)
                {

                    if(posiciontablero[i].posinicial == numeros[x][j])
                    {
                        tab.inic[i]=posiciontablero[i].pInicial;
                        tab.posx[i]=x;
                        tab.posy[i]=j;
                    }
                }
            }
        }
    }**/
    vistaTablero(jugadores, numjug, posiciontablero, tam,tab, TP,numeros,trampas);
}


void vistaTablero(struct player jugadores [maxin],int numjug, struct mapa posiciontablero[maxin],int tam, struct tablero tab,int TP,int numeros[maxin][maxin], struct posi trampas[maxin])
{

    for(int x=0; x<tam; x++)
    {

        for(int y=0; y<tam; y++)
        {
            cout<<"|"<<numeros[x][y];
            for(int i=0; i<TP; i++)
            {
                if(x == tab.posx[i] && y == tab.posy[i])
                {
                    cout<<"  "<<tab.inic[i];
                }
            }
        }
        cout<<"_";
        cout<<endl;
    }
    cout<<endl;

}
void jugarMapaJugadores(struct player jugadores [maxin],int numjug, struct mapa  posiciontablero[maxin],int tam,struct tablero tab,int TP,int numeros[maxin][maxin], struct posi trampas[maxin])
{
    string opci;
    int dado1=0,xsalido=0,ysalido=0,posfast=0;
    bool ganador= false;
    do
    {
        vistaTablero(jugadores, numjug, posiciontablero, tam,tab, TP,numeros,trampas);
        for(int i=0; i<numjug; i++)
        {
            //  system("cls");

            cout<<"El jugador con la ficha: "<<jugadores[i].color<<" juega"<<endl;
            cout<<"Tirar dado? si/no"<<endl;
            cin>>opci;
            if(opci == "si")
            {
                dado1 = rand() % 6+1;

                cout<<"vas a moverte "<<dado1<<" posiciones"<<endl;

                jugadores[i].posjug = jugadores[i].posjug + dado1;
                cout<<jugadores[i].posjug<<endl;

                buscarposi(tab,jugadores,tam,numeros);
            }

        }
    }
    while(ganador == false );
}
void buscarposi( struct tablero tab,struct player jugadores [maxin],int tam,int numeros[maxin][maxin])
{
    for(int i = 0; i < tam; i++ )
    {
        for(int j = 0; j < tam; j++)
        {

            cout<<numeros[i][j];
            if(jugadores[i].posjug == numeros[i][j])
            {

            }

        }
        cout<<endl;
    }
    for(int i = 0; i < tam; i++ )
    {
        for(int j = 0; j < tam; j++)
        {
            if(jugadores[i].posjug == numeros[i][j])
            {

            }

        }
    }
}


