// Change me instead
// All occurences of XXX need to be replaced with
// something more meaningful


auto my_min_element(auto first, auto last)
{
    if (first == last)
        return last;
    auto min = first;
    ++first;
 
    for (; first != last; ++first)
        if (*first < *min)
            min = first;
    return min;
}

void my_swap(auto &a, auto &b){
    auto temp = a;
    a = b;
    b = temp;
}

template<typename iterator>
void my_selection_sort(iterator begin, iterator end){
    for(auto it = begin; it != end; ++it) {
        my_swap(*it, *my_min_element(it, end));
    }
}


