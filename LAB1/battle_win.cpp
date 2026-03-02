#include <cstdio>
#include <cstdlib>
int main(){
    // system("g++ rand_input.cpp -o rand_input.exe");
    // system("g++ check_input.cpp -o check_input.exe");
    // system("g++ solution_1.cpp -o solution_1.exe");
    // system("g++ solution_2.cpp -o solution_2.exe");
    // compile manually if g++ cannot be called from cmd
    while(1){
        system("rand_input.exe > rand.in");
        if(system("check_input.exe < rand.in")!=0){
            printf("invalid input!\n");
            break;
        }
        system("solution_1.exe < rand.in > 1.out");
        system("solution_2.exe < rand.in > 2.out");
        if(system("fc 1.out 2.out >nul")!=0){
            printf("different output!\n");
            break;
        }
    }
    return 0;
}