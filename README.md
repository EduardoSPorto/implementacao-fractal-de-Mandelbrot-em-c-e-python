# Implementacao de Fractal de Mandelbrot em C e Python
* <b>Codigos fonte</b>
    * fractal_mandel.c
        * Implementa o serviço de cálculo para a realização do algoritmo de Mandelbrot.
        * Compila para uma biblioteca compartilhada (.so).
    * fractal_mandel.py
        * Executa o programa em C, gera as imagens e fornece a interface do usuário.
        * Utiliza a biblioteca compartilhada para obter os resultados do cálculo.
    * Makefile
        * Configura as flags necessárias e compila o código em C.
        * Prepara o ambiente para execução.

* <b>Demais arquivos do repositório</b>
    * Documentação da implementação
        * Apresenta o programa desenvolvido.
        * Cita as funcionalidades programadas em cada linguagem.
        * Explica como a comunicação entre elas foi implementada.

* <b>Bibiliotecas Python que necessitam de instalação separada</b>
    * Numpy e MatPlotLib, responsáveis pela interface da aplicação.

* <b>Compilar o programa</b>
    * Execute "make", "make run".
    * ou manualmente
        * gcc -shared -fPIC -o fractal_mandel.so fractal_mandel.c
        * python fractal_mandel.py
