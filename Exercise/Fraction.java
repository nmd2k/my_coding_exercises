public class Fraction {
    private int numerator, denominator;

    public Fraction (int numerator, int denominator){
        this.denominator = 1;
        this.numerator = numerator;
        if (denominator != 0) this.denominator = denominator;
    }

    public int getNumerator(){
        return this.numerator;
    }
    public int getDenominator(){
        return this.denominator;
    }
    
    public void setNumerator(int numerator){
        this.numerator = numerator;
    }
    public void setDenominator(int denominator){
        if (denominator == 0) return;
        this.denominator = denominator;
    }

    public Fraction reduce(){
        for (int i = this.denominator * this.numerator; i > 1; i--) {
            if ((this.denominator % i == 0) && (this.numerator % i == 0)) {  
            this.denominator /= i;  
            this.numerator /= i;
            }
        }
        return this;
    }
    public Fraction add(Fraction other) {
        Fraction a = new Fraction(this.numerator*other.getDenominator() +
            other.getNumerator()*this.denominator, this.denominator*other.getDenominator());
        return a.reduce();
    }
    public Fraction subtract(Fraction other) {
        Fraction a = new Fraction(this.numerator*other.getDenominator() - 
            other.getNumerator()*this.denominator, this.denominator*other.getDenominator());
        return a.reduce();
    }
    public Fraction multiply(Fraction other) {
        Fraction a = new Fraction(this.numerator*other.getNumerator(), this.denominator*other.getDenominator());
        return a.reduce();
    }
    public Fraction divide(Fraction other) {
        if (other.getNumerator() == 0){
            return this;
        }
        Fraction a = new Fraction(this.numerator*other.getDenominator(), this.denominator*other.getNumerator());
        return a.reduce();
    }
    
    public boolean equals(Fraction other){
        if (!(other instanceof Fraction)) return false;
        return this.numerator*other.getDenominator() == this.denominator*other.getNumerator();
    }

    // public static void main(String[] args) {
    //     Fraction test = new Fraction(14, 2);
    //     Fraction test1 = new Fraction(7, 2);
        
    //     System.out.println(test.add(test1).getNumerator() + "/" + test.add(test1).getNumerator);

    // }

    
}