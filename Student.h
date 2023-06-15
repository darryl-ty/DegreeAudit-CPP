//
// Created by darryl-ty on 6/14/2023.
//

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

class Student {
private:
    int m_userIdentification;
    std::string m_userMajor;
    std::vector<std::string> m_userTranscript;

public:
    explicit Student(int userIdentification);

    void SetUserMajor(std::string inputMajor);
    void SetUserTranscript(std::vector<std::string> inputTranscript);

    [[nodiscard]] int GetUserIdentification() const {return m_userIdentification;}
    std::string GetUserMajor() {return m_userMajor;}
    std::vector<std::string> GetUserTranscript() {return m_userTranscript;}


};


#endif //STUDENT_H
