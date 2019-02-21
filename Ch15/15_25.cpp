#include "Quote.h"
int main() {
	Quote a("booka", 10), b("bookb", 20);
	Quote c(a); c.debug(); a.debug();
	Quote d(std::move(b)); d.debug(); b.debug();
	return 0;
}