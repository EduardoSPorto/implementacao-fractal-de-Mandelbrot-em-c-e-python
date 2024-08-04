import numpy as np
import matplotlib.pyplot as plt # Para visualização gráfica
import ctypes # Para interagir com bibliotecas compartilhadas em C


# Carrega a biblioteca compartilhada compilada a partir do código C
loaded_library = ctypes.CDLL('./fractal_mandel.so')

# O C types necessita definição dos tipos de argumentos da função 'main' na biblioteca C
loaded_library.main.argtypes = (ctypes.c_int, ctypes.c_int, ctypes.c_int, ctypes.POINTER(ctypes.c_double))

def mandelbrot_c_program(line, colum, limit_of_iterations):
    # Cria um array com largura e altura especificadas, preenchido com zeros, do tipo float64 (equivalente a double em C)
    result = np.zeros((colum, line), dtype=np.float64)
    # Converte o array numpy para um ponteiro de double em C usando ctypes
    result_ptr = result.ctypes.data_as(ctypes.POINTER(ctypes.c_double))
    # Chama a função 'mandelbrot' na biblioteca C, passando os parâmetros e o ponteiro para o array
    loaded_library.main(line, colum, limit_of_iterations, result_ptr)
    #results é a array numpy com os calculos
    return result

def display_fractal(image):
    plt.imshow(image, cmap='magma', extent=(-3, 2, -2, 2))
    plt.colorbar()
    plt.show()

if __name__ == "__main__":
    # Define a largura, altura e número máximo de iterações para o cálculo do fractal
    line, colum, limit_of_iterations = 800, 600, 1000
    #Chama a funções python para invocar a função em C
    fractal = mandelbrot_c_program(line, colum, limit_of_iterations)
    display_fractal(fractal)