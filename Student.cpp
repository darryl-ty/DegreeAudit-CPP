//
// Created by darryl-ty on 6/14/2023.
//

#include "Student.h"

Student::Student(short userIdentification) {
    m_userIdentification = userIdentification;
    m_userMajor = nullptr;
}

void Student::SetUserMajor(std::string inputMajor) {
    m_userMajor = std::move(inputMajor);
}

void Student::SetUserTranscript(std::vector<std::string> inputTranscript) {
    m_userTranscript = std::move(inputTranscript);
}
