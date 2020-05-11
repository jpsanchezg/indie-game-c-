//hecho por juan pablo sanchez
#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#include <windows.h>
#define maxin 100
using namespace std;
void datosJugadores (struct player jugadores [maxin],int numjug);
void mapaJugadores(struct player jugadores [maxin],int numjug, struct mapa escaleras[maxin],struct mapa resvaladeras[maxin], string tablero[maxin][maxin],int tamx,int tamy,int numeros[maxin][maxin],struct posi poss[maxin],struct mapa posiciontablero[maxin],int TP);
void jugarMapaJugadores(struct player jugadores [maxin],int numjug, struct mapa escaleras[maxin],struct mapa resvaladeras[maxin], string tablero[maxin][maxin],int tamx,int tamy,int numeros[maxin][maxin],struct posi poss[maxin], struct jugador jugadas[maxin],struct maps jugs[maxin]);
void vistaTablero(string tablero[maxin][maxin],int tamx,int tamy,struct maps jugs[maxin]);
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
    string codigoinicio;
    string codigobajada;
};
struct posi
{
    int numero,x,y;
};
struct jugador
{
    string color;
    int dado;
};
struct maps
{
    char ju;
};
int main()
{

    int numjug=4,opc=0,tamy=8,tamx=8,modo=0,TP = 17,TL=21;
    struct player jugadores[numjug];
    struct mapa posiciontablero[TP]= { {4,"Escalera",20}, {5,"Escalera",10}, {7,"Escalera",23}, {22,"Escalera",39}, {18,"Escalera",35}, {5,"Escalera",10}, {27,"Escalera",37}, {41,"Escalera",58}, {42,"Escalera",53}, {49,"Escalera",62}, {34,"Rodadero",2}, {38,"Rodadero",3}, {43,"Rodadero",23}, {46,"Rodadero",33}, {57,"Rodadero",44}, {43,"Rodadero",23}, {59,"Rodadero",46} };
    struct mapa escaleras[maxin];
    struct maps jugs[numjug];
    struct jugador jugadas[TL] = { {"Blanco",3},{"Azul",5},{"Verde",3},{"Rojo",3},{"Blanco",3},{"Azul",4},{"Verde",1},{"Rojo",4},{"Blanco",3},{"Azul",1},{"Verde",5},{"Rojo",3},{"Blanco",4},{"Azul",4},{"Verde",1},{"Rojo",2},{"Blanco",4},{"Azul",4},{"Verde",6},{"Rojo",6}};
    struct mapa resvaladeras[maxin];
    string tablero[maxin][maxin];
    struct posi poss[maxin];
    int numeros [maxin][maxin] ;
    srand(time(NULL));
    cout << "hola a este nuevo juego: " << endl;
    cout << "menu:" << endl;
    cout<<"1. jugar"<<endl;
    cout<<"2. salir"<<endl;
    cin>>opc;
    if(opc==1)
    {
        cout<<"Que modo quieren jugar?"<<endl;
        cout<<"1. Generar mundo"<<endl;
        cout<<"2. aleatorio"<<endl;
        cin>>modo;
        if(modo== 1)
        {
            datosJugadores(jugadores,numjug);
            mapaJugadores(jugadores,numjug,escaleras,resvaladeras,tablero,tamx,tamy,numeros,poss,posiciontablero,TP);
            jugarMapaJugadores(jugadores,numjug,escaleras,resvaladeras,tablero,tamx,tamy,numeros,poss,jugadas,jugs);
        }
    }
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
void mapaJugadores(struct player jugadores [maxin],int numjug, struct mapa escaleras[maxin],struct mapa resvaladeras[maxin], string tablero[maxin][maxin],int tamx,int tamy,int numeros[maxin][maxin],struct posi poss[maxin],struct mapa posiciontablero[maxin],int TP)
{
    int possic= 0;
    int contador = 1;
    int casillasResvalas =0, casillasEscaleras=0;

    for (int i = 0; i < tamx; i++)
    {

        if (i%2 == 0)   // Ascendente en pares
        {
            for (int j = 0; j < tamy; j++)
            {

                numeros[i][j] = contador;
                poss[contador].numero= contador;
                poss[contador].x= i;
                poss[contador].y= j;
                contador ++;
            }

        }
        else     // Descendente en impares
        {
            for (int j = tamy-1; j >= 0; j--)
            {
                numeros[i][j] = contador;
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
            escaleras[i].posini = posiciontablero[i].posini;
            escaleras[i].posfinal = posiciontablero[i].posfinal;
            escaleras[i].codigoinicio = "Es";
            escaleras[i].codigobajada = "Et";
            for(int x=0; x<tamx*tamy; x++)
            {
                if(escaleras[i].posini == poss[x].numero)
                {
                    tablero[poss[x].x][poss[x].y]=escaleras[i].codigoinicio;
                }
                if(escaleras[i].posfinal ==poss[x].numero)
                {
                    tablero[poss[x].x][poss[x].y]=escaleras[i].codigobajada;
                }
            }

        }
        if(posiciontablero[i].codigo == "Rodadero")
        {
            resvaladeras[i].posini = posiciontablero[i].posini;
            resvaladeras[i].posfinal = posiciontablero[i].posfinal;
            resvaladeras[i].codigoinicio = "Rb";
            resvaladeras[i].codigobajada = "Rt";
            for(int x=0; x<tamx*tamy; x++)
            {
                if(resvaladeras[i].posini == poss[x].numero)
                {
                    tablero[poss[x].x][poss[x].y]=resvaladeras[i].codigoinicio;
                }
                if(resvaladeras[i].posfinal ==poss[x].numero)
                {
                    tablero[poss[x].x][poss[x].y]=resvaladeras[i].codigobajada;
                }
            }
        }
    }


}

void vistaTablero(string tablero[maxin][maxin],int tamx,int tamy,struct maps jugs[maxin] )
{
    for(int x=0; x<tamx; x++)
    {

        for(int y=0; y<tamy; y++)
        {
            cout<<"|"<<setw(5)<<tablero[x][y];//<<jugs[0].ju<<jugs[1].ju<<jugs[2].ju<<jugs[3].ju;
        }
        cout<<"_";
        cout<<endl;
    }
}
void jugarMapaJugadores(struct player jugadores [maxin],int numjug, struct mapa escaleras[maxin],struct mapa resvaladeras[maxin], string tablero[maxin][maxin],int tamx,int tamy,int numeros[maxin][maxin],struct posi poss[maxin], struct jugador jugadas[maxin],struct maps jugs[maxin])
{
    string opci;
    int dado1=0,xsalido=tamx * tamy,ysalido=0,posfast=0;
    bool ganador= false;
    do
    {

        for(int i=0; i<numjug; i++)
        {
            //system("cls");
            vistaTablero(tablero,tamx,tamy, jugs);
            cout<<"El jugador con la ficha: "<<jugadores[i].color<<" juega"<<endl;
            cout<<"Tirar dado? si/no"<<endl;
            cin>>opci;
            if(opci == "si")
            {
                tablero[jugadores[i].posx][jugadores[i].posy] = " ";
                if(jugadas[posfast].color == jugadores[i].color)
                {
                    dado1 = jugadas[posfast].dado;
                }
                cout<<"vas a moverte "<<dado1<<" posiciones"<<endl;
//Sleep(1000);
                jugadores[i].posjug = jugadores[i].posjug + dado1;
                for(int h=0; h<10; h++)
                {
                    if(jugadores[i].posjug == escaleras[h].posini)
                    {
                        jugadores[i].posjug = escaleras[h].posfinal;
                    }
                }
                for(int h =0; h<7; h++)
                {
                    if(jugadores[i].posjug == resvaladeras[h].posini)
                    {
                        jugadores[i].posjug = resvaladeras[h].posfinal;
                    }
                }
                buscarposi(numeros,jugadores,tamx,tamy,poss);
                jugs[i].ju = jugadores[i].codigo;
                tablero[jugadores[i].posx][jugadores[i].posy] = jugadores[i].codigo;
                if(jugadores[i].posjug >= xsalido)
                {
                    jugadores[i].ganador=true;
                    ganador=true;
                }
                if(posfast >= 21)
                {
                    ganador=true;
                }

            }
            posfast = posfast +1;
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
            if(jugadores[i].ganador == false){
                cout<<"El jugador con la ficha de color "<< jugadores[i].color<<" no ha ganado: "<<endl;
            }
        }
    }
}
void buscarposi(int numeros[maxin][maxin],struct player jugadores [maxin],int tamx, int tamy,struct posi poss[maxin])
{
    int tam= tamx*tamy;
    for(int i = 0; i < tamx; i++ )
    {
        for(int j = 0; j < tam; j++)
        {
            if(poss[j].numero == jugadores[i].posjug)
            {
                jugadores[i].posx=poss[j].x;
                jugadores[i].posy=poss[j].y;
            }


        }
    }
}

