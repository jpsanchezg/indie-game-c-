//hecho por juan pablo sanchez
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include <windows.h>
#define maxin 100
using namespace std;
void datosJugadores (struct player jugadores [maxin],int numjug);
void presentarJugadores (struct player jugadores [maxin],int numjug);
void PosicionJugadores (struct player jugadores [maxin],int numjug);
void presentarJugadoresClasificados (struct player jugadores [maxin],int numjug);

void mapaJugadores(struct player jugadores [maxin],int numjug,struct maps tablero[][maxin],int tam,struct posi poss[maxin],struct mapa posiciontablero[maxin],int TP);
void jugarMapaJugadores(struct player jugadores [maxin],int numjug,struct maps tablero[maxin][maxin],int tam,struct posi poss[maxin], struct jugador jugadas[maxin],int n);
void vistaTablero( struct maps tablero[][maxin],int tam);
void buscarposi(int numeros[maxin][maxin],struct player jugadores [maxin],int tamx, int tamy,struct posi poss[maxin]);
struct player
{
    string nombre;
    char genero;
    int edad;
    int posjug;
    string color;


    int posx;
    int posy;
    char codigo;
    bool ganador= false;
};
struct mapa
{
    int posini;
    string codigo;
    int posfinal;
};
struct posi
{
    char codigo;
    int numero,x,y;

};
struct maps
{
    int numero;
    char codigo;
    int posfinal;
    int xfinal;
    int yfinal;
    char jug1;
    char jug2;
    char jug3;
    char jug4;
};
struct jugador
{
    string color;
    int dado;
};

int main()
{

    int numjug=4,opc=0,tam=8,modo=0,TP = 17,TL=21,n=0;
    struct player jugadores[numjug];
    struct mapa posiciontablero[TP]= { {4,"Escalera",20}, {5,"Escalera",10}, {7,"Escalera",23}, {22,"Escalera",39}, {18,"Escalera",35}, {5,"Escalera",10}, {27,"Escalera",37}, {41,"Escalera",58}, {42,"Escalera",53}, {49,"Escalera",62}, {34,"Rodadero",2}, {38,"Rodadero",3}, {43,"Rodadero",23}, {46,"Rodadero",33}, {57,"Rodadero",44}, {43,"Rodadero",23}, {59,"Rodadero",46} };
    struct mapa escaleras[maxin];
    struct jugador jugadas[TL] = { {"Blanco",3},{"Azul",5},{"Verde",3},{"Rojo",3},{"Blanco",3},{"Azul",4},{"Verde",1},{"Rojo",4},{"Blanco",3},{"Azul",1},{"Verde",5},{"Rojo",3},{"Blanco",4},{"Azul",4},{"Verde",1},{"Rojo",2},{"Blanco",4},{"Azul",4},{"Verde",6},{"Rojo",6}};
    struct maps tablero[maxin][maxin];
    struct posi poss[maxin];
    bool salir=false;
    datosJugadores(jugadores,numjug);//agrega a los jugadores a la estructura player
    mapaJugadores( jugadores, numjug, tablero, tam, poss,posiciontablero, TP);
    do
    {
        cout<<"Menu principal"<<endl<<endl;
        cout<<"Digite el numero que desea"<<endl<<endl;
        cout<<"1: Presentar jugadores"<<endl;
        cout<<"2: Posicion de los jugadores"<<endl;
        cout<<"3: Mostrar el tablero"<<endl;
        cout<<"4: Simular jugada"<<endl;
        cout<<"5: Mostrar clasificacion"<<endl;
        cout<<"6 Salir"<<endl;

        cin>>opc;
        if(opc == 1)
        {
            presentarJugadores (jugadores, numjug);
            opc=0;

        }

        if(opc == 2)
        {
            PosicionJugadores (jugadores, numjug);
            opc=0;
        }
        if(opc == 3)
        {
            vistaTablero(tablero,tam);
            opc=0;
        }
        if(opc == 4)
        {
            cout<<endl<<"Cantidad de jugadas: ";
            cin>>n;
            jugarMapaJugadores( jugadores, numjug, tablero,tam, poss, jugadas, n);

            opc=0;
        }
        if(opc == 5)
        {
            presentarJugadoresClasificados (jugadores, numjug);
        }
        if(opc==6)
        {
            salir=true;
        }

    }
    while (salir == false);
}


void datosJugadores (struct player jugadores [maxin],int numjug)
{

    string color1 = "Rojo", color2="Verde", color3 ="Blanco", color4="Azul";
    int colores=4,ocpc=0;
    jugadores[0].nombre = "Hugo";
    jugadores[0].genero = 'M';
    jugadores[0].edad = 8;
    jugadores[0].color = "Blanco";
    jugadores[1].nombre ="Daisy";
    jugadores[1].genero = 'F';
    jugadores[1].edad = 7;
    jugadores[1].color = "Rojo";
    jugadores[2].nombre = "Paco";
    jugadores[2].genero = 'M';
    jugadores[2].edad = 8;
    jugadores[2].color = "Verde";
    jugadores[3].nombre = "Minie";
    jugadores[3].genero = 'F';
    jugadores[3].edad = 8;
    jugadores[3].color = "Azul";
    for(int i=0; i<numjug; i++)
    {
        jugadores[i].posx=0;
        jugadores[i].posy=0;
        jugadores[i].posjug =0;

        if(jugadores[i].color == color1)
        {
            jugadores[i].codigo = 'R';
        }
        if(jugadores[i].color == color2)
        {

            jugadores[i].codigo = 'V';
        }
        if(jugadores[i].color == color3)
        {

            jugadores[i].codigo = 'B';
        }
        if(jugadores[i].color == color4)
        {
            jugadores[i].codigo = 'A';
        }
    }
}
void presentarJugadores (struct player jugadores [maxin],int numjug)
{
    for(int i=0; i< numjug; i++)
    {
        cout<<"Jugador #"<<i<<endl;
        cout<<"Nombre: "<<jugadores[i].nombre<<endl;
        cout<<"Edad: "<<jugadores[i].edad<<endl;
        cout<<"Genero: "<<jugadores[i].genero<<endl;
        cout<<"Color: "<<jugadores[i].color<<endl;
    }
}
void PosicionJugadores (struct player jugadores [maxin],int numjug)
{
    for(int i=0; i<numjug; i++)
    {
        cout<<"Jugador #"<<i<<endl;
        cout<<"Nombre: "<<jugadores[i].nombre<<endl;
        cout<<"Con la ficha de color: "<<jugadores[i].color<<" esta en la posicion: " <<jugadores[i].posjug<<endl;

    }
}
void presentarJugadoresClasificados (struct player jugadores [maxin],int numjug)
{
    for(int i=0; i< numjug; i++)
    {
        cout<<"Jugador #"<<i<<endl;
        cout<<"Nombre: "<<jugadores[i].nombre<<endl;
        cout<<"Con la ficha de color: "<<jugadores[i].color<<" esta en la posicion: " <<jugadores[i].posjug<<endl;
        if(jugadores[i].ganador == true)
        {
            cout<<"Gano la partida"<<endl;
        }
        else
        {
            cout<<"No ha ganado la partida"<<endl;
        }

    }
}
void mapaJugadores(struct player jugadores [maxin],int numjug, struct maps tablero[][maxin],int tam,struct posi poss[maxin],struct mapa posiciontablero[maxin],int TP)
{
    int possic= 0;
    int contador = 1;
    int casillasResvalas =0, casillasEscaleras=0;

    for (int i = 0; i < tam; i++)
    {

        if (i%2 == 0)   // Ascendente en pares
        {
            for (int j = 0; j < tam; j++)
            {

                tablero[i][j].numero = contador;
                poss[contador].numero= contador;
                poss[contador].x= i;
                poss[contador].y= j;
                contador ++;
            }

        }
        else     // Descendente en impares
        {
            for (int j = tam-1; j >= 0; j--)
            {
                tablero[i][j].numero = contador;
                poss[contador].numero= contador;
                poss[contador].x= i;
                poss[contador].y= j;
                contador ++;
            }
        }
    }
    for(int i=0; i<TP; i++)
    {
        if(posiciontablero[i].codigo == "Escalera")
        {
            for(int j=0; j<tam*tam; j++)
            {
                if(posiciontablero[i].posini == poss[j].numero)
                {
                    for(int x=0; x<tam; x++)
                    {
                        for(int y=0; y<tam; y++)
                        {
                            if(tablero[x][y].numero == posiciontablero[i].posini )
                            {
                                tablero[x][y].codigo ='E';
                                tablero[x][y].posfinal = posiciontablero[i].posfinal;
                                tablero[x][y].xfinal = poss[j].x;
                                tablero[x][y].yfinal = poss[j].y;
                            }
                        }
                    }

                }
            }
        }
        if(posiciontablero[i].codigo == "Rodadero")
        {
            for(int j=0; j<tam*tam; j++)
            {
                if(posiciontablero[i].posini == poss[j].numero)
                {
                    for(int x=0; x<tam; x++)
                    {
                        for(int y=0; y<tam; y++)
                        {
                            if(tablero[x][y].numero == posiciontablero[i].posini )
                            {
                                tablero[x][y].codigo ='R';
                                tablero[x][y].posfinal = posiciontablero[i].posfinal;
                                tablero[x][y].xfinal = poss[j].x;
                                tablero[x][y].yfinal = poss[j].y;
                            }
                        }
                    }

                }
            }
        }

    }
}

void vistaTablero(struct maps tablero[][maxin],int tam)
{
    for(int x=0; x<tam; x++)
    {

        for(int y=0; y<tam; y++)
        {
            cout<<"|"<<setw(2)<<tablero[x][y].numero<<"|"<<setw(2)<<tablero[x][y].codigo<<"|"<<setw(2)<<tablero[x][y].posfinal<<tablero[x][y].jug1<<tablero[x][y].jug2<<tablero[x][y].jug3<<tablero[x][y].jug4;
        }

        cout<<endl;
    }
}
void jugarMapaJugadores(struct player jugadores [maxin],int numjug,struct maps tablero[maxin][maxin],int tam,struct posi poss[maxin], struct jugador jugadas[maxin],int n)
{
    int dado1=0,xsalido=tam * tam,ysalido=0,posfast=n;
    bool ganador= false;
    do
    {

        for(int i=0; i<numjug; i++)
        {
             //system("cls");

            cout<<"El jugador con la ficha: "<<jugadores[i].color<<" juega"<<endl;
            if(jugadas[posfast].color == jugadores[i].color)
            {
                dado1 = jugadas[posfast].dado;
            }
//Sleep(1000);
            jugadores[i].posjug = jugadores[i].posjug + dado1;

            for(int x=0; x<tam; x++)
            {
                for(int y=0; y<tam; y++)
                {
                    if(tablero[x][y].numero == jugadores[i].posjug)
                    {
                        if("Blanco"== jugadores[i].color)
                        {
                            tablero[jugadores[i].posx][jugadores[i].posy].jug1 = ' ';

                            if( tablero[x][y].posfinal != 0)
                            {
                                jugadores[i].posjug = tablero[x][y].numero;
                                jugadores[i].posx=tablero[x][y].xfinal;
                                jugadores[i].posy=tablero[x][y].yfinal;
                                tablero[jugadores[i].posx][jugadores[i].posy].jug1 =jugadores[i].codigo;
                            }
                            if(tablero[x][y].posfinal == 0 )
                            {
                                int tami= tam*tam;
                                for(int i = 0; i < tam; i++ )
                                {
                                    for(int j = 0; j < tami; j++)
                                    {
                                        if(poss[j].numero == jugadores[i].posjug)
                                        {
                                            jugadores[i].posjug = tablero[x][y].numero;
                                            jugadores[i].posx=poss[j].x;
                                            jugadores[i].posy=poss[j].y;
                                            tablero[jugadores[i].posx][jugadores[i].posy].jug1 =jugadores[i].codigo;
                                        }
                                    }
                                }
                            }

                        }
                        if("Azul"== jugadores[i].color)
                        {

                            if( tablero[x][y].posfinal != 0)
                            {
                                jugadores[i].posjug = tablero[x][y].numero;
                                jugadores[i].posx=tablero[x][y].xfinal;
                                jugadores[i].posy=tablero[x][y].yfinal;
                            }
                            if(tablero[x][y].posfinal == 0 )
                            {
                                int tami= tam*tam;
                                for(int i = 0; i < tam; i++ )
                                {
                                    for(int j = 0; j < tami; j++)
                                    {
                                        if(poss[j].numero == jugadores[i].posjug)
                                        {
                                            jugadores[i].posjug = tablero[x][y].numero;
                                            jugadores[i].posx=poss[j].x;
                                            jugadores[i].posy=poss[j].y;
                                        }
                                    }
                                }

                            }
                            tablero[jugadores[i].posx][jugadores[i].posy].jug2 =jugadores[i].codigo;
                        }
                        if("Verde"== jugadores[i].color)
                        {
                            tablero[jugadores[i].posx][jugadores[i].posy].jug3 = ' ';
                            if( tablero[x][y].posfinal != 0)
                            {
                                jugadores[i].posjug = tablero[x][y].numero;
                                jugadores[i].posx=tablero[x][y].xfinal;
                                jugadores[i].posy=tablero[x][y].yfinal;
                            }
                            if(tablero[x][y].posfinal == 0 )
                            {
                                int tami= tam*tam;
                                for(int i = 0; i < tam; i++ )
                                {
                                    for(int j = 0; j < tami; j++)
                                    {
                                        if(poss[j].numero == jugadores[i].posjug)
                                        {
                                            jugadores[i].posjug = tablero[x][y].numero;
                                            jugadores[i].posx=poss[j].x;
                                            jugadores[i].posy=poss[j].y;
                                        }
                                    }
                                }

                            }
                            tablero[jugadores[i].posx][jugadores[i].posy].jug3 =jugadores[i].codigo;
                        }
                        if("Rojo"== jugadores[i].color)
                        {
                            tablero[jugadores[i].posx][jugadores[i].posy].jug4 = ' ';
                            if( tablero[x][y].posfinal != 0)
                            {
                                jugadores[i].posjug = tablero[x][y].numero;
                                jugadores[i].posx=tablero[x][y].xfinal;
                                jugadores[i].posy=tablero[x][y].yfinal;
                            }
                            if(tablero[x][y].posfinal == 0 )
                            {
                                int tami= tam*tam;
                                for(int i = 0; i < tam; i++ )
                                {
                                    for(int j = 0; j < tami; j++)
                                    {
                                        if(poss[j].numero == jugadores[i].posjug)
                                        {
                                            jugadores[i].posjug = tablero[x][y].numero;
                                            jugadores[i].posx=poss[j].x;
                                            jugadores[i].posy=poss[j].y;
                                        }
                                    }
                                }

                            }
                            tablero[jugadores[i].posx][jugadores[i].posy].jug4 =jugadores[i].codigo;
                        }
                    }
                }
            }
            vistaTablero(tablero,tam);
            if(jugadores[i].posjug >= xsalido)
            {
                jugadores[i].ganador=true;
                ganador=true;
            }

            posfast = posfast +1;
            if(posfast >= n)
            {
                ganador=true;
            }
        }

    }
    while(ganador == false );
    if(ganador == true)
    {
        for(int i=0; i<numjug; i++)
        {
            if(jugadores[i].ganador == true)
            {
                cout<<"El ganador es la ficha con el color: "<<jugadores[i].color<<endl;
            }
            if(jugadores[i].ganador == false)
            {
                cout<<"El jugador con la ficha de color "<< jugadores[i].color<<" no ha ganado: "<<endl;
            }
        }
    }
}


