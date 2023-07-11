#include <iostream>
#include <sys/time.h>
#include <jsoncpp/json/json.h>
#include "contacts.pb.h"

using namespace std;      
using namespace compare_serialization;
using namespace google::protobuf;

#define TEST_COUNT 100000

void createPeopleInfoFromPb(PeopleInfo *people_info_ptr);
void createPeopleInfoFromJson(Json::Value& root);

int main(int argc, char *argv[])
{
  struct timeval t_start,t_end;
  double time_used;
  int count;
  string pb_str, json_str;

  // ------------------------------Protobuf 序列化------------------------------------
  {
    PeopleInfo pb_people;
    createPeopleInfoFromPb(&pb_people);
    count = TEST_COUNT;
    gettimeofday(&t_start, NULL);
    // 序列化count次
    while ((count--) > 0) {
      pb_people.SerializeToString(&pb_str);
    }
    gettimeofday(&t_end, NULL);
    time_used=1000000*(t_end.tv_sec - t_start.tv_sec) + t_end.tv_usec - t_start.tv_usec;
    cout << TEST_COUNT << "次 [pb序列化]耗时：" << time_used/1000 << "ms." 
         << " 序列化后的大小：" << pb_str.length() << endl;
  }
  
  // ------------------------------Protobuf 反序列化------------------------------------
  {
    PeopleInfo pb_people;
    count = TEST_COUNT;
    gettimeofday(&t_start, NULL);
    // 反序列化count次
    while ((count--) > 0) {
      pb_people.ParseFromString(pb_str);
    }
    gettimeofday(&t_end, NULL);
    time_used=1000000*(t_end.tv_sec - t_start.tv_sec) + t_end.tv_usec - t_start.tv_usec;
    cout << TEST_COUNT << "次 [pb反序列化]耗时：" << time_used / 1000 << "ms." << endl;
  }

  // ------------------------------JSON 序列化------------------------------------
  {
    Json::Value json_people;    
    createPeopleInfoFromJson(json_people); 
    Json::StreamWriterBuilder builder;    
    count = TEST_COUNT;
    gettimeofday(&t_start, NULL);
    // 序列化count次
    while ((count--) > 0) {
      json_str = Json::writeString(builder, json_people);  
    }
    gettimeofday(&t_end, NULL);
    // 打印序列化结果
    // cout << "json: " << endl << json_str << endl;
    time_used=1000000*(t_end.tv_sec - t_start.tv_sec) + t_end.tv_usec - t_start.tv_usec;
    cout << TEST_COUNT << "次 [json序列化]耗时：" << time_used/1000 << "ms."
         << " 序列化后的大小：" << json_str.length() << endl;
                          
  }

  // ------------------------------JSON 反序列化------------------------------------
  {
    Json::CharReaderBuilder builder;
    unique_ptr<Json::CharReader> reader(builder.newCharReader());
    Json::Value json_people;
    count = TEST_COUNT;
    gettimeofday(&t_start, NULL);
    // 反序列化count次
    while ((count--) > 0) {
      reader->parse(json_str.c_str(), json_str.c_str() + json_str.length(), &json_people, nullptr);
    }
    gettimeofday(&t_end, NULL);
    time_used=1000000*(t_end.tv_sec - t_start.tv_sec) + t_end.tv_usec - t_start.tv_usec;
    cout << TEST_COUNT << "次 [json反序列化]耗时：" << time_used/1000 << "ms." << endl;                          
  }

  return 0;
}

/** 
 * 构造pb对象
 */
void createPeopleInfoFromPb(PeopleInfo *people_info_ptr)
{
  people_info_ptr->set_name("张珊");
  people_info_ptr->set_age(20);
  people_info_ptr->set_qq("95991122");

  for(int i = 0; i < 5; i++) {
    PeopleInfo_Phone* phone = people_info_ptr->add_phone();
    phone->set_number("110112119");
    phone->set_type(PeopleInfo_Phone_PhoneType::PeopleInfo_Phone_PhoneType_MP);
  }

  Address address;
  address.set_home_address("陕西省西安市长安区");
  address.set_unit_address("陕西省西安市雁塔区");
  google::protobuf::Any * data = people_info_ptr->mutable_data();
  data->PackFrom(address);
  

  people_info_ptr->mutable_remark()->insert({"key1", "value1"}); 
  people_info_ptr->mutable_remark()->insert({"key2", "value2"}); 
  people_info_ptr->mutable_remark()->insert({"key3", "value3"}); 
  people_info_ptr->mutable_remark()->insert({"key4", "value4"}); 
  people_info_ptr->mutable_remark()->insert({"key5", "value5"}); 

}

/** 
 * 构造json对象
 */
void createPeopleInfoFromJson(Json::Value& root) {
  root["name"] = "张珊";    
  root["age"] = 20;    
  root["qq"] = "95991122";    
  
  for(int i = 0; i < 5; i++) {
    Json::Value phone;
    phone["number"] = "110112119";
    phone["type"] = 0;
    root["phone"].append(phone);
  }

  Json::Value address;
  address["home_address"] = "陕西省西安市长安区";
  address["unit_address"] = "陕西省西安市雁塔区";
  root["address"] = address;

  Json::Value remark;
  remark["key1"] = "value1";
  remark["key2"] = "value2";
  remark["key3"] = "value3";
  remark["key4"] = "value4";
  remark["key5"] = "value5";
  root["remark"] = remark;
}