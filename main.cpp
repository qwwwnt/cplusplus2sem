#include <iostream>
#include <numeric>

class Drob {
private:
    int num ;
    int denom ;
public:
    Drob() : num(0), denom(1) {}

    Drob(const int &chil) : num(chil), denom(1) {}

    Drob(const int &num, const int &denom) : num(num), denom(denom) {
    }

    const int &getNum() const { return num; }

    const int &getDenom() const { return denom; }

    Drob(const Drob &drob) : num(drob.num), denom(drob.denom) {}

    friend std::ostream &operator<<(std::ostream &stream, const Drob &fraction);

    friend std::istream &operator>>(std::istream &in, const Drob &f);

    Drob getRed() const {
        int gd = std::gcd(getNum(), getDenom());
        int num = getNum() / gd;
        int denom = getDenom() / gd;
        if (denom < 0) {
            num = -num;
            denom = -denom;
        }
        return Drob(num, denom);
    }

    Drob &operator=(Drob const &b) {
        num = b.getNum();
        denom = b.getDenom();
        return *this;
    }

    Drob &operator+=(Drob const &b) {
        num = b.getNum() * denom + b.getDenom() * num;
        denom = b.getDenom() * denom;
        return *this;
    }

    Drob &operator-=(Drob const &b) {
        num = num * b.getDenom() - denom * b.getNum();
        denom = b.getDenom() * denom;
        return *this;
    }

    Drob &operator/=(Drob const &b) {
        num *= b.getDenom();
        denom *= b.getNum();
        return *this;
    }

    Drob &operator*=(Drob const &b) {
        num = b.getNum() * num;
        denom = b.getDenom() * denom;
        return *this;
    }

};

Drob operator+(const Drob &a, const Drob &b) {
    return Drob(a.getNum() * b.getDenom() +
                b.getNum() * a.getDenom(),
                a.getDenom() * b.getDenom());
}

Drob operator+(const Drob &a, const int &b) {
    return Drob(a.getNum() +
                b * a.getDenom(),
                a.getDenom() );
}

Drob operator-(const Drob &a, const Drob &b) {
    return Drob(a.getNum() * b.getDenom() -
                b.getNum() * a.getDenom(),
                a.getDenom() * b.getDenom());
}

Drob operator-(const Drob &a, const int &b) {
    return Drob(a.getNum()  -
                b * a.getDenom(),
                a.getDenom());
}

Drob operator-(const Drob &a) {
    return Drob(-a.getNum(), a.getDenom());
}

Drob operator*(const Drob &a, const Drob &b) {
    return Drob(a.getNum() * b.getNum(),
                a.getDenom() * b.getDenom());
}

Drob operator*(const Drob &a, const int &b) {
    return Drob(a.getNum() * b,
                a.getDenom()) ;
}

Drob operator/(const Drob &a, const Drob &b) {
    return Drob(a.getNum() * b.getDenom(),
                a.getDenom() * b.getNum());
}

Drob operator/(const Drob &a, const int &b) {
    return Drob(a.getNum() ,
                a.getDenom() * b);
}

std::ostream &operator<<(std::ostream &stream, const Drob &fraction) {
    Drob red = fraction.getRed();
    return stream << red.getNum() << "/" << red.getDenom();
}

std::istream &operator>>(std::istream &in, const Drob &f) {
    char c;
    in >> f.num;
    in >> c;
    in >> f.denom;
    return in;
}


int main() {
    //Drob a;
    //std::cin >> a;
    //std::cout << a;
    std::cout << Drob(2, 3) * 4 << std::endl;
    std::cout << (Drob(5)) << std::endl;
    std::cout << (Drob(2, 4) + Drob(2, 4)) << std::endl;
    std::cout << (Drob(1, 4) -= Drob(3, 2)) << std::endl;
    std::cout << -Drob(5, 4) << std::endl;
    std::cout << (Drob(5, 7) /= Drob(7, 9)) << std::endl;
    std::cout << (Drob(5, 7) *= Drob(7, 9)) << std::endl;
    std::cout << (Drob(5, 7) - Drob(7, 9)) << std::endl;
    Drob f;
    f = Drob(1, 2);
    std::cout << f << std::endl;
    f *= Drob(4, 2);
    std::cout << f << std::endl;
    return 0;
}