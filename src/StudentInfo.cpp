//
// Created by darryl-ty on 6/14/2023.
//

#include "StudentInfo.h"

StudentInfo::StudentInfo(std::string userIdentification) {
    m_userIdentification = userIdentification;
}

void StudentInfo::setUserMajor(std::string inputMajor) {
    m_userMajor = std::move(inputMajor);
}

void StudentInfo::setUserTranscript(std::vector<std::string> inputTranscript) {
    m_userTranscript = std::move(inputTranscript);
}
