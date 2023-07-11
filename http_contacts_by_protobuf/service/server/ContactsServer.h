#include <iostream>

#include "../controller/request/add_contact_request.pb.h"
#include "../controller/request/del_contact_request.pb.h"
#include "../controller/request/find_one_contact_request.pb.h"
#include "../controller/response/add_contact_response.pb.h"
#include "../controller/response/del_contact_response.pb.h"
#include "../controller/response/find_one_contact_response.pb.h"
#include "../controller/response/find_all_contact_response.pb.h"
#include "../dao/contacts.pb.h"

class ContactsServer {
public:
    void add(const add_contact_request::AddContactRequest &request, add_contact_response::AddContactResponse *response) const;
    void del(const del_contact_request::DelContactRequest &request, del_contact_response::DelContactResponse *response) const;
    void findOne(const find_one_contact_request::FindOneContactRequest &request, find_one_contact_response::FindOneContactResponse *response) const;
    void findAll(find_all_contact_response::FindAllContactResponse *response) const;
    
private:
    void printAddContactRequest(const add_contact_request::AddContactRequest &request) const;
    void bulidPeopleInfo(contacts::PeopleInfo *people, const add_contact_request::AddContactRequest &request) const;
    void bulidFindOneContactResponse(const contacts::PeopleInfo &people, find_one_contact_response::FindOneContactResponse *response) const;
    void buildFindAllContactsResponse(const contacts::Contacts &contacts, find_all_contact_response::FindAllContactResponse *response) const;
}; 