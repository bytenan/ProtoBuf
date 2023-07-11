#include "contacts.pb.h"

class ContactsMapper {
public:
    static void readContacts(contacts::Contacts *contacts);
    static void writeContacts(const contacts::Contacts &contacts);
};