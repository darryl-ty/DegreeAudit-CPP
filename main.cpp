#include <iostream>
#include "StudentInfo.h"

void PrintTerminalArt(){
    std::cout << "Welcome to the Degree Audit System!" << std::endl;
    std::cout
    << R"( _____   ______  ______  ______  ______  ______
/\  __-./\  ___\/\  ___\/\  == \/\  ___\/\  ___\
\ \ \/\ \ \  __\\ \ \__/\ \  __<\ \  __\\ \  __\
\ \____-\ \_____\ \_____\ \_\ \_\ \_____\ \_____\
\/____/ \/_____/\/_____/\/_/ /_/\/_____/\/_____/)"
    << std::endl;

    std::cout
    << R"(  ______  __  __  _____   __  ______
 /\  __ \/\ \/\ \/\  __-./\ \/\__  _\
 \ \  __ \ \ \_\ \ \ \/\ \ \ \/_/\ \/
  \ \_\ \_\ \_____\ \____-\ \_\ \ \_\
  \/_/\/_/\/_____/\/____/ \/_/  \/_/ )"
    << std::endl;
}

StudentInfo UserInput() {

}

void DegreeAudit(){
    PrintTerminalArt();
    UserInput();
}


int main() {
    DegreeAudit();
}
