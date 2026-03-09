
module;
#include <string>
#include <sstream>
#include <vector>

export module Anonimization;

import <string>;

std::string mask_chars(const std::string& str, size_t end = std::string::npos, size_t pos = 2);

export std::string mask_email(const std::string& email) {
    size_t end = email.find('@');
    size_t pos = 2;

    if (pos > end / 3)
        pos = end / 3;

    return mask_chars(email, email.find('@'), pos);
}

export std::string mask_phone(const std::string& pn) {
    size_t pos;
    if (!pn.starts_with('+'))
        pos = 0;
    else if (pn.find(' ') == 3)
        pos = 4;
    else
        pos = 3;

    return mask_chars(pn, pn.size() - 3, pos);
}

export std::string mask_name(const std::string& name) {
    if (2 > name.size() / 3)
        return mask_chars(name, std::string::npos, name.size() / 3);
    else
        return mask_chars(name);
}

std::string mask_chars(const std::string& str, size_t end, size_t pos) {
    std::string out = str;

    if (end > out.size())
        end = out.size();

    for (size_t i = pos; i < end; i++)
        out[i] = '*';

    return out;
}

export std::string autoAnonimization(const std::string& text) {
    
    std::istringstream input(text);
    std::string output;
    std::string str;
    std::vector<std::string> temp;
    int capitalcount = 0;
    int wordcount = 0;

    int lastupper;
    while (input >> str) {
        wordcount++;
        
        if (!str.empty() && std::isupper(static_cast<unsigned char>(str[0]))) {
            
            capitalcount++;
            if(capitalcount==1)
            lastupper = wordcount;
        }
        if (capitalcount == 2&&lastupper==wordcount-1) {
            temp[temp.size()-1] = anonymize_name(temp[temp.size()-1]);
            
            temp.push_back(anonymize_name(str));
            
            capitalcount = 0;
        }
        /*else if (capitalcount == 2 && lastupper != wordcount - 1) {
            capitalcount = 0;
            temp.push_back(str);
            
        }*/
        else {
            int pos = str.find('@');
            if (pos != -1) {
                temp.push_back(anonymize_email(str));
                capitalcount = 0;
            }
            else {


                //temp.push_back(str);
                int phone;
                double test;
                try {
                    phone = std::stoi(str);
                    test = phone / 100'000'000;
                    if (test >= 1 && test < 10) {
                        temp.push_back(anonymize_phone_number(str));
                        capitalcount = 0;
                        continue;
                    }
                    
                }
                catch (...) {

                }
                temp.push_back(str);


                //anonymize_email(str);
                //temp.push_back(str);

            }
        }
        


        

        

    }
    for (int i = 0;i < temp.size(); i++) {
        output += temp[i] + " ";
    }
    
    return output;
}