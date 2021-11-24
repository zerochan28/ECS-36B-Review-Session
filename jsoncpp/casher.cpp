// ECS 36B Review Session
// Linhao Chen (hghchen@ucdavis.edu)
#include <jsoncpp/json/json.h>
#include <jsoncpp/json/reader.h>
#include <jsoncpp/json/writer.h>
#include <jsoncpp/json/value.h>
#include <sstream>
#include <stdio.h>
#include <string>
#include <strings.h>
#include <time.h>
#include <unistd.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#include "aggieclient.h"
#include <jsonrpccpp/client/connectors/httpclient.h>

using namespace jsonrpc;
using namespace std;

void cash_pay(string name, string food_name, double balance, double price);
void plan_pay(string name, int meals);

int main() {
    cout << "Gunrock orders $5.5 Salad with $200.0 Balance" << endl;
    cash_pay("Gunrock", "Salad", 200.0, 5.5);

    cout << "Gunrock uses meal plan with 10 swipes remaining" << endl;
    plan_pay("Gunrock", 10);

    cout << "Gunrock orders $5.5 Salad with $2.0 Balance" << endl;
    cash_pay("Gunrock", "Salad", 2.0, 5.5);

    cout << "Gunrock uses meal plan with 0 swipes remaining" << endl;
    plan_pay("Gunrock", 0);
    
}

void cash_pay(string name, string food_name, double balance, double price) {
    HttpClient httpclient("localhost:10580");
    aggieClient myClient(httpclient, JSONRPC_CLIENT_V2);
    Json::Value result;
    try {
        result = myClient.Aggie_Cash(balance, food_name, name, price);
    } catch (JsonRpcException &e) {
        cerr << e.what() << endl;
    }
    cout << result << endl;
}

void plan_pay(string name, int meals) {
    HttpClient httpclient("localhost:10580");
    aggieClient myClient(httpclient, JSONRPC_CLIENT_V2);
    Json::Value result;
    try {
        result = myClient.Meal_Plan(meals, name);
    } catch (JsonRpcException &e) {
        cerr << e.what() << endl;
    }
    cout << result << endl;
}


