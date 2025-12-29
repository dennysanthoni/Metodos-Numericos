#include <iostream>

using namespace std;
int MAX =20;
double truncar(double num,int d)
{   int factor=1;
    for(int i=0;i<d;i++)
        factor *= 10;
    int aux = num * factor;
    return (double) aux/factor;
}
int main()
{
    int n;
    cout<<"Ingrese el n^2 de su Matriz A \n";
    cin>>n;
    if(n>MAX)
        return 1;
    double filaColumna[MAX][MAX]; //declarando variable
    for(int i=0;i<n;i++)
    {   for(int j=0;j<n;j++)
        {   cout<<"Ingrese la fila "<<i+1<<" y la columna "<<j+1<<"\n";
            cin>>filaColumna[i][j];
        }

    }
    cout<<"Ingrese el vector B \n";
    double b[MAX]; //resultado de la matriz A*x=b;
    for(int i=0;i<n;i++)
    {   cout<<"Ingrese la posicion "<<i+1<<" de B\n";
        cin>>b[i];
    }
    //funcion para mostrar datos
    cout<<"Mostrar datos \n";
    for(int i=0;i<n;i++)
    {   for(int j=0;j<n;j++)
        {   cout<<filaColumna[i][j]<<"\t";
        }
        cout<<b[i]<<"\n";

    }
    double multiplicador;

    for(int i=0;i<n - 1;i++)
    {   if(filaColumna[i][i]== 0)
        {   //busca el mayor de su misma columna
            int cambio;
            double valor = filaColumna[i][i];
            for(int m=i;m<n;m++)
            {

                if( valor < filaColumna[m][i])
                    valor =filaColumna[m][i];
                    cambio=m;
            }
            if(valor ==0)
            {   cout<<"ingrese a esta condiciony voy a romper la condicion\n";
                break;
                cout<<"ingrese a este lugar osea que no rompe la condicion\n";
            }
            //hacer el cambio de ecuaciones entre el mayor y el primero
            for(int m =0;m<n;m++)
            {   cout<<filaColumna[i][m]<<""<<filaColumna[0][0]<<"\n";
                filaColumna[i][m]=filaColumna[i][m]+filaColumna[cambio][m];
                cout<<filaColumna[i][m]<<"\n";
                filaColumna[cambio][m]=filaColumna[i][m] - filaColumna[cambio][m];
                cout<<filaColumna[cambio][m]<<"\n";
                filaColumna[i][m]=filaColumna[i][m] - filaColumna[cambio][m];
                cout<<filaColumna[i][m]<<"\n";
                cout<<"despues del cambio "<<m<<"===========\n";
                        for(int k=0;k<n;k++)
                        {   for(int l=0;l<n;l++)
                            {   cout<<filaColumna[k][l]<<"\t";
                            }
                            cout<<b[k]<<"\n";

                        }
            }
            b[i]=       b[i]+b[cambio];
            b[cambio]=  b[i]-b[cambio];
            b[i]=       b[i]-b[cambio];

                       cout<<"despues del cambio =====final======\n";
                        for(int k=0;k<n;k++)
                        {   for(int l=0;l<n;l++)
                            {   cout<<filaColumna[k][l]<<"\t";
                            }
                            cout<<b[k]<<"\n";

                        }
        }
        for(int aux = i + 1; aux < n; aux++)
        {   cout<<aux<<"\n";
               multiplicador = filaColumna[aux][i]/filaColumna[i][i];
            cout<<filaColumna[aux][i]<<" "<<filaColumna[i][i]<<"\n";
            cout<<"el valor del multiplicador es: "<<multiplicador<<"\n";
            for(int j=0;j<n;j++)
            {   filaColumna[aux][j]=filaColumna[aux][j] - (multiplicador * filaColumna[i][j]);

                        cout<<aux<<"======== \n";
                        for(int k=0;k<n;k++)
                        {   for(int l=0;l<n;l++)
                            {   cout<<filaColumna[k][l]<<"\t";
                            }
                            cout<<b[k]<<"\n";

                        }
            }   b[aux]=b[aux] - (multiplicador * b[i]);
                cout<<"sali del bucle de que opera filas aux="<<aux<<"\n";

        }   cout<<"sali del bucle que controla el multiplicador en i="<<i<<"\n";

    }
    cout<<"Mostrar datos \n";
    for(int i=0;i<n;i++)
    {   for(int j=0;j<n;j++)
        {   cout<<filaColumna[i][j]<<"\t";
        }
        cout<<b[i]<<"\n";

    }
    cout<<"Los valores fueron ordenados de forma escalonada\n";//ejercicio D2
    cout<<"Calculando los valores X_1\n";//ejercicio D1
    double x[MAX];

    for(int i=n-1;i >= 0 ;i--)
    {   double suma = 0;
        for(int j= i+1;j<n;j++)
        {   suma= suma + filaColumna[i][j]*x[j];
        }
        x[i]= (b[i]- suma )/ filaColumna[i][i];
    }

    for(int j=0;j<n;j++)
        cout<<"x"<<j+1<<" = "<< truncar(x[j] ,6)<<"\n";

    return 0;
}
//  3 3 2 -1 6 5 4 9 -3 2 9 24 15 D2
// 4 8 3 -1 2 0 5 4 -3 0 0 7 2 0 0 0 6 20 10 15 12 D1
