module;

#include <cstddef>;

export module Matrix;

export template<typename Tp = double, size_t Rows, size_t Cols>
class Matrix {
    using DataTab = Tp[Rows][Cols];
public:

    Matrix(DataTab m = DataTab())
        : _data(m) { }

    Tp* operator[](size_t row) {
        return _data[row];
    }

    const Tp* operator[](size_t row) const {
        return _data[row];
    }

    Matrix& operator*=(const Tp& val) {
        for (size_t i = 0; i < Rows; i++)
            for (size_t j = 0; j < Cols; j++)
                _data[i][j] *= val;
        
        return *this;
    }

    Matrix& operator+=(const Matrix& other) {
        for (size_t i = 0; i < Rows; i++)
            for (size_t j = 0; j < Cols; j++)
                _data[i][j] += other._data[i][j];
        
        return *this;
    }

    Matrix& operator-=(const Matrix& other) {
        for (size_t i = 0; i < Rows; i++)
            for(size_t j = 0; j < Cols; j++)
                _data[i][j] -= other._data[i][j];
        
        return *this;
    }

    Matrix operator+() const {
        return *this;
    }

    Matrix operator-() const {
        Matrix res = *this;

        for (size_t i = 0; i < Rows; i++)
            for(size_t j = 0; j < Cols; j++)
                _data[i][j] = -_data[i][j];
        
        return res;
    }

private:
    DataTab _data;

    friend Matrix<Tp, Cols, Rows> transpose(const Matrix<Tp, Rows, Cols>&); 
};


export template<typename Tp, size_t Rows, size_t Cols>
Matrix<Tp, Cols, Rows> transpose(const Matrix<Tp, Rows, Cols>& mtx) {
    Matrix<Tp, Cols, Rows> trns;

    for (size_t i = 0; i < Rows; i++)
        for (size_t j = 0; j < Cols; j++)
            trns._data[j][i] = mtx._data[i][j];
    
    return trns;
}

export template<typename Tp, size_t Rows, size_t Comn, size_t Cols>
Matrix<Tp, Rows, Cols> operator*(const Matrix<Tp, Rows, Comn>& x, const Matrix<Tp, Comn, Cols>& y) {
    Matrix<Tp, Cols, Rows> out();

    for (size_t i = 0; i < Rows; i++)
        for (size_t j = 0; j < Cols; j++)
            for (size_t k = 0; k < Comn; k++)
                out[i][j] += x[i][k] * x[k][j];
            
    return out;
}

export template<typename Tp, size_t Rows, size_t Cols>
Matrix<Tp, Rows, Cols> operator*(const Matrix<Tp, Rows, Cols>& x, const Tp& y) {
    Matrix<Tp, Rows, Cols> out = x;
    out *= y;
    return out;
}

export template<typename Tp, size_t Rows, size_t Cols>
Matrix<Tp, Rows, Cols> operator*(const Tp& x, const Matrix<Tp, Rows, Cols>& y) {
    return operator*(y, x);
}

export template<typename Tp, size_t Rows size_t Cols>
Matrix<Tp, Rows, Cols> operator+(const Matrix<Tp, Rows, Cols>& x, const Matrix<Tp, Rows, Cols>& y) {
    Matrix<Tp, Cols, Rows> out = x;
    out += y;
    return out;
}

export template<typename Tp, size_t Rows size_t Cols>
Matrix<Tp, Rows, Cols> operator-(const Matrix<Tp, Rows, Cols>& x, const Matrix<Tp, Rows, Cols>& y) {
    Matrix<Tp, Cols, Rows> out = x;
    out -= y;
    return out;
}