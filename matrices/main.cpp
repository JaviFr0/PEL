#include <iostream>
using namespace std;
void Rellenar( int **M, int fil, int col )
{
    cout << "\nRellenar la matriz:\n";
    for( int i = 0; i < fil; i++ ){
        for( int j = 0; j < col; j++ ){
            cout << "Matriz[" << i << "][" << j << "]: ";
            cin >> M[i][j];
        }
    }
}
void imprimir ( int **M, int fil, int col )
{
    for( int i = 0; i < fil; i++ ){
        cout << "\n| ";
        for( int j = 0; j < col; j++ )
            cout << M[i][j] << " ";
 
        cout << " |";
    }
    cout << endl;
}
void suma()
{
    int f, c;
 
    cout << "\nFilas: "; cin >> f;
    cout << "Columnas: "; cin >> c;
 
    int** A = new int*[f];
    for( int i = 0; i < f; i++ )
        A[i] = new int[c];
 
    int** B = new int*[f];
    for( int i = 0; i < f; i++ )
        B[i] = new int[c];
 
    int** C = new int*[f];
    for( int i = 0; i < f; i++ )
        C[i] = new int[c];
 
    cout << "\nDatos de la matriz A: ";
    Rellenar( A, f, c );
 
    cout << "\nDatos de la matriz B: ";
    Rellenar( B, f, c);
 
    for( int i = 0; i < f; i++ )
        for( int j = 0; j < c; j++ )
            C[i][j] = A[i][j] + B[i][j];
    cout << "\nSuma de las matrices (A+B):\n";
    imprimir( C, f, c );
 
}
void resta()
{
    int f, c;
 
    cout << "\nFilas: "; cin >> f;
    cout << "Columnas: "; cin >> c;
 
    int** A = new int*[f];
    for( int i = 0; i < f; i++ )
        A[i] = new int[c];
 
    int** B = new int*[f];
    for( int i = 0; i < f; i++ )
        B[i] = new int[c];
 
    int** C = new int*[f];
    for( int i = 0; i < f; i++ )
        C[i] = new int[c];
 
    cout << "\nDatos de la matriz A: ";
    Rellenar( A, f, c );
 
    cout << "\nDatos de la matriz B: ";
    Rellenar( B, f, c );
 
    for( int i = 0; i < f; i++ )
        for( int j = 0; j < c; j++ )
            C[i][j] = A[i][j] - B[i][j];
 
    cout << "\nResta de las matrices (A-B):\n";
    imprimir( C, f, c );
}
void multiplicacion()
{
    int filA, colA, filB, colB;
 
    cout << "\nDimension de la matriz A:";
    cout << "\nFilas de la matriz: "; cin >> filA;
    cout << "Columnas de la matriz: "; cin >> colA;
 
    int** A = new int*[filA];
    for( int i = 0; i < filA; i++ )
        A[i] = new int[colA];
 
    Rellenar( A, filA, colA );
 
    cout << "\nDimension de la matriz B:";
    cout << "\nFilas de la matriz: "; cin >> filB;
    cout << "Columnas de la matriz: "; cin >> colB;
 
    int** B = new int*[filB];
    for( int i = 0; i < filB; i++ )
        B[i] = new int[colB];
 
    Rellenar( B, filB, colB );
 
    int** C = new int*[filA];
    for( int i = 0; i < filA; i++ )
        C[i] = new int[colA];
 
    if( colA == filB ){
        for( int i = 0; i < filA; ++i ){
            for( int j = 0; j < colB; ++j ){
                C[i][j] = 0;
                for( int z = 0; z < colA; ++z )
                    C[i][j] += A[i][z] * B[z][j];
            }
        }
 
        cout << "\nMultiplicacion de las matrices (A*B):\n";
        imprimir( C, filA, colB );
 
    }else
        cout  << "\n    EL NUMERO DE COLUMNAS DE LA MATRIZ A DEBE COINCIDIR CON EL DE FILAS DE LA MATRIZ B";
             
            
 
}
void Transpuesta()
{
    int f,c,i,j,m,l;
    float a[100][100];
    int det;
    int M[20][20];
    cout<<"filas: ";
    cin>>f;
    cout<<"columnas: ";
    cin>>c;
    if(f==c){
        m=f-1;
        det=a[1][1];
        for(int k=1;k<=m;k++){ 
            l=k+1;
        for(i=l;i<=f;i++){ 
            for(j=l;j<=f;j++)
            a[i][j] = ( a[k][k]*a[i][j]-a[k][j]*a[i][k] )/a[k][k]; }
            det=det*a[k+1][k+1];
        }
        cout << endl;
        cout << "DETERMINANTE = " << det << endl;
        cout << "------------------------" << endl;


    }
    cout << "\nRellenar la matriz:\n";
    for( i = 0; i < f; i++ ){
        for(  j = 0; j < c; j++ ){
            cout << "Matriz[" << i << "][" << j << "]: ";
            cin >> M[i][j];
        }
    }
    cout<<endl;
     cout<<"matriz original"<<endl;
       for(i=0;i<f;i++){
        cout << "\n| ";
        for(j=0;j<c;j++){
            cout<<M[i][j]<<" ";
        }
         cout << " |";
       }
       cout<<endl;
     cout<<"matriz transpuesta"<<endl;
       for(i=0;i<f;i++){
        cout << "\n| ";
        for(j=0;j<c;j++){
            cout<<M[j][i]<<" ";
         }
         cout << " |";
       }
    

}
 
int main()
{
    int opcion;

    do{
        cout << "\n         CALCULADORA DE MATRICES"
         << "\n********************************************"
         << "\n1.- Suma"
         << "\n2.- Resta"
         << "\n3.- Multiplicacion"
         << "\n4.- Transpuesta"
         << "\n********************************************"
         << "\nSELECCIONA UNA OPCION (1 - 4): ";
        cin >> opcion;
 
        switch( opcion ){
            case 1:
                suma();
                break;
 
            case 2:
                resta();
                break;
 
            case 3:
                multiplicacion();
                break;
 
            case 4:
                Transpuesta();
                break;
            case 5:
                cout << "\n\nFIN DEL PROGRAMA\n\n";
                break;
 
            default:
                cout << "\n\nOPCION NO VALIDA\n\n";
                break;
        }
 
    }while( opcion != 5 );
}