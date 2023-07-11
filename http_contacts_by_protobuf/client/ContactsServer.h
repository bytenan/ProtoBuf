#include <iostream>

#include "./request/add_contact_request.pb.h"
#include "./request/del_contact_request.pb.h"
#include "./request/find_one_contact_request.pb.h"
#include "./response/add_contact_response.pb.h"
#include "./response/del_contact_response.pb.h"
#include "./response/find_one_contact_response.pb.h"
#include "./response/find_all_contact_response.pb.h"

class ContactsServer {
public:
    void addContact();
    void delContact();
    void findContact();
    void findContacts();

private:
    void bulidAddContactRequest(add_contact_request::AddContactRequest *request);
    void printFindOneContactsResponse(const find_one_contact_response::FindOneContactResponse &response);
    void printFindAllContactsResponse(const find_all_contact_response::FindAllContactResponse &response);
};