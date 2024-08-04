/**  mandel.c   by Eric R. Weeks   written 9-28-96
 **  weeks@physics.emory.edu
 **  http://www.physics.emory.edu/~weeks/
 **  
 **  This program is public domain, but this header must be left intact
 **  and unchanged.
 **  
 **  to compile:  cc -o mand mandel.c
 ** 
 **/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Baseadp no codigo:https://physics.emory.edu/faculty/weeks/software/mandel.c

void main(int width, int height, int max_iter, double* information) {
    double x, xx, y, cx, cy;
    int iteration;
    double magnify = 1.0;
    int hxres = width;
    int hyres = height;

    // Loop sobre cada pixel da imagem
    for (int hy = 0; hy < hyres; hy++) {
        for (int hx = 0; hx < hxres; hx++) {
            // Calcula as coordenadas complexas correspondentes ao pixel (hx, hy)
            cx = (((float)hx) / ((float)hxres) - 0.5) / magnify * 3.0 - 0.7;
            cy = (((float)hy) / ((float)hyres) - 0.5) / magnify * 3.0;
            x = 0.0; y = 0.0;
            // Itera para determinar se o ponto (cx, cy) pertence ao conjunto de Mandelbrot
            for (iteration = 1; iteration < max_iter; iteration++) {
                xx = x * x - y * y + cx;
                y = 2.0 * x * y + cy;
                x = xx;
                // Se a magnitude do número complexo (x, y) excede 100, considera o ponto fora do conjunto
                if (x * x + y * y > 100.0) {
                    iteration = 999999; // Marca o ponto como fora do conjunto para evitar mais iterações
                    break;
                }
            }
            // Diferentemente do codigo que baseia-se não exibe diretamente
            // Quer apenas dados brutos armazenados em information, para serem exibidos pelo programa em python

            if (iteration < 99999) {
                information[hy * hxres + hx] = 1.0;// 1.0 indica que o ponto pertence ao conjunto de Mandelbrot
            } else {
                information[hy * hxres + hx] = 0.0;//0.0 indica que o ponto não pertence ao conjunto
            }
        }
    }
}