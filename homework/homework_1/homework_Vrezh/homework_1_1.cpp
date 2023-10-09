#include<iostream>

double CubeRoot(double x,double delta );

int main(){
    double num,delta;
    std::cout<<"enter num"<<std::endl;
    std::cin>>num;
    std::cout<<"enter percisions"<<std::endl;
    std::cin>>delta;
    std::cout<<"Cube Root is"<<"\n"<<CubeRoot(num,delta)<<std::endl;
};

double CubeRoot(double x,double delta){
    double xn=1;
    double root;
    int a= x > 0 ? 1 : -1;
    
    while (true){
        if(xn*xn*xn- abs(x) >0){
            a * xn--;
            break;
        }
        else if(xn*xn*xn - abs(x) == 0 ){
            return a * xn;
        }
        xn++;
    }

    while (true){
      root = xn - (xn*xn*xn - x)/(3*xn*xn);
      if(abs(root*root*root -x) <= delta){
        return root;
      }
      xn=root;
    }
};
