
#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#include <windows.h>
#define maxin 100
using namespace std;
void datosJugadores (struct player jugadores [maxin],int numjug);
void mapaJugadores(struct player jugadores [maxin],int numjug, struct mapa escaleras[maxin],struct mapa resvaladeras[maxin], int tablero[maxin][maxin],int tamx,int tamy);
void jugarMapaJugadores(struct player jugadores [maxin],int numjug, struct mapa escaleras[maxin],struct mapa resvaladeras[maxin], int tablero[maxin][maxin],int tamx,int tamy);
void vistaTablero(int tablero[maxin][maxin],int tamx,int tamy);
struct player
{
    string nombre;
    int edad;
    char genero;
    int posicion;
    int codigo;
    string color;
    int dado1;
    int dado2;
    int contador;
    int posx,posy;
    int fichax,fichay;
    bool ganador= false;
};
struct mapa
{
    int posx,posy;
    int codigo;
};


int main()
{
    int numjug=0,opc=0,tamy=0,tamx=0;
    struct player jugadores[numjug];
    struct mapa escaleras[maxin];
    struct mapa resvaladeras[maxin];
    int tablero[maxin][maxin];
    srand(time(NULL));
    cout << "hola a este nuevo juego: " << endl;
    cout << "menu:" << endl;
    cout<<"1. jugar"<<endl;
    cout<<"2. salir"<<endl;
    cin>>opc;
    if(opc==1)
    {
        cout<<"cuantos jugadores van a jugar"<<endl;
        cin>>numjug;
        cout<<"tamano de columnas?"<<endl;
        cin>>tamx;
        cout<<"tamano de filas?"<<endl;
        cin>>tamy;
        // datosJugadores(jugadores,numjug);
        mapaJugadores(jugadores,numjug,escaleras,resvaladeras,tablero,tamx,tamy);
        jugarMapaJugadores(jugadores,numjug,escaleras,resvaladeras,tablero,tamx,tamy);


    }
}
void datosJugadores (struct player jugadores [maxin],int numjug)
{
    string color1= "rojo", color2="verde", color3 ="azul", color4="amarillo";
    int colores=4,ocpc=0;
    for(int i=0; i<numjug; i++)
    {
        cout<<"nombre"<<endl;
        cin>>jugadores[i].nombre;
        cout<<"edad"<<endl;
        cin>>jugadores[i].edad;
        cout<<"genero mujer M/ hombre  H"<<endl;
        cin>>jugadores[i].genero;
        jugadores[i].posicion = 0;
        jugadores[i].codigo = i+1;
        if(colores > 0)
        {
            cout<<"colores disponibles: "<<colores<<endl;
            cout<<"1."<<color1<<endl;
            cout<<"2."<<color2<<endl;
            cout<<"3."<<color3<<endl;
            cout<<"4."<<color4<<endl;
            cin>>ocpc;
            if(ocpc == 1)
            {
                jugadores[i].color = color1;
            }
            if(ocpc == 2)
            {
                jugadores[i].color = color2;
            }
            if(ocpc == 3)
            {
                jugadores[i].color = color3;
            }
            if(ocpc == 4)
            {
                jugadores[i].color = color4;
            }
        }
    }
}

void mapaJugadores(struct player jugadores [maxin],int numjug, struct mapa escaleras[maxin],struct mapa resvaladeras[maxin], int tablero[maxin][maxin],int tamx,int tamy)
{
    int casillasEscaleras=rand() % 10+1, casillasResvalas = rand() % 10+1;
    cout<<casillasEscaleras<<endl;
    int numx,numy;
  for(int x=0; x<tamx; x++)
    {
        for(int y=0; y<tamy; y++)
        {
            if(tablero[x][y] != tablero[tamx-1][0])
            {
                if(tablero[x][y] != tablero[0][0])
                {

                    tablero [x][y]=0;

                }

            }
        }
    }
    for(int i=0; i<casillasEscaleras; i++)
    {
        numx = rand() % tamx-1;
        numy = rand() % tamy-1;
        escaleras[i].codigo = 1;
        if(numx != tamx-1 && numy != 0)
        {
            escaleras[i].posx  = numx;
            escaleras[i].posy  = numy;
tablero[escaleras[i].posx][escaleras[i].posy] = escaleras[i].codigo;
        }

    }
    for(int i=0; i<casillasResvalas; i++)
    {
        numx = rand() % tamx;
        numy = rand() % tamy;
        resvaladeras[i].codigo = 2;
        if(numx != tamx-1 && numy != 0)
        {
            resvaladeras[i].posx  = numx;
            resvaladeras[i].posy  = numy;

                        tablero[resvaladeras[i].posx][resvaladeras[i].posy] = resvaladeras[i].codigo;

        }

    }


}
void vistaTablero(int tablero[maxin][maxin],int tamx,int tamy)
{
    for(int x=0; x<tamx; x++)
    {
        for(int y=0; y<tamy; y++)
        {
            cout<<tablero[x][y];
        }
        cout<<endl;
    }
}
void jugarMapaJugadores(struct player jugadores [maxin],int numjug, struct mapa escaleras[maxin],struct mapa resvaladeras[maxin], int tablero[maxin][maxin],int tamx,int tamy)
{
    vistaTablero(tablero,tamx,tamy);
}
