#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    string vacio = "";

    for (int t = 1; t <= T; ++t)
    {
        cout << vacio;
        vacio = "\n";

        int numCiudades;
        cin >> numCiudades;

        map<string, int> posicionCiudad;

        string temp;

        for (int i = 0; i < numCiudades; ++i)
        {
            cin >> temp;
            posicionCiudad[temp] = i;
        }

        vector<vector<long long>> costo(numCiudades, vector<long long>(numCiudades, -1));

        int numVuelos;

        cin >> numVuelos;

        string temp2;

        for (int i = 0; i < numVuelos; ++i)
        {
            long long cost;

            cin >> temp >> temp2 >> cost;

            int posF = posicionCiudad[temp], posS = posicionCiudad[temp2];

            if (costo[posF][posS] == -1 || costo[posF][posS] > cost)
                costo[posF][posS] = cost;
        }

        vector<vector<long long>> costoPorVuelos(numCiudades, vector<long long>(numCiudades, -1));
        costoPorVuelos[0][0] = 0;

        for (int city = 0; city < numCiudades - 1; ++city)
        {            
            for (int flightNum = 0; flightNum < numCiudades - 1; ++flightNum)
            {
                for (int viajarA = city + 1; viajarA < numCiudades; ++viajarA)
                {
                    if (costo[city][viajarA] != -1 && costoPorVuelos[city][flightNum] != -1 && (costoPorVuelos[viajarA][flightNum + 1] == -1 || costoPorVuelos[viajarA][flightNum + 1] > costoPorVuelos[city][flightNum] + costo[city][viajarA]))
                        costoPorVuelos[viajarA][flightNum + 1] = costoPorVuelos[city][flightNum] + costo[city][viajarA];
                }
            }
        }

        vector<long long> mejorCosto(numCiudades);
        mejorCosto[0] = -1;

        for (int i = 1; i < numCiudades; ++i)
        {
            if (mejorCosto[i - 1] != -1 && costoPorVuelos[numCiudades - 1][i] != -1)
                mejorCosto[i] = min(mejorCosto[i - 1], costoPorVuelos[numCiudades - 1][i]);

            else
                mejorCosto[i] = max(mejorCosto[i - 1], costoPorVuelos[numCiudades - 1][i]);
        }

        cout << "Scenario #" << t << '\n';

        int numeroChecks;
        cin >> numeroChecks;

        while (numeroChecks--)
        {
            int vuelosMaximos;
            cin >> vuelosMaximos;
            ++vuelosMaximos;

            if (vuelosMaximos >= numCiudades)
                vuelosMaximos = numCiudades - 1;

            if (mejorCosto[vuelosMaximos] != -1)
                cout << "Total cost of flight(s) is $" << mejorCosto[vuelosMaximos] << '\n';

            else
                cout << "No satisfactory flights\n";
        }
    }
}