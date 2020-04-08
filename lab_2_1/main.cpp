//Разработать программу, которая должна сделать следующее:
//1. Прочитать содержимое текстового файла. Файл может содержать:
//    a. Слова – состоят из латинских строчных и заглавных букв, 
//    а также цифр, длинна слова должна быть не более 20 символов
//    b. Знаки препинания – «.», «,» «!» «?» «:» «;»
//    c. Пробельные символы – пробел, табуляция, символ новой строки.

//2. Отформатировать текст следующим образом:
//   a. Не должно быть  пробельных символов отличных от пробела
//   b. Не должно идти подряд более одного пробела
//   c. Между словом и знаком препинания не должно быть пробела
//   d. После знака препинания всегда должен идти пробел
//   e. Слова длиной более 10 символов заменяются на слово «Vau!!!»

//3. Преобразовать полученный текст в набор строка, каждая из 
//которых содержит целое количество строк (слово должно целиком 
//находиться в строке) и ее длинна не превышает 40 символов.


//2020-02-15
//Grigory Kulik

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

const int check_for_cyrillic_junk(string &str) {
    string::iterator iter;

    for (iter=str.begin(); iter!=str.end(); iter++) {
        if (*iter<((char) 0x0) || *iter>((char) 0x7F)) {
            cout<<"Unrecognized symbols found. The process will be aborted."<<endl;
            exit(EXIT_FAILURE);
        }
    }
}

void replaceTabsWithSpaces(string &str) {
    int tab=str.find((char) 9);

    while (tab<str.length()) {
        str.replace(tab, 1, " ");
        tab=str.find((char) 9);
    } 
}

void replaceNewLinesWithSpaces(string &str){
    int new_line=str.find('\n');

    while (new_line<str.length()) {
        str.replace(new_line, 1, " ");
        new_line=str.find('\n');
    }
}

void removeSpaces(string &str) {  
    int n=str.length(); 
  
    // i points to the next position to be filled in the output string and j points to the next character 
    // in the original string 
    int i=0, j=-1;
  
    // flag that sets to true if space is found 
    bool spaceFound=false; 
  
    // Handles leading spaces 
    while (++j<n && str[j]==' '); 
  
    // read all characters of original string 
    while (j<n) 
    { 
        // if current characters is non-space 
        if (str[j]!=' ') 
        { 
            // remove preceding spaces before dot, comma & question mark 
            if ((str[j]=='.' || str[j]==',' || str[j]=='?') && i-1>=0 && str[i-1]==' ') 
                str[i-1]=str[j++];   
            else
                // copy current character at index i 
                // and increment both i and j 
                str[i++]=str[j++]; 
  
            // set space flag to false when any 
            // non-space character is found 
            spaceFound=false; 
        } 
        // if current character is a space 
        else if (str[j++]==' ') 
        { 
            // If space is encountered for the first 
            // time after a word, put one space in the 
            // output and set space flag to true 
            if (!spaceFound) 
            { 
                str[i++]=' '; 
                spaceFound=true; 
            } 
        } 
    } 
  
    // Remove trailing spaces 
    if (i<=1) 
        str.erase(str.begin()+i, str.end()); 
    else
        str.erase(str.begin()+i-1, str.end()); 
}


void insertSpacesAfterPunctuation(string &str) {
    int i;
    for (i=0; i<str.length(); i++){
        if ((str[i]=='.' || str[i]==',' || str[i]=='?') && str[i+1]!=' ') {
            str.insert(i+1, 1, ' ');
        }
    }
}


void replaceLongWords(string &str){
    int counter=0;
    int next_word_begin=0;
    
    for (int i=0; i<str.length(); i++){
        counter++;

        if (str.at(i)==' '){
            if (counter>10){
                str.replace(next_word_begin, counter-1, "WOW!");
            }

            next_word_begin=i+1;
            counter=0;
        }
    }

    for (int i=0; i<str.length(); i++){
        counter++;
        
        if (str.at(i)==' '){ 
            counter=0;
            next_word_begin=i+1;
        }

        if (str.at(i)=='.' || str.at(i)==',' || str.at(i)=='?') {
            str.replace(next_word_begin, counter-1, "WOW!");
            counter=0;
            next_word_begin=i+2;
        }
    }  
}


void splitText(string &str) {
    vector<string> vect;
    int pointer=39;
    int i=0;

    while (str.length()>39) {
        if (str.at(39)!=' '){
                do {
                    pointer--;
                }

            while (str.at(pointer)!=' ');

            vect.push_back(str.substr(0, pointer));
            str.erase(0, pointer);
            pointer=39;
            std::cout<<vect[i]<<endl;
        }

        else {
            vect.push_back(str.substr(0, pointer));
            str.erase(0, pointer);
            std::cout<<vect[i]<<endl;
        }

        i++;
    }
}

int main(){
    ifstream file("main.cpp");
    string text;
    vector<string> split_text;
    vector<string>::iterator iter;
    
    if(!file){
        std::cout<<"Cannot open the file!";
        return 1;
    }

    //getline() uses three parameters so that it can receive multiple lines
    getline(file, text, '\0');
    file.close();

    check_for_cyrillic_junk(text);
    std::cout<<"Original text"<<endl;
    std::cout<<text<<endl;

    std::cout<<"Tabs replaced with spaces: "<<endl;
    replaceTabsWithSpaces(text);
    std::cout<<text<<endl;

    std::cout<<"Text with extra spaces removed: "<<endl;
    removeSpaces(text);
    std::cout<<text<<endl;    

    std::cout<<endl<<"Text with spaces after punctuation marks: "<<endl;
    insertSpacesAfterPunctuation(text);
    std::cout<<text<<endl;

    std::cout<<endl<<"Text after replacing long words"<<endl;
    replaceLongWords(text);
    std::cout<<text<<endl;

    replaceNewLinesWithSpaces(text);
    std::cout<<endl<<"Text after splitting"<<endl;
    splitText(text);

    return 0;    
}