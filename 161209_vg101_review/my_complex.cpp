#include <iostream>

class my_complex
{
  public:
    double real;
    double imag;

  public:
    my_complex(double real_i = 0, double imag_i = 0)
    {
        real = real_i;
        imag = imag_i;
    }

    my_complex operator+(const my_complex &b) const
    {
        my_complex temp;
        temp.real = this->real + b.real;
        temp.imag = this->imag + b.imag;
        return temp;
    }
    void show()
    {
        std::cout << real << "+" << imag << std::endl;
    }

    my_complex operator-(const my_complex &b) const
    {
        my_complex temp;
        temp.real = this->real - b.real;
        temp.imag = this->imag - b.imag;
        return temp;
    }
    my_complex operator*(const my_complex &b) const
    {
        my_complex temp;
        temp.real = this->real * b.real - this->imag * b.imag;
        temp.imag = this->real * b.imag + this->imag * b.real;
        return temp;
    }
}

;

int main()
{
    my_complex m1(1, 2);
    my_complex m2(2, 3);

    my_complex m3, m4;

    m3 = m1 * m2;
    m4 = m1 - m2;

    m3.show();
    m4.show();
    std::cin.get();
}