import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation # animazione satellite
from mpl_toolkits.mplot3d import Axes3D # 3D

# Carica i dati
data = pd.read_csv('/Users/Desktop/.../.../Orbita/data/orbita.csv')
x, y, z = data['x_km'], data['y_km'], data['z_km']

# Configura la figura 3D
fig = plt.figure(figsize=(10, 8))
ax = fig.add_subplot(111, projection='3d')

# Disegna l'orbita completa
ax.plot(x, y, z, 'b-', alpha=0.3, label="Orbita")

# Inizializza il pallino (satellite) e una linea della traiettoria passata
satellite, = ax.plot([], [], [], 'ro', markersize=8, label="Satellite")
trajectory, = ax.plot([], [], [], 'r-', alpha=0.5)

# Imposta etichette e legenda
ax.set_xlabel('x [km]') # Corretto: ax.set_xlabel()
ax.set_ylabel('y [km]') # Corretto: ax.set_ylabel()
ax.set_zlabel('z [km]') # Corretto: ax.set_zlabel()
ax.set_title('Animazione Orbita Satellitare 3D')
ax.legend()

# Funzione di inizializzazione
def init():
    satellite.set_data([], [])
    satellite.set_3d_properties([])
    trajectory.set_data([], [])
    trajectory.set_3d_properties([])
    return satellite, trajectory

# Funzione di animazione (chiamata per ogni frame)
def update(frame):
    # Aggiorna la posizione del satellite
    satellite.set_data([x[frame]], [y[frame]])
    satellite.set_3d_properties([z[frame]])
    
    # Disegna la traiettoria passata (fino al frame corrente)
    trajectory.set_data(x[:frame], y[:frame])
    trajectory.set_3d_properties(z[:frame])
    
    return satellite, trajectory

# Crea l'animazione
ani = FuncAnimation(
    fig, 
    update, 
    frames=len(x), 
    init_func=init, 
    blit=True, 
    interval=100,  # Velocità animazione (ms tra frame)
    repeat=True
)

plt.tight_layout()
plt.show()
