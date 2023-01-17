// task 7.7.1 20230113.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <stdexcept>
#include"IntegerArray.h"

int main()
{
    try 
    {
        IntegerArray testArray1(10);
        testArray1.print();

        for (auto i = 0; i < testArray1.size(); ++i)
        {
            testArray1[i] = i + 1;
        }
        testArray1.print();

        IntegerArray testArray2(testArray1);
        testArray2.print();

        IntegerArray testArray3(1);
        testArray3 = testArray2;
        testArray3.print();

        testArray1.resize(15);
        testArray1.print();

        testArray1.resize(8);
        testArray1.print();

        testArray1.remove(0);
        testArray1.print();

        testArray1.push_back(777);
        testArray1.print();

        testArray1.push_front(111);
        testArray1.print();

        testArray1.pop_back();
        testArray1.print();

        testArray1.pop_front();
        testArray1.print();

        std::cout << "index elelement equals 777 = " << testArray1.find(777) << std::endl;
        std::cout << "index elelement equals 7 = " << testArray1.find(7) << std::endl;

        testArray1.erase();
        testArray1.print();
    }      

    catch (bad_range excp)
    {
        std::cerr << excp.what() << std::endl;
    }
    catch (bad_length excp)
    {
        std::cerr << excp.what() << std::endl;
    }

    return 0;
}