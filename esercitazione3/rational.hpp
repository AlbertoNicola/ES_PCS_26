#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <iostream>
#include <numeric>  
#include <concepts>


template<typename I> requires std::integral<I>
class rational {
private:
	I num_;
	I den_;
	
	void simplify()
	{
		if (den_ == 0)
		{
			if (num_ > 0) num_ = 1;
			else if (num_ < 0) num_ = -1;
			else num_ = 0;   
			return;
		}
		
		I divisore = std::gcd(num_, den_);
		num_ = num_ / divisore;
		den_ = den_ / divisore;
		
		if (den_ < 0)
		{
			num_ = -num_;
			den_ = -den_;
		}
	}

public:
	rational() : num_(0), den_(1) {}
	rational(const I& n, const I& d) : num_(n), den_(d)
	{
		simplify();
	}

	I num() const { return num_; }
	I den() const { return den_; }

// Operazioni
// Somma
	rational& operator+=(const rational& other)
	{
		num_ = (num_ * other.den_) + (other.num_ * den_);
		den_ = den_ * other.den_;
		simplify();
		return *this;
	}

	rational operator+(const rational& other) const
	{
		rational risultato = *this;
		risultato += other;
		return risultato;
	}

// Sottrazione
	rational& operator-=(const rational& other)
	{
		num_ = (num_ * other.den_) - (other.num_ * den_);
		den_ = den_ * other.den_;
		simplify();
		return *this;
	}
	
	rational operator-(const rational& other) const
	{
		rational risultato = *this;
		risultato -= other;
		return risultato;
	}

// Moltiplicazione
	rational& operator*=(const rational& other)
	{
		num_ = num_ * other.num_;
		den_ = den_ * other.den_;
		simplify();
		return *this;
	}
	
	rational operator*(const rational& other) const
	{
		rational risultato = *this;
		risultato *= other;
		return risultato;
	}

// Divisione
	rational& operator/=(const rational& other)
	{
		num_ = num_ * other.den_;
		den_ = den_ * other.num_;
		simplify();
		return *this;
	}
	
	rational operator/(const rational& other) const
	{
		rational risultato = *this;
		risultato /= other;
		return risultato;
	}
};

template<typename I>
std::ostream& operator<<(std::ostream& os, const rational<I>& r)
{
	if (r.den() == 0)
	{
		if (r.num() == 0) os << "NaN";
		else if (r.num() > 0) os << "+Inf";
		else os << "-Inf";
	}
	else if (r.den() == 1)
	{
		os << r.num();
	}
	else
	{
		os << r.num() << "/" << r.den();
	}
	return os;
}

#endif