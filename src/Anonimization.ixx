module;
#include <string>

export module Anonimization;

std::string mask_chars(const std::string& str, size_t end = std::string::npos, size_t pos = 2);

export std::string anonymize_email(const std::string& email) {
    return mask_chars(email, email.find('@'));
}

export std::string anonymize_phone_number(const std::string& pn) {
    return mask_chars(pn, pn.size() - 3, 0);
}

export std::string anonymize_name(const std::string& name) {
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