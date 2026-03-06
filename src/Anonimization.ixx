export module Anonimization;

import <string>;

std::string mask_chars(std::string&, size_t, size_t) 

export std::string anonymize_email(const std::string& email) {
    return mask_chars(email, email.find('@'));
}

export std::string anonymize_phone_number(const std::string& pn) {
    return mask_chars(pn, pn.size() - 3, 0);
}

export std::string anonymize_name(const std::string& name) {
    return mask_chars(name);
}

std::string mask_chars(std::string& str, size_t end = std::string::npos, size_t pos = 2) {
    if (end > str.size())
        end = str.size();

    for (size_t i = pos; i < end; i++)
        str[i] = '*';
}