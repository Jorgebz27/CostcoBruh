#include <iostream>
#include <vector>
#include "Pastel.h"

using namespace std;

vector<int> Greedy(vector<Pastel> pasteles, float azucar, float huevo)
{
    vector<int> retVector;
    int valorMax = -1;
    int pIndex = 0;

    for (int i = 0; i < pasteles.size(); i++)
    {
        if (pasteles[i].precio > valorMax)
        {
            valorMax = pasteles[i].precio;
            pIndex = i;
        }
    }

    bool isOk = true;
    int cuantos = 0;
    while (isOk)
    {
        if (azucar > pasteles[pIndex].azucar && huevo > pasteles[pIndex].huevos || azucar > pasteles[pIndex].azucar || huevo > pasteles[pIndex].huevos)
        {
            azucar -= pasteles[pIndex].azucar;
            huevo -= pasteles[pIndex].huevos;
            retVector.push_back(pIndex);
        }
        else
        {
            isOk = false;
        }
    }

    return retVector;
}

int main()
{
    Pastel imperial(0.5f, 8.f, 8.f);
    Pastel limon(1.f, 8.f, 10.f);

    vector<Pastel> _pasteles;
    _pasteles.push_back(imperial);
    _pasteles.push_back(limon);

    float _azucar = 10.f;
    float _huevo = 120.f;

    auto algo = Greedy(_pasteles, _azucar, _huevo);

    for (int i = 0; i < algo.size(); i++)
    {
        cout << algo[i];
    }
}
