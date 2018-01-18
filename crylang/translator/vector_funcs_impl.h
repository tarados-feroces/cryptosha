//#include "vector_funcs.h"


template<class T>
void funcs::insert_one_elem(std::vector<T> &vector, int pos, T &element) {

    if (pos == vector.size()) {
        vector.push_back(element);
        return;
    }

    vector.push_back(vector[vector.size() - 1]);

    for (int i = vector.size() - 2; i > pos; --i) {
        vector[i] = vector[i - 1];
    }

    vector[pos] = element;
}


template<class T>
void funcs::erase(std::vector<T> &vector, int pos) {

    if (vector.size() <= 1) {
        vector.clear();
        return;
    }

    if (pos == vector.size() - 1) {
        vector.pop_back();
        return;
    }

    for (int i = pos; i < vector.size() - 1; ++i)
        vector[i] = vector[i + 1];

    vector.pop_back();

}


template<class T>
void funcs::insert(std::vector<T> &vector, int pos, std::vector<T> &insert_vector) {
    for (auto &element : insert_vector) {
        insert_one_elem(vector, pos++, element);
    }
}


//void funcs::lol() {
//    std::cout << "jope" << std::endl;
//}

