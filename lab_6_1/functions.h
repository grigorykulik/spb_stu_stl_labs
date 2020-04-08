#include <vector>
#include <string>
#include <algorithm>

std::vector<std::string> get_words(std::string string_to_process)
{   
    std::vector<std::string> words;
    int word_begin;
    int word_end;
    int word_len;

    std::string word;
    const std::string delimiters=(" .,\n\t:;!?");

    word_begin=0;
    

    while ((word_end!=std::string::npos) && (word_begin!=std::string::npos))
    {   
        word_end=string_to_process.find_first_of(delimiters, word_begin);
        word_len=word_end-word_begin;
        if (word_len==0)
        {
            word_begin=word_end+1;
            continue;
        }
        words.push_back(string_to_process.substr(word_begin, word_len));
        word_begin=word_end+1;
    }
    
    return words;
}