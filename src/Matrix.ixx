export module Matrix;

import <stdexcept>;
import <utility>;
import <vector>;

export class Matrix {
public:
    using Tp = double;
    using DataTable = std::vector<Tp>;

    Matrix() = default;
    Matrix(const Matrix&) = default;
    Matrix(Matrix&&) noexcept = default;
    Matrix& operator=(const Matrix&) = default;
    Matrix& operator=(Matrix&&) = default;

    Matrix(size_t rows, size_t cols)
        : _rows(rows), _cols(cols), _data(_rows * _cols) { }

    Matrix(std::pair<size_t, size_t> dim)
        : _rows(dim.first), _cols(dim.second), _data(_rows * _cols) { }

    template<size_t Rows, size_t Cols>
    Matrix(const Tp (&m)[Rows][Cols]) 
        : _rows(Rows), _cols(Cols), _data(_rows * _cols) {
            for (size_t i = 0; i < Rows; i++)
                for (size_t j = 0; j < Cols; j++)
                    get(i, j) = m[i][j];
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

    Tp& get(size_t row, size_t col) {
        return _data[row * _cols + col];
    }

    const Tp& get(size_t row, size_t col) const {
        return _data[row * _cols + col];
    }

    Matrix& operator+=(const Matrix& other) {
        if (dim() != other.dim())
            throw std::logic_error("The matrices must have the same dimensions.");

        for (size_t i = 0; i < rows(); i++)
            for (size_t j = 0; j < cols(); j++)
                get(i, j) += other.get(i, j);
        
        return *this;
    }

    Matrix& operator-=(const Matrix& other) {
        if (dim() != other.dim())
            throw std::logic_error("The matrices must have the same dimensions.");

        for (size_t i = 0; i < rows(); i++)
            for(size_t j = 0; j < cols(); j++)
                get(i, j) -= other.get(i, j);
        
        return *this;
    }

    Matrix& operator*=(const Tp& val) noexcept {
        for (size_t i = 0; i < rows(); i++)
            for (size_t j = 0; j < cols(); j++)
                get(i, j) *= val;
        
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
                trsp.get(j, i) = get(i, j);
        }
        *this = std::move(trsp);
    }

private:
    size_t _rows;
    size_t _cols;
    DataTable _data;

    friend Matrix operator*(const Matrix&, const Matrix&);
};


export Matrix operator+(const Matrix& m) noexcept {
    return m;
}

export Matrix operator-(const Matrix& m) {
    Matrix res = m;

    for (size_t i = 0; i < m.rows(); i++)
        for(size_t j = 0; j < m.cols(); j++)
            res.get(i, j) = -m.get(i, j);
    
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
            throw std::logic_error("The number of colums of matrix X must equal to the number of rows of matrix Y.");
        
        Matrix out(x.rows(), y.cols());

        for (size_t i = 0; i < out.rows(); i++)
            for (size_t j = 0; j < out.cols(); j++)
                for (size_t k = 0; k < x.rows(); k++)
                    out.get(i, j) += x.get(i, k) * y.get(k, j);
                
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

export bool operator==(const Matrix& x, const Matrix& y) {
    if (x.dim() != y.dim())
        return false;
    
    for (size_t i = 0; i < x.rows(); i++)
        for (size_t j = 0; j < x.cols(); j++)
            if (x.get(i, j) != y.get(i, j)) return false;

    return true;
}

export bool operator!=(const Matrix& x, const Matrix& y) {
    return !(x == y);
}
