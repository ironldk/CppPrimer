//#pragma once
#include <string>
#include <set>
class Folder;
using std::set;
using std::string;
class Message {
	friend class Folder;
	friend void swap(Message &, Message &);
	friend void swap(Folder &, Folder &);
public:
	explicit Message(const string &str = "") :
		contents(str) { }
	Message(const Message&);
	Message(Message&&)noexcept;
	Message& operator=(const Message&);
	Message& operator=(Message&&)noexcept;
	~Message();
	void save(Folder&);
	void remove(Folder&);
private:
	string contents;
	set<Folder*> folders;
	void add_to_Folders(const Message&);
	void remove_from_Folders();
	void move_folders(Message *);
	void addFldr(Folder &f) { folders.insert(&f); }
	void remFldr(Folder &f) { folders.erase(&f); }
};
class Folder {
	friend class Message;
	friend void swap(Message &, Message &);
	friend void swap(Folder &, Folder &);
public:
	Folder() = default;
	Folder(const Folder &);
	Folder &operator=(const Folder &);
	~Folder();
private:
	set<Message *> msgs;
	void addMsg(Message *);
	void remMsg(Message *);
	void add_to_Messages(const Folder&);
	void remove_from_Messages();
};
void swap(Message &, Message &);
void swap(Folder &, Folder &);