#include <iostream>
#include <cmath>

using namespace std;

//prototios de las funciones
double calcular_sbr(int t,int w,int ibcC,int ibcs,int n,int anios, float ipcr, float ipci);
double calcular_ief(double i);
void datos();

//variables que use globalmente
int t,w,ibcC,ibcs,n,anios;
float ipcr,ipci;
double i,sbr,ief;



int main ()
{
    int opcion,mp;
    double denominador1,denominador2,factincrem,ciap;
    float pmens;
    

    do
    {
        cout << "Bienvenido, elija una de las siguientes opciones.\n";
        cout << "1. Pension para los optados.\n";
        cout << "2. Pension para los afiliados del Sistema Publico de Pensiones.\n";
        cout << "3. Pension de los afiliados al Sistema privado (AFP).\n";
        cout << "4. Salir.\n";
        cout << "\n\n\n";

        cin >> opcion;
        cout << "\n\n";

        switch (opcion)
        {
        case 1:
            datos();
            sbr=calcular_sbr(t,w,ibcC,ibcs,n,anios,ipcr,ipci);
            factincrem=pow(1+0.01,anios-10);
            pmens=0.35*sbr*factincrem;
            cout << "Su pension es de: $ "<< pmens <<"\n";

            break;
        
        case 2:
            datos();
            sbr=calcular_sbr(t,w,ibcC,ibcs,n,anios,ipcr,ipci);
            factincrem=pow(1+0.0175,anios-3);
            pmens=0.30*sbr*factincrem;
            cout << "Su pension es de: $ "<< pmens <<"\n";
            
            break;
        
        case 3:
            mp=5;
            ciap=60000.00;
            i=0.000883;
            ief=calcular_ief(i);
            denominador1=(pow(1+i,240)-1)/(i*(pow(1+i,240)));
            denominador2=(((pow(1+ief,20))-1)*(pow(1+i,(mp-1))))/(ief*(pow(1+ief,20)));//lo hice asi ya que 
            pmens=ciap/(denominador1+5*denominador2);                                 //se mantiene mas el
            cout << "Su pension es de: $"<<pmens<<"\n";                              //orden y pq no me daba 
            //                                                                        el resultado jajaja
            break;
        
        case 4:
            cout << "Saliendo del sistema...\n";

            break;
        
        default:
            cout << "Ha ingresado una opcion invalida, intente de nuevo\n\n";
            
            break;
        }
    } while (opcion!=4);
    
    return 0;
}
void datos ()
{
    cout << "ingrese t: ";
    cin >> t;

    cout << "ingrese w: ";
    cin >> w;

    cout << "ingrese ibcC: ";
    cin >> ibcC;

    cout << "ingrese ibc$: ";
    cin >> ibcs;

    cout << "ingrese n: ";
    cin >> n;

    cout << "ingrese años: ";
    cin >> anios;

    cout << "ingrese ipcr: ";
    cin >> ipcr;

    cout << "ingrese ipci: ";
    cin >> ipci;

}
double calcular_sbr(int t,int w,int ibcC,int ibcs,int n,int anios, float ipcr, float ipci)
{
    double suma1=0,suma2=0;
    double fi=ipcr/ipci;

    //son sumatorias
    for (int i = 0; i < t-w; i++)
    {
        suma1=(suma1+ibcC*fi)/8.75;
    }

    for (int i = t-w+1; i < t; i++)
    {
        suma2=suma2+ibcs*fi;
    }

    sbr=(suma1+suma2)/n;

    return sbr;
    
}
double calcular_ief(double i)
{
    ief=(pow(1+i,12))-1;
    return ief;
}