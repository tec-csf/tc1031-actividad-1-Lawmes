#include<iostream>
#include<vector>
#include<chrono>
#include<algorithm>

using namespace std;


int secuencial(vector<int>v, int size, int search) 
{
    for(int i=0; i<size; i++)
    {
        if(v[i]==search)
        {
            return i;
        }
    }
}

int secuencial_movimiento_frente(vector<int>v, int size, int search) 
{
    for(int i=0; i<size; i++)
    {
        if(search==v[i])
        {
            v[0]=search;
            return i;
        }
    }
}


int secuencial_transposicion(vector<int>v, int size, int search) 
{
    for(int i=0; i<size; i++)
    {
        if(search==v[i])
        {
            v[i] = v[i]+v[i+1];
            v[i+1] = v[i]-v[i+1];
            v[i] = v[i]-v[i+1];
            return i;
        }
    }
}


int secuencial_ordenamiento(vector<int>v, int size, int search) 
{
    for(int i=0; i<size; i++)
    {
        if(search==v[i])
        {
            return i;
        }
    }
    return -1;
    for(int i=0;i<=5;i++)
    {
    for(int j=i+1;j<=6;j++)
    {
    int temp;

    if(v[i] > v[j])
    {
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
    }
    }
 }

}




int binaria(vector<int>v, int min, int max, int search) 
{
    int intento = 0;
    string encontrado = "n";
    while (encontrado=="n") {
        intento = ((v[min] + v[max]) / 2);
        if (v[intento] == search) {
            encontrado = "y";
            return intento;
        }
        else if (v[intento] < search) {
            min = intento + 1;
        }
        else if (v[intento] > search) {
            max = intento - 1;
        }
    }
}






main()
{

    auto start = std::chrono::steady_clock::now();


    vector<int> vec(10000);

    for(int i=0; i<10000; i++)
    {
        vec[i]=i;
    }

    random_shuffle(vec.begin(),vec.end());
 

    int req;

    cout<<endl;
    cout<<"¿Qué número buscas? ";
    cin>>req;
    cout<<endl;
 
    int resultado = binaria(vec, 1, 1000, req);
    if(resultado>=0)
    {
        cout << "Se encontró el número " << req << " en la posición " << resultado << " del vector." <<  endl;
    }
    else
    {
        cout << "No se encontró el número en el vector." << endl;
    }
    



    auto end = std::chrono::steady_clock::now();
    double time = double(std::chrono::duration_cast < std::chrono::nanoseconds > (end-start).count());
    
    cout << "El programa se ejecuto en: " << time/1e9 << " segundos." << endl;


}

