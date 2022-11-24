// Do not change
#include <iostream>
#include <fstream>

#include <string>

#include <list>
#include <vector>
#include <deque>
#include <tuple>

#include "my_sort.hpp"



template <class type, class cont>
void read_file_to_cont(std::ifstream &fi, cont& co)
{
  type myelm;
    if constexpr (std::is_same_v<char, type>) {
        while (fi.get(myelm)) {
            co.push_back(myelm);
            fi.get(myelm);
        }
    }
    else {
        while (fi >> myelm) {
            co.push_back(myelm);
        }
    }

}



template <class type, class cont>
void read_and_sort(std::ifstream& fi, std::ofstream& fo) {
    cont container = {};
    read_file_to_cont<type, cont>(fi, container);
    if constexpr (std::is_integral_v<type>) {
        my_selection_sort(container.begin(), container.end(), [](type l, type r)->bool {
            return std::make_tuple(l%2, l) < std::make_tuple(r%2, r);
        });
    }
    else {
        my_selection_sort(container.begin(), container.end(), [](type l, type r)->bool { return l > r;});

    }
    for (type &myelm : container)
        fo << myelm << "\n";
}



template <class type>
void read_and_sort_decide_container(std::ifstream& fi, std::ofstream& fo) {
    char Line2;
    fi >> Line2;
    fo << Line2 << std::endl;
    switch(Line2)
    {
        case 'l':
            read_and_sort<type, std::list<type>>(fi, fo);
            break;
        case 'v':
            read_and_sort<type, std::vector<type>>(fi, fo);
            break;
        case 'd':
            read_and_sort<type, std::deque<type>>(fi, fo);
            break;
    }
}



void read_and_sort_decide_valuetype(std::ifstream& fi, std::ofstream& fo) {
    char Line1;
    fi >> Line1;
    fo << Line1 << std::endl;
    switch(Line1)
    {
        case 'i':
            read_and_sort_decide_container<int>(fi, fo);
            break;
        case 'u':
            read_and_sort_decide_container<unsigned >(fi, fo);
            break;
        case 'f':
            read_and_sort_decide_container<float>(fi, fo);
            break;
        case 'd':
            read_and_sort_decide_container<double>(fi, fo);
            break;
        case 'c':
            read_and_sort_decide_container<char>(fi, fo);
            break;
        case 's':
            read_and_sort_decide_container<std::string>(fi, fo);
            break;
    }
}



