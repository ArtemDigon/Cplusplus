#include <iostream>
#include <cmath>
using namespace std;
double f(double x, double y){//функция
    return x*y;
}
double Eilera(double a, double b, double n, double y0){
    double h = (b-a)/n;
    cout<< "получаем h = (" << b <<"-"<<a<<")/"<<n<<"= "<<h<< endl;
    double y10 = y0;//далее yi (одна палочка сверху)
    cout<< "получаем y'i = "<<y0<< endl;
    double y20 = y0;//далее 2yi (две палочки)
    cout<< "получаем 2y''i = "<<y0<< endl;
    double y11 = 0;//далее y_(i+1) (одна палочкка)
    double y21 = 0;//далее 2y_(i+1) (две палочк сверху)
    double y22 = 0;//далее 2y_(i+2) (две палочк сверху)
    double kolvo = 0, sch = 0;//для количества, счетчик
    cout<<n<<endl;
    for (int i = 1; i <= n; i++){
        cout<< "получаем цикл из n итераций = " << n <<endl;
        double xi = a+i*h;
        cout<< "получаем x"<< i <<" = "<<a<<"+"<<i<<"*"<<h<<" = "<<xi<<endl;
        y11=y10+f(xi, y10)*h;
        cout<< "получаем y'"<<i+1<<" = "<<"y'"<<i<<"+"<<xi<<"*"<<"y'"<<i<<" = "<<y11<<endl;
        y21=y20+(f(xi, y20))*h/2;
        cout<< "получаем 2y''" <<i + 1<< " = "<<"2y"<<i<<xi<<"*"<<"2y''"<<i<<"*"<<h/2<<" = "<<y21<<endl;
        y22=y21+(f(xi, y21))*h/2;
        cout<< "получаем 2y''" <<i + 2<<" = "<<"2y''"<<i + 1<<"+"<<xi<<"*"<<"2y''"<<i + 1<<"*"<<h/2<<" = "<<y22<<endl;
        if (abs(y22-y11)<=0.5){
            cout<<"если |2y''"<<i + 2<<"- y'"<<i + 1<<"|"<<"<= 0.5"<<endl;
            cout<<"|"<<abs(y22-y11)<<"| <= 0.01"<<endl;
            kolvo++;
            cout<< "кол-во увеличиваеим на 1 и получаем: " << kolvo <<endl;
        }
        y10 = y11;
        cout<< "получаем y'"<<i<< "= y''"<<i + 1<<"="<<y11<<endl;
        y20 = y22;
        cout<< "получаем 2y''"<<i<<"="<<"2y''"<<i+ 2<<"="<<y22<<endl;
    }
    if (kolvo == n){
        cout<<"если кол-во = n,то функция возвращает  1"<<endl;
        sch = 1;
    }
    cout<<sch<<endl;
    return sch;
}
void VyvodEilera(double a, double b, double n, double y0){
    double h = (b-a)/n;
    double y10 = y0;//далее yi (одна палочка сверху)
    double y11 = 0;//далее y_(i+1) (одна палочкка)
    cout << "y'(" << a << ") = " << y10 << ";" << endl;
    for (int i = 1; i <= n; i++){
        double xi = a+i*h;
        y11=y10+f(xi, y10)*h;
        y10 = y11;
        cout << "y'(" << xi << ") = " << y10 << ";" << endl;
    }
}
int main(){
    double a = 0, b = 1, n = 2, s = 0;//s -- счётчик шагов, n -- 10, тк изначальный h -- 0.1, 0.1 = (1-0)/n
    double y0 = 1;
    double sch = 0;
    while (sch == 0){
        sch = Eilera(a, b, n, y0);
        n*=2;
    }
    VyvodEilera(a, b, n, y0);
}

