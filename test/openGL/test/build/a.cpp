#include <iostream>

int aw = 0;

void a(int &b)
{
    b = 10;
}
int main()
{
    a(aw);
    std::cout << aw;
    return 0;
}
