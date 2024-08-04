# Implementacao de Fractal de Mandelbrot em C e Python
* Codigos Fonte
    * fractal_mandel.c
        * Implementa o serviço de cálculo para a realização do algoritmo de Mandelbrot.
        * Compila para uma biblioteca compartilhada (.so).
    * fractal_mandel.py
        * Executa o programa em C, gera as imagens e fornece a interface do usuário.
        * Utiliza a biblioteca compartilhada para obter os resultados do cálculo.

* Bibiliotecas python que necessitam intalação separada: 
    * numpy e matplotlib para tratar a execução da interface.

* Copilar o programa
    * Execute "make", "make run"
    * ou manualemnte
        * gcc -shared -fPIC -o fractal_mandel.so fractal_mandel.c
        * python fractal_mandel.py