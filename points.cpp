#include <iostream>

void addElements(double* x) {
    x[0] = -30;
    for (int i = 0; i < 43;i++) {
        x[i] = x[0] + i*1.4;
        std::cout << x[i] << std::endl;
    }
}

double arrShag() {
    double midleLineY[28] = {167.99,158.33,144.94,129.6,118.97,
                    105.49,94.64,79.7,68.29,55.13,42.61,27.96,18.12,9.37,-1.3,-13.52,
                    -28.08,-39.07,-51.42,-57.44,-71.75,-92.1,-107.9,-118.25,-129.45,
                    -145.69,-157.85,-172.06};
    double h;
    for (int i = 0; i < 27; i++) {
        h+=midleLineY[i+1] - midleLineY[i];
    }
    return h/28;
}

void connectionPoints(double* x, double* y){
    int firstPlusX = 0;
    int firstMinusX = 0;
    for (int i = 0; i < 43;i++) {
        std::cout<<"("<<x[i]<<","<<y[i]<<")"<<std::endl;
    }
    double h =  arrShag();
    std::cout<<"---"<<(h)<<"---"<<std::endl;
    // for (int i = 0; i < 43;i++) {
    //     if (x[i] == 0.8) {
    //         firstPlusX = i;
    //         std::cout<<i<<std::endl;
    //     }
    //     if (x[i] == -0.6) {
    //         firstMinusX = i;
    //         std::cout<<i<<std::endl;
    //     }
    // }
    for (int i = 21; i > 0; i--) {//x[i] = 0.8
        if ((y[i]>y[i-1]) && (x[i]>x[i-1]))  {
            y[i-1] = y[i] + h;
        }
    }
    for (int i = 22; i < 42; i++) {//x[i] = -0.6
        if ((y[i]<y[i+1]) && (x[i]<x[i+1]))  {
            y[i+1] = y[i] - h;
        }
    }
    std::cout << "--------------------------------"<<std::endl;
    for (int i = 0; i < 43;i++) {
        std::cout<<"("<<x[i]<<","<<y[i]<<")"<<std::endl;
    }

    std::cout << "--------------------------------"<<std::endl;
    for (int i = 0; i < 43;i++) {
        std::cout<<x[i]<<", ";
    }
    std::cout << "--------------------------------"<<std::endl;
    for (int i = 0; i < 43;i++) {
        std::cout<<y[i]<<", ";
    }

}

int main() {
    double x[43];
    double y[43] = {-55.11,-64.89,-76.13,-85.63,-95.3,-102.09,-114.79,-122.71,-132.14,
                    -146.04,-155.69,-165.83,-179.95,167.99,158.33,144.94,129.6,118.97,
                    105.49,94.64,79.7,68.29,55.13,42.61,27.96,18.12,9.37,-1.3,-13.52,
                    -28.08,-39.07,-51.42,-57.44,-71.75,-92.1,-107.9,-118.25,-129.45,
                    -145.69,-157.85,-172.06,175.92,168.4};
    addElements(x);
    arrShag();
    connectionPoints(x,y);
    return 0;
}
