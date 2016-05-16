#include "matrix.h"
#include <cstdio>
Matrix::Matrix (int h, int w)
{
    height = h;
    width = w;

    M = new double*[h];
    for (int i=0; i<h; i++)
    {
        M[i] = new double[width];
        for (int j=0; j<w; j++)
            M[i][j] = 0;
            
    }
}
