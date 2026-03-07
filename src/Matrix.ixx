module;

#include <cstddef>
#include <stdexcept>
#include <utility>
#include <vector>

export module Matrix;

export class Matrix {
public:
    using Tp = double;
    using DataTable = std::vector<std::vector<Tp>>;

    Matrix() = default;
    Matrix(const Matrix&) = default;
    Matrix(Matrix&&) noexcept = default;
    Matrix& operator=(const Matrix&) = default;
    Matrix& operator=(Matrix&&) = default;

    Matrix(size_t rows, size_t cols)
        : _rows(rows), _cols(cols), _data(_rows) {
            for (auto& i : _data)
                i.resize(_cols);
    }

    size_t rows() const {
        return _rows;
    }

    size_t cols() const {
        return _cols;
    }

    std::pair<size_t, size_t> dim() const {
        return {_rows, _cols};
    }

    std::vector<double>& operator[](size_t row) {
        return _data[row];
    }

    const std::vector<double>& operator[](size_t row) const {
        return _data[row];
    }

    Matrix& operator+=(const Matrix& other) {
        if (dim() != other.dim())
            throw std::logic_error("Matrices have to have the same dimensions.");

        for (size_t i = 0; i < rows(); i++)
            for (size_t j = 0; j < cols(); j++)
                _data[i][j] += other._data[i][j];
        
        return *this;
    }

    Matrix& operator-=(const Matrix& other) {
        if (dim() != other.dim())
            throw std::logic_error("Matrices have to have the same dimensions.");

        for (size_t i = 0; i < rows(); i++)
            for(size_t j = 0; j < cols(); j++)
                _data[i][j] -= other._data[i][j];
        
        return *this;
    }

    Matrix& operator*=(const Tp& val) noexcept {
        for (size_t i = 0; i < rows(); i++)
            for (size_t j = 0; j < cols(); j++)
                _data[i][j] *= val;
        
        return *this;
    }

    Matrix& operator*=(const Matrix& other) {              
        *this = std::move(*this * other);
        return *this;
    }

    void transpose() {
        Matrix trsp(cols(), rows());

        for (size_t i = 0; i < rows(); i++) {
            for (size_t j = 0; j < cols(); j++)
                trsp._data[j][i] = _data[i][j];
        }
        *this = std::move(trsp);
    }

private:
    size_t _rows;
    size_t _cols;
    DataTable _data;

    friend Matrix operator*(const Matrix&, const Matrix&);
};


Matrix operator+(const Matrix& m) noexcept {
    return m;
}

Matrix operator-(const Matrix& m) {
    Matrix res = m;

    for (size_t i = 0; i < m.rows(); i++)
        for(size_t j = 0; j < m.cols(); j++)
            res[i][j] = -m[i][j];
    
    return res;
}

export Matrix operator+(const Matrix& x, const Matrix& y) {
    Matrix r = x;
    r += y;
    return r;
}

export Matrix operator-(const Matrix& x, const Matrix& y) {
    Matrix r = x;
    r -= y;
    return r;
}

export Matrix operator*(const Matrix& x, const Matrix& y) {
        if (x.cols() != y.rows())
            throw std::logic_error("");
        
        Matrix out(x.rows(), y.cols());

        for (size_t i = 0; i < out.rows(); i++)
            for (size_t j = 0; j < out.cols(); j++)
                for (size_t k = 0; k < x.rows(); k++)
                    out[i][j] += x[k][i] * y[j][k];
                
        return out;
}

export Matrix operator*(const Matrix& x, Matrix::Tp y) {
    Matrix r = x;
    r *= y;
    return r;
}

export Matrix operator*(Matrix::Tp x, const Matrix& y) {
    Matrix r = y;
    r *= x;
    return r;
}
