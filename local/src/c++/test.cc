#include <../../include/database.h>
#include <../../include/customer.h>

int main()
    {
        UniClient::Customer *test=new UniClient::Customer();
        test->ID=123;
        test->FirstName="test";

        UniClient::Database db;
        db.put("",test);
    }
