#include <database.h>

int main()
    {
        UniClient::Database db;
        UniClient::Microsun::Plant* temp=new UniClient::Microsun::Plant();
        temp->ID="καλησπέρα";
        UniClient::Microsun::Problem t;
        t.reg_id=123;
        t.Type="test";
        db.get_user("root","all",t.AssignedMech);
        db.get_user("root","all",t.ReportedUser);
        t.ErrorCode="test";
        t.ErrorNotes="test";
        t.MechNotes="test";
        t.Pos=1;
        t.ReportedDate->fromString("6;4;5;6;4;5;6;");
        t.ResolvedDate->fromString("6;4;5;6;4;5;6;");
        t.plant=temp;
        db.storeError(&t,"TEMP_STORED_ERRORS");
        db.getPendingCount();
    }