#include <iostream>
struct Music{
    int Bit_count;
    int Bit_duration;
};

void input(Music);
int meeting_point (Music,Music);

int main(){

    Music Mus_1,Mus_2;
    std::cout<<"Input 1st tact"<<std::endl;input(Mus_1);
    std::cout<<"Input 2nd tact";input(Mus_2);
    meeting_point (Mus_1,Mus_2);

}
void input(Music){
    std::cout<<"Input 1st tact"<<std::endl;
    std::cout<<"Input 1st tact";
}
int meeting_point (Music,Music);