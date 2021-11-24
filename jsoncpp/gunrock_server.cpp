// ECS 36B Review Session
// Linhao Chen (hghchen@ucdavis.edu)
#include <jsoncpp/json/json.h>
#include <jsoncpp/json/reader.h>
#include <jsoncpp/json/writer.h>
#include <jsoncpp/json/value.h>
#include <string>
#include <strings.h>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include <ctime>
#include <exception> 
#include <stdio.h>
#include <iostream>
#include "aggieserver.h"
#include <jsonrpccpp/server/connectors/httpserver.h>

using namespace jsonrpc;
using namespace std;

class GunrockServer : public aggieServer
{
public:
  GunrockServer(AbstractServerConnector &connector, serverVersion_t type);
  virtual Json::Value Meal_Plan(int meals, const std::string& name);
  virtual Json::Value Aggie_Cash(double balance, const std::string& food, 
                                    const std::string& name, double price);
};

GunrockServer::GunrockServer(AbstractServerConnector &connector, serverVersion_t type)
  : aggieServer(connector, type){}

Json::Value GunrockServer::Meal_Plan(int meals, const std::string& name) {
  Json::Value result;
  int new_meals = meals - 1;
  if(new_meals < 0) {
      result["reason"] = "0 Meal Remaining";
      result["status"] = "failed";
  } else {
      result["new_meals"] = new_meals;
      result["status"] = "successful";
  }
  return result;
}

Json::Value GunrockServer::Aggie_Cash(
    double balance, const std::string& food, const std::string& name, double price) {
  Json::Value result;
  double new_balance = balance - price;
  if(new_balance < 0) {
      result["reason"] = "Insufficient Balance";
      result["status"] = "failed";
  } else {
      result["new_balance"] = new_balance;
      result["status"] = "successful";
  }
  return result;
}


int main() {
  HttpServer httpserver(10580);
  GunrockServer s(httpserver,
		JSONRPC_SERVER_V1V2);
  s.StartListening();
  std::cout << "Hit enter to stop the server" << endl;
  getchar();

  s.StopListening();
  return 0;
}
