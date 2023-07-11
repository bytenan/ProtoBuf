#include "ContactsServer.h"
#include "ContactsException.h"
#include "httplib.h"

#define CONTACTS_HOST "127.0.0.1"
#define CONTACTS_PORT 8080

void ContactsServer::addContact() {
    httplib::Client client(CONTACTS_HOST, CONTACTS_PORT);
    // 构造add_contact_request
    add_contact_request::AddContactRequest request;
    bulidAddContactRequest(&request);
    // 序列化add_contact_request
    std::string request_str;
    if (!request.SerializeToString(&request_str)) {
        throw ContactsException("AddContactRequest 序列化失败!");
    }
    // 发起Post请求
    auto result = client.Post("/contacts/add", request_str, "application/protobuf");
    if (!result) {
        std::string err_desc;
        err_desc.append("/contacts/add 连接错误! 错误信息: ")
                .append(httplib::to_string(result.error()));
        throw ContactsException(err_desc);
    }
    // 反序列化add_contact_response
    add_contact_response::AddContactResponse response;
    bool parse = response.ParseFromString(result->body);
    if (result->status != 200 && !parse) {
        std::string err_desc;
        err_desc.append("post '/contacts/add' 失败: ")
                .append(std::to_string(result->status))
                .append("(").append(result->reason).append(")");
        throw ContactsException(err_desc);
    } else if (result->status != 200) {
        std::string err_desc;
        err_desc.append("post '/contacts/add' 失败: ")
                .append(std::to_string(result->status))
                .append("(").append(result->reason).append(") 错误描述: ")
                .append(response.error_desc());
        throw ContactsException(err_desc);
    } else if (!response.success()) {
        std::string err_desc;
        err_desc.append("post '/contacts/add' 结果异常！异常描述: ")
                .append(response.error_desc());
        throw ContactsException(err_desc);
    }
    // 输出结果
    std::cout << "--->添加联系人成功, ID: " << response.uid() << std::endl;
}

void ContactsServer::delContact() {
    httplib::Client client(CONTACTS_HOST, CONTACTS_PORT);
    // 构造del_contact_request
    del_contact_request::DelContactRequest request;
    std::cout << "--->输入要删除的联系人ID: ";
    std::string uid;
    std::getline(std::cin, uid);
    request.set_uid(uid);
    // 序列化del_contact_request
    std::string request_str;
    if (!request.SerializeToString(&request_str)) {
        throw ContactsException("DelContactRequest 序列化失败!");
    }
    // 发起Post请求
    auto result = client.Post("/contacts/del", request_str, "application/protobuf");
    if (!result) {
        std::string err_desc;
        err_desc.append("/contacts/del 连接错误! 错误信息: ")
                .append(httplib::to_string(result.error()));
        throw ContactsException(err_desc);
    }
    // 反序列化del_contact_response
    del_contact_response::DelContactResponse response;
    bool parse = response.ParseFromString(result->body);
    if (result->status != 200 && !parse) {
        std::string err_desc;
        err_desc.append("post '/contacts/del' 失败: ")
                .append(std::to_string(result->status))
                .append("(").append(result->reason).append(")");
        throw ContactsException(err_desc);
    } else if (result->status != 200) {
        std::string err_desc;
        err_desc.append("post '/contacts/del' 失败: ")
                .append(std::to_string(result->status))
                .append("(").append(result->reason).append(") 错误描述: ")
                .append(response.error_desc());
        throw ContactsException(err_desc);
    } else if (!response.success()) {
        std::string err_desc;
        err_desc.append("post '/contacts/del' 结果异常！异常描述: ")
                .append(response.error_desc());
        throw ContactsException(err_desc);
    }
    // 输出结果
    std::cout << "--->删除联系人成功, ID: " << response.uid() << std::endl;
}

void ContactsServer::findContact() {
    httplib::Client client(CONTACTS_HOST, CONTACTS_PORT);
    // 构造find_one_contact_request
    find_one_contact_request::FindOneContactRequest request;
    std::cout << "--->输入要查找的联系人ID: ";
    std::string uid;
    std::getline(std::cin, uid);
    request.set_uid(uid);
    // 序列化find_one_contact_request
    std::string request_str;
    if (!request.SerializeToString(&request_str)) {
        throw ContactsException("FindOneContactRequest 序列化失败!");
    }
    // 发起Post请求
    auto result = client.Post("/contacts/find-one", request_str, "application/protobuf");
    if (!result) {
        std::string err_desc;
        err_desc.append("/contacts/find-one 连接错误! 错误信息: ")
                .append(httplib::to_string(result.error()));
        throw ContactsException(err_desc);
    }
    // 反序列化find_one_contact_response
    find_one_contact_response::FindOneContactResponse response;
    bool parse = response.ParseFromString(result->body);
    if (result->status != 200 && !parse) {
        std::string err_desc;
        err_desc.append("post '/contacts/find-one' 失败: ")
                .append(std::to_string(result->status))
                .append("(").append(result->reason).append(")");
        throw ContactsException(err_desc);
    } else if (result->status != 200) {
        std::string err_desc;
        err_desc.append("post '/contacts/find-one' 失败: ")
                .append(std::to_string(result->status))
                .append("(").append(result->reason).append(") 错误描述: ")
                .append(response.error_desc());
        throw ContactsException(err_desc);
    } else if (!response.success()) {
        std::string err_desc;
        err_desc.append("post '/contacts/find-one' 结果异常！异常描述: ")
                .append(response.error_desc());
        throw ContactsException(err_desc);
    }
    // 输出结果
    printFindOneContactsResponse(response);
}

void ContactsServer::findContacts() {
    httplib::Client client(CONTACTS_HOST, CONTACTS_PORT);
    // 发起Get请求
    auto result = client.Get("/contacts/find-all");
    if (!result) {
        std::string err_desc;
        err_desc.append("/contacts/find-all 连接错误! 错误信息: ")
                .append(httplib::to_string(result.error()));
        throw ContactsException(err_desc);
    }
    // 反序列化find_all_contact_response
    find_all_contact_response::FindAllContactResponse response;
    bool parse = response.ParseFromString(result->body);
    if (result->status != 200 && !parse) {
        std::string err_desc;
        err_desc.append("post '/contacts/find-all' 失败: ")
                .append(std::to_string(result->status))
                .append("(").append(result->reason).append(")");
        throw ContactsException(err_desc);
    } else if (result->status != 200) {
        std::string err_desc;
        err_desc.append("post '/contacts/find-all' 失败: ")
                .append(std::to_string(result->status))
                .append("(").append(result->reason).append(") 错误描述: ")
                .append(response.error_desc());
        throw ContactsException(err_desc);
    } else if (!response.success()) {
        std::string err_desc;
        err_desc.append("post '/contacts/find-all' 结果异常！异常描述: ")
                .append(response.error_desc());
        throw ContactsException(err_desc);
    }
    // 输出结果
    printFindAllContactsResponse(response);
}

void ContactsServer::bulidAddContactRequest(add_contact_request::AddContactRequest *request) {
    std::cout << "------------------------- start -------------------------" << std::endl;
    std::cout << "输入联系人姓名: ";
    std::string name;
    std::getline(std::cin, name);
    request->set_name(name);
    std::cout << "输入联系人年龄: ";
    int age;
    std::cin >> age;
    std::cin.ignore(256, '\n');
    request->set_age(age);
    for (int i = 0;; ++i) {
        std::cout << "输入联系人电话" << i + 1 << "(仅输入Enter退出): ";
        std::string number;
        std::getline(std::cin, number);
        if (number.empty()) {
            break;
        }
        add_contact_request::AddContactRequest_Phone *phone = request->add_phone();
        phone->set_number(number);
        std::cout << "输入电话类型(1.移动电话  2.固定电话): ";
        int choose;
        std::cin >> choose;
        std::cin.ignore(256, '\n');
        switch (choose) {
            case 1:
                phone->set_type(add_contact_request::AddContactRequest_Phone_PhoneType::AddContactRequest_Phone_PhoneType_MOBILE_PHONE);
                break;
            case 2:
                phone->set_type(add_contact_request::AddContactRequest_Phone_PhoneType::AddContactRequest_Phone_PhoneType_TELEPHONE);
                break;
            default:
                std::cout << "非法选择, 使用默认值(移动电话)!" << std::endl;
                break;
        }
    }
    for (int i = 0;; ++i) {
        std::cout << "输入备注" << i + 1 << "标题(仅输入Enter退出): ";
        std::string remark_key;
        std::getline(std::cin, remark_key);
        if (remark_key.empty()) {
            break;
        }
        std::cout << "输入备注内容: ";
        std::string remark_value;
        std::getline(std::cin, remark_value);
        request->mutable_remark()->insert({remark_key, remark_value});
    }
    std::cout << "-------------------------- end --------------------------" << std::endl;
}

void ContactsServer::printFindOneContactsResponse(const find_one_contact_response::FindOneContactResponse &response) {
    std::cout << "------------------------- start -------------------------" << std::endl;
    std::cout << "联系人姓名: " << response.people_info().name() << std::endl;
    std::cout << "联系人年龄: " << response.people_info().age() << std::endl;
    for (auto &phone : response.people_info().phone()) {
        std::cout << "联系人电话号码("
                  << find_one_contact_response::PeopleInfo_Phone_PhoneType_Name(phone.type()) << "): "
                  << phone.number()<< std::endl;
    }
    std::cout << "联系人备注:" << std::endl;
    for (auto it = response.people_info().remark().cbegin(); it != response.people_info().remark().cend(); ++it) {
            std::cout << "     " << it->first << ": " << it->second << std::endl; 
    }
    std::cout << "-------------------------- end --------------------------" << std::endl;
}

void ContactsServer::printFindAllContactsResponse(const find_all_contact_response::FindAllContactResponse &response) {
    if (response.contacts_size() == 0) {
        std::cout << "联系人为空" << std::endl;
        return;
    }
    std::cout << "------------------------- start -------------------------" << std::endl;
    for (auto &people : response.contacts()) {
        std::cout << "联系人姓名: " << people.name() << " ID: " << people.uid() << std::endl;
    }
    std::cout << "-------------------------- end --------------------------" << std::endl;
}