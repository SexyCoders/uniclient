#include <uniclient.h>
#include <database.h>
#include <mariadb/mysql.h>
#include <stdlib.h>
#include <curl-php.h>
//#include <POST.h>

int main()
	{
		UniClient::Database* t=new UniClient::Database();
		UniClient::Customer C;
		C.setID(2);
		C.setCompany("ΕΛΛΗΝΙΚΑ");
		C.setFirstName("ΕΛΛΗΝΙΚΑ");
		C.setLastName("ΕΛΛΗΝΙΚΑ");
		C.setPhoneNumber(123);
		C.setemail("ΕΛΛΗΝΙΚΑ");
		C.setAddress("ΕΛΛΗΝΙΚΑ");
		C.setzip(1234);
		C.setNotes("ΕΛΛΗΝΙΚΑ");
		Time test;
		test.getTime();
		C.setAdded(test);
		C.setLastInteraction(test);
		//t->exec("INSERT INTO CUSTOMERS VALUES(1,'Γ.ΔΙΑΚΟΥΜΑΚΟΥ Κ ΣΙΑ Ε.Ε.','ΓΑΡΥΦΑΛΙΑ','ΔΙΑΚΟΥΜΑΚΟΥ',6932320122,'diakumakos@microsun.gr','ΣΕΛΕΓΟΥΔΙ, ΓΥΘΕΙΟ',23200,800091939,'SOME NOTES','3;14;4;21;13;31;12;','3;14;4;21;13;31;12;');");
		//t->get("test",2,&C);
		//t->put("test",&C);
		char* response;
		POST("localhost:56083/php/src/external.php","malakies",&response);
		printf("%s\n",response);
	}
