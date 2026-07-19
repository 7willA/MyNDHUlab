int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    if (b == 0) return a;
    return gcd(b, a % b);
  }
  
  
  Fraction operator+(const Fraction &f1, const Fraction &f2) {
  
    int den1 = f1.getDenominator();
    int den2 = f2.getDenominator();
    int lcm = (den1 * den2) / gcd(den1, den2);
  
    int num = f1.getNumerator() * (lcm / den1) + f2.getNumerator() * (lcm / den2);
    
   
    Fraction result(num, lcm);
    
  
    int divisor = gcd(abs(num), lcm);
    result.setNumerator(num / divisor);
    result.setDenominator(lcm / divisor);
    
    return result;
  }
  
  Fraction operator-(const Fraction &f1, const Fraction &f2) {
   
    int den1 = f1.getDenominator();
    int den2 = f2.getDenominator();
    int lcm = (den1 * den2) / gcd(den1, den2);
    
  
    int num = f1.getNumerator() * (lcm / den1) - f2.getNumerator() * (lcm / den2);
    
   
    Fraction result(num, lcm);
    
  
    int divisor = gcd(abs(num), lcm);
    result.setNumerator(num / divisor);
    result.setDenominator(lcm / divisor);
    
    return result;
  }
  
  
  bool operator==(const Fraction &f1, const Fraction &f2) {
  
    return (f1.getNumerator() * f2.getDenominator() == 
            f1.getDenominator() * f2.getNumerator());
  }