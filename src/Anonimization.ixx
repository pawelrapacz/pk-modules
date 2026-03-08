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