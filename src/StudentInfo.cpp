//
// Created by darryl-ty on 6/14/2023.
//

#include "StudentInfo.h"

StudentInfo::StudentInfo(int userIdentification) {
    m_userIdentification = userIdentification;
}

void StudentInfo::SetUserMajor(std::string inputMajor) {
    m_userMajor = std::move(inputMajor);
}

void StudentInfo::SetUserTranscript(std::vector<std::string> inputTranscript) {
    m_userTranscript = std::move(inputTranscript);
}
