#include <iostream>
#include <string>
#include <random>
#include <fstream>

using namespace std;

int randomNum(int num, int num2)
{
    if (num > num2)
        swap(num, num2);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(num, num2);
    return dis(gen);
}

string TypeString()
{
    string type;
    cout << "Enter the sentence you want to encrypt: " << endl;
    getline(cin, type);
    return type;
}

string encryptWord(string word)
{
    string encryptedWord = "";
    for (int i = 0; i < word.length(); i++)
    {
        char c = word[i];
        int method = randomNum(1, 127);
        encryptedWord += char(c + method);
        encryptedWord += to_string(method);
    }
    return encryptedWord;
}

string decryptWord(string word)
{
    string decryptedWord = "";
    for (int i = 0; i < word.length();)
    {
        char c = word[i];
        
        i++;
        string MethodNum = "";

        for (int index = i; index < word.length() && isdigit(word[index]); index++)
        {
            MethodNum += word[index];
            i++;
        }

        int method = stoi(MethodNum);
        decryptedWord += char(c - method);
    }
    return decryptedWord;
}

string EncryptString(string str)
{
    string encryptedString = "";
    string word = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            encryptedString += encryptWord(word);
            encryptedString += ' ';
            word = "";
        }
        else
        {
            word += str[i];
        }
    }
    encryptedString += encryptWord(word);
    return encryptedString;
}

string decryptString(string str)
{
    string decryptedString = "";
    string word = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            decryptedString += decryptWord(word);
            decryptedString += ' ';
            word = "";
        }
        else
        {
            word += str[i];
        }
    }
    decryptedString += decryptWord(word);
    return decryptedString;
}

string WriteMessageToFile(string str)
{
    string fileName;
    cout << "Enter the file name: ";
    cin >> fileName;
    ofstream file(fileName);
    file << str;
    file.close();
    return fileName;
}

void sendTextMessage(ofstream &file)
{
}

int main()
{    
        string str = TypeString();
        string encrypted = EncryptString(str);
        cout << "This is the Encrypted string: " << encrypted << endl;
        WriteMessageToFile(encrypted);
   
        string decrypted = decryptString(encrypted);
        cout << "Decrypted string: " << decrypted << endl;
        WriteMessageToFile(decrypted);

    return 0;
}