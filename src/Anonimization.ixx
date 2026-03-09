export module Anonimization;

import <sstream>;
import <vector>;

// dołączanie partycji
export import :Masking;
// import :Masking; zaimportuje partycję jedynie na użytek wewnątrz modułu - brak export

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
            temp[temp.size()-1] = mask_name(temp[temp.size()-1]);
            
            temp.push_back(mask_name(str));
            
            capitalcount = 0;
        }
        /*else if (capitalcount == 2 && lastupper != wordcount - 1) {
            capitalcount = 0;
            temp.push_back(str);
            
        }*/
        else {
            int pos = str.find('@');
            if (pos != -1) {
                temp.push_back(mask_email(str));
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
                        temp.push_back(mask_phone(str));
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