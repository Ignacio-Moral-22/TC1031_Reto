#ifndef sorter_hpp
#define sorter_hpp

#include <vector>
#include <iostream>

template <typename T>
class Sorter {
public:
    Sorter() {};
    ~Sorter() {};

    void swap(size_t i, size_t j, std::vector<T> &arr)
    {
        T aux = arr.at(i);
        arr.at(i) = arr.at(j);
        arr.at(j) = aux;
    };

    void selectionSort(std::vector<T> &arr, bool (*compare)(T &a, T &b))
    {
        for (size_t i = 0; i < arr.size()-1; i++)
        {
            size_t minimum = i;
            for (size_t j = i + 1; j < arr.size(); j++)
            {
                if ((*compare)(arr[j], arr[minimum]))
                    minimum = j;
            }
            swap(i, minimum, arr);
        }
    };
};



#endif