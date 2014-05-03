#ifndef MATRIX_H
#define MATRIX_H

/*
    It was created only to avoid passing a double** as a parameter for the scenario
*/
class Matrix
{
    public:
        double** M;
        int height, width;

        Matrix (int h, int w);
        
        Matrix & operator = (const Matrix & m)
        {
            if(this != & m)
            {
                M       = m.M;
                height  = m.height;
                width   = m.width;
            }
            return *this;
        }
};

#endif
