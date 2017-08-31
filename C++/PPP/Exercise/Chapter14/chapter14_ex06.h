#pragma once
template<class T>
class Number {
public:
    Number() : val { T { } } {}
    Number(T v) : val { v } {}

    Number<T>& operator=(const Number<T>& a);
    Number<T> operator+(const Number<T>& a);
    Number<T> operator-(const Number<T>& a);
    Number<T> operator*(const Number<T>& a);
    Number<T> operator/(const Number<T>& a);
    Number<T> operator%(const Number<T>& a);

    T get() const { return val; }
private:
    T val;
};

template<typename T>
Number<T>& Number<T>::operator=(const Number<T>& a)
{
    val = a.val;
    return *this;
}

template<typename T>
Number<T> Number<T>::operator+(const Number<T>& a)
{
    return Number<T>(val+a.val);
}

template<typename T>
Number<T> Number<T>::operator-(const Number<T>& a)
{
    return Number<T>(val-a.val);
}

template<typename T>
Number<T> Number<T>::operator*(const Number<T>& a)
{
    return Number<T>(val*a.val);
}

template<typename T>
Number<T> Number<T>::operator/(const Number<T>& a)
{
    return Number<T>(val/a.val);
}

template<typename T>
Number<T> Number<T>::operator%(const Number<T>& a)
{
    return Number<T>(val%a.val);
}

template<typename T>
ostream& operator<<(ostream& os, const Number<T>& a)
{
    os << a.get();
    return os;
}

template<typename T>
istream& operator>>(istream& is, Number<T> &a)
{
    T v;
    is >> v;
    a = v;
    return is;
}