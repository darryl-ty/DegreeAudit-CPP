#include <iostream>
#include <string>
#include <filesystem>
#include "StudentInfo.h"

void degreeAudit();
void printTerminalArt();
void studentInput();
void createTranscriptPath();

StudentInfo userInput();
StudentInfo tryParseInt(std::string *inputStr);

std::filesystem::path assembleTranscriptPath();


int main() {
    degreeAudit();
}
void degreeAudit() {
    printTerminalArt();
    studentInput();

    createTranscriptPath();
}

void printTerminalArt() {
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

void studentInput() {
    StudentInfo student = userInput();
    std::cout << "Here is your student number: " << student.GetUserIdentification();
}


StudentInfo userInput() {
    std::string inputStudentNumber;
    std::cout << "Please input your XULA 900 number: ";
    std::cin >> inputStudentNumber;

    return tryParseInt(&inputStudentNumber);
}

StudentInfo tryParseInt(std::string *inputStr) {
    int convertedNum;

    if(inputStr->length() != 9) {
        std::cout << "Invalid 900 number length. Please try again\n" << std::endl;
        return userInput();
    }

    try{
        convertedNum = std::stoi(*inputStr);
        if(inputStr->length() != std::to_string(convertedNum).length()){
            std::cout << "Invalid 900 number. Please try again.\n" << std::endl;
            return userInput();
        }
    }
    catch (const std::invalid_argument&){
        std::cout << "Invalid 900 number. Please try again.\n" << std::endl;
        return userInput();
    }

    return StudentInfo(convertedNum);
}

void createTranscriptPath() {
    if (std::filesystem::create_directory(assembleTranscriptPath())){

    } else {

    }
}

std::filesystem::path assembleTranscriptPath() {
    std::filesystem::path transcriptPath = std::filesystem::u8path("/transcript");
    std::filesystem::path creationPath = std::filesystem::current_path().parent_path() += transcriptPath;
    return creationPath;
}
