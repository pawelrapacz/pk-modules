module;

#include <cmath>

export module mathh:Complex;

export template<typename Tp>
class Complex {
public:
    Complex(Tp real = Tp(), Tp imag = Tp())
        : _real(real), _imag(imag) { }

    Complex& operator=(const Tp& value) noexcept {
        _real = value;
        _imag = Tp();
        return *this;
    }

    Complex(const Complex&) noexcept = default;
    Complex(Complex&&) noexcept = default;
    Complex& operator=(const Complex& other) noexcept = default;
    Complex& operator=(Complex&&) noexcept = default;

    Tp real() const noexcept {
        return _real;
    }

    Tp imag() const noexcept {
        return _imag;
    }

    void real(Tp value) noexcept {
        _real = value;
    }

    void imag(Tp value) noexcept {
        _imag = value;
    }

    Complex& operator+=(const Tp& value) {
        _real += value;
        return *this;
    }

    Complex& operator-=(const Tp& value) {
        _real -= value;
        return *this;
    }

    Complex& operator*=(const Tp& value) {
        _real *= value;
        _imag *= value;
        return *this;
    }

    Complex& operator/=(const Tp& value) {
        _real /= value;
        _imag /= value;
        return *this;
    }

    Complex& operator+=(const Complex& other) {
        _real += other.real();
        _imag += other.imag();
        return *this;
    }

    Complex& operator-=(const Complex& other) {
        _real -= other.real();
        _imag -= other.imag();
        return *this;
    }

    Complex& operator*=(const Complex& other) {
        Tp re = real() * other.real() - imag() * other.imag();
        _imag = real() * other.imag() + imag() * other.real();
        _real = re;
        return *this;
    }

    Complex& operator/=(const Complex& other) {
        Tp d = other.real() * other.real() + other.imag() * other.imag();
        Tp re = (real() * other.real() + imag() * other.imag()) / d;
        _imag = (imag() * other.real() - real() * other.imag()) / d;
        _real = re;
        return *this;
    }

    
private:
    Tp _real;
    Tp _imag;
};

export template<typename Tp>
Complex<Tp> operator+(const Complex<Tp>& value) {
    return value;
}

export template<typename Tp>
Complex<Tp> operator-(const Complex<Tp>& value) {
    return Complex(-value.real(), -value.imag());
}

export template<typename Tp>
Complex<Tp> operator+(const Complex<Tp>& x, const Complex<Tp>& y) {
    Complex<Tp> r = x;
    r += y;
    return r;
}

export template<typename Tp>
Complex<Tp> operator+(const Complex<Tp>& x, const Tp& y) {
    Complex<Tp> r = x;
    r += y;
    return r;
}

export template<typename Tp>
Complex<Tp> operator+(const Tp& x, const Complex<Tp>& y) {
    Complex<Tp> r = y;
    r += x;
    return r;
}


export {

    template<typename Tp>
    Complex<Tp> operator-(const Complex<Tp>& x, const Complex<Tp>& y) {
        Complex<Tp> r = x;
        r -= y;
        return r;
    }

    template<typename Tp>
    Complex<Tp> operator-(const Complex<Tp>& x, const Tp& y) {
        Complex<Tp> r = x;
        r -= y;
        return r;
    }

    template<typename Tp>
    Complex<Tp> operator-(const Tp& x, const Complex<Tp>& y) {
        Complex<Tp> r = y;
        r -= x;
        return r;
    }

}

export template<typename Tp>
Complex<Tp> operator*(const Complex<Tp>& x, const Complex<Tp>& y) {
    Complex<Tp> r = x;
    r *= y;
    return r;
}

export template<typename Tp>
Complex<Tp> operator*(const Complex<Tp>& x, const Tp& y) {
    Complex<Tp> r = x;
    r *= y;
    return r;
}

export template<typename Tp>
Complex<Tp> operator*(const Tp& x, const Complex<Tp>& y) {
    Complex<Tp> r = y;
    r *= x;
    return r;
}

export template<typename Tp>
Complex<Tp> operator/(const Complex<Tp>& x, const Complex<Tp>& y) {
    Complex<Tp> r = x;
    r /= y;
    return r;
}

export template<typename Tp>
Complex<Tp> operator/(const Complex<Tp>& x, const Tp& y) {
    Complex<Tp> r = x;
    r /= y;
    return r;
}

export template<typename Tp>
Complex<Tp> operator/(const Tp& x, const Complex<Tp>& y) {
    Complex<Tp> r = x;
    r /= y;
    return r;
}

export {
    template<typename Tp>
    bool operator==(const Complex<Tp>& x, const Complex<Tp>& y) {
        return x.real() == y.real() && x.imag() == y.imag();
    }

    template<typename Tp>
    bool operator==(const Tp& x, const Complex<Tp>& y) {
        return x == y.real() && Tp() == y.imag();
    }

    template<typename Tp>
    bool operator==(const Complex<Tp>& x, const Tp& y) {
        return x.real() == y && x.imag() == Tp();
    }


    template<typename Tp>
    bool operator!=(const Complex<Tp>& x, const Complex<Tp>& y) {
        return x.real() != y.real() || x.imag() != y.imag();
    }

    template<typename Tp>
    bool operator!=(const Tp& x, const Complex<Tp>& y) {
        return x != y.real() || Tp() != y.imag();
    }

    template<typename Tp>
    bool operator!=(const Complex<Tp>& x, const Tp& y) {
        return x.real() != y || x.imag() != Tp();
    }
}

export template<typename Tp>
Tp real(const Complex<Tp>& value) {
    return value.real();
}

export template<typename Tp>
Tp imag(const Complex<Tp>& value) {
    return value.imag();
}

export template<typename Tp>
Tp abs(const Complex<Tp>& value) {
    return std::hypot(value.real(), value.imag());
}

export template<typename Tp>
Tp arg(const Complex<Tp>& value) {
    return std::atan2(value.imag(), value.real());
}