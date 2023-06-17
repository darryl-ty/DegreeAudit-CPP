#include <iostream>
#include <string>
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

int TryParseInt(std::string *inputStr);
StudentInfo UserInput();


int TryParseInt(std::string *inputStr) {
    int convertedNum;

    if(inputStr->length() != 9) {
        std::cout << "Invalid 900 number length. Please try again\n" << std::endl;
        return TryParseInt(inputStr);
    }

    try{
        convertedNum = std::stoi(*inputStr);
    }
    catch (const std::invalid_argument&){
        std::cout << "Invalid 900 number. Please try again.\n" << std::endl;
        return TryParseInt(inputStr);
    }

    return convertedNum;
}

StudentInfo UserInput() {
    std::string inputStudentNumber;
    std::cout << "Please input your XULA 900 number: ";
    std::cin >> inputStudentNumber;

    return StudentInfo(TryParseInt(&inputStudentNumber));
}

void DegreeAudit(){
    PrintTerminalArt();
    StudentInfo student = UserInput();
    std::cout << "Here is your student number: " << student.GetUserIdentification();
}


int main() {
    DegreeAudit();
}
