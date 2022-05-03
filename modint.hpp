//
// Created by izurina (Twitter : @izrn_yukikaze) on 2022/05/01.
//


#ifndef MODINT_HPP
#define MODINT_HPP

#include <iostream>

template<int mod> class ModInt {
public:
    // Constractor definition
    ModInt(long long v) noexcept : val(v%mod) {
        if(val < 0) val += mod;
    }

    // Operator overriding
    constexpr ModInt operator+(const ModInt& x) const {return ModInt(*this)+=x;}
    constexpr ModInt operator-(const ModInt& x) const {return ModInt(*this)-=x;}
    constexpr ModInt operator*(const ModInt& x) const {return ModInt(*this)*=x;}
    constexpr ModInt operator/(const ModInt& x) const {return ModInt(*this)/=x;}
    constexpr ModInt& operator+=(const ModInt& x) {
        val += x.val;
        if (val > mod) val -= mod;
        return *this;
    }
    constexpr ModInt& operator-=(const ModInt& x) {
        val -= x.val;
        if (val < 0) val += mod;
        return *this;
    }
    constexpr ModInt& operator*=(const ModInt& x) {
        val *= x.val;
        val %= mod;
        if(val < 0) val += mod;
        return *this;
    }
    constexpr ModInt& operator/=(const ModInt& x) {
        long long a = mod, b = x.val;
        long long s = 1, t = 0, ns = 0, nt = 1;
        while (a % b != 0) {
            int q = a / b;
            int r = a % b;
            int tmps = s - q * ns;
            int tmpt = t - q * nt;

            a = b;
            b = r;
            s = ns;
            t = nt;
            ns = tmps;
            nt = tmpt;
        }
        val = val * nt % mod;
        if (val < 0) val += mod;
        return *this;
    }
    friend constexpr std::ostream& operator<<(std::ostream &o, const ModInt<mod>& x) {
        return o << x.val;
    }


public:
    long long val = 0;
};

#endif //MODINT_HPP
