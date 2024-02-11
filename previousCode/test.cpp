#include <cmath>

using namespace std;

int main(void){
  double x=2.0, y=498.0, z=499.0, k=500.0;
  std::cout<<"x="<<x<<" y="<<y<<" z="<<z<<" k="<<k<<std::endl;
  std::cout<<"log(1/2)="<<log(1/x)<<" log(1/498)="<<log(1/y)<<" log(1/499)="<<log(1/z)<<" log(1/500)="<<log(1/k)<<std::endl;
  std::cout<<"*(-1000)="<<log(1/x)*(-1000)<<" "<<log(1/y)*(-1000)<<" "<<log(1/z)*(-1000)<<" "<<log(1/k)*(-1000)<<std::endl;
  double x1=log(1/x)*(-1000);
  double x2=log(1/k)*(-1000);
  std::cout<<"exp(x)="<<exp(x1)/(-1000)<<" exp(k)="<<exp(x2)/(-1000)<<std::endl;
  return 0;
}
