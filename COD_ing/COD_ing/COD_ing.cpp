#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <vector>

class Ing
{
public:
    void connectMain();

private:
    void wordOutput();
    void comparison(const std::string& russianWord);
    void print(const std::string& word);

private:
    std::string m_txtList;
    std::fstream m_words;
    std::string m_msg;
    std::string m_userInput;
    std::vector<std::string> m_listWords;
    std::string str;
    std::string value;
    std::string m_EndValue;
    std::vector<std::string> m_ruWords;
    std::vector<std::string> m_enWords;
};

void Ing::connectMain()
{
    for (;;)
    {
        this->wordOutput();
        Sleep(2000);
        system("cls");
    }
}

void Ing::wordOutput()
{
    m_txtList = "Copi.txt";
    m_words.open(m_txtList, std::fstream::in);
    if (!m_words.is_open())
    {
        std::cout << "Ошибка открытия файла \n";
        return;
    }

    while (m_words >> m_msg)
    {
        int hyphenPos = m_msg.find('-');
        if (hyphenPos != std::string::npos)
        {
            std::string russianWord = m_msg.substr(0, hyphenPos);
            std::string englishWord = m_msg.substr(hyphenPos + 1);
            this->print(englishWord);
            this->comparison(russianWord);
        }
        else
        {
            std::cout << "Invalid format: " << m_msg << "\n";
        }
    }

    m_words.close();
}

void Ing::print(const std::string& word)
{
    std::cout << "Translate: " << word << "\n";
    std::cin >> m_userInput;
}

void Ing::comparison(const std::string& russianWord)
{
    if (m_userInput == russianWord)
    {
        std::cout << "Ввод правильный\n";
    }
    else
    {
        std::cout << "Ввод не правильный\n";
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Ing inglith;
    inglith.connectMain();
}
