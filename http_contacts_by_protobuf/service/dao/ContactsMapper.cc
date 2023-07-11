#include "ContactsMapper.h"
#include "../common/ContactsException.h"
#include <fstream>

#define FILE_NAME "contacts.bin"

void ContactsMapper::readContacts(contacts::Contacts *contacts) {
    std::fstream input(FILE_NAME, std::ios::in | std::ios::binary);
    if (!input) {
        std::cout << "---> (ContactsMapper::readContacts) " << FILE_NAME << ": File not found.  Creating a new file." << std::endl;
    } else if (!contacts->ParseFromIstream(&input)) {
        input.close();
        throw ContactsException("(ContactsMapper::readContacts) Failed to parse contacts.");
    }
    input.close();
}

void ContactsMapper::writeContacts(const contacts::Contacts &contacts) {
    std::fstream output(FILE_NAME, std::ios::out | std::ios::trunc |std::ios::binary);
    if (!contacts.SerializeToOstream(&output)) {
        output.close();
        throw ContactsException("(ContactsMapper::writeContacts) Failed to write contacts.");
    }
    output.close();
}