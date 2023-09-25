import numpy as np
import matplotlib
matplotlib.use("TkAgg")

import matplotlib.pyplot as plt

#Definindo o tamanho dos arrays para a plotagem

tamanhos_arrays = np.array([62500, 125000, 250000, 375000])\

tempos_quick = np.array([0.065353, 0.248581, 0.973069, 2.130369])

tempos_select = np.array([5.840493, 23.35706, 72.821701, 187.770264])

#Escalando para baixo o array de tamanhos para facilitar a visualização

tamanhos_arrays = tamanhos_arrays/1000;

#Plotando

plt.plot(tamanhos_arrays,tempos_quick, label = "QuickSort")
plt.plot(tamanhos_arrays,tempos_select, label = "SelectionSort")

# Adicionar títulos e rótulos

plt.title('Comparação de Algoritmos de Ordenação')
plt.ylabel('Tempo de Execução (s)')
plt.xlabel('Tamanho do Array (mil)')


# Adicionar a legenda
plt.legend()

# Mostrar o gráfico
plt.show()