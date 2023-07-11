#include <iostream>

#include "../server/ContactsServer.h"
#include "../common/ContactsException.h"
#include "httplib.h"

int main() {
    std::cout << "----------- 服务启动 -----------" << std::endl;
    httplib::Server server;
    ContactsServer contactsServer;// lambda表达式捕捉参数要复习
    server.Post("/contacts/add", [contactsServer](const httplib::Request &req, httplib::Response &resp) {
        add_contact_request::AddContactRequest request; 
        add_contact_response::AddContactResponse response;
        try {
            // 反序列化request
            if (!request.ParseFromString(req.body)) {
                throw ContactsException("AddContactRequest反序列化失败!");
            }
            // 添加联系人
            contactsServer.add(request, &response);
            // 序列化response
            std::string response_str;
            if (!response.SerializeToString(&response_str)) {
                throw ContactsException("AddContactResponse序列化失败!");
            }
            resp.status = 200;
            resp.body = response_str;
            resp.set_header("Content-Type", "application/protobuf");
        } catch (const ContactsException &e) {
            resp.status = 500;
            response.set_success(false);
            response.set_error_desc(e.what());
            std::string response_str;
            if (response.SerializeToString(&response_str)) {
                resp.body = response_str;
                resp.set_header("Content-Type", "application/protobuf");
            }
            std::cout << "/contacts/add 发生异常, 异常信息: " << e.what() << std::endl;
        }
    });
    server.Post("/contacts/del", [contactsServer](const httplib::Request &req, httplib::Response &resp) {
        del_contact_request::DelContactRequest request; 
        del_contact_response::DelContactResponse response;
        try {
            // 反序列化request
            if (!request.ParseFromString(req.body)) {
                throw ContactsException("DelContactRequest反序列化失败!");
            }
            // 删除联系人
            contactsServer.del(request, &response);
            // 序列化response
            std::string response_str;
            if (!response.SerializeToString(&response_str)) {
                throw ContactsException("DelContactResponse序列化失败!");
            }
            resp.status = 200;
            resp.body = response_str;
            resp.set_header("Content-Type", "application/protobuf");
        } catch (const ContactsException &e) {
            resp.status = 500;
            response.set_success(false);
            response.set_error_desc(e.what());
            std::string response_str;
            if (response.SerializeToString(&response_str)) {
                resp.body = response_str;
                resp.set_header("Content-Type", "application/protobuf");
            }
            std::cout << "/contacts/del 发生异常, 异常信息: " << e.what() << std::endl;
        }
    });
    server.Post("/contacts/find-one", [contactsServer](const httplib::Request &req, httplib::Response &resp) {
        find_one_contact_request::FindOneContactRequest request; 
        find_one_contact_response::FindOneContactResponse response;
        try {
            // 反序列化request
            if (!request.ParseFromString(req.body)) {
                throw ContactsException("FindOneContactRequest反序列化失败!");
            }
            // 查询单个联系人
            contactsServer.findOne(request, &response);
            // 序列化response
            std::string response_str;
            if (!response.SerializeToString(&response_str)) {
                throw ContactsException("FindOneContactResponse序列化失败!");
            }
            resp.status = 200;
            resp.body = response_str;
            resp.set_header("Content-Type", "application/protobuf");
        } catch (const ContactsException &e) {
            resp.status = 500;
            response.set_success(false);
            response.set_error_desc(e.what());
            std::string response_str;
            if (response.SerializeToString(&response_str)) {
                resp.body = response_str;
                resp.set_header("Content-Type", "application/protobuf");
            }
            std::cout << "/contacts/find-one 发生异常, 异常信息: " << e.what() << std::endl;
        }
    });
    server.Get("/contacts/find-all", [contactsServer](const httplib::Request &req, httplib::Response &resp) {
        find_all_contact_response::FindAllContactResponse response;
        try {
            // 查询所有联系人
            contactsServer.findAll(&response);
            // 序列化response
            std::string response_str;
            if (!response.SerializeToString(&response_str)) {
                throw ContactsException("FindAllContactResponse序列化失败!");
            }
            resp.status = 200;
            resp.body = response_str;
            resp.set_header("Content-Type", "application/protobuf");
        } catch (const ContactsException &e) {
            resp.status = 500;
            response.set_success(false);
            response.set_error_desc(e.what());
            std::string response_str;
            if (response.SerializeToString(&response_str)) {
                resp.body = response_str;
                resp.set_header("Content-Type", "application/protobuf");
            }
            std::cout << "/contacts/find-all 发生异常, 异常信息: " << e.what() << std::endl;
        }
    });
    server.listen("0.0.0.0", 8080);
    return 0;
}
