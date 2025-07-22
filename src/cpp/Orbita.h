#pragma once
#include <vector>
#include <cmath>

// Struttura che rappresenta una posizione 3D (x, y, z)
struct Position {
    double x;
    double y;
    double z;
};

class OrbitSimulator {
public:

    // Costruttore: riceve semi-asse (a = 7000km), eccentricità (e = 0.1), parametro gravitazionale (mu), inclinazione (i)
    OrbitSimulator(double a, double e, double mu, double inclination = 0.0);

    // Restituisce la posizione (x, y, z) al tempo t [s]
    Position getPosition(double t);

    // Simula un'intera orbita: da t=0 a totalTime, con passo timestep
    std::vector<Position> simulate(double totalTime, double timestep);

private:
    double a;   // semi-asse maggiore (km)
    double e;   // eccentricità (unità)
    double mu;  // parametro gravitazionale (km^3/s^2)
    double i;   // inclinazione orbitale (radianti)

    // Calcola l'anomalia media M al tempo t
    double getMeanAnomaly(double t);
      
    // Risolve l'equazione di Keplero: M = E - e*sin(E), con metodo di Newton
    double solveKepler(double M);
    
    // Converte l'anomalia eccentrica (E) in anomalia vera (theta)
    double getTrueAnomaly(double E);
};