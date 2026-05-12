#ifndef CPPJSON_H
#define CPPJSON_H


#include<string>
#include<vector>
#include<map>
#include<iostream>
enum JsonType{JSON_NULL,JSON_BOOL,JSON_NUM,JSON_STR,JSON_ARR,JSON_OBJ};

struct JsonValue{

    JsonType type;
    bool val_bool;
    double val_num;
    std::string val_str;
    std::vector<JsonValue> val_arr;
    std::map<std::string,JsonValue> val_obj;

};
void print_value(const JsonValue& type,int num);


#endif