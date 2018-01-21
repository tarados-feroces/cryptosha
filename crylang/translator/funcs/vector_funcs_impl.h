

template<class T>
void funcs::insert_one_elem(std::vector<T> &vector, size_t pos, T element) {

    if(pos > vector.size())
        throw std::invalid_argument("pos is too big");

    if (pos == vector.size()) {
        vector.push_back(element);
        return;
    }

    vector.push_back(vector[vector.size() - 1]);

    for (size_t i = vector.size() - 2; i > pos; --i) {
        vector[i] = vector[i - 1];
    }

    vector[pos] = element;
}


template<class T>
void funcs::erase(std::vector<T>& vector, size_t pos) {

    if(pos >= vector.size())
        throw std::invalid_argument("pos is too big");

    if (vector.size() <= 1) {
        vector.clear();
        return;
    }

    if (pos == vector.size() - 1) {
        vector.pop_back();
        return;
    }

    for (size_t i = pos; i < vector.size() - 1; ++i)
        vector[i] = vector[i + 1];

    vector.pop_back();

}


template<class T>
void funcs::insert(std::vector<T>& vector, size_t pos, std::vector<T>& insert_vector) {
    for (auto &element : insert_vector) {
        insert_one_elem(vector, pos++, element);
    }
}


template <class T, class L>
auto funcs::find(std::vector<T>& vector, L element){

    auto it = vector.begin();
    for(; it != vector.end(); ++it) {
        if(*it == element)
            return it;
    }

    return it;
}








