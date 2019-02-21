#include "Query.h"
#include "NotQuery.h"
#include "AndQuery.h"
#include "OrQuery.h"
int main() {
	//Query(s1) | Query(s2) & ~Query(s3);
	//Query(s1) | (Query(s2) & ~Query(s3));
	//(Query(s1) & (Query(s2)) | (Query(s3) & Query(s4)));
	Query q = Query("fiery") & Query("bird") | Query("wind");
	//q.eval();
	cout << q.rep();
	return 0;
}