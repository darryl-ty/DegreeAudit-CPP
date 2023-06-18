#include <iostream>
#include <string>
#include <filesystem>
#include "StudentInfo.h"

void PrintTerminalArt();
void CreateTranscriptPath();
void DegreeAudit();

StudentInfo TryParseInt(std::string *inputStr);
StudentInfo UserInput();


int main() {
    DegreeAudit();
}

void CreateTranscriptPath() {

}

void DegreeAudit() {
    PrintTerminalArt();
    StudentInfo student = UserInput();
    std::cout << "Here is your student number: " << student.GetUserIdentification();

    CreateTranscriptPath();
}

void PrintTerminalArt() {
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

StudentInfo TryParseInt(std::string *inputStr) {
    int convertedNum;

    if(inputStr->length() != 9) {
        std::cout << "Invalid 900 number length. Please try again\n" << std::endl;
        return UserInput();
    }

    try{
        convertedNum = std::stoi(*inputStr);
        if(inputStr->length() != std::to_string(convertedNum).length()){
            std::cout << "Invalid 900 number. Please try again.\n" << std::endl;
            return UserInput();
        }
    }
    catch (const std::invalid_argument&){
        std::cout << "Invalid 900 number. Please try again.\n" << std::endl;
        return UserInput();
    }

    return StudentInfo(convertedNum);
}

StudentInfo UserInput() {
    std::string inputStudentNumber;
    std::cout << "Please input your XULA 900 number: ";
    std::cin >> inputStudentNumber;

    return TryParseInt(&inputStudentNumber);
}
