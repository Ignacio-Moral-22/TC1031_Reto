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

    void ordenaQuick(std::vector<T> &Q, bool (*compare)(T &a, T &b)){
        quicksort(Q, 0, Q.size()-1, *compare);
    };

    void quicksort(std::vector<T> &Q, int low, int high, bool (*compare)(T &a, T &b)){
        if(low<high){
            int pivot=partition(Q, low, high, *compare);
            quicksort(Q, low, pivot-1, *compare);
            quicksort(Q, pivot+1, high, *compare);
        }
    };

    int partition(std::vector<T> &Q, int low, int high, bool (*compare)(T &a, T &b)){
        size_t i = low-1;
        for(size_t j=low; j<high; j++){
            if((*compare)(Q.at(j), Q.at(high))){
                i++;
                swap(i, j, Q);
            }
        }
        swap(i+1, high, Q);
        return (i+1);
    };
};

   
#endif