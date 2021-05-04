#include <random>
#include "List.h"

int main()
{
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_real_distribution<double> distr1(1, 100000);
    std::uniform_real_distribution<double> distr2(1, 100000);
    std::uniform_real_distribution<double> distr3(1, 100000);
    for (;;)
    {
        List l3;
        for (int i = 0; i < 1000; i++)
        {
            Point p3(distr1(eng), distr2(eng), distr3(eng));
            l3.push_back(p3);
        }
    }
    /*
    List l1;
    Point p1(1.1,1.3,1.5);
    Point p2(32,56,4324);
    l1.push_back(p1); 
    l1.push_back(p2);
    std::vector<Point> w;
    w.push_back(p1);
    w.push_back(p2);
    List l2(w);
    std::cout << l2 << "\n";
    std::cout << std::string(20, '-') << "\n";
    try
    {
        Point p1 = l2[0];
        std::cout << p1.x << " " << p1.y << " " << p1.z << "\n";
        std::cout << std::string(20, '-') << "\n";
    }
    catch(const char* message)
    {
        std::cerr << message << std::endl;
    }
    try
    {
        Point p4 = l2.find(p1, 4);
        std::cout << p4.x << " " << p4.y << " " << p4.z << "\n";
        std::cout << std::string(20, '-') << "\n";
    }
    catch (const char* message)
    {
        std::cerr << message << std::endl;
    }
    */
}
