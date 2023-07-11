#include "ContactsServer.h"
#include "../common/Utils.h"
#include "../common/ContactsException.h"
#include "../dao/ContactsMapper.h"

void ContactsServer::add(const add_contact_request::AddContactRequest &request, add_contact_response::AddContactResponse *response) const {
    // 打印联系人信息
    printAddContactRequest(request);
    // 创建通讯录对象
    contacts::Contacts contacts;
    // 读取本地文件，将其放入通讯录对象中
    ContactsMapper::readContacts(&contacts);
    // 根据请求构建一个联系人对象
    contacts::PeopleInfo people;
    bulidPeopleInfo(&people, request);
    // 向通讯录对象中添加联系人对象
    google::protobuf::Map< std::string, ::contacts::PeopleInfo >* map_contacts = contacts.mutable_contacts();
    map_contacts->insert({people.uid(), people});
    // 将通讯录对象写回本地
    ContactsMapper::writeContacts(contacts);
    // 填写add_contact_response
    response->set_success(true);
    response->set_uid(people.uid());
    // 打印日志
    std::cout << "---> (ContactsServer::add) Success to write contacts." << std::endl;
}

void ContactsServer::del(const del_contact_request::DelContactRequest &request, del_contact_response::DelContactResponse *response) const {
    // 打印日志
    std::cout << "---> (ContactsServer::del) DelContactRequest: uid: " << request.uid() << std::endl;  
    // 创建通讯录对象
    contacts::Contacts contacts;
    // 读取本地文件，将其放入通讯录对象中
    ContactsMapper::readContacts(&contacts);
    // 查询目标id是否存在
    if (contacts.contacts().find(request.uid()) == contacts.contacts().end()) {
        std::cout << "---> (ContactsServer::del) not find uid: " << request.uid() << std::endl;  
        response->set_success(false);
        response->set_error_desc("not find uid");
        response->set_uid(request.uid());
        return;
    }
    // 找到了，删除联系人
    contacts.mutable_contacts()->erase(request.uid());
    // 将通讯录对象写回本地
    ContactsMapper::writeContacts(contacts);
    // 填写del_contact_response
    response->set_success(true);
    response->set_uid(request.uid());
    // 打印日志
    std::cout << "---> (ContactsServer::del) Success to del contact, uid: " << request.uid() << std::endl;
}
void ContactsServer::findOne(const find_one_contact_request::FindOneContactRequest &request, find_one_contact_response::FindOneContactResponse *response) const {
    // 打印日志
    std::cout << "---> (ContactsServer::findOne) FindOneContactRequest: uid: " << request.uid() << std::endl;  
    // 创建通讯录对象
    contacts::Contacts contacts;
    // 读取本地文件，将其放入通讯录对象中
    ContactsMapper::readContacts(&contacts);
    // 查询目标id是否存在
    auto it = contacts.contacts().find(request.uid());
    if (it == contacts.contacts().end()) {
        std::cout << "---> (ContactsServer::findOne) not find uid: " << request.uid() << std::endl;  
        response->set_success(false);
        response->set_error_desc("not find uid");
        return;
    }
    // 通过一个联系人的信息构建response
    bulidFindOneContactResponse(it->second, response);
    // 打印日志
    std::cout << "---> (ContactsServer::findOne) Success to find contact, uid: " << request.uid() << std::endl;
}
void ContactsServer::findAll(find_all_contact_response::FindAllContactResponse *response) const {
    // 打印日志
    std::cout << "---> (ContactsServer::findAll) " << std::endl;  
    // 创建通讯录对象
    contacts::Contacts contacts;
    // 读取本地文件，将其放入通讯录对象中
    ContactsMapper::readContacts(&contacts);
    // 通过所有联系人信息构建response
    buildFindAllContactsResponse(contacts, response);
    // 打印日志
    std::cout << "---> (ContactsServer::findAll) Success to find contacts" << std::endl;  
}
    

void ContactsServer::printAddContactRequest(const add_contact_request::AddContactRequest &request) const {
    std::cout << "联系人姓名: " << request.name() << std::endl;
    std::cout << "联系人年龄: " << request.age() << std::endl;
    for (int i = 0; i < request.phone_size(); ++i) {
        add_contact_request::AddContactRequest_Phone phone = request.phone(i);
        std::cout << "联系人电话" << i + 1 << "("
             << add_contact_request::AddContactRequest_Phone_PhoneType_Name(request.phone(i).type())
             << "): " << request.phone(i).number() << std::endl;
    }
    if (request.remark_size()) {
        std::cout << "备注信息: " << std::endl;
    }
    for (auto it = request.remark().cbegin(); it != request.remark().cend(); ++it) {      
        std::cout << "    " << it->first << ": " << it->second << std::endl;      
    }      
}

void ContactsServer::bulidPeopleInfo(contacts::PeopleInfo *people, const add_contact_request::AddContactRequest &request) const {
    people->set_uid(Utils::generate_hex(16));
    people->set_name(request.name());
    people->set_age(request.age());
    for (int i = 0; i < request.phone_size(); ++i) {
        contacts::PeopleInfo_Phone *phone = people->add_phone();
        phone->set_number(request.phone(i).number());
        switch (request.phone(i).type()) {
            case add_contact_request::AddContactRequest_Phone_PhoneType::AddContactRequest_Phone_PhoneType_MOBILE_PHONE:
                phone->set_type(contacts::PeopleInfo_Phone_PhoneType::PeopleInfo_Phone_PhoneType_MOBILE_PHONE);
                break;
            case add_contact_request::AddContactRequest_Phone_PhoneType::AddContactRequest_Phone_PhoneType_TELEPHONE:
                phone->set_type(contacts::PeopleInfo_Phone_PhoneType::PeopleInfo_Phone_PhoneType_TELEPHONE);
                break;
            default:
                break;
        }
    }
    Utils::map_copy(people->mutable_remark(), request.remark());
}

void ContactsServer::bulidFindOneContactResponse(const contacts::PeopleInfo &people, find_one_contact_response::FindOneContactResponse *response) const {
    response->set_success(true);
    find_one_contact_response::PeopleInfo *p = response->mutable_people_info();
    p->set_uid(people.uid());
    p->set_name(people.name());
    p->set_age(people.age());
    for (auto &phone : people.phone()) {
        find_one_contact_response::PeopleInfo_Phone *resp_phone = p->add_phone();
        resp_phone->set_number(phone.number());
        switch (phone.type()) {
            case contacts::PeopleInfo_Phone_PhoneType::PeopleInfo_Phone_PhoneType_MOBILE_PHONE:
                resp_phone->set_type(find_one_contact_response::PeopleInfo_Phone::PhoneType::PeopleInfo_Phone_PhoneType_MOBILE_PHONE);
                break;
            case contacts::PeopleInfo_Phone_PhoneType::PeopleInfo_Phone_PhoneType_TELEPHONE:
                resp_phone->set_type(find_one_contact_response::PeopleInfo_Phone::PhoneType::PeopleInfo_Phone_PhoneType_TELEPHONE);
                break;
            default:
                break;
        }
    }
    Utils::map_copy(p->mutable_remark(), people.remark());
}

void ContactsServer::buildFindAllContactsResponse(const contacts::Contacts &contacts, find_all_contact_response::FindAllContactResponse *response) const {
    response->set_success(true);
    for (auto it = contacts.contacts().cbegin(); it != contacts.contacts().cend(); ++it) {
        find_all_contact_response::PeopleInfo *people = response->add_contacts();
        people->set_uid(it->second.uid());
        people->set_name(it->second.name());
    }
}