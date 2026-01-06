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
    double filaColumna[MAX][MAX]; //U matriz triangular superior
    double fcL[MAX][MAX];           //L matriz triangular inferior

    double b[MAX]; //resultado de la matriz A*x=b;o vector respuesta
    double m[MAX]; //Vector respuesta auxiliar

    //fcL iniciacion de valores en 0 y 1 de forma recta
    for(int i=0;i<n;i++)
    {   for(int j=0;j<n;j++)
        {   if(i==j)
                 fcL[i][j]=1;
            else
                fcL[i][j]=0;
        }
    }
    // Ingreso de variables de la matriz
    for(int i=0;i<n;i++)
    {   for(int j=0;j<n;j++)
        {   cout<<"Ingrese la fila "<<i+1<<" y la columna "<<j+1<<"\n";
            cin>>filaColumna[i][j];
        }

    }
    //Ingreso de variables del vector resultado
    cout<<"Ingrese el vector B \n";

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
    //funcion para mostrar tabla L
    cout<<"Mostrar datos  de L \n";
    for(int i=0;i<n;i++)
    {   for(int j=0;j<n;j++)
        {   cout<<fcL[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<"Fin de mostrar datos %%%% \n";
    double multiplicador;

    //para ordenar los datos de forma escalonada

    for(int i=0;i<n - 1;i++)
    {    // Busca hacer un cambio de filas si esa fila se aproxima a cero
         if(filaColumna[i][i]== 0)
        {   //busca el mayor de su misma columna
            int cambio;
            double valor = filaColumna[i][i];
            for(int m=i;m<n;m++)
            {

                if( valor < filaColumna[m][i]||valor > filaColumna[m][i])
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
        // se busca el valor del multiplicador y recorre por toda la fila para colocar 0
        for(int aux = i + 1; aux < n; aux++)
        {   //se halla el multiplicador y se le manda a la tabla L
            cout<<aux<<"\n";
            multiplicador = filaColumna[aux][i]/filaColumna[i][i];
            fcL[aux][i]=multiplicador;
            cout<<filaColumna[aux][i]<<" "<<filaColumna[i][i]<<"\n";
            cout<<"el valor del multiplicador es: "<<multiplicador<<"\n";
            //hace el recorrido por la filas para hacer el triangulo superior
            for(int j=0;j<n;j++)
            {   filaColumna[aux][j]=filaColumna[aux][j] - (multiplicador * filaColumna[i][j]);


                        cout<<aux<<"====muestra la tabla U en proceso==== \n";
                        for(int k=0;k<n;k++)
                        {   for(int l=0;l<n;l++)
                            {   cout<<filaColumna[k][l]<<"\t";
                            }
                            cout<<b[k]<<"\n";

                        }
                        cout<<aux<<"====muestra la tabla L en proceso==== \n";
                        for(int k=0;k<n;k++)
                        {   for(int l=0;l<n;l++)
                            {   cout<<fcL[k][l]<<"\t";
                            }
                            cout<<b[k]<<"\n";

                        }
            }   // en este caso no se toca el vector resultado al momento de reducir
                //b[aux]=b[aux] - (multiplicador * b[i]);
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
    cout<<"Mostrar tabla L finalizado \n";
    for(int i=0;i<n;i++)
    {   for(int j=0;j<n;j++)
        {   cout<<fcL[i][j]<<"\t";
        }
        cout<<b[i]<<"\n";

    }
    cout<<"Los valores fueron ordenados de forma escalonada\n";//ejercicio D2
    cout<<"Calculando los valores a_1,b_1,...,n_1 \n";//ejercicio D1
    cout<<"0 vector auxiliar m\n";
    double x[MAX];
    //RECORRIDO para hallar los valores a,b,c,... o vector auxiliar m
    for(int i=0;i < n ;i++)
    {   double suma = 0;                //i=2
        for(int j= 0;j<i;j++)           //j=0
        {   suma= suma + fcL[i][j]*m[j];// suma=9
            cout<<"Valor sumando es = "<<suma<< "\n";
        }
        m[i]= (b[i]- suma )/ fcL[i][i];// m0=3,m1=5;m2=
        cout<<"ESTE ES EL VALOR DE M"<<i<<" "<<m[i]<< "\n";
    }

    for(int j=0;j<n;j++)
        cout<<"m"<<j+1<<" = "<< truncar(m[j] ,6)<<"\n";
    //Recorrido para hallar los valores X_1,X_2,...,X_n;
    //El vector auxiliar m se calcula bien para L m = b,
    //pero luego no usas m para resolver U x = m
    //(sigues usando b directamente para x).
    cout << "\nCalculando x (U x = m):\n";

    for (int i = n - 1; i >= 0; i--) {
        double suma = 0;
        for (int j = i + 1; j < n; j++) {
            suma += filaColumna[i][j] * x[j];
        }
        x[i] = (m[i] - suma) / filaColumna[i][i];
        cout << "x" << i+1 << " = " << truncar(x[i], 6) << endl;
    }
    return 0;
}
//  3 3 2 -1 6 5 4 9 -3 2 9 24 15 D2
// 4 8 3 -1 2 0 5 4 -3 0 0 7 2 0 0 0 6 20 10 15 12 D1
// LU 3 1 4 -2 3 -2 5 2 3 1 3 14 11
