
#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#include <windows.h>
#define maxin 100
using namespace std;
void datosJugadores (struct player jugadores [maxin],int numjug);
void mapaJugadoresaleatorio(struct player jugadores [maxin],int numjug, struct mapa escaleras[maxin],struct mapa resvaladeras[maxin], string tablero[maxin][maxin],int tamx,int tamy);
void mapaJugadores(struct player jugadores [maxin],int numjug, struct mapa escaleras[maxin],struct mapa resvaladeras[maxin], string tablero[maxin][maxin],int tamx,int tamy);
void jugarMapaJugadores(struct player jugadores [maxin],int numjug, struct mapa escaleras[maxin],struct mapa resvaladeras[maxin], string tablero[maxin][maxin],int tamx,int tamy);
void vistaTablero(string tablero[maxin][maxin],int tamx,int tamy);
struct player
{
    char nombre [20];
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
    int posfinalx,posfinaly;
    string codigoinicio;
    string codigobajada;
};


int main()
{

    int numjug=0,opc=0,tamy=0,tamx=0,modo=0;
    struct player jugadores[numjug];
    struct mapa escaleras[maxin];
    struct mapa resvaladeras[maxin];
    string tablero[maxin][maxin];
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
        cout<<"Que modo quieren jugar?"<<endl;
        cout<<"1. Generar mundo"<<endl;
        cout<<"2. aleatorio"<<endl;
        cin>>modo;
        if(modo== 1)
        {
            datosJugadores(jugadores,numjug);
            mapaJugadores(jugadores,numjug,escaleras,resvaladeras,tablero,tamx,tamy);
            jugarMapaJugadores(jugadores,numjug,escaleras,resvaladeras,tablero,tamx,tamy);

        }
        if(modo== 2)
        {
            datosJugadores(jugadores,numjug);
            mapaJugadoresaleatorio(jugadores,numjug,escaleras,resvaladeras,tablero,tamx,tamy);
            jugarMapaJugadores(jugadores,numjug,escaleras,resvaladeras,tablero,tamx,tamy);

        }
    }
}
void datosJugadores (struct player jugadores [maxin],int numjug)
{
    string color1 = "Roja", color2="Verde", color3 ="Azul", color4="Amarillo";
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
            cout<<"1. Rojo"<<endl;
            cout<<"2. Verde"<<endl;
            cout<<"3. Azul"<<endl;
            cout<<"4. Amarillo"<<endl;
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
void mapaJugadores(struct player jugadores [maxin],int numjug, struct mapa escaleras[maxin],struct mapa resvaladeras[maxin], string tablero[maxin][maxin],int tamx,int tamy)
{
    int casillasResvalas =0, casillasEscaleras=0;
    int x1=0,y1=0,x2=0,y2=0;
    cout<<"cuantas escalesras quiere poner?"<<endl;
    cin>>casillasEscaleras;

    cout<<"cuantas resvaladeros quiere poner?"<<endl;
    cin>>casillasResvalas;

    for(int i=1; i<=casillasEscaleras; i++)
    {
        cout<<"Escalera #"<<i<<endl;

        escaleras[i].codigoinicio = "Es";
        escaleras[i].codigobajada = "Et";
        cout<<"digite la posicion de inicio en x de la escalera "<<endl;
        cin>>x1;
        escaleras[i].posx = x1;
        cout<<"digite la posicion de inicio en y de la escalera "<<endl;
        cin>>y1;
        escaleras[i].posy = y1;
        tablero[escaleras[i].posx][escaleras[i].posy];
        cout<<"digite la posicion del final en x de la escalera "<<endl;
        cin>>x2;
        escaleras[i].posfinalx = x2;
        cout<<"digite la posicion del final en y de la escalera "<<endl;
        cin>>y2;
        escaleras[i].posfinaly = y2;
        tablero[escaleras[i].posfinalx][escaleras[i].posfinaly];
       /** if(tablero[escaleras[i].posx][escaleras[i].posy] == tablero[0][tamx-1])
        {
            cout<<"cambie las posiciones iniciales"<<endl;
            cout<<endl;
            cout<<"digite la posicion de inicio en x de la escalera "<<endl;
            cin>>x1;
            escaleras[i].posx = x1;
            cout<<"digite la posicion de inicio en y de la escalera "<<endl;
            cin>>y1;
            escaleras[i].posy = y1;
        }**/
        tablero[escaleras[i].posx][escaleras[i].posy]=escaleras[i].codigoinicio;
        tablero[escaleras[i].posfinalx][escaleras[i].posfinaly]=escaleras[i].codigobajada;
        x1=0,y1=0,x2=0,y2=0;
    }

    for(int i=0; i<casillasResvalas; i++)
    {
        cout<<"resvaladeras #"<<i<<endl;
        int x1=0,y1=0,x2=0,y2=0;
        resvaladeras[i].codigoinicio = "Rb";
        resvaladeras[i].codigobajada = "Rt";
        cout<<"digite la posicion de inicio en x de la resvaladeras "<<endl;
        cin>>x1;
        resvaladeras[i].posx = x1;
        cout<<"digite la posicion de inicio en y de la resvaladeras "<<endl;
        cin>>y1;
        resvaladeras[i].posy = y1;
        cout<<"digite la posicion del final en x de la resvaladeras "<<endl;
        cin>>x2;
        resvaladeras[i].posfinalx = x2;
        cout<<"digite la posicion del final en y de la resvaladeras "<<endl;
        cin>>y2;
        resvaladeras[i].posfinaly = y2;
        /**if(tablero[resvaladeras[i].posx][resvaladeras[i].posy] != tablero[0][tamx-1])
        {
            cout<<"cambie las posiciones iniciales"<<endl;
            cout<<endl;
            cout<<"digite la posicion de inicio en x de la escalera "<<endl;
            cin>>x1;
            resvaladeras[i].posx = x1;
            cout<<"digite la posicion de inicio en y de la escalera "<<endl;
            cin>>y1;
            resvaladeras[i].posy = y1;
        }**/
        tablero[resvaladeras[i].posx][resvaladeras[i].posy]=resvaladeras[i].codigoinicio;
        tablero[resvaladeras[i].posfinalx][resvaladeras[i].posfinaly]=resvaladeras[i].codigobajada;

    }

}

void mapaJugadoresaleatorio(struct player jugadores [maxin],int numjug, struct mapa escaleras[maxin],struct mapa resvaladeras[maxin], string tablero[maxin][maxin],int tamx,int tamy)
{
    int casillasEscaleras=1, casillasResvalas = 1;
    int numx,numy;
    bool logrado=false;

    for(int i=0; i<casillasEscaleras; i++)
    {
        int posi=0,x=0,y=0,suma=0;
        numx = rand() % tamx-1;
        numy = rand() % tamy-1;
        escaleras[i].codigoinicio = "Es";
        escaleras[i].codigobajada = "Et";
        if(numx != tamx-1 && numy != 0)
        {
            escaleras[i].posx  = numx;
            escaleras[i].posy  = numy;
            posi = escaleras[i].posx + escaleras[i].posy;
            suma = posi + rand() % 5+1;

            tablero[escaleras[i].posx][escaleras[i].posy] = escaleras[i].codigoinicio;
        }

    }
    do
    {
        for(int i=0; i<casillasResvalas; i++)
        {
            int posi=0,x=0,y=0,resta=0;
            numx = rand() % tamx;
            numy = rand() % tamy;
            resvaladeras[i].codigoinicio = "Rb";
            resvaladeras[i].codigobajada = "Rt";
            if(numx != tamx-1 && numy != 0)
            {
                resvaladeras[i].posx  = numx;
                resvaladeras[i].posy  = numy;
                posi = resvaladeras[i].posx + resvaladeras[i].posy;
                resta = posi - rand() % 5+1;
                x = resta /2;
                y = resta - x;
                resvaladeras[i].posfinaly = resvaladeras[i].posx - x;
                resvaladeras[i].posfinalx = resvaladeras[i].posy + y;
                tablero[resvaladeras[i].posx][resvaladeras[i].posy] = resvaladeras[i].codigoinicio;
                tablero[resvaladeras[i].posfinalx][resvaladeras[i].posfinaly] = resvaladeras[i].codigobajada;
                logrado = true;
            }

        }
    }
    while (logrado == false);
}
void vistaTablero(string tablero[maxin][maxin],int tamx,int tamy)
{
    for(int x=0; x<tamx; x++)
    {

        for(int y=0; y<tamy; y++)
        {
            cout<<"|"<<setw(5)<<tablero[x][y];
        }
        cout<<"_";
        cout<<endl;
    }
}
void jugarMapaJugadores(struct player jugadores [maxin],int numjug, struct mapa escaleras[maxin],struct mapa resvaladeras[maxin], string tablero[maxin][maxin],int tamx,int tamy)
{

    for(int i=0; i<numjug; i++)
    {
        //  system("cls");
        vistaTablero(tablero,tamx,tamy);
        cout<<"El jugador con la ficha: "<<jugadores[i].color<<" juega"<<endl;
        do
        {
            jugadores[i].ganador =true;
        }
        while(jugadores[i].ganador =false );
    }

}
