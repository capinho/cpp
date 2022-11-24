// Change me instead
// All occurences of XXX need to be replaced with
// something more meaningful

void my_swap(auto &a, auto &b){
    auto temp = a;
    a = b;
    b = temp;
}


template<typename iterator, class COMP>
void my_selection_sort( iterator begin, iterator end, COMP comp) {
    for (iterator it = begin; it != end; ++it) {
        iterator min = it;
        for (iterator j = it; j != end; ++j) {
            if (comp(*j, *min)) {
                min = j;
            }
        }
        my_swap(*it, *min);
    }
}
