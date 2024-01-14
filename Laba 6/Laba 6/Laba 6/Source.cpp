#include <iostream>
#include <functional>

// Интерфейс стратегии
class RootFindingStrategy {
public:
    virtual double findRoot(std::function<double(double)> f, double a, double b, double tolerance) const = 0;
};

// Конкретная стратегия для метода бисекции
class BisectionStrategy : public RootFindingStrategy {
public:
    double findRoot(std::function<double(double)> f, double a, double b, double tolerance) const override {
        double fa = f(a);
        double fb = f(b);

        if (fa * fb > 0) {
            std::cerr << "Error: Function values at the endpoints must have opposite signs." << std::endl;
            return std::numeric_limits<double>::quiet_NaN();
        }

        double c = 0.0;
        while ((b - a) / 2 > tolerance) {
            c = (a + b) / 2;
            double fc = f(c);

            if (fc == 0.0)
                break;

            if (fa * fc < 0)
                b = c;
            else
                a = c;
        }

        return (a + b) / 2;
    }
};

// Конкретная стратегия для метода хорд
class ChordStrategy : public RootFindingStrategy {
public:
    double findRoot(std::function<double(double)> f, double a, double b, double tolerance) const override {
        double fa = f(a);
        double fb = f(b);

        if (fa * fb > 0) {
            std::cerr << "Error: Function values at the endpoints must have opposite signs." << std::endl;
            return std::numeric_limits<double>::quiet_NaN();
        }

        double c = 0.0;
        do {
            c = (a * fb - b * fa) / (fb - fa);
            double fc = f(c);

            if (fc == 0.0)
                break;

            if (fa * fc < 0)
                b = c;
            else
                a = c;
        } while (std::abs(b - a) > tolerance);

        return c;
    }
};

// Конкретная стратегия для метода Ньютона
class NewtonStrategy : public RootFindingStrategy {
public:
    NewtonStrategy(std::function<double(double)> f_prime) : f_prime(f_prime) {}

    double findRoot(std::function<double(double)> f, double x0, double b, double tolerance) const override {
        double x = x0;
        double fx = f(x);
        double f_prime_x = f_prime(x);

        while (std::abs(fx) > tolerance) {
            if (f_prime_x == 0.0) {
                std::cerr << "Error: Derivative is zero." << std::endl;
                return std::numeric_limits<double>::quiet_NaN();
            }

            x = x - fx / f_prime_x;
            fx = f(x);
            f_prime_x = f_prime(x);
        }

        return x;
    }

private:
    std::function<double(double)> f_prime;
};

// Класс, использующий стратегию
class RootFinder {
public:
    RootFinder(const RootFindingStrategy& strategy) : strategy(strategy) {}

    double findRoot(std::function<double(double)> f, double a, double b, double tolerance) const {
        return strategy.findRoot(f, a, b, tolerance);
    }

private:
    const RootFindingStrategy& strategy;
};

int main() {
    // Пример использования
    BisectionStrategy bisection;
    ChordStrategy chord;
    NewtonStrategy newton([](double x) { return 2 * x; }); // Производная функции f(x) = x^2

    RootFinder bisectionFinder(bisection);
    RootFinder chordFinder(chord);
    RootFinder newtonFinder(newton);

    double resultBisection = bisectionFinder.findRoot([](double x) { return x * x - 4; }, 1, 10, 0.01);
    double resultChord = chordFinder.findRoot([](double x) { return x * x - 4; }, 1, 10, 0.01);
    double resultNewton = newtonFinder.findRoot([](double x) { return x * x - 4; }, 1, 10, 0.01);

    std::cout << "Bisection method result: " << resultBisection << std::endl;
    std::cout << "Chord method result: " << resultChord << std::endl;
    std::cout << "Newton method result: " << resultNewton << std::endl;

    return 0;
}
