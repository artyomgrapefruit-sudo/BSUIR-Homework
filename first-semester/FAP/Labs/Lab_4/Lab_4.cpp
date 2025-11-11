#include <cmath>
#include <iostream>
#include <iomanip>
#define POWER 100000

double fact (double num) {
  if (num < 3) {
    return num;
  }
  return num * fact(num - 1);
}

double Y (double x, double n){
  return round(sin(x)*pow(10, 5))/pow(10, 5);
}

double S (double x, double n) {
  double ans = 0;
    for (int k = 0; k < n; ++k) {
      ans += pow(-1, k) * pow(x, 2 * k + 1) / fact(2 * k + 1);
      ans = round(ans*pow(10, 5))/pow(10, 5);
    }
  return ans;
}

double Difference (double x, double n) {
  double s = S(x, n);
  double y = Y(x, n);
  return (s > y) ? (s - y) : (y - s);
}

void Out_Rez (double mem (double, double), double a, double b, double h, double n) {
  double ans, x = a;
  
  while (x < b) {
    ans = mem(x, n);
    std::cout << std::fixed << "\t" << x << "\t" << ans << std::endl;
    x += h;
  }
}

int main () {
  double difference, a, b, h, n, x, y, s, power;
  int choose, after_point = 5;

  std::cout << "Input a, b, h, n" << std::endl;
  std::cin >> a >> b >> h >> n;

  std::cout << std::setprecision(after_point);
  power = pow(10, after_point);

  while (true) { 
    std::cout << "Choose between: \n Y(x) - 1 \n S(x) - 2 \n |S(x) - Y(x)| - 3 \n Exit - 4" << std::endl;
    std::cin >> choose;

    x = a;

    switch (choose)
    {
    case 1:
      Out_Rez(Y, a, b, h, n);
      break;
    
    case 2:
      Out_Rez(S, a, b, h, n);
      break;
    
    case 3:
      Out_Rez(Difference, a, b, h, n);
      break;
    
    case 4:
      std::cout << "Bye" << std::endl;
      return 0; 
      break;
    
    default:
      std::cout << "Somethink was wrong...";
      break;
    }
  }
}