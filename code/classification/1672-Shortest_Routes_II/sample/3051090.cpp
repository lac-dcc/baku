#include<iostream>
#include<string>
#include<vector>
#include<memory>
#include<limits>
 
struct index2d_t {
    size_t row;
    size_t column;
};
 
template<typename T>
class matrix final{
public:
    matrix(size_t rows, size_t columns, T default_value):
    _rows(rows),
    _columns(columns),
    data(std::make_unique<T[]>(rows * columns)) {
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < columns; j++) {
                (*this)[{i, j}] = default_value;
            }
        }
    }
    
    T& operator[](const index2d_t idx) {
        return this->data[idx.row * this->_columns + idx.column];
    }
    
    const T operator[](const index2d_t idx) const {
        return this->data[idx.row * this->_columns + idx.column];
    }
    
    size_t columns() const {
        return this->_columns;
    }
    
    size_t rows() const {
        return this->_rows;
    }
    
private:
    std::unique_ptr<T[]> data;
    size_t _columns;
    size_t _rows;
};
 
 
void relax_floyd(matrix<int64_t> &d) {
    for (size_t k = 0; k < d.rows(); k++) {
        for (size_t i = 0; i < d.rows(); i++) {            
            for (size_t j = 0; j < d.rows(); j++) {
                if (d[{i, k}] == -1 || d[{k, j}] == -1) continue;
                auto new_distance = d[{i, k}] + d[{k, j}];
                if (d[{i, j}] == -1 || d[{i, j}] > new_distance) {
                    d[{i, j}] = new_distance;
                }
            }
        }   
    }
}
 
int main(){
    size_t n, m, q;
    std::cin >> n >> m >> q;
    matrix<int64_t> d(n, n, -1);
    for (size_t i = 0; i < n; i++) {
        d[{i, i}] = 0;
    }
    for (size_t i = 0; i < m; i++) {
        size_t from, to;
        int64_t len;
        std::cin >> from >> to >> len;
        from--, to--;
        if (d[{from, to}]  == -1 || d[{from, to}] > len) {
            d[{from, to}] = len;
            d[{to, from}] = len;
        }
    }
    relax_floyd(d);
    for (size_t i = 0; i < q; i++) {
        size_t from, to;
        std::cin >> from >> to;
        from--, to--;
        std::cout << d[{from, to}]  << std::endl;
    }
    return 0;
}
