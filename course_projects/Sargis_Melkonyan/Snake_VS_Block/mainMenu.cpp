#include "mainMenu.hpp"

int mainMenu(){
    int menuChoice = menuView();
    
    switch (menuChoice){
    case 0:             //Play
        {
            Controller play;
            play.run();
        }
          break;
    case 1:             //Setting
        break;

    case 2:             //Help
        break;

    case 3:             //Exit
        break;  

    default:
        break;
    }

    return 0;
}

