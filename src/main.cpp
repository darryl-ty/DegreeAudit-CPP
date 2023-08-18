#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include "StudentInfo.h"

void degreeAudit();
void printTerminalArt();
void createAuditPaths();
void createPath(const std::string&);
void checkForStudentTranscript(const StudentInfo&);

StudentInfo studentInput();
StudentInfo userInput();
StudentInfo tryParseInt(const std::string& inputStr);

std::filesystem::path assemblePath(const std::string&);


int main() {
    degreeAudit();
}
void degreeAudit() {
    printTerminalArt();
    StudentInfo student = studentInput();

    createAuditPaths();

    checkForStudentTranscript(student);

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

StudentInfo studentInput() {
    StudentInfo student = userInput();
    std::cout << "Here is your student number: " << student.GetUserIdentification();

    return student;
}


StudentInfo userInput() {
    std::string inputStudentNumber;
    std::cout << "Please input your XULA 900 number: ";
    std::cin >> inputStudentNumber;

    return tryParseInt(inputStudentNumber);
}

StudentInfo tryParseInt(const std::string& inputStr) {
    int convertedNum;

    if(inputStr.length() != 9) {
        std::cout << "Invalid 900 number length. Please try again\n" << std::endl;
        return userInput();
    }

    try{
        convertedNum = std::stoi(inputStr);
        if(inputStr.length() != std::to_string(convertedNum).length()){
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

void createAuditPaths(){
    void (*creation) (const std::string &);

    creation = &createPath;

    creation("Transcripts");
    creation("Curriculum");
}

void createPath(const std::string& pathToCreate) {
    if (std::filesystem::exists(std::filesystem::current_path().parent_path() += std::filesystem::u8path("/" + pathToCreate))){
        return;
    }
    std::filesystem::create_directory(assemblePath(pathToCreate));
}

std::filesystem::path assemblePath(const std::string& pathToCreate) {
    std::filesystem::path path = std::filesystem::u8path("/" + pathToCreate);
    std::filesystem::path creationPath = std::filesystem::current_path().parent_path() += path;
    return creationPath;
}

void checkForStudentTranscript(const StudentInfo& student){

}
