# Orbita-Satellite 🌍🛰️  
**Simulazione di orbita satellitare in C++ e Python**  
Un simulatore di orbite satellitari che implementa la meccanica orbitale kepleriana per calcolare traiettorie 3D realistiche intorno alla Terra, con visualizzazione animata.
Il simulatore implementa un modello matematico basato sui parametri orbitali kepleriani, tra cui : 
  - Semi-asse maggiore (a): Dimensione dell'orbita in km  
  - Eccentricità (e): Forma dell'ellisse orbitale (0 = circolare, <1 = ellittica)
  - Parametro gravitazionale (μ): Costante gravitazionale del corpo centrale (Terra: 398,600 km³/s²)
  - Inclinazione orbitale (i): Angolo rispetto al piano equatoriale per orbite 3D
  - Equazione di Keplero: Risoluzione numerica di M = E - e·sin(E) usando il metodo di Newton-Raphson


<img width="1000" height="835" alt="Screenshot 2025-07-22 alle 14 38 52" src="https://github.com/user-attachments/assets/ef372526-9281-4e93-a180-398cd80d5776" />


## 📌 **Caratteristiche**  
- **Backend C++**:  
  - Modello fisico **Kepleriano** con estensione per inclinazione 3D  
  - Risolutore **Newton-Raphson** per l'equazione di Keplero  
  - Output in CSV con posizioni (x, y, z)  
- **Frontend Python**:  
  - Animazione 3D con `matplotlib`  
  - Traiettoria progressiva e satellite in movimento  

##  **Struttura del codice**  
### C++ (Core di simulazione)  
| File | Contenuto |  
|------|-----------|  
| `Orbita.h` | Definizione classe `OrbitSimulator` e metodi per il calcolo orbitale |  
| `Orbita.cpp` | Implementazione:  
                  - `solveKepler()`: Risolutore numerico (Newton-Raphson)  
                  - `getPosition()`: Conversione anomalie → coordinate 3D  
                  - `simulate()`: Genera traiettoria temporale |  
| `Main.cpp` | Configura parametri orbitali e salva CSV |  

### Python (Visualizzazione)  
| File | Contenuto |  
|------|-----------|  
| `Orbita.py` | Animazione 3D con:  
  - **Linea blu**: Orbita completa  
  - **Punto rosso**: Satellite (frame-by-frame)  
  - **Linea rossa**: Traiettoria passata |  

## 🚀 **Come eseguire**  
1. **Compilazione C++**:  
   ```bash
   g++ main.cpp Orbita.cpp -o Orbita_sim
   
   ./Orbita_sim  # Genera orbita.csv
   
   python Orbita.csv #Visualizzare il satellite che gira
   ```
work in progress...
