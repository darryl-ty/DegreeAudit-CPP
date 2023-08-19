//
// Created by darryl-ty on 6/14/2023.
//

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

class StudentInfo {
private:
    std::string m_userIdentification;
    std::string m_userMajor;
    std::vector<std::string> m_userTranscript;

public:
    explicit StudentInfo(std::string userIdentification);

    void setUserMajor(std::string inputMajor);
    void setUserTranscript(std::vector<std::string> inputTranscript);

    [[nodiscard]] std::string getUserIdentification() const {return m_userIdentification;}
    std::string getUserMajor() {return m_userMajor;}
    std::vector<std::string> getUserTranscript() {return m_userTranscript;}


};


#endif //STUDENT_H
