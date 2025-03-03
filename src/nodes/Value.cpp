#include "Value.h"

Value::Value(double v) :
    value(v), sigDigits(0)
    {}
Value::Value(double v, int sigDigits) :
    value(v), sigDigits(sigDigits)
    {}

Value::Value(const std::string& valueString)
    {
        int pos = 0;
        int decimalIndex = 0;
        while (pos < valueString.size() && (isdigit(valueString[pos]) || valueString[pos] == '.')) {
            if(valueString[pos] == '.'){
                decimalIndex = pos;
            }
            pos++;
        }
        value = stod(valueString.substr(0, pos));
        if(decimalIndex != 0 ){
           sigDigits = pos - decimalIndex -1;
        }
        else{
            sigDigits = 0;
        }
        
    }


double Value::calc() {
    return value;
}

std::string Value::print() {
    std::ostringstream out;
    out.precision(sigDigits);
    out << std::fixed << value;
    return std::move(out).str();
}
