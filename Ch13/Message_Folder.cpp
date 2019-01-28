#include "stdafx.h"
#include "Message_Folder.h"

void Message::save(Folder &f)
{
	folders.insert(&f);
	f.addMsg(this);
}
void Message::remove(Folder &f)
{
	folders.erase(&f);
	f.remMsg(this);
}
void Message::add_to_Folders(const Message &m)
{
	for (auto f : m.folders)
		f->addMsg(this);
}
Message::Message(const Message &m) :
	contents(m.contents), folders(m.folders) {
	add_to_Folders(m);
}
Message::Message(Message &&m)noexcept:
	contents(std::move(m.contents)){
	move_folders(&m);
}
void Message::remove_from_Folders() {
	for (auto f : folders)
		f->remMsg(this);
	folders.clear();
}
void move_folders(Message *m) {
	folders = std::move(m->folders);
	for (auto f : folders) {
		f->remMsg(m);
		f->addMsg(this);
	}
	m->folders.clear();
}
Message::~Message() {
	remove_from_Folders();
}
Message& Message::operator=(const Message &rhs)
{
	remove_from_Folders();
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_Folders(rhs);
	return *this;
}
Message& Message::operator=(Message &&rhs)noexcept
{
	if (this != &rhs) {
		remove_from_Folders();
		contents = std::move(rhs.contents);
		this->move_folders(&rhs);
	}
	return *this;
}
void swap(Message &lhs, Message &rhs)
{
	using std::swap;
	for (auto f : lhs.folders)
		f->remMsg(&lhs);
	for (auto f : rhs.folders)
		f->remMsg(&rhs);
	swap(lhs.folders, rhs.folders);
	swap(lhs.contents, rhs.contents);
	for (auto f : lhs.folders)
		f->addMsg(&lhs);
	for (auto f : rhs.folders)
		f->addMsg(&rhs);
}

Folder::Folder(const Folder &f) {
	msgs = f.msgs;
	add_to_Messages(*this);
}
Folder &Folder::operator=(const Folder &rhs) {
	this->remove_from_Messages();
	msgs = rhs.msgs;
	this->add_to_Messages(*this);
	return *this;
}
Folder::~Folder() {
	this->remove_from_Messages();
	msgs.clear();
}
void Folder::add_to_Messages(const Folder &f) {
	for (auto m : f.msgs) {
		m->folders.insert(this);
	}
}
void Folder::remove_from_Messages() {
	for (auto m : msgs) {
		m->folders.erase(this);
	}
	msgs.clear();
}
void Folder::addMsg(Message *m) {
	msgs.insert(m);
}
void Folder::remMsg(Message *m) {
	msgs.erase(m);
}
void swap(Folder &lhs, Folder &rhs) {
	using std::swap;
	for (auto m : lhs.msgs)
		m->addFldr(lhs);
	for (auto m : rhs.msgs)
		m->remFldr(rhs);
	swap(lhs.msgs, rhs.msgs);
	for (auto m : lhs.msgs)
		m->addFldr(lhs);
	for (auto m : rhs.msgs)
		m->remFldr(rhs);
}